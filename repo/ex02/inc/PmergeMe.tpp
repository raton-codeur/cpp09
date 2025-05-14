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
static void swapElements(T& t, size_t i, size_t j, size_t n)
{
	for (size_t k = 0; k < n; ++k)
		std::swap(t[i + k], t[j + k]);
}

template <typename T>
static void checkPairs(T& t, size_t n)
{
	size_t iR = t.size() - t.size() % (2 * n);
	for (size_t iE = 0; iE + n < iR; iE += 2 * n)
	{
		if (t[iE + n - 1] > t[iE + 2 * n - 1])
			swapElements(t, iE, iE + n, n);
	}
}

template <typename T>
static void initAB(const T& t, T& a, T& b, size_t iR, size_t n)
{
	for (size_t i = 0; i < n; ++i)
		a.push_back(t[i]);
	
	for (size_t iE = 0, k = 0; iE < iR; iE += n, ++k)
	{
		if (k % 2)
		{
			for (size_t j = 0; j < n; ++j)
				a.push_back(t[iE + j]);
		}
		else
		{
			for (size_t j = 0; j < n; ++j)
				b.push_back(t[iE + j]);
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
T sort(T& t, size_t n)
{
	checkPairs(t, n);

	if (t.size() / (2 * n) > 1)
		t = sort(t, n * 2);

	size_t iR = t.size() - t.size() % n;

	if (t.size() / n <= 2)
		return t;

	T a, b;
	initAB(t, a, b, iR, n);
	insertAllB(a, b, iR, n);
	for (size_t i = iR; i < t.size(); ++i)
		a.push_back(t[i]);
	return a;
}
