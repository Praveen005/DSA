#include<iostream>
using namespace std;
int main(){
	long long int a,b=0,r=1,c,i=2000;
	cin>>a;
	//b=a;
	while(i>0){
		b++;
		c= a*a+b*b;
		
		while (r*r<=c){
			r++;
		}

		if(c%(r-1)==0 && c/(r-1)==(r-1) && a+b >r && a+r >b && b+r > a && b<a && r<a){
			if(b< r-1){
				cout<<b<<" "<< r-1;
			}
			else cout<< r-1<<" "<<b;
			break;
		}


		i--;
	}

	if(c % (r-1) !=0 || c/(r-1) != (r-1) || a+b <=r || a+r <=b || b+r <=a || b>a || r >a) cout<<"-1"<<endl;
}
