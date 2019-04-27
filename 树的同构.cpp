#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
struct tree 
{
	char data;
	int left;
	int right;
}t1[15],t2[15];
int findroot[15];
int createtree(struct tree t[])
{
	for (int j = 0; j < 15; j++)
	{
		findroot[j] = 0;
	}
	int root = -1, i;
	char l, r;
	int n;
	//cin >> n;
	scanf("%d", &n);
	if (n)
	{
		for (i = 0; i < n; i++)
		{
			//cin >> t[i].data >> l >> r;
			scanf("\n%c %c %c", &t[i], &l, &r);
			if (l == '-')
			{
				t[i].left = -1;
			}
			else if (l >= '0'&&l <= '9')
			{
				t[i].left = l - '0';
				findroot[t[i].left] = 1;
			}
			if (r == '-')
			{
				t[i].right = -1;
			}
			else if (r >= '0'&&r <= '9')
			{
				t[i].right = r - '0';
				findroot[t[i].right] = 1;
			}
		}
		for (i = 0; i < n; i++)
		{
			if (!findroot[i])
			{
				root = i;
				break;
			}
		}
	}
	return root;

}
int judge(int r1, int r2)
{
	if ((r1 == -1) && (r2 == -1))
	{
		return 1;
	}
	if ((r1 == -1) && (r2 != -1) || (r1 != -1) && (r2 == -1))
	{
		return 0;
	}
	if (t1[r1].data != t2[r2].data)
	{
		return 0;
	}
	if ((t1[r1].left == -1) && t2[r2].left == -1)
	{
		return judge(t1[r1].right, t2[r2].right);
	}
	if (((t1[r1].left != -1) && (t2[r2].left != -1)) && ((t1[t1[r1].left].data) == (t2[t2[r2].left].data)))
	{
		return judge(t1[r1].left, t2[r2].left) && judge(t1[r1].right, t2[r2].right);
	}
	else
	{
		return judge(t1[r1].left, t2[r2].right) && judge(t1[r1].left, t2[r2].right);
	}
}
int main()
{
	int R1, R2;
	R1 = createtree(t1);
	R2 = createtree(t2);
	if (judge(R1, R2) == 1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;

}
