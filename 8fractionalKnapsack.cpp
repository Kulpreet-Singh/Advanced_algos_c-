#include<bits/stdc++.h>
using namespace std;

struct node{
	int w;
	int val;
	int index;
};

bool comp(node a, node b){
	if((float)a.val/a.w > (float)b.val/b.w){
		return true;
	}
	return false;
}

int fractionalKnapsack(node* arr, int n, int maxW){
	int i=0;
	int profit = 0;
	while(maxW>0 && i<n){
		if(arr[i].w<=maxW){
			profit+=arr[i].val;
			maxW -= arr[i].w;
		}
		else{
			profit+=((float)arr[i].val/arr[i].w)*maxW;
			maxW = 0;
		}
		i++;
	}
	return profit;
}

int main(){
	int n;
	cin>>n;
	int maxW;
	cin>>maxW;
	
	node *arr = new node[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].val>>arr[i].w;
		arr[i].index = i;
	}
	sort(arr, arr+n, comp);
	
	int ans = fractionalKnapsack(arr, n, maxW);
	
	cout<<"Maximum Profit is: "<<ans<<endl;
	return 0;
}

/*
3 50
60 10
100 20
120 30
*/
