// LEET CODE QUESTION 344, Warrning generated

#include<stdio.h>
void swap(char *x,char *y){ // swap function
    char s = *x;
    *x = *y;
    *y = s;
}
void reverseString(char* s[], int sSize) {
    int i=0,j=sSize-1;
    while(i<j){
        swap((s+i),(s+j));  // swap(&s[i],&s[j])
        i++;j--;
    }
}
int main(){
    char *s[] = {"h","e","l","l","o"};
    int size=5,i;
    printf("Reverse string : ");
    reverseString(s,size);
    for(i=0;i<size;i++)
        printf("%s",*(s+i));  //s[i]
    return 0;
}
/*
OUTPUT :
Reverse string : olleh
*/