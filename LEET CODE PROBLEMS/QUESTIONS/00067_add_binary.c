// LEET CODE - 67
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(a,b) ((a>b)?a:b)
char* addBinary(char* a, char* b) {
    char *res=NULL;
    int i=strlen(a)-1,j=strlen(b)-1,c=0;
    int x = max(i,j)+1;

    res=(char *)malloc((x+2)*sizeof(char)); // generate memory for carry also
    int p,q;
    res[0]='0';
    res[x+1]='\0';
    while(x>=0){
        p=(i>=0)?a[i--]-48 : 0; // ascii value of 0
        q=(j>=0)?b[j--]-48 : 0; 

        res[x--]=(p^q^c)+48;

        c=((p == 1 && q == 1) || (c == 1 && q == 1) || (p ==1 && c == 1))?1 : 0;
    }
    return res+(res[0]=='0');   // if no carry
}
int main(){
    printf("%s\n", addBinary("11", "1"));
    return 0;
}
/*OUTPUT : 100 */