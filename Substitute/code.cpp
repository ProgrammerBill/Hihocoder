#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdio>
const int MAX = 301;
using namespace std;
bool Strcmp(char str1[],char str2[]);
char * replace(char str[],char org[],char pat[]);
int main(){
 char origin[30] = "marshtomp";
 char pattern[30] = "fjxmlhx";
 char buf[301]; 
 while(gets(buf)){
     printf("%s\n",replace(buf,origin,pattern)); 
 }

 return 0;
}

bool Strcmp(char str1[],char str2[]){
    char tmp;
    for(int i = 0 ; i < strlen(str2);i++){
         tmp = tolower(str1[i]);
	 if(tmp != str2[i]) return false;
    }
    return true;
}

char * replace(char str[],char org[],char pat[]){
    char tmp[MAX];
    int end = strlen(str) - strlen(org);
    int i = 0;
    int j = 0;
    while(i <= end){
        if(Strcmp(str + i,org)){
            strcpy(tmp + j,pat);
            j += strlen(pat);
	    i += strlen(org);	    
	}
	else{
	    tmp[j++] = str[i++]; 
	}
    }
     
    while(str[i]){
        tmp[j++] = str[i++];
    } 
    tmp[j] = '\0';
    strcpy(str,tmp);
    return str;    
}
