#include <iostream>
#include<string.h>
using namespace std;

int main()
{
	//定义图的大小
	int n,i,j;
	cout<<"hello\n";
	//输入
	while(cin>>n){
		int G[n+2][n+2];//加边框
		memset(G,1,sizeof(G));
		for(i=1;i<n+1;i++)
			for(j=1;j<n+1;j++)
				cin >> G[i][j];
		
		//输出G
		for(i=0;i<n+2;i++){
			for(j=0;j<n+2;j++){
				cout.setf(ios::left); //设置对齐方式为left 
				cout.width(10); //设置宽度为10，不足用空格填充 
				if(i==0||i==n+1||j==0||j==n+1){
					cout<<"M";
					continue;
				}
				cout << G[i][j];
			}
			cout<<endl;
		}
		
		//找出局部最小值
		for(i=1;i<n+1;i++)
			for(j=1;j<n+1;j++)
				if(G[i][j]<G[i-1][j] && G[i][j]<G[i+1][j] && G[i][j]<G[i][j+1] && G[i][j]<G[i][j-1])       
					cout <<"local minimum: "<< G[i][j] << endl;	
	}
	
}
