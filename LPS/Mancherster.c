#include <stdio.h>
#include <string.h>
int min(int a,int b){
  return a < b ? a : b;
}
const int MAX = 1000;
int main(){
 int N;
 scanf("%d",&N);
 while(N--){
   char s[MAX * 2];
   int p[MAX * 2];
   scanf("%s",s); 
   int len = strlen(s);
   int id = 0;
   int maxlen = 0;
   int i;
   for(i = len;i >= 0;i--){
       s[2 * i + 2] = s[i];
       s[2 * i + 1] = '#'; 
   }
   s[0] = '*'; 
   
   for(i = 2;i < 2 * len + 1;i++){
       if(p[id] + id > i)
           p[i] = min(p[2 * id - i],p[id] + id - i);
       else
	   p[i] = 1;
       while(s[i - p[i]] == s[i + p[i]] )
	       ++p[i];
       if(id + p[id] < i + p[i])
	       id = i;
       if(maxlen < p[i]) maxlen = p[i];
   
   } 
   printf("%d\n",maxlen - 1);
 
 
 } 
 return 0;
}
