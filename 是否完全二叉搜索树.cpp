#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<string>
#include<queue>
using namespace std;
int tree[21];
//typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	int Data;
	BinTree Left;
	BinTree Right;
};
void midorder(BinTree T);
Position insert(Position T, int a)
{
	if (!T)
	{
		T = (Position)malloc(sizeof(struct TNode));
		T->Data = a;
		T->Left = T->Right = NULL;
	}
	else
	{
		if (T->Data > a)
		{
			T->Right = insert(T->Right, a);
		}
		else if (T->Data < a)
		{
			T->Left = insert(T->Left, a);
		}
	}
	return T;
}
BinTree build(int *tree,int n)
{
	Position T=NULL;
	int i = 0;
	while (i<n)
	{
		T = insert(T, tree[i]);
		i++;
	}
	return T;
}
int IsBST(BinTree T)
{
	if ((!T) || (!T->Left) && (!T->Right)) return 1;
	else
	{
		if (!T->Left)
		{
			if (T->Right)
			{
				BinTree p = T->Right;
				while (p->Left)
				{
					p = p->Left;
				}
				if (T->Data >= p->Data)
				{
					return 0;
				}
				else
				{
					return IsBST(T->Right);
				}
			}
		}
		else
		{
			BinTree q = T->Left;
			while (q->Right)
			{
				q = q->Right;
			}
			if (T->Data <= q->Data)
			{
				return 0;
			}
			else
			{
				if (!T->Right)
				{
					IsBST(T->Left);
				}
				else
				{
					BinTree p = T->Right;
					while (p->Left) {
						p = p->Left;
					}
					if (T->Data >= p->Data)
						return 0;
					else
						return (IsBST(T->Left) && IsBST(T->Right));
				}
			}
		}
	}
}
int judge(BinTree T,int n)
{
	BinTree que[21],t;
	int front = 0, rear = 0;
	//que[rear++] = T;
	if (T == NULL)
	{
		return 1;
	}
	else
	{
		int cnt = 0;
		que[rear++] = T;
		while ((t = que[front++]) != NULL)
		{
			
			que[rear++] = t->Left;
			que[rear++] = t->Right;
			cnt++;
		}
		if (cnt == n)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
int Judge(BinTree &T, int n)//判断是否为完全二叉树
{
	queue<BinTree> Q;
	if (T == NULL)
		return 1;
	else
	{
		int Count = 0;//计算访问了几个结点
		Q.push(T);
		BinTree t;
		while ((t = Q.front()) != NULL)//当出现“空洞”时退出循环
		{
			Q.push(t->Left);
			Q.push(t->Right);
			Q.pop();
			Count++;
		}
		if (Count == n)
			return 1;
		else
			return 0;
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tree[i];
	}
	BinTree T;
	T=build(tree, n);
	midorder(T);
	printf("\n");
	if (Judge(T,n) == 0)
	{
		printf("NO\n");
	}
	else if(Judge(T,n)==1)
	{
		printf("YES\n");
	}
	
	return 0;
}
void midorder(BinTree T)
{
	BinTree t;
	BinTree que[21];
	int front=0, rear = 0;
	int flag = 0;
	if (T)
	{
		que[rear++] = T;
		while (front != rear)
		{
			t = que[front++];
			if (flag == 0)
			{
				printf("%d", t->Data);
				flag = 1;
			}
			else
			{
				printf(" %d", t->Data);
			}
			if (t->Left)que[rear++] = t->Left;
			if (t->Right)que[rear++] = t->Right;
		}
	}
}
