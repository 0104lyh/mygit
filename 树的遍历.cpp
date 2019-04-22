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
BinTree createtree(int n, int *mid, int *behind);
void LevelorderTraversal(BinTree BT)
{
	BinTree tree[101],t;
	int front = 0, rear = 0;
	int flag = 0;
	if (BT)
	{
		tree[rear++] = BT;
		while (front != rear)
		{
			t = tree[front++];
			if (flag == 0)
			{
				flag = 1;
				printf("%d", t->Data);
			}
			else
			{
				printf(" %d", t->Data);
			}
			if (t->Left)tree[rear++] = t->Left;
			if (t->Right)tree[rear++] = t->Right;

		}
	}
}
int main()
{
	int behind[31];
	int mid[31];
	int n;
	cin >> n;
	int num;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		behind[i] = num;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		mid[i] = num;
	}
	BinTree tree = NULL;
	tree = createtree(n, mid, behind);
	//printf("Preorder:");
	//PreorderTraversal(tree);
	LevelorderTraversal(tree);
	printf("\n");
}
BinTree createtree(int n, int *mid, int *behind)
{
	BinTree tmp;
	if (n <= 0)
	{
		return NULL;
	}
	tmp = (TNode *)malloc(sizeof(TNode));
	tmp->Data = behind[n - 1];
	tmp->Right = NULL;
	tmp->Left = NULL;
	int i;
	for (i = 0; i < n; i++)
	{
		if (mid[i] == behind[n - 1])
		{
			break;
		}
	}
	tmp->Left = createtree(i, mid, behind);
	tmp->Right = createtree(n - 1 - i, mid + i + 1, behind + i);
	return tmp;
}
