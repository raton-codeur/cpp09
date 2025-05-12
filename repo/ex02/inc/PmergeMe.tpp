#include "PmergeMe.hpp"

template <typename T>
void print(T& t, size_t n)
{
	size_t iR;

	iR = t.size() - t.size() % n;
	for (size_t iE = 0; iE < iR; iE += n)
	{
		if (n != 1)
			std::cout << "[";
		for (size_t i = iE; i < iE + n; ++i)
		{
			std::cout << t[i];
			if (i != iE + n - 1)
				std::cout << " ";
		}
		if (n != 1)
			std::cout << "]";
		if (iE + n != iR)
			std::cout << " ";
	}
	for (size_t i = iR; i < t.size(); ++i)
	{
		std::cout << t[i];
		if (i != t.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

template <typename T>
static void swapElements(T& v, size_t i, size_t j, size_t n)
{
	for (size_t k = 0; k < n; ++k)
		std::swap(v[i + k], v[j + k]);
}

template <typename T>
static void checkPairs(T& v, size_t n)
{
	size_t iR = v.size() - v.size() % (2 * n);
	for (size_t iE = 0; iE + n < iR; iE += 2 * n)
	{
		if (v[iE + n - 1] > v[iE + 2 * n - 1])
			swapElements(v, iE, iE + n, n);
	}
}

template <typename T>
static void initAB(const T& v, T& a, T& b, size_t iR, size_t n)
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

template <typename T>
static void insertE(T& a, const T& b, size_t iA, size_t iB, size_t n)
{
	iA *= n;
	iB *= n;
	for (int i = n - 1; i >= 0; --i)
		a.insert(a.begin() + iA, b[iB + i]);
}

template <typename T>
static void binarySearchInsert(T& a, const T& b, size_t i, size_t j, size_t iB, size_t n)
{
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

template <typename T>
static void insertAllB(T& a, T& b, size_t iR, size_t n)
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

template <typename T>
T sort(T& v, size_t n)
{
	checkPairs(v, n);

	if (v.size() / (2 * n) > 1)
		v = sort(v, n * 2);

	size_t iR = v.size() - v.size() % n;
	T a, b;
	if (iR / n <= 2)
	{
		for (size_t i = 0; i < v.size(); ++i)
			a.push_back(v[i]);
	}
	else
	{
		initAB(v, a, b, iR, n);
		insertAllB(a, b, iR, n);
		for (size_t i = iR; i < v.size(); ++i)
			a.push_back(v[i]);
	}

	return a;
}
