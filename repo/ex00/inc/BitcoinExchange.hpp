#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <map>
#define RED "\033[31m"
#define RESET "\033[0m"
#include "Date.hpp"

class BitcoinExchange
{
	private :
		std::ifstream			_inputStream;
		std::ifstream			_dataStream;
		std::map<Date, float>	_data;

							BitcoinExchange();
							BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);

	public :
		BitcoinExchange(int argc, char **argv);
		~BitcoinExchange();

		void	parseData();
		void	parseInput();
		float	getRate(const Date& date) const;
};

#endif