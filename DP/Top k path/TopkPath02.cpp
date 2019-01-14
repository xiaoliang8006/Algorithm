#include <iostream>
#include<vector>
#include <utility>
#include <cstdlib>
#include<cstdio>
#include <list>
using namespace std;

typedef pair<int, int> Pair;
list<int> List;//List存放获得价值
int i=0;
list<int>::iterator iter;


	
//定义输出路径函数
void Printway(vector<Pair> path,int N)
{
	printf("Following is one way:\n");
	int i;
    for (i=0; i<N-1; i++)
		cout<<"("<<path[i].first<<","<<path[i].second<<")"<<"-->";
	cout<<"("<<path[i].first<<","<<path[i].second<<")"<<endl;
}//Printway


//查找从u到v的一条路径
void Findway(int **graph, int M,int N, vector<Pair> path,Pair u,Pair v,int len){
    
	path.push_back(u);
    
	if(u==v){//访问到最后一个顶点
	   int value=0;
	   for (int i=0;i<M+N-1;i++)
		   value += graph[path[i].first][path[i].second];
	   if(List.empty()){
		  List.push_back(value); 
		  return;
	   }
	   iter=List.begin();
		while(value < *iter)
			iter++;	
		List.insert(iter,value);
	   //Printway(path,M+N-1);
					
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
	vector<Pair> path;//path存放路径 
	Pair u,v;//图中的点
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

	for(iter = List.begin(),i=0; i<k-1; iter++,i++)
		cout<<*iter<<" ";
	cout<<*iter;

}



	