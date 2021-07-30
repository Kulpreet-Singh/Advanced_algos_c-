#include<bits/stdc++.h>
using namespace std;

struct job{
	int val; // profit
	int d; // deadline
	int index; 
};

bool comp(job a1, job a2){
	if(a1.val == a2.val){
		return a1.d  > a2.d;
	}
	return a1.val > a2.val;
}

int maxD(job *arr, int n){
	int max = INT_MIN;
	for(int i=0;i<n;i++){
		if(arr[i].d > max){
			max = arr[i].d;
		}
	}
	return max;
}

int maxProfit(job* arr, int n){
	int m = maxD(arr, n);
	int *sequence = new int[m+1];
	for(int i=0;i<=m;i++){
		sequence[i] = -1;
	}
	for(int i=0;i<n;i++){
		int j = arr[i].d;
		while(j>0){
			if( sequence[j] == -1 ){
				break;
			}
			j--;
		}
		if(j>0){
			sequence[j] = i;
		}
	}
	int ans = 0;
	for(int i=0; i<=m;i++){
		if(sequence[i]!=-1){
			ans+=arr[sequence[i]].val;
		}
	}
	cout<<"Sequence of jobs is: "<<endl;
	for(int i=0;i<=m;i++){
		if(sequence[i] != -1){
			cout<<arr[sequence[i]].index<<" ";
		}
	}
	cout<<endl;
	
	return ans;
}

int main(){
	int n;
	cin>>n;
	job* arr = new job[n];
	
	for(int i = 0; i<n; i++){
		cin>>arr[i].val>>arr[i].d;
		arr[i].index = i;
	}
	sort(arr, arr+n, comp);
	
	int ans = maxProfit(arr, n);
	cout<<"Maximum Profit is: "<<ans<<endl;
	
	delete[] arr;
	return 0;
}

/*
4
20 4
10 1
40 1
30 1
*/

