// LEETCODE 58
#include<stdio.h>
#include<string.h>
int lengthOfLastWord(char* s) {
    int i,count=0,flag=1;
    for(i=strlen(s)-1;i>=0 ;i--){
        if(flag==1 && s[i]==' '){
            continue;   // if space before any word then skip
        }
        else if(s[i]!=' '){
            count++;
            flag=0;
        }
        else break; // if any space occur then exit the loop
    }
    return count;
}
int main(){
    char str[]="   fly me   to   the moon  ";

    printf("Length of the last word : %d\n",lengthOfLastWord(str));
    return 0;
}
/* OUTPUT : Length of the last word : 4 */