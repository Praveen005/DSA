#include <iostream> 
#include <string> 
#include <cstring>
using namespace std; 
 

int main() 
{ 
	
	char s2[]= "hello";
	char* s1 =s2;
	cout<<sizeof(s1)<<endl<<sizeof(s2)<<endl;                           


	return 0; 
} 



