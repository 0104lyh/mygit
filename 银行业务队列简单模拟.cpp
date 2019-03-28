#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int i, n;
	queue<int> A, B;
	int num;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> num;
		if (num % 2 != 0)
			A.push(num);
		else
			B.push(num);
	}
	int flag = 0;
	while (!A.empty() && !B.empty())
	{
		if (!A.empty())
		{
			if (flag)
				cout << " ";
			cout << A.front();
			A.pop();
			flag = 1;
		}
		if (!A.empty())
		{
			if (flag)
				cout << " ";
			cout << A.front();
			A.pop();
			flag = 1;
		}
		if (!B.empty())
		{
			if (flag)
				cout << " ";
			cout << B.front();
			B.pop();
			flag = 1;
		}
	}
	while (!A.empty())
	{
		if (flag)
			cout << " ";
		cout << A.front();
		A.pop();
		flag = 1;
	}
	while (!B.empty())
	{
		if (flag)
			cout << " ";
		cout << B.front();
		B.pop();
		flag = 1;
	}
	return 0;
}
//这里我理解错了，并不需要排序输入的数据，题目并没有要求，虽然我觉得可能拿号码的人要按照顺序排队。。。如果排序的话，最大的数据会出错（并不知道为啥）
