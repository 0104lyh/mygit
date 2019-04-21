/*函数接口定义：
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );
其中BinTree结构定义如下：

typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
要求4个函数分别按照访问顺序打印出结点的内容，格式为一个空格跟着一个字符。

裁判测试程序样例：
#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}*/
/* 你的代码将被嵌在这里 */
void InorderTraversal(BinTree BT)
{
	if (BT)
	{
		if (BT->Left)
		{
			InorderTraversal(BT->Left);
		}
		printf(" %c", BT->Data);
		if (BT->Right)
		{
			InorderTraversal(BT->Right);
		}
	}
}
void PreorderTraversal(BinTree BT)
{
	if (BT)
	{
		printf(" %c", BT->Data);
		if (BT->Left)
		{
			PreorderTraversal(BT->Left);
		}
		
		if (BT->Right)
		{
			PreorderTraversal(BT->Right);
		}
	}
}
void PostorderTraversal(BinTree BT)
{
	if (BT)
	{
		
		if (BT->Left)
		{
			PostorderTraversal(BT->Left);
		}

		if (BT->Right)
		{
			PostorderTraversal(BT->Right);
		}
		printf(" %c", BT->Data);
	}
}
void LevelorderTraversal(BinTree BT)
{
	BinTree que[101], t;
	int front = 0, rear = 0;
	if (BT)
	{
		que[rear++] = BT;
		while (front != rear)
		{
			t = que[front++];
			printf(" %c", t->Data);
			if (t->Left)que[rear++] = t->Left;
			if (t->Right)que[rear++] = t->Right;
		}
	}
}
