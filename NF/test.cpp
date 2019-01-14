/*
*
*date:2019-01-09
*language:c++11
*/
#include <bits/stdc++.h>
using namespace std;

namespace matching {
  typedef int val_t;
  const int SIZE = 1000;
  int v1;
   vector < int >graph[SIZE];
  int mx[SIZE], my[SIZE];
  int total_matching;
  int dist[SIZE];
  int inf_dist;
  bool bfs() {
    int x, y;
     queue < int >q;
    for (x = 0; x < v1; x++) {
      if (mx[x] == -1) {
        dist[x] = 0;
        q.push(x);
      } else
         dist[x] = -1;
    }
    bool flg = false;
    while (!q.empty()) {
      x = q.front();
      q.pop();
      for (int i = 0; i < graph[x].size(); i++) {
        y = graph[x][i];
        if (my[y] == -1) {
          inf_dist = dist[x] + 1;
          flg = true;
        } else if (dist[my[y]] == -1) {
          dist[my[y]] = dist[x] + 1;
          q.push(my[y]);
        }
      }
    }
    return flg;
  }
  bool dfs(int x) {
    if (x == -1)
      return true;
    for (int i = 0; i < graph[x].size(); i++) {
      int y = graph[x][i];
      int tmp = (my[y] == -1) ? inf_dist : dist[my[y]];
      if (tmp == dist[x] + 1 && dfs(my[y])) {
        mx[x] = y;
        my[y] = x;
        return true;

      }

    }
    dist[x] = -1;
    return false;
  }
  //don't forget to clear graph;
  int hopcroft() {
    memset(mx, -1, sizeof(mx));
    memset(my, -1, sizeof(my));
    inf_dist = 0;
    total_matching = 0;
    while (bfs()) {
      for (int x = 0; x < v1; x++)
        if (mx[x] == -1 && dfs(x))
          total_matching++;

    }
    return total_matching;
  }
}


vector < string > a;
int x[] = {2,2,1,1,-1,-1,-2,-2};
int y[] = {1,-1,2,-2,2,-2,1,-1};
int n,m;

int num(int nx, int ny) {
  int nc = nx*n+ny;
  bool px = nx&1, py = ny&1;
  if(px^py) return nc/2;
  return n*n-1-nc/2;
}

int main() {
	//ios_base::sync_with_stdio(0);
    cin >> n >> m;
    a.resize(n);
	int X,Y;
    for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			a[i][j]='.';
	for(int i=0;i<m;i++){
		cin>>X>>Y;
		a[X-1][Y-1]='#';
	}
    matching::v1 = (n*n)/2;
    int t1 = 0;
    for(int i=0; i<n*n; i++) matching::graph[i].clear();
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        if(a[i][j]=='#') {
          t1++;
          continue;
        }
        for(int k=0; k<8; k++) {
          int nx = i+x[k];
          int ny = j+y[k];
          if(nx>=0 && nx<n && ny>=0 && ny<n && a[nx][ny]!='#') {
            //cout<<i<<" "<<j<<" "<<nx<<" "<<ny<<" "<<num(i,j)<<" "<<num(nx,ny)<<endl;
            matching::graph[num(i,j)].push_back(num(nx,ny));
          }
        }
      }
    }
    int t2 = matching::hopcroft();
	//cout<<n*n-t1-t2<<endl;//<<" "<<t1<<" "<<t2<<endl;
	printf("%d",n*n-t1-t2);
  
  return 0;
}
