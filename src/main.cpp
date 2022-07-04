#include "lexer.h"
#include "preprocessor.h"
#include "codegen.h"
#include "fileio.h"

int main(int argc, char * argv[])
{
	std::string test = bfc::fileio::input("./test.b");
	std::string str = bfc::preprocessor::preProcess(test);
	std::vector <bfc::lexer::Token> tokenList = bfc::lexer::tokenization(str);
	std::string finalCode = bfc::codegen::codegen(tokenList);
	bfc::fileio::output("./test.s", finalCode);
	return 0;
}
