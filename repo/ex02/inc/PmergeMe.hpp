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
#define RED "\033[31m"
#define RESET "\033[0m"

typedef std::vector<int> Vec;

class PmergeMe
{
	private :
		Vec _v;

					PmergeMe();
					PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);

	public :
		PmergeMe(int argc, char** argv);
		~PmergeMe();

		void	sort(size_t n);
		void	swapPairs(size_t n);
		std::vector<int>& getV() { return _v; }
};

#endif