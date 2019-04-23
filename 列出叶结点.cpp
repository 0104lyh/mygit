#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
using namespace std;
struct node{
	char Left,Right;
}p[15];
int Root[15];
vector<int> Leaf[15];
void func(int s,int cur){
	if(p[s].Left=='-'&&p[s].Right=='-'){
		Leaf[cur].push_back(s);
		return;
	}
	if(p[s].Left!='-') func(p[s].Left-'0',cur+1);
	if(p[s].Right!='-') func(p[s].Right-'0',cur+1);
}
int main() {
	int n;
	memset(Root,0,sizeof Root);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i].Left>>p[i].Right;
		Root[p[i].Left-'0']=Root[p[i].Right-'0']=1;//能成为别人左右节点的节点必然不是根节点 
	}
	int rt;//记录根节点下标 
	for(int i=0;i<n;i++){
		if(!Root[i]){
			rt=i;
			break;
		}
	}
	func(rt,1);//将叶节点储存 
	int f=0;
	for(int i=1;i<=n;i++){ 
		for(int j=0;j<Leaf[i].size();j++){
			if(f) cout<<' ';
			else f=1;
			cout<<Leaf[i][j];
		}
	}
	cout<<endl;
	return 0;
}
