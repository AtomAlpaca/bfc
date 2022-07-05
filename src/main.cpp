#include <iostream>
#include "lexer.h"
#include "preprocessor.h"
#include "codegen.h"
#include "fileio.h"

int main(int argc, char * argv[])
{
	std::string sourcePath, outputPath;
	if (argc != 2 and argc != 3)
	{
		std::cerr << "Error: Bad input. Use bfc <source_file> (<output_file>)" << std::endl;
		return -1;
	}
	else if (argc == 2)
	{
		sourcePath = std::string(argv[1]);
		long found = sourcePath.rfind(".");
		if (found == std::string::npos)
		{
			outputPath = sourcePath + ".s";
		}
		else
		{
			outputPath = sourcePath.substr(0, found) + ".s";
		}
	}
	else if (argc == 3)
	{
		sourcePath = std::string(argv[1]);
		outputPath = std::string(argv[2]);
	}
		
	std::string sourceCode = bfc::fileio::input(sourcePath);
	bfc::fileio::output
	(
		outputPath,
		bfc::codegen::codegen
		(
			bfc::lexer::tokenization
			(
				bfc::preprocessor::preProcess(sourceCode)
			)
		)
	);
/*
	std::string test = bfc::fileio::input("./test.b");
	std::string str = bfc::preprocessor::preProcess(test);
	std::vector <bfc::lexer::Token> tokenList = bfc::lexer::tokenization(str);
	std::string finalCode = bfc::codegen::codegen(tokenList);
	bfc::fileio::output("./test.s", finalCode);*/
	return 0;
}
