#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe()
{}

static void checkArg(const char* s)
{
	size_t i = 0;

	while (std::isspace(s[i]))
		++i;
	if (!std::isdigit(s[i]))
		throw std::invalid_argument("\"" + std::string(s) + "\" : invalid argument");
	++i;
	while (std::isdigit(s[i]))
		++i;
	while (std::isspace(s[i]))
		++i;
	if (s[i] != '\0')
		throw std::invalid_argument("\"" + std::string(s) + "\" : invalid argument");

	errno = 0;
	long n = std::strtol(s, NULL, 10);
	if (errno == ERANGE || n > INT_MAX)
		throw std::invalid_argument("\"" + std::string(s) + "\" : int overflow");
}

PmergeMe::PmergeMe(int argc, char** argv)
{
	if (argc == 1)
		throw std::invalid_argument("expecting at least one argument");
	for (int i = 1; i < argc; ++i)
	{
		checkArg(argv[i]);
		_v.push_back(std::atoi(argv[i]));
	}
	std::unordered_set<int> set(_v.begin(), _v.end());
	if (set.size() != _v.size())
		throw std::invalid_argument("duplicate values detected");
}



void printVec(const Vec& v)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v[i];
		if (i != v.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void swapPairs(Vec& v)
{
	for (size_t i = 0; i < v.size() - 1; i += 2)
	{
		if (v[i] > v[i + 1])
			std::swap(v[i], v[i + 1]);
	}
}

void sortPairs(Vec& v)
{
	for (size_t i = 0; i < v.size / 2; ++i)
	{
		
	}
}

void PmergeMe::sort()
{
	Vec v = _v;

	swapPairs(v);

	sortPairs(v);

	printVec(v);



}
