#include <iostream>
#include <map>  
#include <list>
using namespace std;
typedef pair<int, int> Pair;
typedef pair<Pair, Pair> PairPoint; 

struct comp{  
	typedef pair<Pair, Pair> PairPoint; 
	bool operator () (const PairPoint & ls, const PairPoint &rs) {  
		return  true;                 //ls.first.first <= rs.first.first || ls.second.first <= rs.second.first; 
	}  
};  

list<int> List;//List存放获得价值
map<PairPoint, list<int>, comp> res; //res存放已经计算过的价值，避免重复计算
int i=0;
list<int>::iterator Liter;


//查找是否已经计算过
list<int> Find(map<PairPoint, list<int>, comp> res, PairPoint points){
	map<PairPoint, list<int>, comp>::iterator it = res.begin( ); 	
	while(it!=res.end() && it->first!=points)
		it++;
		
	if (it == res.end()){  
		//printf("NULL\n");
		return list<int>();		
	}else{    
		return it->second;
	}
}

list<int> Updateuv(int **graph,list<int> value,Pair u,Pair v){
	list<int> List = Find(res,make_pair(u,v));//List存放获得价值
	list<int>::iterator Litere;
	for(Litere = value.begin(); Litere != value.end(); Litere++){
		List.push_back(graph[u.first][u.second] + *Litere);
	}
	return List;
}




int main() {
	Pair u0,v;
	int M,N,k; int i=0;
	scanf("%d%d%d",&M,&N,&k);
	u0.first=0; u0.second=0;
	v.first=M-1; v.second=N-1;
	
	
	int  **graph = new int*[M];  //只有每行内是连续排列，各行并不一定连续排列 
	for( int i = 0; i < M; i++ ) 
		graph[i]   =   new   int[N]; 
	for ( int i = 0; i < M; i++ ) 
		for ( int j = 0; j < N; j++ ) 
			cin>>graph[i][j]; 	
	
	List.push_back(34543);
	List.push_back(34545);
	res[make_pair(u0,v)]=List;
	
	list<int> AList=Updateuv(graph,List,u0,v);
	cout<<AList.front();
	return 0;  
  
}  

























