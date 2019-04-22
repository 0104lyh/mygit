#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};
int main()
{
	int n;
	cin >> n;
	int tree[1001];
	int father[1001];
	for (int i = 0; i < n; i++)
	{
		cin >> tree[i];
	}
	int x, y;
	cin >> x >> y;
	if (!tree[x-1])
	{
		printf("ERROR: T[%d] is NULL\n", x);
	}
	else if (!tree[y-1])
	{
		printf("ERROR: T[%d] is NULL\n", y);
	}
	else if (x == y)
	{
		printf("%d %d", x, tree[x - 1]);
	}
	else
	{
		int cnt1 = 1, cnt2 = 1;
		int u = x,v = y;
		while (1)
		{
			if (u == 1)
			{
				break;
			}
			u = u / 2;
			cnt1++;
		}
		while (1)
		{
			if (v == 1)
			{
				break;
			}
			v = v / 2;
			cnt2++;
		}
		if (cnt1 > cnt2)
		{
			while (cnt1 != cnt2)
			{
				x = x / 2;
				cnt1--;
			}
		}
		else if(cnt1<cnt2)
		{
			while (cnt1 != cnt2)
			{
				y = y / 2;
				cnt2--;
			}
		}
		while (x != y)
		{
			x /= 2;
			y /= 2;
		}
		printf("%d %d\n", x, tree[x-1]);
	}
	return 0;
}
