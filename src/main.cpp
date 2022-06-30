#include "lexer.h"
#include "preprocessor.h"

int main(int argc, char * argv[])
{
	std::string test = ">>>>>>>>>>>>>>>>+++++++++++<<<<<<<<<<,,    HelloWorld!  42 ........The quick brown fox jumps over the lazy dog[[]]";
	/*std::string test = "[[[]";
	std::string test = ">>><<<<<<<<<<<<<";
	std::string test = "[]]]";*/
	std::string str = bfc::preprocessor::preProcess(test);
	std::cout << str << std::endl;

	std::vector <bfc::lexer::Token> tokenList = bfc::lexer::tokenization(str);

	const long len = tokenList.size();

	for (int i = 0; i < len; ++i)
	{

		if (tokenList.at(i).tokenKind == bfc::lexer::ADD)
		{
			std::cout << "add:" << tokenList.at(i).operNumber << std::endl;
		}
		else if (tokenList.at(i).tokenKind == bfc::lexer::MOV)
		{
			std::cout << "mov:" << tokenList.at(i).operNumber << std::endl;
		}
		else if (tokenList.at(i).tokenKind == bfc::lexer::LOS)
		{
			std::cout << "start of loop" << std::endl;
		}
		else if (tokenList.at(i).tokenKind == bfc::lexer::LOE)
		{
			std::cout << "end of loop" << std::endl;
		}
		else if (tokenList.at(i).tokenKind == bfc::lexer::INP)
		{
			std::cout << "input" << std::endl;
		}	
		else if (tokenList.at(i).tokenKind == bfc::lexer::OUP)
		{
			std::cout << "output" << std::endl;
		}
		else
		{
			std::cout << "Start/End of token list" << std::endl;
		}
	}

	return 0;
}
