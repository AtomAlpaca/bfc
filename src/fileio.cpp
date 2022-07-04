#include "fileio.h"

namespace bfc
{
	namespace fileio
	{
		std::string input(std::string path)
		{
			std::string str;
			std::ifstream inputFile;
			inputFile.open(path);
			if (!inputFile.is_open())
			{
				std::cerr << "Error: Can't open file " << path << std::endl;
				exit(-1);
			}
			while (inputFile.good())
			{
				std::string thisLine;
				getline(inputFile, thisLine);
				str.append(thisLine);
			}

			inputFile.close();

			return str;
		}

		void output(std::string path, std::string source)
		{
			std::ofstream outputFile;
			outputFile.open(path);

			if (!outputFile.is_open())
			{
				std::cerr << "Error: Can't open file " << path << std::endl;
				exit(-1);
			}

			outputFile << source;
			
			outputFile.close();

			return ;
		}
	}
}
