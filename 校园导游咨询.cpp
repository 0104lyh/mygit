#include<stdio.h>
#include<string>
#include<string.h>
#include<malloc.h>
#include<iostream>
#include<map>
#include<queue>
#include<stack>

using namespace std;
#define Max	20000
#define NUM 20
int pstack[NUM], top, cnt;
int Vtd[NUM];
typedef struct ArcCell
{
	int adj;//地址权重
}ArcCell;
typedef struct VertexType
{
	int number;
	const char *sight;//景点名称
	const char *description;//景点描述
}VertexType;//景点信息数组
typedef struct
{
	VertexType vex[NUM];//带权无向图
	ArcCell acrs[NUM][NUM];//vexnum是景点的数量
	int vexnum;
}MGraph;

MGraph G;
MGraph CAR;
int P1[NUM][NUM];
int P2[NUM][NUM];
long int D1[NUM];
long int D2[NUM];
int x[19] = { 0 };
void artpoint(MGraph *G, int i);
void apsearch(MGraph *G);
void clearpath(int a[], int b[]);
void CreateUDN(int v);
void CreateCRD(int v);
void allpath(MGraph *G, int a, int b);
void narrate();
void ShortestPath1(int num);
void ShortestPath2(int num);
void output1(int sight1, int sight2);
void output2(int sight1, int sight2);
char Menu();
void search();
char SearchMenu();
int main()
{
	int v0, v1;
	int way;
	char ck;
	CreateUDN(NUM);
	CreateCRD(NUM);
	do
	{
		ck = Menu();
		switch (ck)
		{
		case '1':system("cls");
			narrate();
			printf("\n\n\t\t\t请选择出行方式（0：步行 1：驾车）");
			scanf("%d", &way);
			if (way != 1 && way != 0)
			{
				printf("\n\t\t请重新输入...");
				getchar();
				getchar();
				break;
			}
			printf("\n\n\t\t\t查询景点路径\n");
			printf("\n\n\t\t\t请选择起点景点(0~19):");
			scanf("%d", &v0);
			printf("\n\n\t\t\t请选择终点景点(0~19):");
			scanf("%d", &v1);
			if (way == 1)
			{
				ShortestPath2(v0);
				output2(v0, v1);
				printf("\n\n\t\t\t请按任意键继续...\n");
				getchar();
				getchar();
				break;
			}
			if (way == 0)
			{
				ShortestPath1(v0);
				output1(v0, v1);
				printf("\n\n\t\t\t请按任意键继续...\n");
				getchar();
				getchar();
				break;
			}
			
		case '2':search(); break;
		case '3':system("cls");
			narrate();
			printf("\n\n\t\t\t请选择出行方式（0：步行 1：驾车）");
			scanf("%d", &way);
			if (way != 1 && way != 0)
			{
				printf("\n\t\t请重新输入...");
				getchar();
				getchar();
				break;
			}
			printf("\n\n\t\t\t查询景点路径\n");
			printf("\n\n\t\t\t请选择起点景点(0~19):");
			scanf("%d", &v0);
			printf("\n\n\t\t\t请选择终点景点(0~19):");
			scanf("%d", &v1);
			if (way == 1)
			{
				allpath(&CAR, v0, v1);
				clearpath(pstack, Vtd);
				top = cnt = 0;
				printf("\n\n\t\t\t请按任意键继续...\n");
				getchar();
				getchar();
				break;
			}
			else if (way == 0)
			{
				allpath(&G, v0, v1);
				clearpath(pstack, Vtd);
				top = cnt = 0;
				printf("\n\n\t\t\t请按任意键继续...\n");
				getchar();
				getchar();
				break;
			}
		case '4':
			system("cls");
			apsearch(&G);
			printf("\n\n\t\t\t请按任意键继续...\n");
			getchar();
			getchar();
			break;
		}

	} while (ck != 'e');
}
char Menu()
{
	char c;
	int flag;
	do {
		flag = 1;
		system("cls");
		narrate();
		printf("\n");
		printf("\t\t\t##########################\n");
		printf("\t\t\t#                        #\n");
		printf("\t\t\t#    1、查询景点路径     #\n");
		printf("\t\t\t#    2、查询景点信息     #\n");
		printf("\t\t\t#    3、查询所有路径     #\n");
		printf("\t\t\t#    4、打印关节点       #\n");
		printf("\t\t\t#    e、退出             #\n");
		printf("\t\t\t#                        #\n");
		printf("\t\t\t##########################\n");
		printf("\t\t\t\t 请输入您的选择：");
		scanf("%c", &c);
		if (c == '1' || c == '2' || c == 'e'||c == '3'||c=='4')
		{
			flag = 0;
		}

	} while (flag);
	return c;
}
char SearchMenu()
{
	char c;
	int flag;
	do {
		flag = 1;
		system("cls");
		narrate();
		printf("\n\t\t\t############################\n");
		printf("\t\t\t#                          #\n");
		printf("\t\t\t#       1、按景点编号查询  #\n");
		printf("\t\t\t#       2、按景点名称查询  #\n");
		printf("\t\t\t#       e、返回            #\n");
		printf("\t\t\t#                          #\n");
		printf("\t\t\t############################\n");
		printf("\t\t\t\t 请输入您的选择：");
		scanf("%c", &c);
		if (c == '1' || c == '2' || c == 'e')
		{
			flag = 0;
		}

	} while (flag);
	return c;
}
void search()
{
	int num;
	int i;
	char c;
	char name[20];
	do
	{
		system("cls");
		c = SearchMenu();
		switch (c)
		{
		case '1':
			system("cls");
			narrate();
			printf("\n\n\t\t请输入您要查找的景点编号：");
			scanf("%d", &num);
			for (i = 0; i < NUM; i++)
			{
				if (num == G.vex[i].number)
				{
					printf("\n\n\t\t\t您要查找的景点信息如下：");
					printf("\n\n\t\t\t%-25s\n\n", G.vex[i].description);
					printf("\n\t\t\t按任意键返回...");
					getchar();
					getchar();
					break;
				}
			}
			if (i == NUM)
			{
				printf("\n\n\t\t\t 没有找到！");
				printf("\n\n\t\t\t 按任意键返回...");
				getchar();
				getchar();
			}
			break;
		case '2':
			narrate();
			system("cls");
			printf("\n\n\t\t请输入您要查找的景点名称：");
			scanf("%s", name);
			for (i = 0; i < NUM; i++)
			{
				if (!strcmp(name, G.vex[i].sight))
				{
					printf("\n\n\t\t\t您要查找的景点信息如下：");
					printf("\n\n\t\t\t%-25s\n\n", G.vex[i].description);
					printf("\n\t\t\t按任意键返回...");
					getchar();
					getchar();
					break;
				}
			}
			if (i == NUM)
			{
				printf("\n\n\t\t\t没有找到！");
				printf("\n\n\t\t\t按任意键返回...");
				getchar();
				getchar();
			}
			break;
		}
	} while (c != 'e');
}
void CreateUDN(int v)//人行道图定义
{
	G.vexnum = v;
	for (int i = 0; i < G.vexnum; ++i)
	{
		G.vex[i].number = i;
	}
	G.vex[0].sight = "尚大楼";
	G.vex[0].description = "学校领导行政办公之地";
	G.vex[1].sight = "月明楼";
	G.vex[1].description = "学生生活中心，学校文艺汇演举报地点";
	G.vex[2].sight = "陆大楼";
	G.vex[2].description = "教室，机房，计算机学院上课地点";
	G.vex[3].sight = "美玲楼";
	G.vex[3].description = "教室，学生自习室";
	G.vex[4].sight = "嘉庚图书馆";
	G.vex[4].description = "阅览，借阅图书，学生自习";
	G.vex[5].sight = "万人食堂";
	G.vex[5].description = "餐饮休闲";
	G.vex[6].sight = "黑天鹅湖";
	G.vex[6].description = "休闲，景观";
	G.vex[7].sight = "西苑餐厅";
	G.vex[7].description = "餐饮休闲";
	G.vex[8].sight = "五社区";
	G.vex[8].description = "学生宿舍";
	G.vex[9].sight = "益禾堂";
	G.vex[9].description = "圣地";
	G.vex[10].sight = "延奎图书馆";
	G.vex[10].description = "阅览，借阅图书，学生自习";
	G.vex[11].sight = "禹州楼";
	G.vex[11].description = "教室，学生自习室";
	G.vex[12].sight = "中山纪念馆";
	G.vex[12].description = "校史展览馆";
	G.vex[13].sight = "光前体育馆";
	G.vex[13].description = "体育馆";
	G.vex[14].sight = "克立楼";
	G.vex[14].description = "信息学院教室";
	G.vex[15].sight = "小高";
	G.vex[15].description = "收快递的地方";
	G.vex[16].sight = "汉水楼";
	G.vex[16].description = "外国语学院上课地点";
	G.vex[17].sight = "体院体育场";
	G.vex[17].description = "体育场，体育活动中心";
	G.vex[18].sight = "篮球场";
	G.vex[18].description = "学生体育活动开展地点";
	G.vex[19].sight = "诚毅玻璃房";
	G.vex[19].description = "学生生活中心";
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			G.acrs[i][j].adj = Max;
		}
	}
	G.acrs[0][2].adj = G.acrs[2][0].adj = 50;
	G.acrs[0][3].adj = G.acrs[3][0].adj = 80;
	G.acrs[1][3].adj = G.acrs[3][1].adj = 400;
	G.acrs[6][4].adj = G.acrs[4][6].adj = 40;
	G.acrs[3][8].adj = G.acrs[8][3].adj = 280;
	G.acrs[5][7].adj = G.acrs[7][5].adj = 190;
	G.acrs[7][8].adj = G.acrs[8][7].adj = 30;
	G.acrs[1][9].adj = G.acrs[9][1].adj = 20;
	G.acrs[5][9].adj = G.acrs[9][5].adj = 10;
	G.acrs[8][4].adj = G.acrs[4][8].adj = 140;
	G.acrs[3][6].adj = G.acrs[6][3].adj = 20;
	G.acrs[2][18].adj = G.acrs[18][2].adj = 60;
	G.acrs[18][19].adj = G.acrs[19][18].adj = 50;
	G.acrs[0][15].adj = G.acrs[15][0].adj = 80;
	G.acrs[16][19].adj = G.acrs[19][16].adj = 300;
	G.acrs[10][0].adj = G.acrs[0][10].adj = 200;
	G.acrs[12][10].adj = G.acrs[10][12].adj = 300;
	G.acrs[3][13].adj = G.acrs[13][3].adj = 600;
	G.acrs[11][13].adj = G.acrs[13][11].adj = 20;
	G.acrs[14][13].adj = G.acrs[13][14].adj = 90;

}
void CreateCRD(int v)//车行道图定义
{
	CAR.vexnum = v;

	for (int i = 0; i < CAR.vexnum; ++i)
	{
		CAR.vex[i].number = i;
	}
	CAR.vex[0].sight = "尚大楼";
	CAR.vex[0].description = "学校领导行政办公之地";
	CAR.vex[1].sight = "月明楼";
	CAR.vex[1].description = "学生生活中心，学校文艺汇演举报地点";
	CAR.vex[2].sight = "陆大楼";
	CAR.vex[2].description = "教室，机房，计算机学院上课地点";
	CAR.vex[3].sight = "美玲楼";
	CAR.vex[3].description = "教室，学生自习室";
	CAR.vex[4].sight = "嘉庚图书馆";
	CAR.vex[4].description = "阅览，借阅图书，学生自习";
	CAR.vex[5].sight = "万人食堂";
	CAR.vex[5].description = "餐饮休闲";
	CAR.vex[6].sight = "黑天鹅湖";
	CAR.vex[6].description = "休闲，景观";
	CAR.vex[7].sight = "西苑餐厅";
	CAR.vex[7].description = "餐饮休闲";
	CAR.vex[8].sight = "五社区";
	CAR.vex[8].description = "学生宿舍";
	CAR.vex[9].sight = "益禾堂";
	CAR.vex[9].description = "圣地";
	CAR.vex[10].sight = "延奎图书馆";
	CAR.vex[10].description = "阅览，借阅图书，学生自习";
	CAR.vex[11].sight = "禹州楼";
	CAR.vex[11].description = "教室，学生自习室";
	CAR.vex[12].sight = "中山纪念馆";
	CAR.vex[12].description = "校史展览馆";
	CAR.vex[13].sight = "光前体育馆";
	CAR.vex[13].description = "体育馆";
	CAR.vex[14].sight = "克立楼";
	CAR.vex[14].description = "信息学院教室";
	CAR.vex[15].sight = "小高";
	CAR.vex[15].description = "收快递的地方";
	CAR.vex[16].sight = "汉水楼";
	CAR.vex[16].description = "外国语学院上课地点";
	CAR.vex[17].sight = "体院体育场";
	CAR.vex[17].description = "体育场，体育活动中心";
	CAR.vex[18].sight = "篮球场";
	CAR.vex[18].description = "学生体育活动开展地点";
	CAR.vex[19].sight = "诚毅玻璃房";
	CAR.vex[19].description = "学生生活中心";
	for (int i = 0; i < CAR.vexnum; i++)
	{
		for (int j = 0; j < CAR.vexnum; j++)
		{
			CAR.acrs[i][j].adj = Max;
		}
	}
	CAR.acrs[0][2].adj = CAR.acrs[2][0].adj = 50;
	CAR.acrs[0][3].adj = CAR.acrs[3][0].adj = 80;
	CAR.acrs[1][3].adj = CAR.acrs[3][1].adj = 400;
	CAR.acrs[6][4].adj = CAR.acrs[4][6].adj = 40;
	CAR.acrs[3][8].adj = CAR.acrs[8][3].adj = 280;
	CAR.acrs[5][7].adj = CAR.acrs[7][5].adj = 190;
	CAR.acrs[7][8].adj = CAR.acrs[8][7].adj = 30;
	CAR.acrs[1][9].adj = CAR.acrs[9][1].adj = 20;
	CAR.acrs[5][9].adj = CAR.acrs[9][5].adj = 10;
	CAR.acrs[8][4].adj = CAR.acrs[4][8].adj = 140;
	CAR.acrs[3][6].adj = CAR.acrs[6][3].adj = 20;
	CAR.acrs[2][18].adj = CAR.acrs[18][2].adj = 60;
	CAR.acrs[18][19].adj = CAR.acrs[19][18].adj = 50;
	CAR.acrs[0][15].adj = CAR.acrs[15][0].adj = 80;
	CAR.acrs[16][19].adj = CAR.acrs[19][16].adj = 300;
	CAR.acrs[10][0].adj = CAR.acrs[0][10].adj = 200;
	CAR.acrs[12][10].adj = CAR.acrs[10][12].adj = 300;
	CAR.acrs[3][13].adj = CAR.acrs[13][3].adj = 600;
	CAR.acrs[11][13].adj = CAR.acrs[13][11].adj = 20;
	CAR.acrs[14][13].adj = CAR.acrs[13][14].adj = 90;

}
void narrate()//景点信息打印
{
	int i, k = 0;
	printf("\n\t\t**********************欢迎使用校园导游程序************************\n");
	printf("\t________________________________________________________________________\n");
	printf("\t\t景点名称\t\t\t景点描述\n");
	printf("\t________________________________________________________________________\n");
	for (i = 0; i < NUM; i++)
	{
		printf("\t(%2d)%-10s\t\t\t|\t%-25s\n", i, G.vex[i].sight, G.vex[i].description);
		k = k + 1;
	}
	printf("\t________________________________________________________________________\n");
}
void ShortestPath1(int num)
{
	int Final[NUM];
	int min;
	int v, w;
	for (v = 0; v < NUM; v++)
	{
		Final[v] = 0;
		D1[v] = G.acrs[num][v].adj;
		for (w = 0; w < NUM; w++)
		{
			P1[v][w] = 0;
		}
		if (D1[v] < 20000)
		{
			P1[v][num] = 1;
			P1[v][v] = 1;//有边没边就是0
		}
	}
	D1[num] = 0;
	Final[num] = 1;
	for (int i = 0; i < NUM; ++i)
	{
		min = Max;
		for (w = 0; w < NUM; ++w)
			if (!Final[w])
			 if (D1[w] < min)
			 {
				v = w;
				min = D1[w];
			 }
			Final[v] = 1;
			for (w = 0; w < NUM; ++w)
			{
				if (!Final[w] && ((min + G.acrs[v][w].adj) < D1[w]))
				{
					D1[w] = min + G.acrs[v][w].adj;
					for (int t = 0; t < NUM; t++)
					{
						P1[w][t] = P1[v][t];
					}
					P1[w][w]=1;
				}
			}
		
	}
}
void ShortestPath2(int num)
{
	int Final[NUM];
	int min;
	int v, w;
	for (v = 0; v < NUM; v++)
	{
		Final[v] = 0;
		D2[v] = CAR.acrs[num][v].adj;
		for (w = 0; w < NUM; w++)
		{
			P2[v][w] = 0;
		}
		if (D2[v] < 20000)
		{
			P2[v][num] = 1;
			P2[v][v] = 1;
		}
	}
	D2[num] = 0;
	Final[num] = 1;
	for (int i = 0; i < NUM; ++i)
	{
		min = Max;
		for (w = 0; w < NUM; ++w)
		{
			if (!Final[w])
			{
				if (D2[w] < min)
				{
					v = w;
					min = D2[w];
				}
			}
		}
		Final[v] = 1;
		for (w = 0; w < NUM; ++w)
		{
			if (!Final[w] && ((min + CAR.acrs[v][w].adj) < D2[w]))
			{
				D2[w] = min + CAR.acrs[v][w].adj;
				for (int t = 0; t < NUM; t++)
				{
					P2[w][t] = P2[v][t];
				}
				P2[w][w] = 1;
			}
		}

	}
}
void output1(int sight1, int sight2)
{
	int a, b, c, d, q = 0;
	a = sight2;
	if (a != sight1)
	{
		printf("\n\t从%s到%s的最短路径是", G.vex[sight1].sight, G.vex[sight2].sight);
		printf("\t(最短距离为 %dm.)\n\n\t", D1[a]);
		printf("\t%s", G.vex[sight1].sight);
		d = sight1;
		for (c = 0; c < NUM; ++c)
		{
		gate:;
			P1[a][sight1] = 0;
			for (b = 0; b < NUM; b++)
			{
				if ((G.acrs[d][b].adj < 20000) && P1[a][b])
				{
					printf("-->%s", G.vex[b].sight);
					q = q + 1;
					P1[a][b] = 0;
					d = b;
					if (q % 8 == 0)printf("\n");
					goto gate;
				}
			}
		}
	}
}
void output2(int sight1, int sight2)
{
	int a, b, c, d, q = 0;
	a = sight2;
	if (a != sight1)
	{
		printf("\n\t从%s到%s的最短路径是", CAR.vex[sight1].sight, CAR.vex[sight2].sight);
		printf("\t(最短距离为 %dm.)\n\n\t", D2[a]);
		printf("\t%s", CAR.vex[sight1].sight);
		d = sight1;
		for (c = 0; c < NUM; ++c)
		{
		gate:;
			P2[a][sight1] = 0;
			for (b = 0; b < NUM; b++)
			{
				if (CAR.acrs[d][b].adj < 20000 && P2[a][b])
				{
					printf("-->%s", CAR.vex[b].sight);
					q = q + 1;
					P2[a][b] = 0;
					d = b;
					if (q % 8 == 0)printf("\n");
					goto gate;
				}
			}
		}
	}
}
void allpath(MGraph *G, int a, int b)
{
	int i, j, dist = 0;
	pstack[top] = a;
	top++;
	Vtd[a] = 1;
	for (i = 0; i < G->vexnum; i++)
	{
		if (G->acrs[a][i].adj > 0 && G->acrs[a][i].adj != Max && !Vtd[i])
		{
			if (i == b)
			{
				printf("\n\t第%d道路：", cnt++);
				for (j = 0; j < top; j++)
				{
					printf("%s-->", G->vex[pstack[j]].sight);
					if (j < top - 1)
					{
						dist = dist + G->acrs[pstack[j]][pstack[j + 1]].adj;
					}
				}
				dist = dist + G->acrs[pstack[top - 1]][b].adj;
				printf("%s\n", G->vex[b].sight);
				printf("\n\t总长度为:%d m\n\n", dist);
			}
			else
			{
				allpath(G, i, b);
				top--;
				Vtd[i] = 0;
			}
		}
	}
}
void clearpath(int a[], int b[])
{
	for (int i = 0; i < NUM; i++)
	{
		a[i] = b[i] = 0;
	}
}
void apsearch(MGraph *G)
{
	int i;
	cnt = 0;
	for (i = 0; i < G->vexnum; i++)
	{
		memset(Vtd, 0, sizeof(Vtd));
		Vtd[i] = -1;
		artpoint(G, i);
	}
	printf("\n\t校园图的关节点个数为：%d\n\n", cnt);
	printf("\n\t分别是：\n");
	for (i = 0; i < G->vexnum; i++)
	{
		if (x[i] == 1)
		{
			printf("%s\t", G->vex[i].sight);
		}
	}
	printf("\n");
	cnt = 0;
	clearpath(Vtd, x);
}
void artpoint(MGraph *G, int i)
{
	int child = 0;
	int j;
	if (Vtd[i] != -1)
	{
		Vtd[i] = 1;
	}
	for (j = 0; j < G->vexnum; j++)
	{
		if (G->acrs[i][j].adj != 0 && G->acrs[i][j].adj != Max && !Vtd[j])
		{
			child++;
			artpoint(G, j);
		}

	}
	if (Vtd[i] == -1 && child >= 2)
	{
		cnt++;
		x[i] = 1;
	}
}