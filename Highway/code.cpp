#include <iostream>
#include <vector>
#include <iomanip>
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
    for(int j = i + 1;j < N;j++){ 
     float t = (team[i].start - team[j].start) / (team[i].MaxSpeed - team[j].MaxSpeed);
     float send = team[i].start + t * team[i].MaxSpeed;
     if(send >= team[i].end){
         time[i] = (team[i].end - team[i].start)/team[i].MaxSpeed;
     }
     else{
         
     }

   }
 }

 return 0;
}
