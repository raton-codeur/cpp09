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
		std::cout << v[i] << "\t";
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

	for (size_t i = n - 1, j = 0; i < _v.size() - n; i += 2 * n, j += 2 * n)
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

void printElement(Vec& v, size_t i, size_t n)
{
	std::cout << "[";
	for (size_t k = 0; k < n; ++k)
	{
		if (k != 0)
			std::cout << ", ";
		std::cout << v[i + k];
	}
	std::cout << "]";
}

/* k donne l'indice d'un élément */
void printElements(Vec& v, size_t n)
{
	std::cout << "[";
	for (size_t i = 0; i < v.size(); i += n)
	{
		if (i != 0)
			std::cout << ", ";
		printElement(v, i, n);
	}
	std::cout << "]";
	std::cout << "\n";
}

Vec getCheet(Vec& v, size_t n)
{
	Vec res;
	Vec T;
	size_t i, j;
	for (i = n - 1, j = 0; i < v.size(); i += n, j += n)
	{
		T.push_back(v[i]);
	}
	size_t after = j;
	
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
	while (after < v.size())
	{
		res.push_back(v[after++]);
	}
	return res;
}

// n : la taille d'un élément indivisible
void PmergeMe::sort(size_t n)
{
	(void)n;

	Vec a(1, 0);
	Vec b(1, 0);

	for (size_t i = 0; i < _v.size(); ++i)
	{
		if (i % 2)
			a.push_back(_v[i]);
		else
			b.push_back(_v[i]);
	}
	for (size_t i = 0; i < b.size(); ++i)
	{
		if (b[i] > a[i])
		{
			std::swap(a[i], b[i]);
		}
	}

	printVec(a);
	printVec(b);

	

	// swapPairs(n);
	// std::cout << "swap sur (n = " << n << ") :\t";
	// printVec(_v);

	// Vec current = getCheet(_v, 2 * n);
	// printElements(current, 2 * n);
	// std::cout << "current :\t\t";
	// printVec(current);

	// if (current.size() / n <= 2)
	// 	std::cout << "cas d'une liste petite déjà triée après les swap" << std::endl;

	// Vec next;
	// next.push_back(current[0]);
	// next.push_back(current[1]);
	// int j_p = 1;
	// int j_n = 3;

	// for (size_t i = n - 1, j = 0; i < v.size(); i += n, j += n)
	// {

	// }
	

}
