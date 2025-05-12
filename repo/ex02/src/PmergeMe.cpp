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
		// std::cout << std::endl;
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

void initAB(const Vec& v, Vec& a, Vec& b, size_t iR, size_t n)
{
	for (size_t i = 0; i < n; ++i)
		a.push_back(v[i]);
	
	for (size_t iE = 0, k = 0; iE < iR; iE += n, ++k)
	{
		if (k % 2)
		{
			for (size_t j = 0; j < n; ++j)
				a.push_back(v[iE + j]);
		}
		else
		{
			for (size_t j = 0; j < n; ++j)
				b.push_back(v[iE + j]);
		}
	}
}

void insertE(Vec& a, const Vec& b, size_t iA, size_t iB, size_t n)
{
	iA *= n;
	iB *= n;
	for (int i = n - 1; i >= 0; --i)
		a.insert(a.begin() + iA, b[iB + i]);
}

void binarySearchInsert(Vec& a, const Vec& b, size_t i, size_t j, size_t iB, size_t n)
{
	// std::cout << "binary search avec size(a) = " << a.size() << ", i = " << i << ", j = " << j << std::endl;
	if (i == j)
		insertE(a, b, i, iB, n);
	else
	{
		size_t c = i + (j - i) / 2;
		if (b[(iB + 1) * n - 1] < a[(c + 1) * n - 1])
			binarySearchInsert(a, b, i, c, iB, n);
		else
			binarySearchInsert(a, b, c + 1, j, iB, n);
	}
}

void insertAllB(Vec& a, Vec& b, size_t iR, size_t n)
{
	size_t jp, l, j, z, iBp, iB, end, tmp, ll;
	
	l = 2;
	jp = 1;
	j = 3;
	z = 2;
	iBp = 0;
	end = 0;
	iR = b.size() / n;

	while (end == 0)
	{
		iB = j - 1;
		ll = l + z - 1;
		if (iB >= iR)
		{
			iB = iR - 1;
			ll = a.size() / n;
			end = 1;
		}
		while (iB != iBp)
		{
			binarySearchInsert(a, b, 0, ll, iB, n);
			print(a, n);
			iB--;
		}
		iBp = j - 1;
		tmp = l;
		l += 2 * z;
		z = tmp;
		tmp = j;
		j += 2 * jp;
		jp = tmp;
	}
}

Vec sort(Vec& v, size_t n)
{
	std::cout << "on trie ";
	print(v, n);
	checkPairs(v, n);

	if (v.size() / 2 / n > 1)
		v = sort(v, n * 2);
	std::cout << "paires qui doivent être triées : ";
	print(v, n * 2);

	size_t iR = v.size() - v.size() % n;
	size_t nbE = iR / n;
	Vec a, b;
	if (nbE <= 2)
	{
		for (size_t i = 0; i < v.size(); ++i)
			a.push_back(v[i]);
	}
	else
	{
		initAB(v, a, b, iR, n);
		std::cout << "a : ";
		print(a, n);
		std::cout << "b : ";
		print(b, n);

		insertAllB(a, b, iR, n);

		for (size_t i = iR; i < v.size(); ++i)
			a.push_back(v[i]);
	}
	std::cout << "on renvoie : ";
	print(a, n);
	return a;
}

void PmergeMe::main()
{
	// size_t n = 2;
	Vec v = sort(_v, 1);
	std::cout << "result : ";
	print(v, 1);

	std::is_sorted(v.begin(), v.end()) ? std::cout << "OK\n" : std::cout << "KO\n";
}
