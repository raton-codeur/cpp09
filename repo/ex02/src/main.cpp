#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	try
	{
		PmergeMe p(argc, argv);
		p.main();
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "error : " << e.what() << RESET << std::endl;
		return 1;
	}
}
