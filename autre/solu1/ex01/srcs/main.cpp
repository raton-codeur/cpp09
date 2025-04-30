/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:46:19 by raveriss          #+#    #+#             */
/*   Updated: 2024/07/04 23:32:37 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Include the RPN class */
#include "../incs/RPN.hpp"

/**
 * @brief Function to check if a double is an integer
 */
bool isInteger(double value)
{
    return std::floor(value) == value;
}

/**
 * @brief Function to print the result
 */
void printResult(double result)
{
    if (isInteger(result))
        std::cout << static_cast<int>(result) << std::endl;

    else
        std::cout << std::fixed << std::setprecision(2) << result << std::endl;
}

/***
 * @brief Main function
 */
int main(int argc, char* argv[])
{
    if (argc != EXPECTED_ARGC)
    {
        std::cerr << NC << RED_BG << "Usage: " << argv[0] << " \"operant operant operator ...\"" << NC << std::endl;
        return RETURN_FAILURE;
    }

    try
    {
        RPN rpn;
        double result = rpn.evaluate(argv[1]);
        printResult(result);
    }
    
    catch (const std::exception& e) 
    {
        std::cerr << NC << RED_BG << e.what() << NC << std::endl;
        return RETURN_FAILURE;
    }

    return RETURN_SUCCESS;
}

/* main.cpp */
