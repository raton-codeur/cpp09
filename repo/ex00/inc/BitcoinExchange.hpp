#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <string>
#include <fstream>
#define RED "\033[31m"
#define RESET "\033[0m"

class BitcoinExchange
{
	private :
		std::ifstream	_input;
		std::ifstream	_data;

		std::map<Date, float>	
		int				_year;
		int				_month;
		int				_day;
		std::string		_s_value;

							BitcoinExchange();
							BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);

	public :
		BitcoinExchange(int argc, char **argv);
		~BitcoinExchange();

		void	parseInput();
		void	parse_line(const std::string& line);
};

#endif