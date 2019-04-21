/*
本题要求给定二叉树的高度。

函数接口定义：
int GetHeight( BinTree BT );
其中BinTree结构定义如下：

typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
要求函数返回给定二叉树BT的高度值。

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
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}
*/
int GetHeight(BinTree BT)
{
	int lh=0,rh=0;
	if (BT == NULL)
	{
		return 0;
	}
	if (BT)
	{
		lh=GetHeight(BT->Left);
	
		rh=GetHeight(BT->Right);
		
	}
	return(lh > rh) ? (lh + 1) : (rh + 1);
}
