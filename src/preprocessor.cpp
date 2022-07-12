#include "preprocessor.h"
namespace bfc
{
	namespace preprocessor
	{
		void checkLoop(int loopDepth)
		{
			if (loopDepth < 0)
			{
				std::cerr << "Error: Loop mismatch" << std::endl
						  << -loopDepth	<< " more `[` requested.";
				exit(-1);
			}
			else if (loopDepth > 0)
			{
				std::cerr << "Error: Loop mismatch" << std::endl
						  << loopDepth	<< " more `]` requested.";
				exit(-1);
			}
			return ;
		}

		inline bool isBfChar(char ch)
		{
			if (   ch == '<'
				or ch == '>'
				or ch == '-'
				or ch == '+'
				or ch == '['
				or ch == ']'
				or ch == ','
				or ch == '.')
			{
				return true;
			}
			return false;
		}

		std::string preProcess(std::string source)
		{
			const long length = source.length();
			long loopDepth   {0};
			std::string result {};

			for (int i = 0; i < length; ++i)
			{
				const char ch = source.at(i);
				if (!isBfChar(ch))
				{
					continue;
				}

				result.push_back(ch);

				if (ch == '[')
				{
					++loopDepth;
				}
				else if (ch == ']')
				{
					--loopDepth;
				}
			}
			checkLoop(loopDepth);
			
			return result;
		}
	}
}
