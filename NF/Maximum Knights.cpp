/*
*date:2019-01-10
*author:liangfh
*/
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>

#define MAX 200
typedef long long int LL;
using namespace std;

int n,m,match[MAX][MAX];
char g[MAX][MAX];
bool seen[MAX][MAX];
int dx[] = {1, 1, 2, 2,-1,-1,-2,-2};
int dy[] = {2,-2, 1,-1, 2,-2, 1,-1};


inline bool valid(int i,int j)
{
	return i>=0 && i<n && j>=0 && j<n && g[i][j] != '#';
}

bool dfs(int i,int j)
{
	if(seen[i][j])		return false;
	seen[i][j] = true;
	for(int k=0;k<8;k++)
	{
		int ni,nj;
		ni=i+dx[k],nj=j+dy[k];
		if(!valid(ni,nj))	continue;
		if(match[ni][nj] == -1 || dfs(match[ni][nj] /n, match[ni][nj] %n))
		{
			match[i][j] = ni*n + nj;
			match[ni][nj] = i*n + j;
			return true;
		}
	}
	return false;	
}

bool augment(void)
{
	int i,j;
	memset(seen,0,sizeof(seen));
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
		if(g[i][j] == '#')	continue;	
		if(((i+j)&1) && match[i][j] == -1 && dfs(i,j))	return true;
	}
	return false;
}	

int main()
{
	int i,j,b,tot,X,Y;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			g[i][j]='.';
	for(int i=0;i<m;i++){
		cin>>X>>Y;
		g[X-1][Y-1]='#';
	}
	
	b=tot=0;		
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)			
			if(g[i][j] == '#')	b++;		
	
	memset(match,-1,sizeof(match));
	
	while(augment())
		tot++;	//printf("%d  %d  %d\n",n*n,b,tot);
	printf("%d",n*n - b - tot);
	
	return 0;
}

