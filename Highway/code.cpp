#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
struct Car{
   float start;
   float end;
   float MaxSpeed;
   Car(float s,float e,float m):start(s),end(e),MaxSpeed(m){}
};
int main(){
 int N;
 cin>>N;
 vector<Car>team;
 for(int i = 0 ; i < N;i++){
     int s,e,m;
     cin>>s>>e>>m;
     Car tmp(s,e,m);
     team.push_back(tmp);
 }

 vector<float>time(N,0.0);
 time[0] = team[0].end - team[0].start / team[0].MaxSpeed;
 for(int i = 1; i < N;i++){
   
   float cur = team[i].start;
   //遍历在之前的所有车 
   for(int j = i - 1;j >= 0 && cur < team[j].end;j--){
     //计算第i辆车以最大速度行驶时,相遇点是否在第j辆车到达终点之前 
     float t =abs( (team[i].start - team[j].start) / (team[i].MaxSpeed - team[j].MaxSpeed));
     float send = team[j].start + t * team[j].MaxSpeed;
     //第i辆车可以以最大速度开往终点
     if(send >= team[j].end){
         time[i] = (team[i].end - team[i].start)/team[i].MaxSpeed;
         cur = team[i].end;
         break;
     }
     else{
       if(team[i].end >= team[j].end){       
         time[i] = time[j];
         cur = team[j].end;     
       }
       else{
         
       }
     }
   }

   if(team[i].end - cur){
       time[i] += (team[i].end -cur) / team[i].MaxSpeed;
   }
  
 }

   for(int k = 0; k < N;k++){
     cout<<fixed<<setprecision(2)<<time[k]<<endl;
   }

 return 0;
}
