#pragma once

#include <vector>
#include <string>

namespace bfc
{
	namespace codegen
	{
		std::string codegen(std::vector <bfc::lexer::Token> tokenList);
	}
}
