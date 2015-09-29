#include<stdio.h>
int main(){
   int Total;
   scanf("%d",&Total);
   while(Total--){
      int N,M;
      scanf("%d%d",&N,&M);
      if(N <= M){
         printf("%d\n",100);
	 continue;
      }
      int Array[N];
      int i,j;
      for(i = 0; i < N;i++){
          scanf("%d",&Array[i]);
      }
      int Delta[N + 1];
      for(i = 1;i < N;i ++){
          Delta[i] = Array[i] - Array[i - 1] - 1;
      }
      Delta[0] = Array[0] - 1;
      Delta[N] = 100 - Array[N - 1] - 1;

      //for(i = 0;i < N + 1;i++)
      //	      printf("%d ",Delta[i]);
      int max = 0;
      for(i = 0;i <= N - M;i++){
          int tmp = Delta[i];
	  for(j = 1;j <= M;j++){
	      tmp += Delta[i + j] + 1;        
	  }
	  if(tmp > max)
		  max = tmp;
      }
      printf("%d\n",max); 
   } 
}
