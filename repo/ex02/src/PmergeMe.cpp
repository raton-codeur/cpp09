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


void print(Vec& v, size_t n)
{
	size_t iR;

	iR = v.size() - v.size() % n;
	for (size_t iE = 0; iE < iR; iE += n)
	{
		std::cout << "[";
		for (size_t i = iE; i < iE + n; ++i)
		{
			std::cout << v[i];
			if (i != iE + n - 1)
				std::cout << " ";
		}
		std::cout << "]";
	}
	for (size_t i = iR; i < v.size(); ++i)
	{
		std::cout << v[i];
		if (i != v.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void swapElements(Vec& v, size_t i, size_t j, size_t n)
{
	for (size_t k = 0; k < n; ++k)
		std::swap(v[i + k], v[j + k]);
}

void checkPairs(Vec& v, size_t n)
{
	size_t iR = v.size() - v.size() % (2 * n);
	for (size_t iE = 0; iE + n < iR; iE += 2 * n)
	{
		if (v[iE + n - 1] > v[iE + 2 * n - 1])
			swapElements(v, iE, iE + n, n);
	}
}



void PmergeMe::main()
{
	Vec v = _v;
	size_t n = 1;

	checkPairs(v, n);
	print(v, n);

	/* appel rec */

	Vec a;
	Vec b;

	size_t iR = v.size() - v.size() % n;
	for (size_t iE = 0; iE < iR; iE += n)
	

	

}
