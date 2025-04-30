#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		BitcoinExchange b(argc, argv);
		b.parseData();
		b.parseInput();
		b.print();
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "error : " << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}
