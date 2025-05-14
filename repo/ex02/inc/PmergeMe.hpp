#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <deque>
#include <cerrno>
#include <climits>
#include <ctime>
#define RED "\033[31m"
#define RESET "\033[0m"

typedef std::vector<int> Vector;
typedef std::deque<int> Deque;

class PmergeMe
{
	private :
		Vector	_arg;

				PmergeMe();
				PmergeMe(const PmergeMe& other);
	PmergeMe&	operator=(const PmergeMe& other);

	public :
		PmergeMe(int argc, char** argv);
		~PmergeMe();

		void	printArg() const;
		Vector	sort1() const;
		Deque	sort2() const;
};

template <typename T>
T sort(T& v, size_t n);

template <typename T>
void print(T& t, size_t n = 1);

#include "PmergeMe.tpp"

#endif