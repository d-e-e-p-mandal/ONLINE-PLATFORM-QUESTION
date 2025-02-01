//LEETCODE QUESTION 3
#include<stdio.h>
#include<string.h>
int lengthOfLongestSubstring(char* str) {
    int i,j,len,count=1,maxCount=1,x=0;
    len = strlen(str);
    if(len==0)
        return 0;
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
    return maxCount;
}

int main(){
    char s[] = "pwwkew";
    
    printf("The length of the longest substring without repeating characters %d",lengthOfLongestSubstring(s));
    return 0;
}
/*
OUTPUT :
The length of the longest substring without repeating characters 3
*/
