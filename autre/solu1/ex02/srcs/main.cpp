/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:29:15 by raveriss          #+#    #+#             */
/*   Updated: 2024/07/10 12:03:54 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion of the PmergeMe header file */
#include "../incs/PmergeMe.hpp"

// Macro pour vérifier une expression et afficher un message de test passé/échoué
#define ASSERT_TEST(expression, message) \
    if (expression) { std::cout << "\033[32m[TEST PASSED]\033[0m " << message << std::endl; } \
    else { std::cout << "\033[31m[TEST FAILED]\033[0m " << message << std::endl; }

/**
 * @brief Get the sum of the numbers from 1 to n with O(n) complexity
 */
long long int getSum_On(long n)
{
    long long int sum = 0;
    for (int number = 1; number <= n; ++number)
    {
        sum += number;
    }
    return sum;
}

/**
 * @brief Get the sum of the numbers from 1 to n with O(1) complexity
 */
long long int getSum_O1(long n)
{
    return n * (n + 1) / 2;
}

/**
 * @brief Check if a string is a positive integer
 */
bool isPositiveInteger(const std::string& str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return !str.empty();
}

/**
 * @brief Format a number with spaces
 */
std::string formatWithSpaces(int number, int maxWidth)
{
    std::ostringstream oss;
    oss << number;
    std::string str = oss.str();
    int numSpaces = maxWidth - str.length();
    for (int i = 0; i < numSpaces; ++i)
    {
        str = " " + str;
    }
    return str;
}

/**
 * @brief Convert an integer to a string
 */
std::string intToString(int number)
{
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

void testPmergeMe()
{
    /* Création d'un objet PmergeMe et initialisation des données */
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    std::deque<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deq.push_back(4);
    deq.push_back(5);
    
    PmergeMe original;
    original.setData(vec);
    original.setDeq(deq);

    /* Test du constructeur de copie */
    PmergeMe copy(original);
    ASSERT_TEST(copy.getData() == original.getData(), "Copy constructor - vector");
    ASSERT_TEST(copy.getDeq() == original.getDeq(), "Copy constructor - Deque");

    // Modification de l'objet original
    std::vector<int> newVec;
    newVec.push_back(10);
    newVec.push_back(20);
    newVec.push_back(30);
    
    std::deque<int> newDeq;
    newDeq.push_back(10);
    newDeq.push_back(20);
    newDeq.push_back(30);
    
    original.setData(newVec);
    original.setDeq(newDeq);

    // Vérification que les données de la copie ne sont pas affectées par les modifications de l'original
    ASSERT_TEST(copy.getData() != original.getData(), "Copy constructor - Independent data vector after modification");
    ASSERT_TEST(copy.getDeq() != original.getDeq(), "Copy constructor - Independent deque after modification");

    // Test de l'opérateur d'affectation
    PmergeMe assigned;
    assigned = copy;
    ASSERT_TEST(assigned.getData() == copy.getData(), "Assignment operator - Data vector");
    ASSERT_TEST(assigned.getDeq() == copy.getDeq(), "Assignment operator - Deque");

    // Modification de la copie
    std::vector<int> modifiedVec;
    modifiedVec.push_back(100);
    modifiedVec.push_back(200);
    modifiedVec.push_back(300);
    
    std::deque<int> modifiedDeq;
    modifiedDeq.push_back(100);
    modifiedDeq.push_back(200);
    modifiedDeq.push_back(300);
    
    copy.setData(modifiedVec);
    copy.setDeq(modifiedDeq);

    // Vérification que les données de l'objet affecté ne sont pas affectées par les modifications de la copie
    ASSERT_TEST(assigned.getData() != copy.getData(), "Assignment operator - Independent data vector after modification");
    ASSERT_TEST(assigned.getDeq() != copy.getDeq(), "Assignment operator - Independent deque after modification");
    std::cout << std::endl;
}

/**
 * @brief Main function
 */
int main(int argc, char* argv[])
{
    try
    {
        if (argc < EXPECTED_ARGC || (argc > 3 && strcmp(argv[FIRST_ARGUMENT], TEST_ARG) == 0))
        {
            std::cerr << NC << RED_BG << "Usage: " << argv[0] << " num1 num2 ... numN or " << argv[0] << " tester num or " << argv[0] << " tester" << NC << std::endl;
            return RETURN_FAILURE;
        }
        
        else if (argc == ARG_ONE)
        {
            if (strcmp(argv[FIRST_ARGUMENT], TEST_ARG) == STRING_COMPARE_SUCCESS)
            {
                testPmergeMe();
                return RETURN_SUCCESS;
            }
            else
            {
                std::cerr << NC << RED_BG << "Usage: " << argv[0] << " num1 num2 ... numN or " << argv[0] << " tester num or " << argv[0] << " tester" << NC << std::endl;
                return RETURN_FAILURE;
            }
        }

        else if (argc == ARG_TWO && strcmp(argv[FIRST_ARGUMENT], TEST_ARG) == STRING_COMPARE_SUCCESS)
        {
            if (!isPositiveInteger(argv[SECOND_ARGUMENT]))
            {
                std::cerr << NC << RED_BG << "Error: Invalid input '" << argv[SECOND_ARGUMENT] << "'. The input must be a positive integer." << NC << std::endl;
                return RETURN_FAILURE;
            }

            long long value = std::strtoll(argv[SECOND_ARGUMENT], NULL, 10);

            if (value > INT_MAX)
            {
                std::cerr << NC << RED_BG << "Error: Input value '" << argv[SECOND_ARGUMENT] << "' exceeds the maximum allowed integer value (INT_MAX)." << NC << std::endl;
                return RETURN_FAILURE;
            }

            std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std::endl;
            std::cout << CYAN << "/*                                 OPTIONNEL                                  */" << NC << std::endl;
            std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std::endl;

            std::clock_t start_O1 = std::clock();
            getSum_O1(value);
            std::clock_t end_O1 = std::clock();
            double duration_O1 = 1000000.0 * (end_O1 - start_O1) / CLOCKS_PER_SEC;

            std::clock_t start_On = std::clock();
            getSum_On(value);
            std::clock_t end_On = std::clock();
            double duration_On = 1000000.0 * (end_On - start_On) / CLOCKS_PER_SEC;

            const char* OnColor = (duration_On <= duration_O1) ? GREEN_BG : RED_BG;
            const char* O1Color = (duration_O1 <= duration_On) ? GREEN_BG : RED_BG;

            int maxWidth = std::max(intToString(duration_On).length(), intToString(duration_O1).length());

            std::cout << BRIGHT_MAGENTA << "Time to process a range of " << value << " elements with std::\n" << NC << OnColor << " getSum_On "
                      << NC << ": " << formatWithSpaces(duration_On, maxWidth) << " us" << std::endl;
            std::cout << NC << O1Color << " getSum_O1 " << NC << ": " << formatWithSpaces(duration_O1, maxWidth) << " us" << std::endl << std::endl;
        }
        else
        {
            std::vector<int> data;
            std::deque<int> deq;

            for (int i = 1; i < argc; ++i)
            {
                if (!isPositiveInteger(argv[i]))
                {
                    std::cerr << NC << RED_BG << "Error: Invalid input '" << argv[i] << "'. All inputs must be positive integers." << NC << std::endl << std::endl;
                    return RETURN_FAILURE;
                }

                long long verifie = std::strtoll(argv[i], NULL, 10);

                if (verifie > INT_MAX)
                {
                    std::cerr << NC << RED_BG << "Error: Input value '" << argv[i] << "' exceeds the maximum allowed integer value (INT_MAX)." << NC << std::endl;
                    return RETURN_FAILURE;
                }

                int num = std::atoi(argv[i]);

                data.push_back(num);
                deq.push_back(num);
            }

            PmergeMe pmergeMe;
            pmergeMe.setData(data);
            pmergeMe.setDeq(deq);

            std::cout << CYAN << "/*   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   */\n" << NC;
            std::cout << CYAN << "/*                                  VECTOR                                   */\n" << NC;
            std::cout << CYAN << "/*   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   */\n" << NC;

            std::cout << BRIGHT_BLUE << "Before" << NC << " : ";
            for (std::vector<int>::iterator it = pmergeMe.getData().begin(); it != pmergeMe.getData().end(); ++it)
            {
                std::cout << *it << " ";
            }

            if (pmergeMe.getData().size() > 26)
                std::cout << std::endl;

            std::clock_t startVector = std::clock();
            sortsFordJohnson(pmergeMe.getData());
            std::clock_t endVector = std::clock();
            double durationVector = 1000000.0 * (endVector - startVector) / CLOCKS_PER_SEC;

            std::cout << BRIGHT_BLUE << "\nAfter" << NC << " : ";
            for (std::vector<int>::iterator it = pmergeMe.getData().begin(); it != pmergeMe.getData().end(); ++it)
            {
                std::cout << *it << " ";
            }

            if (pmergeMe.getData().size() > 26 || pmergeMe.getDeq().size() <= 10)
                std::cout << std::endl;

            std::cout << CYAN <<  "\n/*   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   */\n" << NC;
            std::cout << CYAN << "/*                                   DEQUE                                   */\n" << NC;
            std::cout << CYAN << "/*   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   */\n" << NC;

            std::cout << BRIGHT_BLUE << "Before" << NC << " : ";
            for (std::deque<int>::iterator it = pmergeMe.getDeq().begin(); it != pmergeMe.getDeq().end(); ++it)
            {
                std::cout << *it << " ";
            }

            if (pmergeMe.getDeq().size() > 26 || pmergeMe.getDeq().size() > 10)
                std::cout << std::endl;

            std::clock_t startDeque = std::clock();
            sortsFordJohnson(pmergeMe.getDeq());
            std::clock_t endDeque = std::clock();
            double durationDeque = 1000000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;

            if (pmergeMe.getDeq().size() > 26 || pmergeMe.getDeq().size() <= 10)
                std::cout << std::endl;

            std::cout << BRIGHT_BLUE << "After" << NC << " : ";
            for (std::deque<int>::iterator it = pmergeMe.getDeq().begin(); it != pmergeMe.getDeq().end(); ++it)
            {
                std::cout << *it << " ";
            }

            if (pmergeMe.getDeq().size() > 26 || pmergeMe.getDeq().size() <= 10)
                std::cout << std::endl;

            std::cout << CYAN <<  "\n/*   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   */\n" << NC;
            std::cout << CYAN << "/*                                  RESULTAT                                 */\n" << NC;
            std::cout << CYAN << "/*   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   */\n" << NC;

            const char* vectorColor = (durationVector <= durationDeque) ? GREEN_BG : RED_BG;
            const char* dequeColor = (durationDeque <= durationVector) ? GREEN_BG : RED_BG;

            int maxWidth = std::max(intToString(durationVector).length(), intToString(durationDeque).length());

            std::cout << BRIGHT_MAGENTA << "Time to process a range of " << pmergeMe.getData().size() << " elements with std::\n" << NC << vectorColor << " vector "
                      << NC << ": " << formatWithSpaces(durationVector, maxWidth) << " us" << std::endl;
            std::cout << dequeColor << "  deque " << NC << ": " << formatWithSpaces(durationDeque, maxWidth) << " us" << NC << std::endl << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << NC << RED_BG << "Exception: " << e.what() << NC << std::endl;
        return RETURN_FAILURE;
    }
    return RETURN_SUCCESS;
}

/* main.cpp */