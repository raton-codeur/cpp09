#include "PmergeMe.hpp"

template <typename T>
void print(T& t, size_t n = 1)
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


int main(int argc, char** argv)
{
	clock_t	start, end;
	double	time;

	try
	{
		PmergeMe p(argc, argv);
		std::cout << "before : ";
		print(p.v);
		start = clock();
		Vector v = p.sort(p.v, 1);
		end = clock();
		time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
		std::cout << "after : ";
		print(v);
		// std::is_sorted(v.begin(), v.end()) ? std::cout << "ok\n" : std::cout << "ko\n";
		std::cout << "time to process a range of " << v.size() << " elements with std::vector : " << time << " us" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "error : " << e.what() << RESET << std::endl;
		return 1;
	}
}
