#ifndef DATE_HPP
#define DATE_HPP
#include <stdexcept>

class Date
{
	private :
		int	_year;
		int	_month;
		int	_day;

				Date();
				Date(const Date& other);
		Date&	operator=(const Date& other);

	public :
		Date(int year, int month, int day);
		~Date();
		
		bool operator<(const Date& other) const;
};

#endif