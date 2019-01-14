#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	double *s = new double[5];
	double *t = new double[5];
	for(int i = 0; i < 5; i++){
		scanf("%lf %lf", &s[i], &t[i]);
	}

	double left = 0, right = 24;
	while (abs(right - left)>1e-5){
		double mid = (left + right)/2;
		double st = s[0];

		for(int i = 1; i<5;i++){
			st = st + mid;
			if(st > t[i]){
				right = mid;
				break;
			}else {
				if(i < 4) {
					st = max(st,s[i]);
				}else{
					left = mid;
				}
			} 
		}
	}

	printf("%.2f", s[0]);
	double st = s[0];
	double mid = (left + right)/2;
	for(int i=1; i<5; i++){
		st = max(st + mid, s[i]);
		printf(" %.2f", (st + 0.0005) * 1000 / 1000);
	}
} 