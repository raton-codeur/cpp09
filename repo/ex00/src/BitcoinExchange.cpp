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

	_f_arg.open(argv[1]);
	if (!_f_arg.is_open())
		throw std::invalid_argument("could not open input file");

	_f_data.open("data.csv");
	if (!_f_data.is_open())
		throw std::invalid_argument("could not open \"data.csv\"");
	
	std::string first_line;
	if (!std::getline(_f_arg, first_line))
	{
		if (_f_arg.eof())
			throw std::invalid_argument("empty input file");
		throw std::runtime_error("getline failed to read header");
	}
	if (first_line != "date | value")
		throw std::invalid_argument("wrong header in input file : expecting \"date | value\"");
}

void f(const std::string& line)
{
	size_t i = 0, j;

	for (j = 0; j < 4; ++i, ++j)
	{
		if (i == line.size() || !std::isdigit(line[i]))
			throw std::logic_error("wrong date : \"" + line + "\"");
	}
	if (line[i++] != '-')
		throw std::logic_error("wrong date : \"" + line + "\"");
	for (j = 0; j < 2; ++i, ++j)
	{
		if (i == line.size() || !std::isdigit(line[i]))
		throw std::logic_error("wrong date : \"" + line + "\"");
	}
	if (line[i++] != '-')
		throw std::logic_error("wrong date : \"" + line + "\"");
	for (j = 0; j < 2; ++i, ++j)
	{
		if (i == line.size() || !std::isdigit(line[i]))
			throw std::logic_error("wrong date : \"" + line + "\"");
	}



	std::cout << "line : \"" << line << '"' << std::endl;
}

void BitcoinExchange::parseInput()
{
	std::string line;

	while (std::getline(_f_arg, line))
	{
		if (line.empty())
			continue;
		try
		{
			f(line);
		}
		catch (const std::exception& e)
		{
			std::cerr << "error : " << e.what() << std::endl;
		}
	}
	if (!_f_arg.eof())
		throw std::runtime_error("getline failed");
}
