#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		BitcoinExchange bce(argc, argv);
		bce.parseInput();
	}
	catch (const std::exception& e)
	{
		std::cerr << "error : " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
