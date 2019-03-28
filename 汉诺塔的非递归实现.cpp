#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stack>
char s[4] = { 'q','a','b','c' };
using namespace std;
stack<int>a[4];
bool move(int before, int after)
{
	if (a[before].empty())
	{
		return false;
	}
	if (!a[after].empty())
	{
		if (a[after].top() - a[before].top() < 0)
		{
			return false;
		}
	}
	a[after].push(a[before].top());
	a[before].pop();
	printf("%c -> %c\n", s[before], s[after]);
}
int main()
{
	int n;
	cin >> n;
	int i;
	for (i = 0; i < n; i++)
	{
		a[1].push(n - i);
	}
	if (n % 2 == 1)
	{
		s[2] = 'c';
		s[3] = 'b';
	}
	int count = 0;
	while (++count)
	{
		move((count - 1) % 3 + 1, count % 3 + 1);
		if (!move((count - 1) % 3 + 1, (count + 1) % 3 + 1) && !move((count + 1) % 3 + 1, (count - 1) % 3 + 1))
		{
			break;
		}
	}
	return 0;
}