#include "RPN.hpp"



int is_operator(char c)
{
	return (std::string("+-/*").find(c) != std::string::npos);
}

int rpn_calculator(const std::string& s)
{
	std::stack<int> rpn;
	int tmp_a;
	int tmp_b;
	int tmp;
	for (std::string::const_iterator it = s.begin(); it != s.end(); it++)
	{
		if (isdigit(*it))
			rpn.push(*it - '0');
		else if (is_operator(*it))
		{
			if (rpn.size() < 2)
				throw std::runtime_error("Error");
			tmp_b = rpn.top();
			rpn.pop();
			tmp_a = rpn.top();
			rpn.pop();
			switch (*it)
			{
				case '+':
					tmp = tmp_a + tmp_b;
					rpn.push(tmp);
					break;
				case '-':
					tmp = tmp_a - tmp_b;
					rpn.push(tmp);
					break;
				case '/':
					if (tmp_b == 0)
						throw std::runtime_error("division per 0");
					tmp = tmp_a / tmp_b;
					rpn.push(tmp);
					break;
				case '*':
					tmp = tmp_a * tmp_b;
					rpn.push(tmp);
					break;
			}
		}

	}
	if (rpn.size() != 1)
		throw std::runtime_error("expression impossible to calculate");
	return (rpn.top());
}


int main(int ac, char **av)
{
	try
	{
		int tmp;
		if (ac == 1)
			throw std::runtime_error("not enough arguments");
		tmp = rpn_calculator(av[1]);
		std::cout << "RPN Expression : " << av[1] << " = " << tmp << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


}
