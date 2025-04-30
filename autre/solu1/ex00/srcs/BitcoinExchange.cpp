/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:53:54 by raveriss          #+#    #+#             */
/*   Updated: 2024/07/04 23:33:02 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion de la classe BitcoinExchange */
#include "../incs/BitcoinExchange.hpp"

/**
 * @brief Constructeur par défaut
 */
BitcoinExchange::BitcoinExchange()
{}

/**
 * @brief Constructeur par copie
 */
BitcoinExchange::BitcoinExchange(const BitcoinExchange & other)
: _exchangeRates(other._exchangeRates)
{}

/**
 * @brief Opérateur d'affectation
 */
BitcoinExchange & BitcoinExchange::operator = (const BitcoinExchange & other)
{
    if (this != &other)
        _exchangeRates = other._exchangeRates;

    return *this;
}

/**
 * @brief Destructeur
 */
BitcoinExchange::~BitcoinExchange()
{}

/**
 * Fonction pour vérifier si un caractère est un espace blanc
 */
bool isNotSpace(char ch)
{
    return !std::isspace(static_cast<unsigned char>(ch));
}

/**
 * Fonction pour supprimer les espaces en tête de la chaîne
 */
std::string& ltrim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), isNotSpace));
    return s;
}

/**
 * Fonction pour supprimer les espaces en queue de la chaîne
 */
std::string& rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), isNotSpace).base(), s.end());
    return s;
}

/**
 * @brief Fonction pour supprimer les espaces en tête et en queue de la chaîne
 */
std::string& trim(std::string &s)
{
    return ltrim(rtrim(s));
}

/**
 * @brief Charge la base de données data.csv
 */
void BitcoinExchange::loadDatabase(const std::string & filename)
{
	/* Ouvre le fichier data.csv */
    std::ifstream file(filename.c_str());
	
	/* Vérifie si le fichier a été ouvert avec succès */
    if (!file)
        throw std::runtime_error("Error: could not open file.");

	/* Déclare des variables de type string */
    std::string line, date;

	/* Déclare une variable de type double */
    double rate;

    /* Check if the first line contains header */
    if (std::getline(file, line))
    {
        /* Check if the first line is "date,exchange_rate" */
        if (line != "date,exchange_rate")
        {
            /* Create a stringstream from the line */
            std::istringstream ss(line);

            /* Extract the date and rate from the line */
            if (std::getline(ss, date, ',') && (ss >> rate))
                _exchangeRates[date] = rate;
        }
    }
    
	/* Lit le fichier ligne par ligne */
    while (getline(file, line))
    {
		/* Create a stringstream from the line */
        std::stringstream ss(line);

		/* Extract the date and rate from the line */
        if (getline(ss, date, ',') && (ss >> rate))
            _exchangeRates[date] = rate;
    }
}

/**
 * @brief Traite l'entrée input.txt
 */
void BitcoinExchange::processInput(const std::string & filename)
{
    /* Ouvre le fichier input.txt */
    std::ifstream file(filename.c_str());

    /* Vérifie si le fichier a été ouvert avec succès */
    if (!file)
        throw std::runtime_error("Error: could not open file.");

    /* Déclare des variables de type string */
    std::string inputLine, datePart, valuePart;

    /* Déclare une variable de type double */
    double value;

    /* Read the file line by line */
    bool firstLine = true;

    while (getline(file, inputLine))
    {
        trim(inputLine);
        
        if (firstLine)
        {
            /* Check if the first line is "date | value" */
            if (inputLine == "date | value")
            {
                firstLine = false;
                continue;
            }
        }
        
        firstLine = false;

        /* Create a stringstream from the line */
        std::stringstream ss(inputLine);
        
        /* Check if the line is of the form "date | value" */
        if (inputLine[11] != '|' || inputLine[10] != ' ' || inputLine[12] != ' ' )
        {
            inputLine = inputLine.empty() ? "empty" : inputLine;
            std::cout << "Error: bad input => " << inputLine << std::endl;
            continue;
        }

        /* Extract the date and value from the inputLine */
        if (getline(ss, datePart, '|'))
        {
            /* Extract the value from the stringstream */
            if (!getline(ss, valuePart))
            {
                std::cout << "Error: bad input => " << inputLine << std::endl;
                continue;
            }
            /* Erase trailing whitespace */
            datePart.erase(datePart.find_last_not_of(" \n\r\t") + 1);
            
            /* Erase leading whitespace */
            valuePart.erase(0, valuePart.find_first_not_of(" \n\r\t"));
            
            /* Check if the date is valid */
            if (!isValidDate(datePart))
            {
                std::cout << "Error: bad input => " << datePart << std::endl;
                continue;
            }

            /* Check if the value is valid */
            if (!isValidValue(valuePart))
            {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }

            /* Convert the string to a double */
            value = atof(valuePart.c_str());

            /* check if the value is greater than 1000 */
            if (value > 1000)
            {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }

            /* Get the exchange rate for the date */
            double rate = getExchangeRate(datePart);
            std::cout << datePart << " => " << value << " = " << value * rate << std::endl;
        }
        else
        {
            /* If the date could not be extracted, print an error message */
            inputLine = inputLine.empty() ? "empty" : inputLine;
            std::cout << "Error: bad input => " << inputLine << std::endl;
        }
    }
}

/**
 * @brief Récupère le taux de change
 */
double BitcoinExchange::getExchangeRate(const std::string & date) const
{
	/* Find first element in _exchangeRates with key >= date, store const iterator */
    std::map<std::string, double>::const_iterator it = _exchangeRates.lower_bound(date);
	
	/* If the iterator is at the end of the map or the key is not equal to date, decrement the iterator */
    if (it == _exchangeRates.end() || it->first != date)
    {
		/* If the iterator is at the beginning of the map, return 0 */
        if (it == _exchangeRates.begin())
			return 0;
        --it;
    }
    return it->second;
}

/**
 * @brief Vérifie si la date est valide
 */
bool BitcoinExchange::isValidDate(const std::string & date) const
{

    /* Check if the date is of the form YYYY-MM-DD */
    if (date.size() != DATE_LENGTH || date[YEAR_POSITION] != '-' || date[MONTH_POSITION] != '-')
        return false;

    /* Check if the year is a number */
    for (int i = MIN_YEAR_DIGITS; i < MAX_YEAR_DIGITS; ++i)
    {
        if (!isdigit(date[i]))
            return false;
    }

    /* Check if the month is a number */
    for (int i = MIN_MONTH_DIGITS; i < MAX_MONTH_DIGITS; ++i)
    {
        if (!isdigit(date[i]))
            return false;
    }

    /* Check if the day is a number */
    for (int i = MIN_DAY_DIGITS; i < MAX_DAY_DIGITS; ++i)
    {
        if (!isdigit(date[i]))
            return false;
    }

    /* Extract year from date: substr first 4 chars, c_str to const char* for atoi, atoi to int */
    int year = atoi(date.substr(MIN_YEAR_DIGITS, YEAR_LENGTH).c_str());

    /* Extract month from date: substr 5th and 6th chars, c_str to const char* for atoi, atoi to int */
    int month = atoi(date.substr(MIN_MONTH_DIGITS, MONTH_LENGTH).c_str());

    /* Extract day from date: substr 8th and 9th chars, c_str to const char* for atoi, atoi to int */
    int day = atoi(date.substr(MIN_DAY_DIGITS, DAY_LENGTH).c_str());

    /* Check if the month is between 1 and 12 */
    if (month < MIN_MONTH || month > MAX_MONTH)
        return false;

    /* Check if the day is between 1 and 31 */
    if (day < MIN_DAY || day > MAX_DAY)
        return false;

    /* Check if the month is February */
    if (month == FEBRUARY)
    {
        /* Declare a boolean isLeap */
        bool isLeap;

		/* Check if the year is a leap year */
		isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

		/* Check if the day is greater than 29 or 29 on a non-leap year */
        if (day > 29 || (day == 29 && !isLeap))
            return false;
    }

    /* Check if the month is April, June, September or November */
    else if (month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER)
    {
		/* Check if the day is greater than 30 */
        if (day > 30)
            return false;
    }

    return true;
}

/**
 * @brief Vérifie si la valeur est valide
 */
bool BitcoinExchange::isValidValue(const std::string & value) const
{
	/* Declare a pointer to a char */
    char* end;

	/* Convert the string to a double */
    double val = strtod(value.c_str(), &end);
	
	/* Check if the conversion was successful and the value is positive */
    return end != value.c_str() && *end == '\0' && val >= 0;
}

/* BitcoinExchange.cpp */
