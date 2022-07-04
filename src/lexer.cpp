#include "lexer.h"

namespace bfc
{
	namespace lexer
	{
		std::map <char, TokenKind> charKindList
		{
			std::make_pair('<', MOV),
			std::make_pair('>', MOV),
			std::make_pair('+', ADD),
			std::make_pair('-', ADD),
			std::make_pair(',', INP),
			std::make_pair('.', OUP),
			std::make_pair('[', LOS),
			std::make_pair(']', LOE)
		};

		TokenKind getCharKind(char ch)
		{
			return charKindList.at(ch);
		}

		std::vector <Token> tokenization(std::string source)
		{
			const long length = source.length();
			Token lastToken {NUL, 0};
			std::vector <Token> tokens;
			
			for (int i = 0; i < length; ++i)
			{
				const char ch = source.at(i);
				const TokenKind thisTokenKind = getCharKind(ch);

				if (lastToken.tokenKind != thisTokenKind
					or thisTokenKind == LOS
					or thisTokenKind == LOE
					or thisTokenKind == INP
					or thisTokenKind == OUP)
				{
					tokens.push_back(lastToken);
					lastToken.tokenKind  = thisTokenKind;
					lastToken.operNumber = 0;
				}	
				
				if (   ch == '<'
					or ch == '-')
				{
					--lastToken.operNumber;
				}
				else
				{
					++lastToken.operNumber;
				}
			}
			
			tokens.push_back(lastToken);

			long len 	= tokens.size();
			long loopID {0};
			std::stack <long> loops;

			for (int i = 0; i < len; ++i)
			{
				Token & thisToken = tokens.at(i);
				if (thisToken.tokenKind == ADD
					and thisToken.operNumber == 0)
				{
					tokens.erase(tokens.begin() + i);
					--i;
					--len;
				}
				else if (thisToken.tokenKind == LOS)
				{
					thisToken.operNumber = loopID;
					loops.push(loopID);
					++loopID;
				}
				else if (thisToken.tokenKind == LOE)
				{
					thisToken.operNumber = loops.top();
					loops.pop();
				}

			}

			return tokens;
		}
	}
}
