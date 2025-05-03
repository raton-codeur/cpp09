#include "RPN.hpp"
#define RED "\033[31m"
#define RESET "\033[0m"

int main(int argc, char** argv)
{
	try
	{
		RPN rpn(argc, argv);
		rpn.checkArg();
		rpn.execute();
		rpn.printResult();
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "error : " << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}
