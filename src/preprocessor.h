#pragma once

#include <iostream>

namespace bfc
{
	namespace preprocessor
	{
		void checkLoop(int loopNumber);
		inline bool isBfChar(char ch);
		std::string preProcess(std::string source);
	}
}
