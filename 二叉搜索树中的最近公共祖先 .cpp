#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef struct TreeNode *Tree;
struct TreeNode {
	int   Key;
	Tree  Left;
	Tree  Right;
};

Tree BuildTree(); /* 细节在此不表 */
int LCA(Tree T, int u, int v);

int main()
{
	Tree T;
	int u, v, ans;

	T = BuildTree();
	scanf("%d %d", &u, &v);
	ans = LCA(T, u, v);
	if (ans == ERROR) printf("Wrong input\n");
	else printf("LCA = %d\n", ans);

	return 0;
}
int LCA(Tree T, int u, int v)
{
	if (!T)
	{
		return ERROR;
	}
	Tree p, q;
	p = T;
	q = T;
	while (1)
	{
		if (q==NULL)
		{
			return ERROR;
		}
		else if (q->Key == u)
		{
			break;
		}
		else if (q->Key > u)
		{
			q = q->Left;
		}
		else if (q->Key < u)
		{
			q = q->Right;
		}
	}
	while (1)
	{
		if (p == NULL)
		{
			return ERROR;
		}
		else if (p->Key == v)
		{
			break;
		}
		else if (p->Key > v)
		{
			p = p->Left;
		}
		else if (p->Key < v)
		{
			p = p->Right;
		}
	}
	if (T->Key == u || T->Key == v)
	{
		return T->Key;
	}
	if (T->Key > u&&T->Key<v || T->Key>v&&T->Key < u)
	{
		return T->Key;
	}
	if (u > T->Key)
	{
		return LCA(T->Right, u, v);
	}
	if (u < T->Key)
	{
		return LCA(T->Left, u, v);
	}
}
