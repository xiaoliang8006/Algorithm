#include <iostream>
#include <algorithm>
using namespace std;
 

class Solution{
public:
	int numRescueBoats(int people[], int n, int limit){
		sort(people,people+n);
		int ans=0;
		int p=0;
		int q=n-1;

		while(p<=q){
			ans++;
			if(people[p]+people[q]<=limit)
				p++;
			q--;
		}
		return ans;
	}
};

int main()
{
	int n,limit;
	cin>>n>>limit;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	Solution solution;
	int num = solution.numRescueBoats(arr,n,limit);
	cout<<num;
}
