#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a[12]={2,4,1,23,5,76,0,43,24,65},i;
	for(i=0;i<12;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	sort(a,a+12);
	for(i=0;i<12;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
