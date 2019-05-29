6-1【基础编程_课后练习】 二叉树基本运算 (20 分)
void CreateBTNode(BTNode *&b,char *str); //根据括号表示法的str，创建二叉树b。
int BTNodeDepth(BTNode *b); //求二叉树b的深度。
void PreOrder(BTNode *b); //先序遍历二叉树b
void InOrder(BTNode *b); //中序遍历二叉树b
void PostOrder(BTNode *b); //后序遍历二叉树b
void TravLevel(BTNode *b); //层次遍历二叉树b
void DestroyBTNode(BTNode *&b); //销毁二叉树b。 (由裁判程序实现，略去)
void CreateBTNode(BTNode *&b, char *str)
{
    BTNode *St[101], *p;
    int top = -1, k, j = 0;
    char ch;
    b = NULL;
    ch = str[j];
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
        ch = str[j];
    }
}
int BTNodeDepth(BTNode *b)
{
    int n = 0;
    int l, r;
    if (!b)
    {
        return 0;
    }
    else
    {
        l = BTNodeDepth(b->lchild);
        r = BTNodeDepth(b->rchild);
        return (l > r) ? (l + 1) : (r + 1);
    }
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
    BTNode *tree[101], *t;
    int front = 0, rear = 0;
    if (b)
    {
        tree[rear++] = b;
        while (front != rear)
        {
            t = tree[front++];
            printf("%c ", t->data);
            if (t->lchild) tree[rear++] = t->lchild;
            if (t->rchild) tree[rear++] = t->rchild;
        }
    }
}
6-2【基础编程_课后练习】 求二叉树结点数 (15 分)
int Nodes(BTNode *b); //计算并返回二叉树b的节点个数
int Nodes(BTNode *b)
{
if(b==NULL)
return 0;
else
return Nodes(b->lchild)+Nodes(b->rchild)+1;
}
7-5【基础编程_课后练习】 求二叉树叶到根路径 (30 分)
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<numeric>
#include<string>
#include<bitset>
#include<functional>
#include<algorithm>
#include<set>
#include<map>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<climits>
#include<cstdbool>
using namespace std;

typedef struct Node {
    char date;
    struct Node* Left, * Right;

}*Tree;


void createrTree(Tree& T, string str) {
    stack<Tree> st;
    Tree p;
    int k = 1;
    int i;
    for (int i = 0; i < str.size(); i++) {
        switch (str[i]) {
        case '(':
            st.push(p);
            k = 1;
            break;
        case ',':
            k = 2;
            break;
        case ')':
            st.pop();
            break;
        default:
            p = new struct Node;
            p->date = str[i];
            p->Right = p->Left = NULL;
            if (!T)
                T = p;
            else {
                if (k == 1) {
                    st.top()->Left = p;
                }
                else {
                    st.top()->Right = p;
                }

            }


        }
    }
}


int flag = 0;
void print(Tree T) {
    if (T) {

        print(T->Left);
        if (!T->Left && !T->Right) {
            
            cout << T->date << " ";
            flag = 1;
        }
        print(T->Right);

    }
}

pair<int, string> getdeep(Tree T) {
    pair<int, string> p(0, "");;
    if (!T)
        return p;
    pair<int, string> dp1, dp2;
    dp1 = getdeep(T->Left);
    dp2 = getdeep(T->Right);
    if (dp1.first >= dp2.first) {
        if (T->Left)
            dp1.second += T->Left->date;
        dp1.first += 1;
        return dp1;

    }
    else {
        if (T->Right)
            dp2.second += T->Right->date;
        dp2.first += 1;
        return dp2;

    }
}

int main()
{
    string str;
    getline(cin, str);
    Tree T = NULL;
    createrTree(T, str);
    print(T);
    pair<int, string> p = getdeep(T);
    cout << endl;
    string ans = p.second;
    if (T)
        ans += T->date;
    for (int i = 0; i < ans.size(); i++) {
        
        cout << ans[i] << " ";
    }
    cout<<endl;
    return 0;
}
6-1 jmu-ds-哈希表操作集 (15 分)
#include<iostream>
#define MaxSize 100 //定义最大哈希表长度
#define NULLKEY -1 //定义空关键字值
#define DELKEY -2 //定义被删关键字值
using namespace std;
typedef int KeyType; //关键字类型
typedef char * InfoType; //其他数据类型
typedef struct node
{
KeyType key; //关键字域
InfoType data; //其他数据域
int count; //探查次数域
} HashTable[MaxSize]; //哈希表类型
void InsertHT(HashTable ha,int &n,KeyType k,int p) ;//哈希表插入数据
void CreateHT(HashTable ha,KeyType x[],int n,int m,int p); //创建哈希表
int SearchHT(HashTable ha,int p,KeyType k) ; //在哈希表中查找关键字k
int uns_count=0;//查找不成功查找次数
int main()
{
int n,p,m,i,k;
cin>>n>>p;
int x[n];
HashTable ha;
for(i=0;i<n;i++) cin>>x[i];
m=p;
CreateHT(ha,x,n,m,p);
cin>>k;
uns_count=0;
i=SearchHT(ha,p,k);
if (i!=-1)
{
cout<<k<<" 哈希地址:"<<i<<endl;
cout<<"查找次数："<<ha[i].count;
}
else
{
cout<<"not find!"<<endl;
cout<<"查找次数："<<uns_count;
}
return 0;
}

int SearchHT(HashTable ha,int p,KeyType k){
int i=0,adr;
adr = k%p;
while (ha[adr].key!=NULLKEY && ha[adr].key!=k)
{
i++; //采用线性探查法找下一个地址
adr = (adr+1)%p;
}
if(ha[adr].key==k) //查找成功
return adr;
else //查找失败
return -1;

}
//将关键字k插入到哈希表中
void InsertHT(HashTable ha,int &n,KeyType k,int p){
int i,adr;
adr = k%p;
if (ha[adr].key==NULLKEY || ha[adr].key==DELKEY) //x[j]可以直接放在哈希表中
{
ha[adr].key=k;
ha[adr].count=1;
}
else //发生冲突时,采用线性探查法解决冲突
{
i=1; //i记录x[j]发生冲突的次数
do
{
adr = (adr+1)%p;
i++;
} while (ha[adr].key!=NULLKEY && ha[adr].key!=DELKEY);
ha[adr].key=k;
ha[adr].count=i;
}
n++;
}
//创建哈希表
void CreateHT(HashTable ha,KeyType x[],int n,int m,int p){
int i,n1=0;
for (i=0;i<m;i++) //哈希表置初值
{
ha[i].key=NULLKEY;
ha[i].count=0;
}
for(i=0;i<n;i++)
InsertHT(ha,n1,x[i],p);
}
//查找不成功没过
7-1-【基础编程-课前作业】必做 构造哈夫曼树 (20 分)
/*哈夫曼树*/
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<numeric>
#include<string>
#include<bitset>
#include<functional>
#include<algorithm>
#include<set>
#include<map>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<climits>
#include<cstdbool>
using namespace std;
int main()
{
    int  i, n;
    double sum = 0;
    string str;
    int num;
    cin >> n;
    vector<int> v;
    priority_queue<double,vector<double> ,greater<double> > pq;
    for (i = 0; i < n; i++) {
        cin >> str>>num;
        sum += num;
        v.push_back(num);
    }
    for (auto k : v)
        pq.push(k / sum);
    double a, b;
    sum = 0;
    while (pq.size() > 1) {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        sum += (a + b);
        pq.push(a + b);
    }
    printf("%.5f", sum);
    return 0;
}
