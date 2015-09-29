#include<iostream>
#include<string>
#include<map>
using namespace std;
typedef multimap<char,int>::iterator it;

int main(){
 int N;
 cin>>N;
 while(N--){
   string s1,s2,s3;
   cin>>s1>>s2>>s3;
   multimap<char,int>Seq;
   map<char,int>Num; 
    
   for(size_t i = 0; i < s3.size();i++){
        Seq.insert(make_pair(s3[i],i)); 
   } 

   for(size_t i = 0 ; i < s1.size();i++)
	Num[s1[i]]++;
   for(size_t i = 0; i < s2.size();i++)
	Num[s2[i]]++;
   /*
   map<char,int>::iterator itr = Num.begin();
   for(;itr != Num.end(); itr++){
       cout<<itr->first<<" "<<itr->second<<" ";
   }
   */
   bool flag1 = false;
   bool flag2 = false;
   for(size_t i = 0 ; i < s1.size() - 1;i++){
          it pre = Seq.lower_bound(s1[i]);
          it cur = Seq.lower_bound(s1[i + 1]); 
           while(cur != Seq.upper_bound(s1[i + 1])){
		if(pre->second < cur->second){
		    flag1 = true;
		    break;   
		}
	        else
		    flag1 = false;	
	        ++cur;	
	  }
   }
   cout<<"flag1 = "<<flag1<<endl;

 }

 return 0;
}
