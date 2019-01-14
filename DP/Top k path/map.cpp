#include <iostream>
#include <map>  
using namespace std;
typedef pair<int, int> Pair;
typedef pair<Pair, Pair> PairPoint; 

struct comp{  
	typedef pair<Pair, Pair> PairPoint; 
	bool operator () (const PairPoint & ls, const PairPoint &rs) {  
		return  true;                 //ls.first.first <= rs.first.first || ls.second.first <= rs.second.first; 
	}  
};  

int Find(map<PairPoint, int, comp> res, PairPoint points){
	map<PairPoint, int, comp>::iterator iter = res.begin( ); 	
	while(iter!=res.end() && iter->first!=points)
		iter++;
		
	if (iter == res.end()){  
		printf("NULL\n");
		return 0;		
	}else{  
		printf("$$$%d %d %d %d %d \n", iter->first.first.first, iter->first.first.second, iter->first.second.first, iter->first.second.second,iter->second);  
		return iter->second;
	}
}
      
int main(){  
    
	map<PairPoint, int, comp> res;  
	Pair p1,p2,p3,p4,p5;
	p1.first=10; p1.second=20;
	p2.first=30; p2.second=40;
	p3.first=50; p3.second=60;
	p4.first=70; p4.second=80;
	p5.first=10; p5.second=20;

	res.insert(make_pair(make_pair(p1,p2), 644));  
	res.insert(make_pair(make_pair(p1,p3), 234));  
	res.insert(make_pair(make_pair(p2,p3), 975)); 
	res[make_pair(p2,p4)] = 356; 
	res.insert(make_pair(make_pair(p1,p5), 987)); 
	
	map<PairPoint, int, comp>::iterator iter;
	for ( iter = res.begin( ); iter != res.end( ); iter++ )
		printf("%d %d %d %d %d \n", iter->first.first.first, iter->first.first.second, iter->first.second.first, iter->first.second.second,iter->second);  
	
	int has = Find(res,make_pair(p1,p5));
	if(val != 0)
		
	
	return 0;  
  
}  
