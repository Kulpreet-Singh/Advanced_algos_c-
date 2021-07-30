#include<bits/stdc++.h>
using namespace std;

int f(int n, int num){
	if(n==0){
		return num;
	}
	int sum = 0;
	while(num){
		sum+=num%10;
		num = num/10;
	}
	return f(n-1,sum*sum);
}

int main(){
	cout<<f(1988,11);
}
