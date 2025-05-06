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
