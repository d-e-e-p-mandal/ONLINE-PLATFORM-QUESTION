//LEET CODE QUESTION 3
#include<stdio.h>
#include<string.h>
int main(){
    char str[20]="";
    int i,j,len,count=1,maxCount=1,x=0;
    printf("Enter string : ");
    //scanf("%s",str);
    len = strlen(str);
    if(len==0){
        printf("The length of the longest substring without repeating characters 0");
        return 0;
    }
    for(i=1;i<len;i++){
        count=1;
        for(j=x;j<i;j++){
            if(str[j]!=str[i])
                count++;
            else{
                x=j+1;
                break;
            }
                
        }
        maxCount=(maxCount<count)?count:maxCount;
    }
    printf("The length of the longest substring without repeating characters %d",maxCount);
    return 0;
}
/*
OUTPUT :
Enter string : pwwkew
The length of the longest substring without repeating characters 3
*/
