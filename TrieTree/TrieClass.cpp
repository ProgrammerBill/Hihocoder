#include<iostream>
using namespace std;
const int Max = 11;
class Trie{
    public:
       Trie():num(0){
          for(int i = 0 ; i < 26;++i)
		 next[i] = NULL; 
       }
       void Insert(const char word[]);
       int Find(const char word[]);
     private:
       int num;
       Trie *next[26];
};
Trie *tree;
void Trie::Insert(const char word[]){
       Trie *node = tree;   
       for(int i = 0 ; word[i] != '\0'; i++){
	   int a = word[i] - 'a';
           if(node->next[a] == NULL){
	        node->next[a] =  new Trie();
	   }    
           node = node->next[a];
           node->num++;
       }        
}

int Trie::Find(const char word[]){
    Trie *node = tree;   
       for(int i = 0 ; word[i] != '\0'; i++){
           int a = word[i] - 'a';
           if(node->next[a] == NULL)
                 return 0;    
           node = node->next[a];
       }   
       return node->num;    
}
int main(){
    int n,m;
    char word[Max];
    tree = new Trie();
    cin>>n;
    while(n--){
        cin>>word;
        tree->Insert(word);
    }
    cin>>m;
    while(m--){
        cin>>word;
        cout<<tree->Find(word)<<endl;
    }
}

