#include<iostream>
using namespace std;
int main(){
	int repeat;
	cin>>repeat;
	int c1,c2,c3,c4,n,m;
	for(int i=0; i<repeat; i++){
		
		cin>>c1>>c2>>c3>>c4>>n>>m;
		while(c1>0 && c1<=1000 && c2>0 && c2<=1000 && c3>0 && c3<=1000 && c4>0 && c4<=1000 && n>0 && n<=1000 && m>0 && m<=1000 ){

			int sum1=0,cost1, cost2=0;
			int rick[n]={0};
			for(int i=0; i<n; i++){
				cin>>rick[i];
				cost1= min((c1*rick[i]), c2);
				cost2=cost2+cost1;

			}
			sum1= min(c3, cost2);


			int sum2=0,cost21, cost3=0;
			int cab[m]={0};
			for(int i=0; i<m; i++){
				cin>>cab[i];
				cost21= min(c1*cab[i], c2);
				cost3=cost3+cost21;

			}
			sum2= min(c3, cost3);
			int totalcost= sum1+sum2;

			int finalcost= min(c4, totalcost);
			cout<<"min fare = "<<finalcost<<endl;



		
			break;
		}
	}
}