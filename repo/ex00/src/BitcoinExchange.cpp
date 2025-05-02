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
{}

BitcoinExchange::BitcoinExchange(int argc, char **argv)
{
	if (argc != 2)
		throw std::invalid_argument("wrong number of arguments");

	_inputStream.open(argv[1]);
	if (!_inputStream.is_open())
		throw std::invalid_argument("could not open input file");

	_dataStream.open("data.csv");
	if (!_dataStream.is_open())
		throw std::invalid_argument("could not open \"data.csv\"");
}

void BitcoinExchange::parseData()
{
	std::string	line;
	int			year, month, day;
	float		rate;

	if (!std::getline(_dataStream, line))
		throw std::runtime_error("cannot read data header");
	while (std::getline(_dataStream, line))
	{
		year = std::atoi(line.substr(0, 4).c_str());
		month = std::atoi(line.substr(5, 2).c_str());
		day = std::atoi(line.substr(8, 2).c_str());
		rate = std::atof(line.substr(11).c_str());
		_data[Date(year, month, day)] = rate;
	}
	if (!_dataStream.eof())
		throw std::runtime_error("getline failed");
}

void checkLineFormat(const std::string& line)
{
	const char* s = line.c_str();
	size_t i = 0, j;

	for (j = 0; j < 4; ++j)
	{
		if (!std::isdigit(s[i++]))
			throw std::logic_error("invalid date format");
	}
	if (s[i++] != '-')
		throw std::logic_error("invalid date format");
	for (j = 0; j < 2; ++j)
	{
		if (!std::isdigit(s[i++]))
			throw std::logic_error("invalid date format");
	}
	if (s[i++] != '-')
		throw std::logic_error("invalid date format");
	for (j = 0; j < 2; ++j)
	{
		if (!std::isdigit(s[i++]))
			throw std::logic_error("invalid date format");
	}
	if (s[i++] != ' ')
		throw std::logic_error("invalid format");
	if (s[i++] != '|')
		throw std::logic_error("invalid format");
	if (s[i++] != ' ')
		throw std::logic_error("invalid format");
	if (!std::isdigit(s[i++]))
		throw std::logic_error("invalid value format : expecting a digit");
	while (std::isdigit(s[i]))
		++i;
	if (s[i] == '.')
	{
		++i;
		if (!std::isdigit(s[i++]))
			throw std::logic_error("invalid value format : expecting a digit after the decimal point");
		while (std::isdigit(s[i]))
			++i;
		}
	if (s[i] != '\0')
		throw std::logic_error("invalid value : unexpected character");
}

float BitcoinExchange::getRate(const Date& date) const
{
	float result;

	result = _data.end()->second;
	for (std::map<Date, float>::const_reverse_iterator it = _data.rbegin(); it != _data.rend(); ++it)
	{
		if (date <= it->first)
			result = it->second;
		else
			break;
	}
	return result;
}

void BitcoinExchange::parseInput()
{
	std::string line;
	int			year, month, day;
	float		value, rate;
	Date		date;
	const Date	firstDataDate = Date(2009, 1, 2);

	if (!std::getline(_inputStream, line))
	{
		if (_inputStream.eof())
			throw std::invalid_argument("empty input file");
		throw std::runtime_error("getline failed to read header");
	}
	if (line != "date | value")
		throw std::invalid_argument("wrong header in input file : expecting \"date | value\"");

	while (std::getline(_inputStream, line))
	{
		if (line.empty())
			continue;
		try
		{
			checkLineFormat(line);

			year = std::atoi(line.substr(0, 4).c_str());
			month = std::atoi(line.substr(5, 2).c_str());
			day = std::atoi(line.substr(8, 2).c_str());
			date = Date(year, month, day);
			if (date < firstDataDate)
				throw std::logic_error("invalid date : too old");

			value = std::atof(line.substr(13).c_str());
			if (value > 1000)
				throw std::logic_error("invalid value : too large number");

			rate = getRate(date);
			std::cout << "rate : " << rate << " ";
			date.print();
			std::cout << " => " << value << " = " << value * rate << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << "error in \"" << line << "\" : " << e.what() << RESET << std::endl;
		}
	}
	if (!_inputStream.eof())
		throw std::runtime_error("getline failed");
}
