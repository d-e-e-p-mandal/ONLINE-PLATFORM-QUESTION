// LEETCODE QUESTION 541
#include<stdio.h>
#include<string.h>
void swap(char *x , char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}
void rev(char *s, int start, int end){
    while(start<end){
        swap(s+start,s+end);
        start++;end--;
    }
}
char* reverseStr(char* s, int k) {
    int i,len=strlen(s);
    for(i=0;i<len-1;i+=2*k){
        rev(s,i,(i+k-1<len)?i+k-1:len-1);   // minimum of length and k
    }
    return s;
}
int main(){
    char s[20]="abcdefgh";
    int k=2;
    char *str=reverseStr(s,k);
    printf("Rverse : %s \n",str);
    return 0;
}
/*OUTPUT : Rverse : bacdfegh */