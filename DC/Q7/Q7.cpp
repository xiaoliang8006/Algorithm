#include <iostream>
using namespace std;

int main()
{
	//input the length of the unsorted array A and the index k
    int n,k,i,j;
	
	while(cin >> n >> k){
		if(n<1||n>5000000||k<1||k>n){
			//cout<<"input error\n";
			return false;
		}
		
		//input the all elements in array A and split by spaces
		int arr[n];
		for(i=0;i<n;i++){
			cin>>arr[i];
			if(arr[i]>1000000000)
				return false;
		}
		
		//Find the kth largest element in array A
		//插入排序
		for(j=0;j<n;j++){
			int key = arr[j];
			i=j-1;
			while(i>=0 && arr[i]>key){
				arr[i+1]=arr[i];
				i--;
			}
			arr[i+1]=key;
		}
		
		cout<<arr[n-k]<<endl;
	}
}
