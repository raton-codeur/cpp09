#include "Date.hpp"

Date::Date() :
	_year(0),
	_month(0),
	_day(0)
{}

static bool isLeapYear(int year)
{
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

Date::Date(int year, int month, int day) :
	_year(year),
	_month(month),
	_day(day)
{
	if (month < 1 || month > 12)
		throw std::logic_error("invalid date");
	if (day < 1 || day > 31)
		throw std::logic_error("invalid date");
	if (month == 2)
	{
		if (isLeapYear(year))
		{
			if (day > 29)
				throw std::logic_error("invalid date");
		}
		else
		{
			if (day > 28)
				throw std::logic_error("invalid date");
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			throw std::logic_error("invalid date");
	}
}

Date::Date(const Date& other) :
	_year(other._year),
	_month(other._month),
	_day(other._day)
{}

Date& Date::operator=(const Date& other)
{
	if (this != &other)
	{
		_year = other._year;
		_month = other._month;
		_day = other._day;
	}
	return *this;
}

Date::~Date()
{}

void Date::print() const
{
	std::cout << _year << "-" << (_month < 10 ? "0" : "") << _month << "-" << (_day < 10 ? "0" : "") << _day;
}

bool Date::operator<(const Date& other) const
{
	if (_year != other._year)
		return _year < other._year;
	else if (_month != other._month)
		return _month < other._month;
	else
		return _day < other._day;
}

bool Date::operator==(const Date& other) const
{
	return _year == other._year && _month == other._month && _day == other._day;
}

bool Date::operator>(const Date& other) const
{
	return !(*this < other || *this == other);
}
