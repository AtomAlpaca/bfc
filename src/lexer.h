#pragma once

#include <string>
#include <stack>
#include <map>
#include <vector>

namespace bfc
{
	namespace lexer
	{
		enum TokenKind
		{
			MOV,
			ADD,
			LOS,
			LOE,
			INP,
			OUP,
			NUL
		};

		struct Token
		{
			TokenKind tokenKind;
			long operNumber;
		};

		TokenKind getCharKind(char ch);
		std::vector <Token> tokenization(std::string source);
	}
}
