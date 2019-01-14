#include <iostream>
#include<vector>
#include <utility>
#include <cstdlib>
#include<cstdio>
#include <list>
#include <map>  
using namespace std;

typedef pair<int, int> Pair;
typedef pair<Pair, Pair> PairPoint;

struct comp{  
	typedef pair<Pair, Pair> PairPoint; 
	bool operator () (const PairPoint & ls, const PairPoint &rs) {  
		return  true; 
	}  
}; 

map<PairPoint, list<int>, comp> res; //res存放已经计算过的价值，避免重复计算

Pair u0,v;//图中的点 
list<int> List;//记录


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


//查找从u到v的一条路径
list<int> Findway(int **graph, int M,int N,Pair u,Pair v){
    
	list<int> Uvalue = Find(res,make_pair(u,v));
	if(!Uvalue.empty()){
		return Uvalue;
		cout<<"haha1";
	}
	
	if(u==v){
		list<int> List;//记录
		List.push_back(graph[M-1][N-1]);
		res[make_pair(u,v)]=List;
		return List;		
	}
	
	list<int> value;
	//往下走
	if(u.first+1<M){			
		Pair t;
		t.first=u.first+1; t.second=u.second;
		value = Findway(graph, M, N, t, v);
		Uvalue = Updateuv(graph,value,u,v);
		res[make_pair(u,v)] = Uvalue;
	}
			
	//往右走
	if(u.second+1<N){
		Pair t;
		t.first=u.first; t.second=u.second+1;
		value = Findway(graph, M, N, t, v);
		Uvalue = Updateuv(graph,value,u,v);
		res[make_pair(u,v)] = Uvalue;
	}
	
	return Uvalue;

}//Findway   


//测试
int main() {
	int M,N,k; int i=0;
	scanf("%d%d%d",&M,&N,&k);
	u0.first=0; u0.second=0;
	v.first=M-1; v.second=N-1;
	List.push_back(12345);
	List.push_back(12346);
	
	int  **graph = new int*[M];  //只有每行内是连续排列，各行并不一定连续排列 
	for( int i = 0; i < M; i++ ) 
		graph[i]   =   new   int[N]; 
	for ( int i = 0; i < M; i++ ) 
		for ( int j = 0; j < N; j++ ) 
			cin>>graph[i][j]; 
	
	//调用函数
	Findway(graph,M,N,u0,v);
	
	//输出结果
	map<PairPoint, list<int>, comp>::iterator iter=res.begin(); 
	list<int>::iterator Liter;
	for ( ;iter != res.end(); iter++){
		printf("%d %d %d %d $$", iter->first.first.first, iter->first.first.second, iter->first.second.first, iter->first.second.second);  
		for(Liter = iter->second.begin();Liter!=iter->second.end(); Liter++)
			cout<<*Liter<<"  ";
		cout<<endl;
	}
	
	cout<<res.size()<<"********\n";
	//while(iter!=res.end() && iter->first != make_pair(v,v))
	//	iter++;
	///if (iter == res.end()){  
	//	printf("NULL\n");
	//	return 0;
	//}	
	printf("wawawaawa\n");
	//for(Liter = iter->second.begin(),i=0; i<k-1; Liter++,i++)	
	//for(Liter = iter->second.begin();Liter!=iter->second.end(); Liter++)
	//	cout<<*Liter<<" ";
	//cout<<*Liter;

}



	