/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:45:49 by raveriss          #+#    #+#             */
/*   Updated: 2024/07/04 22:45:39 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Define macro to avoid multiple inclusions */
#pragma once

/* Inclusion de la bibliothèque standard pour std::cout */
#include <iostream>

/* Include the stack container files */
#include <stack>

/* Inclusion de la bibliothèque standard pour std::sstream */
#include <sstream>

/* Inclusion de la bibliothèque standard pour std::string */
#include <string>

/* Include the standard library for std::floor */
#include <cmath>

/* Include the standard library for std::setprecision */
#include <iomanip>

/* Define values */
#define RETURN_SUCCESS 0
#define RETURN_FAILURE 1
#define EXPECTED_ARGC 2

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
 * @brief Class RPN
 */
class RPN
{
    public:
    
        /* Constructeur par défaut */
        RPN();

        /* Constructeur par copie */
        RPN(const RPN & other);

        /* Opérateur d'affectation */
        RPN & operator = (const RPN & other);

        /* Destructeur */
        ~RPN();

        /* Fonction pour évaluer l'expression */
        double evaluate(const std::string & expression);

    private:

        /* Pile d'entiers */
        std::stack<double> _stack;

        /* Function to check if a token is an operator */
        bool isOperator(const std::string & token);
        
        /* Function to perform an operation */
        double performOperation(const std::string & operation, double operand1, double operand2);

        /* Function to validate the expression */
        void validateExpression(const std::string & expression);

};

/* RPN_HPP */
