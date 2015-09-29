#include<iostream>
#include<vector>
using namespace std;
int main(){
 int N;
 cin>>N;
 vector<int> Price;
 for(int i = 0;i < N;i++){
    int tmp;
    cin>>tmp;
    Price.push_back(tmp); 
 } 
 int max1 = 0;
 int max2 = 0;
 int max = 0;
 for(int i = 2 ; i < N - 1;i++){
   max1 = 0;
   max2 = 0;  
   if(Price[i] > Price[i - 1])
	  continue; 
   for(int k = 0; k < i - 1;k++){
       int head = Price[k];
       for(int j = k + 1; j < i ;j++){
          int tmp = Price[j];
	  if(tmp > head && tmp - head > max1){
		  max1 = tmp - head; 
	  }	 
       } 
   }
   for(int n = i; n < N - 1;n++){
       int head = Price[n];
       for(int j = n + 1; j < N;j++){
            int tmp = Price[j];
	    if(tmp > head && tmp - head > max2){
		   max2 = tmp - head;
            }		   
       } 
   }
   if(max1 + max2 > max)
	   max = max1 + max2;
 }
 cout<<max<<endl; 
 return 0;
}
