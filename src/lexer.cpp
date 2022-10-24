#include "lexer.h"

namespace bfc
{
	namespace lexer
	{
		const std::map <char, TokenKind> charKindList
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

		/*
		bfc::lexer::getCharKind :: char -> TokenKind
		*/
		TokenKind getCharKind(char ch)
		{
			return charKindList.at(ch);
		}

		Token mergeToken(Token token, char ch)
		{
			if (ch == '<' or ch == '-')
			{
				return {token.tokenKind, token.operNumber - 1};
			}
			else if (ch == '>' or ch == '+')
			{
				return {token.tokenKind, token.operNumber + 1};
			}
			else
			{
				throw "Error: Enable to merge the char to this token";
			}
		}

		bool isIgnorableToken(Token token)
		{
			if ((token.tokenKind == ADD or token.tokenKind == MOV)
				and token.operNumber == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		/*
		bfc::lexer::tokenization :: std::string -> std::vector <Token>
		*/
		std::vector <Token> tokenization(std::string source)
		{
			Token lastToken {NUL, 0};
			std::vector <Token> tokens;
			std::stack <long> loops;
			long loopID {0};

			auto addToken = [&loopID, &loops](Token token, std::vector <Token> list)
			-> std::vector <Token>
			{
				if (!isIgnorableToken(token))
				{
					if (token.tokenKind == LOS)
					{
						loops.push(loopID);
						list.push_back({token.tokenKind, loopID});
						++loopID;
					}
					else if (token.tokenKind == LOE)
					{
						list.push_back({token.tokenKind, loops.top()});
						loops.pop();
					}
					else
					{
						list.push_back({token.tokenKind, token.operNumber});
					}
				}
				return list;
			};

			for (const char ch : source)
			{
				const TokenKind thisTokenKind = getCharKind(ch);
				
				if (thisTokenKind == lastToken.tokenKind
				and (	thisTokenKind == MOV 
					 or thisTokenKind == ADD))
				{
					lastToken = mergeToken(lastToken, ch);
				}
				else
				{
					tokens = addToken(lastToken, tokens);
					lastToken = {thisTokenKind, 0};
					if (thisTokenKind == MOV or thisTokenKind == ADD)
					{
						lastToken = mergeToken(lastToken, ch);	
					}
				}
				
			}
			tokens = addToken(lastToken, tokens);
			return tokens;
		}
	}
}
