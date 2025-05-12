#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <list>
#include <cerrno>
#include <climits>
#include <ctime>
#define RED "\033[31m"
#define RESET "\033[0m"

typedef std::vector<int> Vector;

class PmergeMe
{
	private :
	
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe&	operator=(const PmergeMe& other);
	
	public :
		Vector v;

		PmergeMe(int argc, char** argv);
		~PmergeMe();

		Vector sort(Vector& v, size_t n);
};

#endif