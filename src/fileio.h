#pragma once

#include <iostream>
#include <fstream>

namespace bfc
{
	namespace fileio
	{
		std::string input(std::string path);
		void output(std::string path, std::string source);
	}
}
