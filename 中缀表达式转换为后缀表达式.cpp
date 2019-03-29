#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<vector>
#include<string>
using namespace std;
bool isoper(char c)//�ж��Ƿ��ǲ�����
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}
int Priority(char a, char b)//�ж����ȼ�
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
void Sign(char *s, int *t)//�ж��Ƿ��ǼӼ���
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
	{//�����������������ź�����Ϊ�Ӽ���
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
		if (*it == '$')//�������ּ�ķָ���
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
	vector<char> result;//���׺���ʽ
	char str[100];//��ԭʼ���ʽps:���鳤�Ȳ���̫С
	for (int i = 0; i<100; i++)
		str[i] = '\0';
	int tmp[30];//���ڱ���Ƿ�Ϊ�Ӽ���
	for (int i = 0; i<30; i++)
		tmp[i] = 0;
	gets(str);
	Sign(str, tmp);
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != '('&&str[i] != ')'&&tmp[i] != 1)//������ֱ�Ӵ���result�����У�����������С����
		{
			if (str[i] != '+')
			{
				if (str[i] == '-')
					result.push_back('@');//������ţ�����������븺��
				else
					result.push_back(str[i]);
			}
			if (tmp[i + 1] == 1)
				result.push_back('$');//��Ϊ���ּ�ķָ���
		}
		else
		{
			while (Priority(A.top(), str[i]) == -1)//��ǰ���ű�ջ�����ȼ�С
			{
				result.push_back(A.top());
				A.pop();
			}
			if (Priority(A.top(), str[i]) == 1)//��ǰ���ű�ջ�����ȼ���
			{
				A.push(str[i]);
			}
			else if (Priority(A.top(), str[i]) == 0)//���ȼ�һ������������������
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
