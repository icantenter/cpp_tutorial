#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
//目前只支持二元，且括号不能省去。如果表达式中有空格或其他无意义字符需要修改，改为只检测运算符。


int main()
{
	std::stack<char> ops;	
	std::stack<double> vals;
	double a, b;
	std::string statement;

	std::cin >> statement;
	for (std::string::iterator i = statement.begin(); i < statement.end(); i++)
	{
		if (*i == ')')
		{
			a = vals.top();
			vals.pop();
			b = vals.top();
			vals.pop();

			switch (ops.top())
			{
			case '*':
				vals.push(a * b);
				break;
			case '+':
				vals.push(a + b);
				break;
			case '-':
				vals.push(a - b);
				break;
			case '/':
				vals.push(a / b);
				break;
			}
			ops.pop();
		}
		else if (isdigit(*i))
		{
			vals.push(*i - '0');
		}
		else if (*i != '(')
		{
			ops.push(*i);
		}
	}
	std::cout << std::fixed << std::setprecision(2) << vals.top();
	return 0;
}
