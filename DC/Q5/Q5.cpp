#include <iostream>
using namespace std;


int main()
{
	//输入长度n
    int n,i,j;
	
	
	while(cin >> n ){
		//输入序列an
		int a[n];
		int num=0;//计数器
		for(i=0;i<n;i++)
			cin>>a[i];
		
		//查找significant inversion
		for(i=0;i<n;i++){
			j=i+1;
			while(j<n){
				if( a[i] > 3*a[j]){
					cout<<"significant inversion of a: "<<a[i]<<endl;
					num++;
					break;
				}
				j++;
			}
		}
		
		cout<<"total number: "<<num<<endl;
		
	}
}