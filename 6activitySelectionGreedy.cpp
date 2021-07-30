#include<bits/stdc++.h>
using namespace std;

struct activity{
	int st;
	int et;
};

bool comp(activity a1, activity a2){
	if(a1.et == a2.et){
		return a1.st < a2.st;
	}
	return a1.et < a2.et;
}

int selection(activity *arr, int n){
	int count = 1; // considering 0th activity is always included
	int i=0;
	cout<<"Activities taken are: \n";
	cout<<arr[0].st << " " << arr[0].et<<endl;
	for(int j=1; j<n;j++){
		if(arr[j].st >= arr[i].et){
			cout<<arr[j].st << " " << arr[j].et<<endl;
			count++;
			i = j;
		}
	}
	return count;
}

int main(){
	int n;
	cin>>n;
	activity* arr = new activity[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i].st>>arr[i].et;
	}
	sort(arr, arr+n, comp);
	
	int ans = selection(arr, n);
	cout<<"Total No. of activities selected are:"<<ans<<endl;
	
	delete[] arr; 
	return 0;
}
