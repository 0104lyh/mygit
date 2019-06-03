#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
typedef struct GNode *PtrToGNode;
#define MaxVertexNum 100  /* 最大顶点数设为10 */
#define INFINITY 65535   /* ∞设为双字节无符号整数的最大值65535*/
int D, N;//D:007的最远跳跃距离，N:鳄鱼的个数
int answer = 0;
struct GNode {
	int x;
	int y;
}dot[110];
int visited[110];
int firststep(int n)
{
	int d1 = dot[n].x*dot[n].x;
	int d2 = dot[n].y*dot[n].y;
	int r = (D + 7.5)*(D + 7.5);
	if (r>=(d1+d2))
	{
		return 1;
	}
	return 0;
}
int jumpside(int n)
{
	if (dot[n].x - D <= -50 || dot[n].x + D >= 50 || dot[n].y - D <= -50 || dot[n].y + D >= 50)
	{
		return 1;
	}
	return 0;
}
int jump(int n,int m)
{
	int d1 = (dot[n].x - dot[m].x)*(dot[n].x - dot[m].x);
	int d2 = (dot[n].y - dot[m].y)*(dot[n].y - dot[n].y);
	int r = D * D;
	if (r >= (d1 + d2))
	{
		return 1;
	}
	return 0;
}
int dfs(int n)
{
	visited[n] = 1;
	if (jumpside(n) == 1)
	{
		answer = 1;
	}
	for (int i = 0; i < N; i++)
	{
		if (!visited[i] && jump(n, i))
		{
			answer = dfs(i);
		}
	}
	return answer;
}
int main()
{
	cin >> N >> D;
	for (int i=0; i < N; i++)
	{
		cin >> dot[i].x >> dot[i].y;
	}
	if (D >= (50 - 7.5))
	{
		cout << "Yes"<<endl;
	}
	for (int i = 0; i < N; i++)
	{
		if (!visited[i] && firststep(i))
		{
			dfs(i);
		}
	}
	if (answer == 1)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}
