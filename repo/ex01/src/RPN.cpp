#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN& RPN::operator=(const RPN& other)
{
	(void)other;
	return *this;
}

RPN::RPN(int argc, char** argv)
{
	if (argc != 2)
		throw std::invalid_argument("wrong number of arguments");

	_arg = argv[1];
}

RPN::~RPN()
{}

void RPN::checkArg() const
{
	const std::string	valid = "0123456789+-*/";
	size_t				i;

	// characters
	for (i = 0; _arg[i]; ++i)
	{
		if (std::isspace(_arg[i]))
			continue;
		if (valid.find(_arg[i]) == std::string::npos)
			throw std::invalid_argument("invalid character");
	}

	// spaces
	for (i = 0; _arg[i] && _arg[i + 1]; ++i)
	{
		if (valid.find(_arg[i]) != std::string::npos && !std::isspace(_arg[i + 1]))
			throw std::invalid_argument("consecutive digits or operators");
	}
}

static int applyOperation(int a, int b, char op)
{
	switch (op)
	{
		case '+' :
			return a + b;
		case '-' :
			return a - b;
		case '*' :
			return a * b;
		case '/' :
			if (b == 0)
				throw std::invalid_argument("division by zero");
			return a / b;
		default :
			throw std::logic_error("unexpected");
	}
}

void RPN::execute()
{
	int		a, b;

	for (size_t i = 0; _arg[i]; ++i)
	{
		if (std::isspace(_arg[i]))
			continue;
		if (std::isdigit(_arg[i]))
			_stack.push(_arg[i] - '0');
		else
		{
			if (_stack.size() < 2)
				throw std::invalid_argument("invalid syntax");
			b = _stack.top();
			_stack.pop();
			a = _stack.top();
			_stack.pop();
			_stack.push(applyOperation(a, b, _arg[i]));
		}
	}
	if (_stack.size() != 1)
		throw std::invalid_argument("invalid syntax");
}

void RPN::printResult() const
{
	std::cout << _stack.top() << std::endl;
}
