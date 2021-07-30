#include<bits/stdc++.h>
using namespace std;

int calcWeight(int wt[], int* x, int n){
	int sum = 0;
	for(int i=0;i<n;i++){
		if(x[i] == 1){
			sum += wt[i];
		}		
	}
	return sum;
}

int calcProfit(int val[], int* x, int n){
	int sum = 0;
	for(int i=0;i<n;i++){
		if(x[i] == 1){
			sum += val[i];
		}		
	}
	return sum;
}


void knapSackRec(int W, int wt[], int val[], int i, int n, int* x, int &ans) 
{ 
	if(calcWeight(wt, x, n) > W){
		return;
	}
	if (i == n) {
		if(calcWeight(wt, x, n) <= W){
			int temp = calcProfit(val, x, n);
			cout<<"A feasible solution is: \n";
			for(int i=0;i<n;i++){
				cout<<x[i]<<" ";
			}
			cout<<endl<<"Profit: "<<temp<<endl<<endl;
			if(temp>ans){
				ans = temp;
			}
		}
		return;
	}

	x[i] = 1;
	knapSackRec(W, wt, val, i+1, n, x, ans); 
	x[i] = 0;
	knapSackRec(W, wt, val, i+1, n, x, ans);
}
 

int knapSack(int W, int wt[], int val[], int n) 
{
	int* x; 
	x = new int[n]; 
	for(int i=0;i<n;i++){
		x[i] = 0;
	}
	int ans = INT_MIN;
	knapSackRec(W, wt, val, 0, n, x, ans); 
	return ans;
}
 
int main() 
{ 
	int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50;  
	int n = sizeof(val) / sizeof(val[0]); 
	cout << knapSack(W, wt, val, n); 
	return 0; 
}  
