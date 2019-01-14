/*
*date:2019-01-09
*author:liangfh
*/
#include<bits/stdc++.h> 
using namespace std;
 
const int INF=0x3f3f3f3f;
const int MAX_V=1200;
 
struct edge{
    int to,rev;long cap;
    edge(int _to,int _cap,int _rev):to(_to),cap(_cap),rev(_rev){}
};
 
vector<edge>G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
int n,m;
 
void add_edge(int from,int to,long cap)
{
    G[from].push_back(edge(to,cap,G[to].size()));
    G[to].push_back(edge(from,0,G[from].size()-1));
}
 
void bfs(int s)
{
    memset(level,-1,sizeof(level));
    queue<int>que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
        int v=que.front();que.pop();
        for(int i=0;i<G[v].size();i++){
            edge &e=G[v][i];
            if(e.cap>0&&level[e.to]<0){
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}
 
long dfs(int v,int t,long f)
{
    if(v==t){
        return f;
    }
    for(int &i=iter[v];i<G[v].size();i++){
        edge &e=G[v][i];
        if(e.cap>0&&level[v]<level[e.to]){
            long d=dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
 
long max_flow(int s,int t)
{
    long flow=0;
    for(;;){
        bfs(s);
        if(level[t]<0){
            return flow;
        }
        memset(iter,0,sizeof(iter));
        long f;
        while((f=dfs(s,t,INF))>0){
            flow+=f;
        }
    }
}
 
int main()
{
    int s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    int u,v,w;
    for(int i=0;i<m;i++){
        scanf("%d%d%ld",&u,&v,&w);
        add_edge(u,v,w);
    }
    printf("%ld",max_flow(s,t));
    return 0;
}
