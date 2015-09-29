#include<iostream>
using namespace std;
void RightRotate_90(char Sit[][3]);
int main(){
 int row,col;
 cin>>row>>col;
 char Map[row][col];
 for(int i = 0 ; i < row;i++){
     for(int j = 0 ; j < col;j++){
         cin>>Map[i][j]; 
     }
 }
 
 char Situation[3][3];
 for(int i = 0 ; i < 3;i++){
     for(int j = 0 ; j < 3;j++){
         cin>>Situation[i][j];
     }
 }

 RightRotate_90(Situation);

 for(int i = 0 ; i < 3;i++){
     for(int j = 0 ; j < 3;j++){
         cout<<Situation[i][j]<<" ";
     }
     cout<<endl;
 }


 return 0;
}
void RightRotate_90(char Sit[][3]){
   char tmp[3][3];
   for(int i = 0 ; i < 3;i++){
      for(int j = 0;j < 3;j++){
          tmp[j][2 - i] = Sit[i][j];  
      }
   }

   for(int i = 0 ; i < 3;i++){
       for(int j = 0 ; j < 3;j++){
           Sit[i][j] =  tmp[i][j];
       }
   }    
}
