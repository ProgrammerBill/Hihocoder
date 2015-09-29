#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int LPS_Dp(const string str);
int main(){
 int n;
 cin>>n;
 while(n--){
  string buffer;
  cin>>buffer;
  cout<<LPS_Dp(buffer)<<endl; 
 }
       
 return 0;
}

int LPS_Dp(const string str){
  int Tlen = str.size();
  bool Dp[Tlen][Tlen] = {0};
  memset(Dp,0,sizeof(Dp));
  for(int i = 0 ; i < Tlen;i++){
      Dp[i][i] = 1;
      if(i - 1 >= 0 && str[i] == str[i - 1])
	     Dp[i-1][i] = 1; 
  } 
  int maxlen = 1;
  int maxindex = 0;  
  string Palidromic = str;  
  for(int len = 2;len < Tlen;len++){
      for(int begin = 0;begin < Tlen - len;begin++){
          int end = begin + len;
	  int size = end - begin + 1;
	  if(str[begin] == str[end] && Dp[begin + 1][end - 1] == 1){
	      Dp[begin][end] = Dp[begin + 1][end - 1];
	      if(maxlen < size){
		  cout<<"here"<<endl;
	          maxlen = size;
		  maxindex = begin;
	          Palidromic = str.substr(begin,size);
	      } 
	  }
      } 
  }

   


  cout<<Palidromic<<endl;
  return maxlen;
}



