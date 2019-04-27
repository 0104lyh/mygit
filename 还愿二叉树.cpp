#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int count(char pre[], char mid[],int n);
char pre[51];
char mid[51];
int main()
{

	int n;
	cin >> n;
	//scanf("%s", pre);
	//scanf("%s", mid);
	cin >> pre >> mid;
	int m = count(pre, mid, n);
	printf("%d", m);
	return 0;
}
int count(char pre[], char mid[],int n)
{
	
	if (n == 0)
	{
		return 0;
	}
	int i;
	for (i = 0; i < n; i++)
	{
		if (mid[i] == pre[0])
		{
			break;
		}
	}
	int left = count(pre + 1, mid, i) + 1;
	int right = count(pre + i + 1, mid + i + 1, n - i - 1) + 1;
	return left > right ? left : right;
}
/*根据前序遍历的特点, 知前序序列(PreSequence)的首个元素(PreSequence[0])为二叉树的根(root),  然后
在中序序列(InSequence)中查找此根(root),  根据中序遍历特点, 知在查找到的根(root) 前边的序列为根的左子树
的中序遍历序列,  后边的序列为根的右子树的中序遍历序列。 设在中序遍历序列(InSequence)根前边有left个元素. 则
在前序序列(PreSequence)中, 紧跟着根(root)的left个元素序列(即PreSequence[1...left]) 为根的左子树的前序遍
历序列, 在后边的为根的右子树的前序遍历序列.而构造左子树问题其实跟构造整个二叉树问题一样，只是此时前序序列为PreSequence[1...left]), 
中序序列为InSequence[0...left-1], 分别为原序列的子串, 构造右子树同样, 显然可以用递归方法解决。*/


