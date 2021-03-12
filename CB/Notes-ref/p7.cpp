#include<iostream> 
using namespace std; 
int main(){ 
	int k,c1,c2,c3,c4,n,m,i,a1,p1,p2,sum1,sum2,p4,l1,b1,l2,fare,finalfare,l4; 
	cin>>k; 
//	while(c1>=1 && c1<=1000 && c2>=1 && c2<=1000 && c3>=1 && c3<=1000 && c4>=1 && c4<=1000 && n>=1 && n<=1000 && m>=1 && m<=1000 ){ 
	for(i=0 ; i<k ; i++){ 
		cin>>c1>>c2>>c3>>c4>>n>>m; 
		sum1=0,sum2=0; 
		while(n>0){ 
			cin>>a1; 
			p1=a1*c1; 
			if(p1<c2){ 

				p2=p1; 

			} 
		
		else{ 
			p2=c2; 
		} 
		sum1=sum1+p2; 
			n--;
	} 
	if(sum1<c3){ 
		p4=sum1; 
	} 
	else{ 
		p4=c3; 
	}
	while(m>0){ 
		cin>>b1; 
		l1=b1*c1; 
		if(l1<c2){ 
		l2=l1;
		} 
	 
		else{ 
			l2=c2; 
		} 
		sum2=sum2+l2; 
		m--;
	} 

	if(sum2<c3){ 
		l4=sum2; 
	} 
	else{ 
		l4=c3; 
	}
	fare=l4+p4; 
	if(fare<c4){ 
		finalfare=fare; 
	} 
	else{ 
		finalfare=c4; 
	} 
	cout<<finalfare<<endl; 
} 
}
