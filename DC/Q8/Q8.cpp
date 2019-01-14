#include <iostream>
#include "stdlib.h"
#include "math.h"
using namespace std;

double distance(double x1,double y1,double x2,double y2){
	return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}
	
int main()
{
	//input N: the total number of points.
    int N,i,j;
	
	while(cin >> N){
		if(N<2||N>100000)
			return false;
		//input the coordinates of every points
		double x[N],y[N];
		for(i=0;i<N;i++){
			cin>>x[i]>>y[i];
			if(x[i]>1000000000||y[i]>1000000000)
				return false;
		}
	
		
		//find the nearest two points, print the minimum distance
		double minDist = 1000000.0;
		for(i=1;i<N;i++){
			for(j=0;j<i;j++){
				double distXY = distance(x[i],y[i],x[j],y[j]);
				if(distXY < minDist)
					minDist = distXY;
			}
		}
		
		cout<<"minimum distance: "<<minDist<<endl;
	}
}
