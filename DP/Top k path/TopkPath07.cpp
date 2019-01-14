#include <iostream>
#include<vector>
#include <utility>
#include <cstdlib>
#include<cstdio>
using namespace std;

//测试
int main() {
	int M,N,k,z; 
	scanf("%d%d%d",&M,&N,&k);
	vector<vector<int> > graph(M,vector<int>(N));
	vector<vector<vector<int> > > TopkPath(M,vector<vector<int> >(N,vector<int>(k)));
	//输入矩阵
	for(int x=0;x<M;x++)
		for (int y=0;y<N;y++)
			cin>>graph[x][y];
	//初始化
	TopkPath[0][0][0]=graph[0][0];
	for (int y=1;y<N;y++)
		TopkPath[0][y][0]=TopkPath[0][y-1][0]+graph[0][y];
	for (int x=1;x<M;x++)
		TopkPath[x][0][0]=TopkPath[x-1][0][0]+graph[x][0];	
	
	//开始记录
	for(int x=1;x<M;x++)
		for (int y=1;y<N;y++){
			int z=0;int i=0;int j=0;
			while(z!=k){
				if(i!=k && j!=k){
					if(TopkPath[x][y-1][i] <= TopkPath[x-1][y][j] && TopkPath[x-1][y][j]>0)
						TopkPath[x][y][z++] = TopkPath[x-1][y][j++]+graph[x][y];
					else if(TopkPath[x][y-1][i] > TopkPath[x-1][y][j] && TopkPath[x][y-1][i]>0)
						TopkPath[x][y][z++] = TopkPath[x][y-1][i++]+graph[x][y];
					else
						break;
				}
			}
		}
	
	//输出结果
	//cout<<"$$$$$$$$$$\n";
	for (z=0;z<k-1;z++){
		cout<<TopkPath[M-1][N-1][z];
		if(TopkPath[M-1][N-1][z+1]==0)
			return 0;	
		cout<<" ";
	}
	cout<<TopkPath[M-1][N-1][z];
	
	
	//cout<<"\n**********\n";
	//for(int x=0;x<M;x++)
	//	for (int y=0;y<N;y++){
	//		for (int z=0;z<k;z++)
	//			cout<<TopkPath[x][y][z]<<"  ";
	//		cout<<endl;
	//	}
}



	