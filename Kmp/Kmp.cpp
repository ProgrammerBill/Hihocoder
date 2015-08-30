#include <iostream>
#include <cstring>
using namespace std;

void GetNext(const char *P,int Next[]){
   int pLen = strlen(P);
   Next[0] = -1;
   int k = -1;
   int j = 0;
   while(j < pLen){
      if(k == -1 || P[j] == P[k]){
          ++k;
	  ++j;
          Next[j] = k;
      }
      else
	  k = Next[k];  
   } 
}

int KmpSearch(const char * T,const char *P){
    int i = 0;
    int j = 0;

    int TLen = strlen(T);
    int PLen = strlen(P);
    int Next[PLen];
    GetNext(P,Next);
    int count = 0 ;
    while(i < TLen ){
       if(j == -1 || T[i] == P[j]){
          ++i;
	  ++j;  
       }
       else
	  j = Next[j];

       if(j == PLen){
           count++;
       }
    }
    
    return count;    
}

int main(){
  int N;
  cin>>N;
  char Pattern[10001];
  char String[1000001];
  while(N--){
      cin>>Pattern;
      cin>>String; 
      cout<<KmpSearch(String,Pattern)<<endl;        
  }
  return 0;
}
