#include <iostream>
using namespace std;

int main()
{
	//输入个数n
	int n,i,j;
    
	while(cin >> n ){
		//输入两个数据库
		int data1[n],data2[n];
		for(i=0;i<n;i++)
			cin>>data1[i];
		for(i=0;i<n;i++)
			cin>>data2[i];
	
		//连一起排序
		int allData[2*n];
		for(i=0;i<2*n;i++){
			j=i;
			if(i<n){
				allData[i] = data1[i];
				while(j>0&&(allData[j]<allData[j-1])){
					swap(allData[j],allData[j-1]);
					j--;
				}
			}else{
				allData[i] = data2[i-n];
				while(j>0&&(allData[j]<allData[j-1])){
					swap(allData[j],allData[j-1]);
					j--;
				}
			}
		
		}
		
		cout<<"answer: "<<allData[n-1]<<endl;
	}
}