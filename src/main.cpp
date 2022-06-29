#include "preprocessor.h"

int main(int argc, char * argv[])
{
	std::string test = ">>>>>>>>>>>>>>>>+++++++++++<<<<<<<<<<,,    HelloWorld!  42 ........The quick brown fox jumps over the lazy dog";
	/*std::string test = "[[[]";
	std::string test = ">>><<<<<<<<<<<<<";
	std::string test = "[]]]";*/
	std::string str = bfc::preprocessor::preProcess(test);
	std::cout << str;
	return 0;
}
