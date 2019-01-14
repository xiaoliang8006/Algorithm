#include <iostream>
using namespace std;

void ISort(int A[],int n){
	for(int j=0;j<n;j++){
		int key = A[j];
		int i=j-1;
		while(i>=0 && A[i]<key){
			A[i+1]=A[i];
			i--;
		}
		A[i+1]=key;
	}
}

int SELECT(int A[],int n,int k){
	//int n=0;
	//while(A[n]>0) n++;
	int pivot = A[n/2];
	int Splus[n+1];
	int Sminus[n+1];
	int a=0;//Splus下标
	int b=0;//Sminus下标
	for(int j=0;j<n;j++){
		if(A[j]>=pivot){
			Splus[a++]=A[j];
		}
		else if(A[j]<pivot)
			Sminus[b++]=A[j];
	}
	if(b==0){
		ISort(Splus,a);
		return Splus[k-1];
	}
	if(a==k)
		return pivot;
	else if(a<k)
		return SELECT(Sminus,b,k-a);
	else
		return SELECT(Splus,a,k);
}

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
		int answer= SELECT(arr,n,k);

		cout<<answer<<endl;
	}
}
