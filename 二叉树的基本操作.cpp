#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
typedef char ElemType;
typedef struct node
{
	ElemType data;		        //数据元素
	struct node *lchild;		//指向左孩子
	struct node *rchild;		//指向右孩子
} BTNode;
void CreateBTNode(BTNode *&b, char *str); //根据括号表示法的str，创建二叉树b。 
int BTNodeDepth(BTNode *b);  //求二叉树b的深度。 
void PreOrder(BTNode *b);   //先序遍历二叉树b 
void InOrder(BTNode *b); //中序遍历二叉树b 
void PostOrder(BTNode *b);  //后序遍历二叉树b  
void TravLevel(BTNode *b);  //层次遍历二叉树b  
void DestroyBTNode(BTNode *&b);  //销毁二叉树b。 (由裁判程序实现，略去)
int main()
{
	BTNode *b, *p, *lp, *rp;
	char str[100];
	scanf("%s", str);
	CreateBTNode(b, str);  //括号表示法创建二叉树 
	printf("Depth:%d\n", BTNodeDepth(b));
	printf("PreOrder:  ");
	PreOrder(b);  		//先序遍历
	printf("\n");
	printf("InOrder:  ");
	InOrder(b);   		//中序遍历
	printf("\n");
	printf("PostOrder:  ");
	PostOrder(b); 		//后序遍历
	printf("\n");
	printf("TravLevel:  ");
	TravLevel(b);   //层次遍历 
	DestroyBTNode(b);  //释放二叉树b 
	return 0;
}
void CreateBTNode(BTNode *&b, char *str)
{
	BTNode *s[101], *p;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;
	ch = str[j];
	while (ch!='\0')
	{
		switch (ch)
		{
		case '(':top++; s[top] = p; k = 1; break;
		case ')':top--; break;
		case ',':k = 2; break;
		default:
			p = (BTNode *)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)
			{
				b = p;
			}
			else
			{
				switch (k)
				{
				case 1:s[top]->lchild = p; break;
				case 2:s[top]->rchild = p; break;

				}
			}
		}
		j++;
		ch = str[j];
	}
} 
int BTNodeDepth(BTNode *b)
{
	int lh , rh;
	if (!b)
	{
		return 0;
	}
	else
	{
		lh=BTNodeDepth(b->lchild);
		rh=BTNodeDepth(b->rchild);
	}
	return lh > rh ? (lh + 1) : (rh + 1);
}
void PreOrder(BTNode *b)
{
	if (b)
	{
		printf("%c ", b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}
void InOrder(BTNode *b)
{
	if (b)
	{
		InOrder(b->lchild);
		printf("%c ", b->data);
		InOrder(b->rchild);
	}
}
void PostOrder(BTNode *b)
{
	if (b)
	{
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%c ", b->data);
	}
}
void TravLevel(BTNode *b)
{
	BTNode *que[101], *t;
	int front = 0, rear = 0;
	if (b)
	{
		que[rear++] = b;
		while (front != rear)
		{
			t = que[front++];
			printf(" %c", t->data);
			if (t->lchild) que[rear++] = t->lchild;
			if (t->rchild) que[rear++] = t->rchild;
		}
	}
}
