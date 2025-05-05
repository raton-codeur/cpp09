#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
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

void printVec(Vec v)
{
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

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











/*
i donne l'indice d'un tete d'élément
j donne l'indice du début d'un élément
*/
void PmergeMe::swapPairs(size_t n)
{
	size_t k;

	for (size_t i = n - 1, j = 0; i < _v.size(); i += 2 * n, j += 2 * n)
	{
		if (_v[i] > _v[i + n])
		{
			for (k = 0; k < n; ++k)
			{
				std::swap(_v[j + k], _v[j + n + k]);
			}
		}
	}
}

/* k donne l'indice d'un élément */
void printElements(Vec& v, size_t n)
{
	for (size_t i = n - 1, j = 0, k = 0; i < v.size(); i += n, j += n, k++)
	{
		std::cout << "élément d'indice : " << k << " : " << v[i] << std::endl;
	}
	std::cout << "\n";
}

Vec getCheet(Vec& v, size_t n)
{
	Vec res;
	Vec T;
	for (size_t i = n - 1, j = 0; i < v.size(); i += n, j += n)
	{
		T.push_back(v[i]);
	}
	std::sort(T.begin(), T.end());
	for (Vec::iterator it = T.begin(); it != T.end(); ++it)
	{
		for (size_t i = n - 1, j = 0; i < v.size(); i += n, j += n)
		{
			if (v[i] == *it)
			{
				for (size_t k = 0; k < n; ++k)
				{
					res.push_back(v[j + k]);
				}
			}
		}
	}
	return res;
}

// n : la taille d'un élément indivisible
void PmergeMe::sort(size_t n)
{
	n = 1;
	std::cout << "n : " << n << std::endl;

	std::cout << "v :\t\t";
	printVec(_v);
	printElements(_v, n);

	swapPairs(n);
	std::cout << "after swap :\t";
	printVec(_v);

	_v = getCheet(_v, 2 * n);
	std::cout << "cheet :\t\t";
	printVec(_v);
	
	Vec jacobsthal;
	jacobsthal.push_back(1);
	jacobsthal.push_back(3);
	jacobsthal.push_back(5);
	jacobsthal.push_back(11);
	jacobsthal.push_back(21);
	jacobsthal.push_back(43);

	

	

}
