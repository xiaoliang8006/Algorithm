#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
 

int main()
{
	int flag = 0;
	int time = -1;//总时间
	int temp=0;
	char c;
	vector<int> monkey;
	vector<int> banana;
	
	//输入monkey数组
	cin>>temp;
	monkey.push_back(temp);
	while ((c=getchar()) != '\n'){
		cin>>temp;
		monkey.push_back(temp);
	}
	//输入banana数组
	cin>>temp;
	banana.push_back(temp);
	while ((c=getchar()) != '\n'){
		cin>>temp;
		banana.push_back(temp);
	}
	
	if(banana.size()!=monkey.size())
		return 0;
	//排序
	sort(monkey.begin(), monkey.end());
	sort(banana.begin(), banana.end());
	
	//开始处理
	while(flag!=monkey.size()){
		flag=0;
		time++;
		for(int i=0;i<monkey.size();i++){
			if(monkey[i]<banana[i])
				monkey[i]++;
			else if(monkey[i]>banana[i])
				monkey[i]--;
			else
				flag++;
		}
		
	}
	
	//cout<<"Time is "<<time<<" !\n";
	cout<<time;
	
}