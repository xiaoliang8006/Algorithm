#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
using namespace std;

//计算距离
double distance(double x1,double y1,double x2,double y2){
	return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}

// 按坐标排序  采用插入排序
void SortXY(double x[],double y[],int start,int end){
	for(int j=start;j<=end;j++){
		double key1 = x[j];
		double key2 = y[j];
		int i=j-1;
		while(i>=0 && x[i]>key1){
			x[i+1]=x[i];
			y[i+1]=y[i];
			i--;
		}
		x[i+1]=key1;
		y[i+1]=key2;
	}
}

//分治计算最近距离
double CLOSESTPAIR(double x[],double y[],int l,int r,int N){
	if(r-l==1)
		return distance(x[l],y[l],x[r],y[r]);
	if(r-l==0)
		return 99999999;
	int m=(l+r)/2;
	double middle;
	if((l+r)/2.0!=m)
		middle=(x[m]+x[m+1])/2.0;
	else
		middle=x[m];
	double delta1=CLOSESTPAIR(x,y,l,m,N);
	double delta2=CLOSESTPAIR(x,y,m+1,r,N);
	double delta=min(delta1,delta2);
	
	int a,b;//带状区域下标界限
	bool flag=true;
	for(int t=l;t<r-l+1;t++){
		if(flag=true&&t==0&&x[t]>=middle-delta){ 
			a=t;
			flag=false;
		}
		else if(flag=true&&x[t-1]<middle-delta&&x[t]>=middle-delta){
			a=t;
			flag=false;
		}
		else if(t==r-l&&x[t]<=middle+delta) 
			b=t;
		else if(x[t]<=middle+delta&&x[t+1]>middle+delta)
			b=t;
	}
	SortXY(y,x,a,b);//对y排序
	
	for(int t=a;t<=m;t++){
		for(int k=m+1;k<=b;k++){
			double Dist;
			Dist=distance(x[t],y[t],x[k],y[k]);
			if(Dist<delta) delta=Dist;
		}
	}
	
	return delta;
	
}
	
int main()
{
	//input N: the total number of points.
    int N,i,j;

	scanf("%d",&N);
	if(N<2||N>100000)
		return false;
	//input the coordinates of every points
	double x[N],y[N];
	for(i=0;i<N;i++){
		scanf("%lf%lf",&x[i],&y[i]);
		if(x[i]>1000000000||y[i]>1000000000)
			return false;
	}
	
	//find the nearest two points, print the minimum distance
	SortXY(x,y,0,N-1);
	double minDist=CLOSESTPAIR(x,y,0,N-1,N);
	//cout<<"****************************"<<endl;
	//for(int i=0;i<N;i++)
	//	cout <<x[i]<<"  "<<y[i]<<endl;
	cout<<minDist<<endl;
		
		
	
}
