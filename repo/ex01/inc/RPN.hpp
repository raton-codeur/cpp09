#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>

class RPN
{
	private :
		char*				_arg;
		std::stack<int>		_stack;

				RPN();
				RPN(const RPN& other);
		RPN&	operator=(const RPN& other);

	public :
		RPN(int argc, char** argv);
		~RPN();

		void	checkArg() const;
		void	execute();
		void	printResult() const;
};

#endif