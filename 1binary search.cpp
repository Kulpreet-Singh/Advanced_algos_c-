#include<bits/stdc++.h>
using namespace std;
//recursive
bool binarySearch(int a[],int ele, int beg, int end){
	if(beg>end){
		return false;
	}
	int mid = (beg + end)/2;
	if(a[mid] == ele){
		return true;
	}
	else if(a[mid] < ele){
		return binarySearch(a,ele,mid+1,end);
	}
	else{
		return binarySearch(a,ele,beg,mid-1);
	}
}

int main(){
	int a[] = {1,4,7,9,13,17 };
	int beg = 0;
	int end = 5;
	
	int ele;
	cout<<"enter the element to be searched: ";
	cin>>ele;
	cout<<binarySearch(a,ele,beg,end)<<endl;
	//iterative
	while(beg<=end){
		int mid =  (beg + end)/2;
		if(a[mid] == ele){
			cout<<"found"<<endl;
			break;
		}   
		else if(a[mid] < ele){
			beg = mid+1;
		}
		else{
			end = mid -1;
		}
	}
	if(beg>end){
		cout<<"Not Found"<<endl;
	}
}
