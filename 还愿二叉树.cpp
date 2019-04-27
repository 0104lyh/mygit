#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int count(char pre[], char mid[],int n);
char pre[51];
char mid[51];
int main()
{

	int n;
	cin >> n;
	//scanf("%s", pre);
	//scanf("%s", mid);
	cin >> pre >> mid;
	int m = count(pre, mid, n);
	printf("%d", m);
	return 0;
}
int count(char pre[], char mid[],int n)
{
	
	if (n == 0)
	{
		return 0;
	}
	int i;
	for (i = 0; i < n; i++)
	{
		if (mid[i] == pre[0])
		{
			break;
		}
	}
	int left = count(pre + 1, mid, i) + 1;
	int right = count(pre + i + 1, mid + i + 1, n - i - 1) + 1;
	return left > right ? left : right;
}
