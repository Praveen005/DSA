#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	int c1,c2,c3,c4,n,m;
	while(t--){
		cin>>c1>>c2>>c3>>c4;
		cin>>n>>m;
		int rick[n],cab[m];
		
		//elements of these arrays represent no of times i th rickshaw/cab will we repeated 

		//i.e. if rick[0]=4 means Ramu will ride 0th rickshaw 4 times
		int scost1=0;
		for(int i=0; i<n; i++){
			cin>>rick[i];
			int cost1= min(rick[i]*c1 , c2);
			scost1=scost1+cost1;
    //        cout<<"rick["<<i<<"] = "<<rick[i]<<"\t"<<"cost1= "<<cost1<<"\t"<<"scost1= "<<scost1<<endl;
		}
		int rickcost=min(c3 , scost1);
    //    cout<<"rickshaw cost = "<<rickcost<<endl;

		int scost2=0;
		for(int i=0; i<m; i++){
			cin>>cab[i];
			int cost1=min(cab[i]*c1 , c2);
			scost2=scost2+cost1;
     //        cout<<"cab["<<i<<"] = "<<cab[i]<<"\t"<<"cost1= "<<cost1<<"\t"<<"scost2= "<<scost2<<endl;

		}
		int cabcost=min(c3, scost2);
	//	cout<<endl<<"cab cost= "<<cabcost<<endl;

		int finalcost=min(c4, (cabcost+rickcost));
		cout<<finalcost<<endl;

	}
}