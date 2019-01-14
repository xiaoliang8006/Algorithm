#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <utility>
#include <cstdlib>
#include<cstdio>
using namespace std;
const int MAX=32767;
typedef pair<int, int> Pair;

int VALUE[200];
int j=0;

void SortArr(int arr[],int n){
	//插入排序
	int i;
	for(j=0;j<n;j++){
		int key = arr[j];
		i=j-1;
		while(i>=0 && arr[i]<key){
			arr[i+1]=arr[i];
			i--;
		}
		arr[i+1]=key;
	}
}

	
//定义输出路径函数
void Printway(vector<Pair> path,int N)
{
	printf("Following is one way:\n");
	int i;
    for (i=0; i<N-1; i++)
		cout<<"("<<path[i].first<<","<<path[i].second<<")"<<"-->";
	cout<<"("<<path[i].first<<","<<path[i].second<<")"<<endl;
}//Printway


//查找从u到v的一条类哈密顿回路
void Findway(int **graph, int M,int N, vector<Pair> path,Pair u,Pair v,int len){
    
	path.push_back(u);
    
	if(u==v){//访问到最后一个顶点
	   int value=0;
	   for (int i=0;i<M+N-1;i++)
		   VALUE[j]+=graph[path[i].first][path[i].second];
	   j++;
	   //Printway(path,M+N-1);
	   //cout<<"value="<<value<<endl;			   
	 }else{
		//往下走
		if(u.first+1<M){
			Pair t;
			t.first=u.first+1; t.second=u.second;
			Findway(graph, M, N, path, t, v, len+1);
		}
		//往右走
		if(u.second+1<N){
			Pair t;
			t.first=u.first; t.second=u.second+1;
			Findway(graph, M, N, path, t, v, len+1);
		}
		
	}
	

}//Findway   


//测试
int main() {
	int M,N,k;
	scanf("%d%d%d",&M,&N,&k);
	//path记录路径，visited记录顶点是否访问过，len记录当前路径的长度
	vector<Pair> path;
	Pair u,v;
	u.first=0; u.second=0;
	v.first=M-1; v.second=N-1;
	
	int  **graph = new int*[M];  //只有每行内是连续排列，各行并不一定连续排列 

	for( int i = 0; i < M; i++ ) 
		graph[i]   =   new   int[N]; 

	for ( int i = 0; i < M; i++ ) 
		for ( int j = 0; j < N; j++ ) 
			cin>>graph[i][j]; 
	
	//调用函数
	Findway(graph,M,N,path,u,v,0);
	SortArr(VALUE,j);

	for(int i=0;i<k-1;i++)
		cout<<VALUE[i]<<" ";
	cout<<VALUE[k-1]<<endl;
}



	