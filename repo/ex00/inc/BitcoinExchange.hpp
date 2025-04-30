#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <string>
#include <fstream>

class BitcoinExchange
{
	private :
		std::ifstream	_f_arg;
		std::ifstream	_f_data;

							BitcoinExchange();
							BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);

	public :
		BitcoinExchange(int argc, char **argv);
		~BitcoinExchange();

		void parseInput();
};

#endif