#include <stdio.h>
#include <stdlib.h>
typedef enum { false, true } bool;

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
	int flag;
};

/*------堆栈的定义-------*/
typedef Position SElementType;
typedef struct SNode *PtrToSNode;
struct SNode {
	SElementType Data;
	PtrToSNode Next;
};
typedef PtrToSNode Stack;

/* 裁判实现，细节不表 */
Stack CreateStack();
bool IsEmpty(Stack S);
bool Push(Stack S, SElementType X);
SElementType Pop(Stack S); /* 删除并仅返回S的栈顶元素 */
SElementType Peek(Stack S);/* 仅返回S的栈顶元素 */
						   /*----堆栈的定义结束-----*/

BinTree CreateBinTree(); /* 裁判实现，细节不表 */
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);

int main()
{
	BinTree BT = CreateBinTree();
	printf("Inorder:");    InorderTraversal(BT);    printf("\n");
	printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
	printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
	return 0;
}
void InorderTraversal(BinTree BT)
{
	Stack s = CreateStack();
	BinTree p = BT;
	while (p||!IsEmpty(s))
	{
		while (p)
		{
			Push(s, p);
			p = p->Left;
		}
		p = Pop(s);
		printf(" %c", p->Data);
		p = p->Right;
	}
}
void PreorderTraversal(BinTree BT)
{
	Stack s = CreateStack();
	BinTree p = BT;
	while (p || !IsEmpty(s))
	{
		while (p)
		{
			printf(" %c", p->Data);
			Push(s, p);
			p = p->Left;
		}
		p = Pop(s);
		
		p = p->Right;
	}
}
void PostorderTraversal(BinTree BT) {
	Stack s = CreateStack();
	if (BT != NULL)
		Push(s, BT);
	BinTree now = BT, last = NULL;
	while (!IsEmpty(s)) {
		while (Peek(s)->Left != NULL)
			Push(s, Peek(s)->Left);
		while (!IsEmpty(s)) {
			now = Peek(s);
			if (now->Right == last || now->Right == NULL) {
				printf(" %c", now->Data);
				Pop(s);
				last = now;
			}
			else {
				Push(s, now->Right);
				break;
			}
		}
	}
}
