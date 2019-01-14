#include <iostream>
#include <stdio.h>
using namespace std;

void MERGE(int A[],int l,int m,int r){
	//Merge A[l..m] and A[m+1..r]
	int L[m-l+1];
	int R[r-m];
	int i=0;
	int j=0;
	for(int k=l;k<=r;k++){
		if(k<=m)
			L[i++]=A[k];
		else
			R[j++]=A[k];
	}

	i=0;j=0;
	for(int k=l;k<=r;k++){
		if(j==r-m)
			A[k]=L[i++];
		else if(i==m-l+1)
			A[k]=R[j++];
		else if(L[i]<=R[j])
			A[k]=L[i++];
		else if(L[i]>R[j])
			A[k]=R[j++];
	}
}

void MERGESORT(int A[],int l,int r){
	//Sort elements in A[l,...,r]
	if(l<r){
		int m=(l+r)/2;//middle point
		MERGESORT(A,l,m);
		MERGESORT(A,m+1,r);
		MERGE(A,l,m,r);//Combing
	}
}


int main()
{
	//input the length of the unsorted array A and the index k
    int n,k,i,j;
	
		scanf("%d%d",&n,&k);
		if(n<1||n>5000000||k<1||k>n){
			//cout<<"input error\n";
			return false;
		}
		
		//input the all elements in array A and split by spaces
		int arr[n];
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
			if(arr[i]>1000000000)
				return false;
		}
		
		//Find the kth largest element in array A
		//归并排序
		MERGESORT(arr,0,n-1);
		
		//for(i=0;i<n;i++)
		//	cout<<arr[i]<<" ";
		cout<<arr[n-k]<<endl;
	
}
