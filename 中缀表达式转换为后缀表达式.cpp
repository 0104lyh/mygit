#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<vector>
#include<string>
using namespace std;
bool isoper(char c)//判断是否是操作符
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}
int Priority(char a, char b)//判断优先级
{
	if (a == '+')
	{
		if (b == '+' || b == '-' || b == ')')
			return -1;
		else if (b == '*' || b == '/' || b == '(')
			return 1;
	}
	if (a == '-')
	{
		if (b == '+' || b == '-' || b == ')')
			return -1;
		else if (b == '*' || b == '/' || b == '(')
			return 1;
	}
	if (a == '*')
	{
		if (b == '+' || b == '-' || b == '*' || b == '/' || b == ')')
			return -1;
		else if (b == '(')
			return 1;
	}
	if (a == '/')
	{
		if (b == '+' || b == '-' || b == '*' || b == '/' || b == ')')
			return -1;
		else if (b == '(')
			return 1;
	}
	if (a == '(')
	{
		if (b == ')')
			return 0;
		else
			return 1;
	}
	if (a == ')')
	{
		return -1;
	}
	if (a == '#')
		return 1;
}
void Sign(char *s, int *t)//判断是否是加减号
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
	{//紧跟在数字与右括号后面则为加减号
		if (s[i] >= '0'&&s[i] <= '9'&&isoper(s[i + 1]))
			t[i + 1] = 1;
		if (s[i] == ')'&&isoper(s[i + 1]))
			t[i + 1] = 1;
	}
}
void Print(vector<char> &A, int *arr)
{
	int flag = 0;
	vector<char>::iterator it;
	it = A.begin();
	while (it<A.end())
	{
		if (*it == '@')
		{
			flag = 0;
			it++;
			cout << '-';
		}
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			flag = 1;
			cout << *it;
			it++;
		}
		while ((*it >= '0'&&*it <= '9') || *it == '.')
		{
			if (flag == 1)
				cout << " ";
			cout << *it;
			it++;
			flag = 0;
		}
		if (*it == '$')//遇到数字间的分隔符
		{
			flag = 0;
			it++;
		}
		if (it != A.end())
		{
			flag = 0;
			cout << " ";
		}
	}
}
int main()
{
	stack<char> A;
	A.push('#');
	vector<char> result;//存后缀表达式
	char str[100];//存原始表达式ps:数组长度不宜太小
	for (int i = 0; i<100; i++)
		str[i] = '\0';
	int tmp[30];//用于标记是否为加减号
	for (int i = 0; i<30; i++)
		tmp[i] = 0;
	gets(str);
	Sign(str, tmp);
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != '('&&str[i] != ')'&&tmp[i] != 1)//将数字直接存入result向量中，包括减号与小数点
		{
			if (str[i] != '+')
			{
				if (str[i] == '-')
					result.push_back('@');//代替减号，以区别减号与负号
				else
					result.push_back(str[i]);
			}
			if (tmp[i + 1] == 1)
				result.push_back('$');//作为数字间的分隔符
		}
		else
		{
			while (Priority(A.top(), str[i]) == -1)//当前符号比栈顶优先级小
			{
				result.push_back(A.top());
				A.pop();
			}
			if (Priority(A.top(), str[i]) == 1)//当前符号比栈顶优先级大
			{
				A.push(str[i]);
			}
			else if (Priority(A.top(), str[i]) == 0)//优先级一样，即左右括号相遇
			{
				A.pop();
			}
		}
	}
	while (A.top() != '#')
	{
		result.push_back(A.top());
		A.pop();
	}
	Print(result, tmp);
}
