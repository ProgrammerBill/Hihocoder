#include<iostream>
#include<string>
using namespace std;
int Eliminate(string str);
int main(){
 int N;
 cin>>N;
 string str;
 while(N--){
     cin>>str;
     int max = 0;
     int len = str.size();
     int t;
     for(int i = 0 ; i < len; i++){
         string tmp = str;
	 tmp.insert(i,"A");
         if((t = Eliminate(tmp)) > max)
		 max = t;
	 tmp = str;
	 tmp.insert(i,"B");
	 if((t = Eliminate(tmp)) > max)
		 max = t;
	 tmp = str;
	 tmp.insert(i,"C");
	 if((t = Eliminate(tmp)) > max)
		 max = t;
     }
     cout<<max<<endl;
 } 
 return 0;
}

int Eliminate(string str){
     if(str.empty()) return 0;
     int len = str.size();
     string t;
     int tlen;
     int head = 0;
     str += '$';
     for(int i = 1 ; i < len + 1;i++){
         if(str[i] != str[i - 1]){
	     if(head == i - 1)
		 t += str[i - 1];
	     head = i;    
	 }	
     } 
     if((tlen = t.size()) == len) return 0;
     return len - tlen + Eliminate(t);

}
