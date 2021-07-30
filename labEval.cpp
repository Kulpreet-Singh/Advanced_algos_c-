#include <iostream> 
using namespace std; 
  
  
// findMax function will return max element from an array of size n  
long findMax(long *arr, long n){
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if(arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

// maxIncreasingProduct function will return maximum product formed 
// by multiplying numbers of an increasing subsequence of the array
long maxIncreasingProduct(long *arr, long n) 
{ 
	// dp array which will store the product of
	// increasing elements upto that position
    long *dp = new long[n]; 
    
	// initially we store each element of the
	// array itself in the dp array
    for (int i = 0; i < n; i++) {
    	dp[i] = arr[i];
	}
	
	// we go through all the elements of the array considering 
	// them as the last element of the increasing subsequence
    for (int i = 1; i < n; i++) {
    	
    	// we check with all the previously computed increasing
		// subsequences and if multiplying the current element 
		// with the product of previously computed increasing 
		//subsequence yields a higher product, then we update 
		// the product of subsequence ending at current element 
		// as last element
    	for (int j = 0; j < i; j++) {
    		if (arr[i] > arr[j] && dp[i] < (dp[j] * arr[i])) {
    			dp[i] = dp[j] * arr[i]; 
			}
		}
	}    
	
	// we have highest product of all increasing subsequences
	// ending at each index in dp
	// now we just need to find the maximum out of it
    long ans = findMax(dp, n);
    delete[] dp;
    return ans;
} 
  
int main() 
{ 
    int n;
    long *arr;
    cin >> n;
    arr = new long[n];
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
	}
    cout << maxIncreasingProduct(arr, n) << endl; 
    delete[] arr;
	return 0; 
} 

/* 
INPUT
6
6 200 8 10 300 12
OUTPUT
360000
*/


