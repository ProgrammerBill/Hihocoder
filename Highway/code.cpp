#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int CMP(double a,double b){
    return a >= b;
}
int main(){
 int N;
 cin>>N;
 vector<double>Begin;
 vector<double>End;
 map<double,double>BeginToEnd;
 map<double,double>BeginToSpeed;
 map<double,int>BeginToIndex;
 for(int i = 0 ; i < N;i++){
   double b,e,s;
   cin>>b>>e>>s;
   Begin.push_back(b);
   End.push_back(e);
   BeginToEnd.insert(make_pair(b,e));
   BeginToSpeed.insert(make_pair(b,s));
   BeginToIndex.insert(make_pair(b,i));
 } 
 vector<double>TimeTable(N,0.0);
 vector<double>Ans(N,0.0);
 sort(Begin.begin(),Begin.end(),CMP);
 sort(End.begin(),End.end());
 
 for(int i = 0; i < N;i++){
     double t = 0;
     double cur = Begin[i];
     for(int j = 0;j < N;j++){
         if(Begin[i] < End[j]){
             t += (End[j] - cur) / BeginToSpeed[Begin[i]];
             t = max(t,TimeTable[j]);
             TimeTable[j] = t;
             cur = End[j]; 
             if(BeginToEnd[Begin[i]] == End[j]){
                 Ans[BeginToIndex[Begin[i]]] = t;
                 break;
             }
         }    
     }
 } 

 
 for(int i = 0; i < N;i++)
     cout<<fixed<<setprecision(2)<<Ans[i]<<endl;
 return 0;
}
