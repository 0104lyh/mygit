//这里给出全部代码
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100

typedef char ElemType;
typedef struct node
{
	ElemType data;			//数据元素
	struct node *lchild;		//指向左孩子
	struct node *rchild;		//指向右孩子
} BTNode;

void CreateBTNode(BTNode *&b);  // 键盘输入括号表示法表示二叉树的字符串，并由此创建二叉树b,  裁判程序实现，细节不表。
int Nodes(BTNode *b);	//求二叉树b的节点个数
int main()
{
	BTNode *b;
	CreateBTNode(b);
	printf("%d", Nodes(b));
	return 0;
}
void CreateBTNode(BTNode *&b)
{
	BTNode *St[MaxSize], *p;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;
	//ch = str[j];
	scanf("%c", &ch);
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; k = 1; break;
		case ')':top--; break;
		case ',':k = 2; break;
		default:p = (BTNode *)malloc(sizeof(BTNode));
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
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
		j++;
		scanf("%c", &ch);
		if (ch == '\n')
		{
			break;
		}
	}
}
int Nodes(BTNode *b)
{
	int n;
	if (!b)
	{
		return 0;
	}
	else
	{
		return n = Nodes(b->lchild) + Nodes(b->rchild) + 1;
	}
}
