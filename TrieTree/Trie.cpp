#include<iostream>
#include<cstring>
#define MAX 11
using namespace std;

struct Trie{
    int num;
    Trie * next[26];
    Trie():num(0){
        for(int i = 0 ; i < 26 ;++i)
	       next[i] = NULL;	
    }
}tree;

void Insert(const char str[]){
   Trie *node = &tree;
   for(int i = 0 ; str[i] != '\0'; ++i){
       int a = str[i] - 'a';
       if(node->next[a] == NULL){
           node->next[a] = new Trie();
       }
       node = node->next[a];
       node->num++;
   }
}

int  Find(const char str[]){
   Trie * node = &tree;
   for(int i = 0 ; str[i] != '\0';++i){
       int a = str[i] - 'a';
       if(node->next[a] == NULL) return 0;
       node = node->next[a];
   }
   return node->num;
}



int main(){
 int n,m;
 cin>>n;
 char oneLine[MAX];
 while(n--){
     cin>>oneLine;
     Insert(oneLine);
 }
 cin>>m;
 while(m--){
     cin>>oneLine; 
     cout<<Find(oneLine);
 }


 return 0;
}
