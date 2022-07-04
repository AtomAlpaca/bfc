#include "lexer.h"
#include "codegen.h"

namespace bfc
{
	namespace codegen
	{
		std::string codegen(std::vector <bfc::lexer::Token> tokenList)
		{
			std::string code;
			code.append(std::string(   "	.text\n")
									 + "	.globl	ch\n"
									 + "	.bss\n"
									 + "	.align	32\n"
									 + "	.type	ch, @object\n"
									 + "	.size	ch, 1000000\n"
									 + "ch:\n"
									 + "	.zero	1000000\n"
									 + "	.globl	ptr\n"
									 + "	.section	.data.rel.local,\"aw\"\n"
									 + "	.align	8\n"
									 + "	.type	ptr, @object\n"
									 + "	.size	ptr, 8\n"
									 + "ptr:\n"
									 + "	.quad	ch\n"
									 + "	.text\n"
									 + "	.globl	main\n"
									 + "	.type	main, @function\n"
									 + "main:\n"
									 + "	pushq	%rbp\n"
									 + "	movq	%rsp, %rbp");

			const long length = tokenList.size();

			for (int i = 0; i < length; ++i)
			{
				bfc::lexer::Token thisToken = tokenList.at(i);
				if (thisToken.tokenKind == bfc::lexer::MOV)
				{
					if (thisToken.operNumber > 0)
					{
						code.append(std::string("	 movq  	ptr(%rip),	%rax\n")
											  + "	 addq	$" 
											  + 	std::to_string(thisToken.operNumber) 
										      + ", %rax\n"
											  + "	 movq	%rax, ptr(%rip)\n");
					}
					else
					{
						code.append(std::string("	 movq    ptr(%rip), %rax\n")
        									  + "	 subq    $"
											  + 	std::to_string(-thisToken.operNumber)
											  + ", %rax\n"
										      + "	 movq    %rax, ptr(%rip)\n");
					}
				}
				else if (thisToken.tokenKind == bfc::lexer::ADD)
				{
					code.append(std::string("	 movq    ptr(%rip), %rax\n")
										  + "	 movzbl  (%rax), \%eax\n"
										  + "	 leal    "
										  + 	std::to_string(thisToken.operNumber)
										  + "(%rax), \%edx\n"
		       							  + "	 movq    ptr(%rip), %rax\n"
		 								  + "	 movb    \%dl, (%rax)\n");
				}
				else if (thisToken.tokenKind == bfc::lexer::INP)
				{
					code.append("	movq	$0, \%rax\n");
					code.append("	movq 	$0, \%rdi\n");
					code.append("	movq 	ptr(\%rip), \%rsi\n");
					code.append("	movq 	$1, \%rdx\n");
					code.append("	syscall\n");
				}
				else if (thisToken.tokenKind == bfc::lexer::OUP)
				{
					code.append("	movq	$1, \%rax\n");
					code.append("	movq 	$1, \%rdi\n");
					code.append("	movq 	ptr(\%rip), \%rsi\n");
					code.append("	movq 	$1, \%rdx\n");
					code.append("	syscall\n");
				}
				else if (thisToken.tokenKind == bfc::lexer::LOS)
				{
					code.append(std::string("	 movq   ptr(%rip), %rax\n")
										  + "	 movzbl (%rax), \%eax\n"
							       		  + " 	 testb  \%al, \%al\n"
										  + "	 je		LOOP_END_"
										  + std::to_string(thisToken.operNumber)
										  + "\n"
										  + "	 LOOP_START_"
										  + std::to_string(thisToken.operNumber)
										  + ":\n");
					/*code.append("	cmpb 	$0, 	(ptr)\n");
					code.append("	je 		LOOP_END_");
					code.append(std::to_string(thisToken.operNumber));
					code.append("\n");
					code.append("	LOOP_START_");
					code.append(std::to_string(thisToken.operNumber));
					code.append(":\n");*/
				}
				else if (thisToken.tokenKind == bfc::lexer::LOE)
				{
					code.append(std::string("	 movq   ptr(%rip), %rax\n")
										  + "	 movzbl (%rax), \%eax\n"
							       		  + " 	 testb  \%al, \%al\n"
										  + "	 jne	LOOP_START_"
										  + std::to_string(thisToken.operNumber)
										  + "\n"
										  + "	 LOOP_END_"
										  + std::to_string(thisToken.operNumber)
										  + ":\n");

				}
				code.append("\n");
			}

			code.append("popq	%rbp\n");
			code.append("ret\n");

			return code;
		}
	}
}
