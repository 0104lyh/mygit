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
	int adj;//��ַȨ��
}ArcCell;
typedef struct VertexType
{
	int number;
	const char *sight;//��������
	const char *description;//��������
}VertexType;//������Ϣ����
typedef struct
{
	VertexType vex[NUM];//��Ȩ����ͼ
	ArcCell acrs[NUM][NUM];//vexnum�Ǿ��������
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
			printf("\n\n\t\t\t��ѡ����з�ʽ��0������ 1���ݳ���");
			scanf("%d", &way);
			if (way != 1 && way != 0)
			{
				printf("\n\t\t����������...");
				getchar();
				getchar();
				break;
			}
			printf("\n\n\t\t\t��ѯ����·��\n");
			printf("\n\n\t\t\t��ѡ����㾰��(0~19):");
			scanf("%d", &v0);
			printf("\n\n\t\t\t��ѡ���յ㾰��(0~19):");
			scanf("%d", &v1);
			if (way == 1)
			{
				ShortestPath2(v0);
				output2(v0, v1);
				printf("\n\n\t\t\t�밴���������...\n");
				getchar();
				getchar();
				break;
			}
			if (way == 0)
			{
				ShortestPath1(v0);
				output1(v0, v1);
				printf("\n\n\t\t\t�밴���������...\n");
				getchar();
				getchar();
				break;
			}
			
		case '2':search(); break;
		case '3':system("cls");
			narrate();
			printf("\n\n\t\t\t��ѡ����з�ʽ��0������ 1���ݳ���");
			scanf("%d", &way);
			if (way != 1 && way != 0)
			{
				printf("\n\t\t����������...");
				getchar();
				getchar();
				break;
			}
			printf("\n\n\t\t\t��ѯ����·��\n");
			printf("\n\n\t\t\t��ѡ����㾰��(0~19):");
			scanf("%d", &v0);
			printf("\n\n\t\t\t��ѡ���յ㾰��(0~19):");
			scanf("%d", &v1);
			if (way == 1)
			{
				allpath(&CAR, v0, v1);
				clearpath(pstack, Vtd);
				top = cnt = 0;
				printf("\n\n\t\t\t�밴���������...\n");
				getchar();
				getchar();
				break;
			}
			else if (way == 0)
			{
				allpath(&G, v0, v1);
				clearpath(pstack, Vtd);
				top = cnt = 0;
				printf("\n\n\t\t\t�밴���������...\n");
				getchar();
				getchar();
				break;
			}
		case '4':
			system("cls");
			apsearch(&G);
			printf("\n\n\t\t\t�밴���������...\n");
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
		printf("\t\t\t#    1����ѯ����·��     #\n");
		printf("\t\t\t#    2����ѯ������Ϣ     #\n");
		printf("\t\t\t#    3����ѯ����·��     #\n");
		printf("\t\t\t#    4����ӡ�ؽڵ�       #\n");
		printf("\t\t\t#    e���˳�             #\n");
		printf("\t\t\t#                        #\n");
		printf("\t\t\t##########################\n");
		printf("\t\t\t\t ����������ѡ��");
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
		printf("\t\t\t#       1���������Ų�ѯ  #\n");
		printf("\t\t\t#       2�����������Ʋ�ѯ  #\n");
		printf("\t\t\t#       e������            #\n");
		printf("\t\t\t#                          #\n");
		printf("\t\t\t############################\n");
		printf("\t\t\t\t ����������ѡ��");
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
			printf("\n\n\t\t��������Ҫ���ҵľ����ţ�");
			scanf("%d", &num);
			for (i = 0; i < NUM; i++)
			{
				if (num == G.vex[i].number)
				{
					printf("\n\n\t\t\t��Ҫ���ҵľ�����Ϣ���£�");
					printf("\n\n\t\t\t%-25s\n\n", G.vex[i].description);
					printf("\n\t\t\t�����������...");
					getchar();
					getchar();
					break;
				}
			}
			if (i == NUM)
			{
				printf("\n\n\t\t\t û���ҵ���");
				printf("\n\n\t\t\t �����������...");
				getchar();
				getchar();
			}
			break;
		case '2':
			narrate();
			system("cls");
			printf("\n\n\t\t��������Ҫ���ҵľ������ƣ�");
			scanf("%s", name);
			for (i = 0; i < NUM; i++)
			{
				if (!strcmp(name, G.vex[i].sight))
				{
					printf("\n\n\t\t\t��Ҫ���ҵľ�����Ϣ���£�");
					printf("\n\n\t\t\t%-25s\n\n", G.vex[i].description);
					printf("\n\t\t\t�����������...");
					getchar();
					getchar();
					break;
				}
			}
			if (i == NUM)
			{
				printf("\n\n\t\t\tû���ҵ���");
				printf("\n\n\t\t\t�����������...");
				getchar();
				getchar();
			}
			break;
		}
	} while (c != 'e');
}
void CreateUDN(int v)//���е�ͼ����
{
	G.vexnum = v;
	for (int i = 0; i < G.vexnum; ++i)
	{
		G.vex[i].number = i;
	}
	G.vex[0].sight = "�д�¥";
	G.vex[0].description = "ѧУ�쵼�����칫֮��";
	G.vex[1].sight = "����¥";
	G.vex[1].description = "ѧ���������ģ�ѧУ���ջ��ݾٱ��ص�";
	G.vex[2].sight = "½��¥";
	G.vex[2].description = "���ң������������ѧԺ�Ͽεص�";
	G.vex[3].sight = "����¥";
	G.vex[3].description = "���ң�ѧ����ϰ��";
	G.vex[4].sight = "�θ�ͼ���";
	G.vex[4].description = "����������ͼ�飬ѧ����ϰ";
	G.vex[5].sight = "����ʳ��";
	G.vex[5].description = "��������";
	G.vex[6].sight = "������";
	G.vex[6].description = "���У�����";
	G.vex[7].sight = "��Է����";
	G.vex[7].description = "��������";
	G.vex[8].sight = "������";
	G.vex[8].description = "ѧ������";
	G.vex[9].sight = "�����";
	G.vex[9].description = "ʥ��";
	G.vex[10].sight = "�ӿ�ͼ���";
	G.vex[10].description = "����������ͼ�飬ѧ����ϰ";
	G.vex[11].sight = "����¥";
	G.vex[11].description = "���ң�ѧ����ϰ��";
	G.vex[12].sight = "��ɽ�����";
	G.vex[12].description = "Уʷչ����";
	G.vex[13].sight = "��ǰ������";
	G.vex[13].description = "������";
	G.vex[14].sight = "����¥";
	G.vex[14].description = "��ϢѧԺ����";
	G.vex[15].sight = "С��";
	G.vex[15].description = "�տ�ݵĵط�";
	G.vex[16].sight = "��ˮ¥";
	G.vex[16].description = "�����ѧԺ�Ͽεص�";
	G.vex[17].sight = "��Ժ������";
	G.vex[17].description = "�����������������";
	G.vex[18].sight = "����";
	G.vex[18].description = "ѧ���������չ�ص�";
	G.vex[19].sight = "���㲣����";
	G.vex[19].description = "ѧ����������";
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
void CreateCRD(int v)//���е�ͼ����
{
	CAR.vexnum = v;

	for (int i = 0; i < CAR.vexnum; ++i)
	{
		CAR.vex[i].number = i;
	}
	CAR.vex[0].sight = "�д�¥";
	CAR.vex[0].description = "ѧУ�쵼�����칫֮��";
	CAR.vex[1].sight = "����¥";
	CAR.vex[1].description = "ѧ���������ģ�ѧУ���ջ��ݾٱ��ص�";
	CAR.vex[2].sight = "½��¥";
	CAR.vex[2].description = "���ң������������ѧԺ�Ͽεص�";
	CAR.vex[3].sight = "����¥";
	CAR.vex[3].description = "���ң�ѧ����ϰ��";
	CAR.vex[4].sight = "�θ�ͼ���";
	CAR.vex[4].description = "����������ͼ�飬ѧ����ϰ";
	CAR.vex[5].sight = "����ʳ��";
	CAR.vex[5].description = "��������";
	CAR.vex[6].sight = "������";
	CAR.vex[6].description = "���У�����";
	CAR.vex[7].sight = "��Է����";
	CAR.vex[7].description = "��������";
	CAR.vex[8].sight = "������";
	CAR.vex[8].description = "ѧ������";
	CAR.vex[9].sight = "�����";
	CAR.vex[9].description = "ʥ��";
	CAR.vex[10].sight = "�ӿ�ͼ���";
	CAR.vex[10].description = "����������ͼ�飬ѧ����ϰ";
	CAR.vex[11].sight = "����¥";
	CAR.vex[11].description = "���ң�ѧ����ϰ��";
	CAR.vex[12].sight = "��ɽ�����";
	CAR.vex[12].description = "Уʷչ����";
	CAR.vex[13].sight = "��ǰ������";
	CAR.vex[13].description = "������";
	CAR.vex[14].sight = "����¥";
	CAR.vex[14].description = "��ϢѧԺ����";
	CAR.vex[15].sight = "С��";
	CAR.vex[15].description = "�տ�ݵĵط�";
	CAR.vex[16].sight = "��ˮ¥";
	CAR.vex[16].description = "�����ѧԺ�Ͽεص�";
	CAR.vex[17].sight = "��Ժ������";
	CAR.vex[17].description = "�����������������";
	CAR.vex[18].sight = "����";
	CAR.vex[18].description = "ѧ���������չ�ص�";
	CAR.vex[19].sight = "���㲣����";
	CAR.vex[19].description = "ѧ����������";
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
void narrate()//������Ϣ��ӡ
{
	int i, k = 0;
	printf("\n\t\t**********************��ӭʹ��У԰���γ���************************\n");
	printf("\t________________________________________________________________________\n");
	printf("\t\t��������\t\t\t��������\n");
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
			P1[v][v] = 1;//�б�û�߾���0
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
		printf("\n\t��%s��%s�����·����", G.vex[sight1].sight, G.vex[sight2].sight);
		printf("\t(��̾���Ϊ %dm.)\n\n\t", D1[a]);
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
		printf("\n\t��%s��%s�����·����", CAR.vex[sight1].sight, CAR.vex[sight2].sight);
		printf("\t(��̾���Ϊ %dm.)\n\n\t", D2[a]);
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
				printf("\n\t��%d��·��", cnt++);
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
				printf("\n\t�ܳ���Ϊ:%d m\n\n", dist);
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
	printf("\n\tУ԰ͼ�Ĺؽڵ����Ϊ��%d\n\n", cnt);
	printf("\n\t�ֱ��ǣ�\n");
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