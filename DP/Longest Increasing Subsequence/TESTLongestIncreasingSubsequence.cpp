#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string>
using namespace std;

int longest_increasing_subsequence(int nums[],int N){
    int dp[N];
    int update_from[N];
    for (int i = 0; i < N; i ++){
        dp[i] = 1;
        update_from[i]=-1;
    }
    int lis_len=1;
    int index = 0;
    for(int i=0;i<N;i++){
        for(int j=i-1;j>-1;j--){
            if(nums[j]<nums[i] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                update_from[i] = j;
            }
        }
        if(dp[i] > lis_len){
             lis_len= dp[i];
              index =i;
        }

    }

    int ans[lis_len];
    int k=0;
    while (index != -1){
        ans[k++] = nums[index];
        index = update_from[index];
    }

    return lis_len;
}



bool isDigit(char a) {
	if (a - '0' == 0 || a - '0' == 1 || a - '0' == 2 || a - '0' == 3 ||
		a - '0' == 4 || a - '0' == 5 || a - '0' == 6 || a - '0' == 7 ||
		a - '0' == 8 || a - '0' == 9)
		return true;
 
	return false;
}
 
bool isInteger(string y) {
	for (int i = 0; i<y.length();i++)//字符串内容是否为整数
		if (!isDigit(y[i])) {
		    return false;
		}
	return true;	
	
}



int main() {
    //T组
	int k=0;
	int T;
	string TS;
	cin>>TS;
	if(isInteger(TS)){
		T = atoi(TS.c_str());
	}else
		return false;
	if(T<1||T>100000)
		return false;
	
	int answer[T];
	//读入每一组数
	while (k < T) {
		int N;
		string NS;
		cin>>NS;
		if(isInteger(NS)){
			N = atoi(NS.c_str());
		}else
			return false;
		if(N<1||N>100000)
			return false;
		
		int arr[N];		
		for (int i = 0; i < N; i++) {
			string arrS;
			cin>>arrS;
			if(isInteger(arrS)){
				arr[i] = atoi(arrS.c_str());
			}else
				return false;
			if(arr[i]<0||arr[i]>1000000)
				return false;
		}
        answer[k]=longest_increasing_subsequence(arr,N);
		k++;
	}
	//输出结果
    for(int i=0;i<T;i++)
        printf("%d\n", answer[i]);
	return 0;
}





