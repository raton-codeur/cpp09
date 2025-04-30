/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:53:59 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/29 23:27:31 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Définition de la macro pour éviter les inclusions multiples */
#pragma once

/* Inclusion de la bibliothèque standard pour std::map */
#include <map>

/* Inclusion de la bibliothèque standard pour std::string */
#include <string>

/* Inclusion de la bibliothèque standard pour std::cerr */
#include <iostream>

/* Inclusion de la bibliothèque standard pour std::ifstream */
#include <fstream>

/* Inclusion de la bibliothèque standard pour std::sstream */
#include <sstream>

/* Inclusion de la bibliothèque standard pour std::runtime_error */
#include <stdexcept>

/* Inclusion de la bibliothèque standard pour std::atof */
#include <cstdlib>

/* Inclusion de la bibliothèque standard pour std::cout */
#include <iostream>

/* Inclusion de la bibliothèque standard pour std::find_if */
#include <algorithm>

/* Inclusion de la bibliothèque standard pour std::isspace */
#include <cctype>

/* Define values */
#define RETURN_SUCCESS 0
#define RETURN_FAILURE 1
#define EXPECTED_ARGC 2

/* Définition des constantes pour la validation de la date */
#define DATE_LENGTH 10
#define YEAR_POSITION 4
#define MONTH_POSITION 7
#define MIN_YEAR_DIGITS 0
#define MAX_YEAR_DIGITS 4
#define MIN_MONTH_DIGITS 5
#define MAX_MONTH_DIGITS 7
#define MIN_DAY_DIGITS 8
#define MAX_DAY_DIGITS 10
#define MIN_MONTH 1
#define MAX_MONTH 12
#define MIN_DAY 1
#define MAX_DAY 31

/* Définition des constantes pour les longueurs de sous-chaînes */
#define YEAR_LENGTH 4
#define MONTH_LENGTH 2
#define DAY_LENGTH 2

/* Définition des constantes pour les mois */
#define FEBRUARY 2
#define APRIL 4
#define JUNE 6
#define SEPTEMBER 9
#define NOVEMBER 11

/* Definitions of ANSI color codes for console output */
#define GREY        "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define CYAN        "\033[0;36m"
#define WHITE       "\033[0;37m"

/* Definitions of ANSI bright color codes for console output */
#define BRIGHT_GREY    "\033[1;30m"
#define BRIGHT_RED     "\033[1;31m"
#define BRIGHT_GREEN   "\033[1;32m"
#define BRIGHT_YELLOW  "\033[1;33m"
#define BRIGHT_BLUE    "\033[1;34m"
#define BRIGHT_MAGENTA "\033[1;35m"
#define BRIGHT_CYAN    "\033[1;36m"
#define BRIGHT_WHITE   "\033[1;37m"

/* Definitions of ANSI background color codes for console output */
#define BLACK_BG       "\033[40m"
#define RED_BG         "\033[41m"
#define GREEN_BG       "\033[42m"
#define YELLOW_BG      "\033[43m"
#define BLUE_BG        "\033[44m"
#define MAGENTA_BG     "\033[45m"
#define CYAN_BG        "\033[46m"
#define WHITE_BG       "\033[47m"

/* Definitions of ANSI text style codes for console output */
#define BOLD           "\033[1m"
#define UNDERLINE      "\033[4m"
#define RESET          "\033[0m"

/* No Color */
#define NC             RESET

/**
 * @brief Classe BitcoinExchange
 */
class BitcoinExchange
{
    public:

		/* Constructeur par défaut */
        BitcoinExchange();

		/* Constructeur par copie */
        BitcoinExchange(const BitcoinExchange & other);

		/* Opérateur d'affectation */
        BitcoinExchange & operator = (const BitcoinExchange & other);

		/* Destructeur */
        ~BitcoinExchange();

		/* Charge la base de données */
        void loadDatabase(const std::string & filename);

		/* Traite l'entrée */
        void processInput(const std::string & filename);

		/* Récupère le taux de change */
        double getExchangeRate(const std::string & date) const;

    private:

		/* containers pour stocker les taux de change */
        std::map<std::string, double> _exchangeRates;

		/* Fonction membre pour vérifier la validité de la date */
        bool isValidDate(const std::string & date) const;

		/* Fonction membre pour vérifier la validité de la valeur */
        bool isValidValue(const std::string & value) const;
};

/* BitcoinExchange.hpp */
