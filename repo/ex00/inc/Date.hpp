#ifndef DATE_HPP
#define DATE_HPP
#include <stdexcept>
#include <iostream>

class Date
{
	private :
		int	_year;
		int	_month;
		int	_day;

	public :
				Date();
				Date(int year, int month, int day);
				Date(const Date& other);
		Date&	operator=(const Date& other);
				~Date();

		void print() const;

		bool operator<(const Date& other) const;
		bool operator==(const Date& other) const;
		bool operator>(const Date& other) const;
};

#endif