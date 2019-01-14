#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main(){
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

	cout<<"monkey: ";
	for(int i=0;i<monkey.size();i++){
		cout<<monkey[i]<<" ";
	}
	cout<<"banana: ";
	for(int i=0;i<banana.size();i++){
		cout<<banana[i]<<" ";
	}
}
