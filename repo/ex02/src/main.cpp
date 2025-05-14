#include "PmergeMe.hpp"

bool isSorted(const Vector& v)
{
	for (size_t i = 0; i < v.size() - 1; ++i)
	{
		if (v[i + 1] < v[i])
			return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	clock_t	start, end;
	double	time1, time2;

	try
	{
		PmergeMe p(argc, argv);

		start = clock();
		Vector v = p.sort1();
		end = clock();
		time1 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

		start = clock();
		Deque d = p.sort2();
		end = clock();
		time2 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

		std::cout << "before : ";
		p.printArg();
		std::cout << "after : ";
		print(v);
		std::cout << "time to process a range of " << v.size() << " elements with std::vector<int> : " << time1 << " us" << std::endl;
		std::cout << "time to process a range of " << d.size() << " elements with std::deque<int> : " << time2 << " us" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "error : " << e.what() << RESET << std::endl;
		return 1;
	}
}
