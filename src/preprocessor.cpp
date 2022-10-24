#include "preprocessor.h"
namespace bfc
{
	namespace preprocessor
	{
		/*
		bfc::preprocessor::checkLoop :: long int -> void
		Check if the loop is mismatch. If so, throw a exception
		with the type of `std::string'.
		*/
		void checkLoop(const long loopDepth)
		{
			if (loopDepth < 0)
			{
				throw std::string("Error: Loop mismatch. ")
					+ std::to_string(-loopDepth)
					+ "more `[' requested.";
			}
			else if (loopDepth > 0)
			{
				throw std::string("Error: Loop mismatch. ")
				  	 + std::to_string(loopDepth)
					 + "more `]' requested.";
			}
			else
			{
				return ;
			}
		}

		/*
		bfc::preprocessor::isBfChar :: char -> bool
		Check if the char is a defined BrainFuck command.
		*/
		bool isBfChar(const char ch)
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
			else
			{
				return false;
			}
		}

		/*
		bfc::preprocessor::preProcess :: std::string -> std::string
		Accept a string of source code and return another string
		without undefined BrainFuck command. Moreover, when there is
		an unsolvable problem in the source, like loop mismatch, the
		function will print the error message and end the program.
		*/
		std::string preProcess(const std::string source)
		{
			long loopDepth     {0};
			std::string result { };

			for (const char ch : source)
			{
				if (isBfChar(ch))
				{
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
			}

			try
			{
				checkLoop(loopDepth);
			}
			catch (std::string errorMsg)
			{
				std::cerr << errorMsg;
				exit(-1);
			}
			
			return result;
		}
	}
}
