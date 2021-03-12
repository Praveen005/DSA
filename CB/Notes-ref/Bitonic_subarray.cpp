
#include <bits/stdc++.h> 
using namespace std; 

int bitonic(int arr[], int n) 
{ 
	
	int inc[n]; 
	
	int dec[n]; 
	int i, max; 

	inc[0] = 1; 
	dec[n-1] = 1; 

	for (i = 1; i < n; i++) 
	inc[i] = (arr[i] >= arr[i-1])? inc[i-1] + 1: 1; 

	for (i = n-2; i >= 0; i--) 
	dec[i] = (arr[i] >= arr[i+1])? dec[i+1] + 1: 1; 

	max = inc[0] + dec[0] - 1; 
	for (i = 1; i < n; i++) 
		if (inc[i] + dec[i] - 1 > max) 
			max = inc[i] + dec[i] - 1; 

	return max; 
} 
int main() 
{ 
	
	int itr;
    cin>>itr;
    while(itr>0){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
    } 
	cout << bitonic(arr, n)<<endl; 
//	return 0; 
    itr--;
    }
} 


