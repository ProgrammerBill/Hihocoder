#include<iostream>
#include<string>
using namespace std;
int Elimate(string str,string &);
int main(){
 int N;
 cin>>N;
 string tmp;
 while(N--){
     cin>>tmp;
     int max = 0;
     int record;
     for(size_t i = 0 ; i < tmp.size();i++){
         string buf = tmp;
	 buf.insert(i,1,tmp[i]);
	 string ans;
	 record = 0; 
	 int count;
	 while(count = Elimate(buf,ans)){
	     record += count; 
             buf = ans;
	     ans = ""; 
	 }
	 if(record > max)
		 max = record;

     }
     cout<<max<<endl;
     }
 return 0;
}

int Elimate(string str,string & ans){
     if(str.empty()) {
         ans = "";
	 return 0;
     }	     
     int len = str.size();
     int head,last;
     head = 1;
     last = 0;
     while(str[head] != '\0'){
         if(str[head] != str[last]){
	     head++;
	     last++;
	 }
	 else{
	    while(str[head] == str[last])
		    head++;
            str.erase(last,head - last);
	    if(str[last] != '\0'){
	       if(str[last + 1] != '\0'){
	           head = last + 1;
	       }
	       else
		 break;
	    }
	    else
		 break;
	 } 
     }
     ans = str;
     return len - str.size();     
}


