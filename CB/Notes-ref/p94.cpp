//matrix search problem
//staircase search


#include<bits/stdc++.h>
using namespace std; 
int search(int a[][1000] , int n,int m,int key){
    if(key>a[n-1][m-1]){
        return 0;
    }
	int start;
	// block 1
	//since the elements in array are in increasing order
	//so we are only considering those corner elements
	//jinke ek taraf elements decrease kar rahe hain 
	//aur dusri taraf badh rahe hain
	//wo iss liye kyun ki agar ham dusra cornor element agar consider karte hain to usme 
	//ye pata nahi ki kis side move karen
	//kyun ki ya to dono taraf value increase kar raha ya decrease kar raha
	//yahan m- colums hai aur n rows

	// agr phir bhi samajh nahi aaya to staircase waala video dekho

	if(abs( a[n-1][0]-key ) < abs(a[0][m-1]-key) ) {
		start=a[n-1][0];
	}
	else{
		start=a[0][m-1];
	}
	int i=n-1 , j=m-1,k=0, l=0;
	//n rows  m columns


	//n rows  m columns

	//block 2
	//start bar bar update hota rahega , tab tak jab tak key na mil jaaye
	//key mil gaya to 1 return kar denge   warna  0

	while(start != key){
				// ye if condition iss liye kyun ki i--  ke wajah se limit se bahar chala ja raha tha value
		//aur jab uss i pe array ka koi value na hone ki wajah se  segmentation error de raha tha

		if(i<0 || k>n-1){
			return 0;
		}
		if(start==a[i][k]){
			if(a[i][k]>key){
				if(a[i-1][k]<a[i][k]){
					start=a[i-1][k];
					i--;

				}
				else{
					start =a[i][k+1];
					k++;
				}
			}
	
			else if(a[i][k]<key){
				if(a[i-1][k]>a[i][k]){
					start=a[i-1][k];
					i--;
				}
				else{
					start =a[i][k+1];
					k++;
				}
			}
		}
	//	l=0,j=m-1;
		else if(start==a[l][j]){
			if(l>m-1 || j <0){
				return 0;
			}
			if(a[l][j]>key){
				if(a[l][j-1]<a[l][j]){
					start=a[l][j-1];
					j--;
				}
				else{
					start =a[l+1][j];
					l++;
				}
			}
	
			if(a[l][j]<key){
				if(a[l][j-1]>a[l][j]){
					start=a[l][j-1];
					j--;
				}
				else{
					start =a[l+1][j];
					l++;
				}
			}
	
		}

	}
  //  cout<<start<<endl;
//	cout<<i<<" "<<k<<endl;
//	return start;
	if(start==key){
		return 1;
	}
	else{
		return 0;
	}

}
int main(){
	int n,m;
	cin>>n>>m;
	int val=1;
	int a[1000][1000];
	for(int row =0; row<n; row++){
		for(int col=0; col<m; col++){
			cin>>a[row][col];
			// a[row][col]=val;
			// val++;
			
		}
	}

	// for(int row =0; row<n; row++){
	// 	for(int col=0; col<n; col++){
	// 		cout<<a[row][col]<<" ";
			
	// 	}
	// 	cout<<endl;
	// }

//	cout<<endl<<endl<<endl;
	int key;
	cin>>key;
	int x= search(a,n,m,key);
	cout<<x<<endl;
}
