// LEETCODE 1790
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
void swap(char *x, char *y){
    char temp=*x;
    *x=*y;
    *y=temp;
}
bool areAlmostEqual(char* s1, char* s2) {
    if(strcmp(s1,s2)==0) return true;
    int i,j,len=strlen(s1);
    for(i=0;i<len;i++)
        if(s1[i]!=s2[i])
            break;

    for(j=len-1;j>=0;j--)
        if(s1[j]!=s2[j])
            break;

    swap(s2+i,s2+j);
    if(strcmp(s1,s2)==0)return true;
    return false;
}
int main(){
    char s1[] = "bank", s2[] = "kanb";

    if(areAlmostEqual(s1,s2)==true)
        printf("True\n");
    else 
        printf("False\n");
    return 0;
}
/* OUTPUT : True */