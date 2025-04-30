#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	(void)other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	(void)other;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	_f_arg.close();
	_f_data.close();
}

BitcoinExchange::BitcoinExchange(int argc, char **argv)
{
	if (argc != 2)
		throw std::invalid_argument("wrong number of arguments");

	std::ifstream f_arg(argv[1]);
	if (!f_arg.is_open())
		throw std::invalid_argument("could not open file \"" + std::string(argv[1]) + "\"");

	std::ifstream f_data("data.csv");
	if (!f_data.is_open())
		throw std::invalid_argument("could not open file \"data.csv\"");
}
