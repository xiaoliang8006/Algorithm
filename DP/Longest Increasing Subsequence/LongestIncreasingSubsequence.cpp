#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
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



int main() {
    //T组
	int T;
	int k=0;
	scanf("%d", &T);
	int answer[T];
	//读入每一组数
	while (k < T) {
		int N;
		scanf("%d", &N);
		int arr[N];
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}
        answer[k]=longest_increasing_subsequence(arr,N);
		k++;
	}
	//输出结果
    for(int i=0;i<T;i++)
        printf("%d\n", answer[i]);
	return 0;
}





