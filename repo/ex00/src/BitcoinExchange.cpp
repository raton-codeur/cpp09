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
	_input.close();
	_data.close();
}

BitcoinExchange::BitcoinExchange(int argc, char **argv)
{
	if (argc != 2)
		throw std::invalid_argument("wrong number of arguments");

	_input.open(argv[1]);
	if (!_input.is_open())
		throw std::invalid_argument("could not open input file");

	_data.open("data.csv");
	if (!_data.is_open())
		throw std::invalid_argument("could not open \"data.csv\"");

	std::string first_line;
	if (!std::getline(_input, first_line))
	{
		if (_input.eof())
			throw std::invalid_argument("empty input file");
		throw std::runtime_error("getline failed to read header");
	}
	if (first_line != "date | value")
		throw std::invalid_argument("wrong header in input file : expecting \"date | value\"");
}

void check_format(const std::string& line)
{
	const char* s = line.c_str();
	size_t i = 0, j;

	for (j = 0; j < 4; ++j)
	{
		if (!std::isdigit(s[i++]))
			throw std::logic_error("invalid format");
	}
	if (s[i++] != '-')
		throw std::logic_error("invalid format");
	for (j = 0; j < 2; ++j)
	{
		if (!std::isdigit(s[i++]))
			throw std::logic_error("invalid format");
	}
	if (s[i++] != '-')
		throw std::logic_error("invalid format");
	for (j = 0; j < 2; ++j)
	{
		if (!std::isdigit(s[i++]))
			throw std::logic_error("invalid format");
	}
	if (s[i++] != ' ')
		throw std::logic_error("invalid format");
	if (s[i++] != '|')
		throw std::logic_error("invalid format");
	if (s[i++] != ' ')
		throw std::logic_error("invalid format");
	if (!std::isdigit(s[i++]))
		throw std::logic_error("invalid format");
	while (std::isdigit(s[i]))
		++i;
	if (s[i++] == '.')
	{
		if (!std::isdigit(s[i++]))
			throw std::logic_error("invalid format");
		while (std::isdigit(s[i]))
			++i;
		if (s[i] != '\0')
			throw std::logic_error("invalid format");
	}
}

void BitcoinExchange::parse_line(const std::string& line)
{
	check_format(line);
	_year = std::stoi(line.substr(0, 4));
	_month = std::stoi(line.substr(5, 2));
	_day = std::stoi(line.substr(8, 2));
	_s_value = line.substr(13);
	if (_s_value.find('.') != != std::string::npos)
	{
		std::cout << "float : \"" << s_value << '"' << std::endl;
	}
	else
	{
		std::cout << "int : \"" << s_value << '"' << std::endl;
	}
	// std::string s_value;
	// if (_month < 1 || _month > 12)
	// 	throw std::logic_error("invalid date");
	// if (_day < 1 || _day > 31)
	// 	throw std::logic_error("invalid date");
	// if isLeapYear(_year)
	// {
	// 	if (_month == 2 && _day > 29)
	// 		throw std::logic_error("invalid date");
	// }
	// else
	// {
	// 	if (_month == 2 && _day > 28)
	// 		throw std::logic_error("invalid date");
	// }
	// s_value = std::string(s + i_value);
	// std::cout << "value found : \"" << std::string(s + i_value) << '"' << std::endl;
	// std::cout << "line : \"" << line << '"' << std::endl;
}

void BitcoinExchange::parseInput()
{
	std::string line;

	while (std::getline(_input, line))
	{
		if (line.empty())
			continue;
		try
		{
			parseLine(line);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << "error in \"" << line << "\" : " << e.what() << RESET << std::endl;
		}
	}
	if (!_input.eof())
		throw std::runtime_error("getline failed");
}
