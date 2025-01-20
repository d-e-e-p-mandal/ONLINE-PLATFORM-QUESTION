//LEET CODE QUESTION 13
#include<stdio.h>
int romanToInt(char* s) {
    int i,j,number=0;
    
    for(i=0,j=1;s[i]!='\0' ;i++,j=i+1){ // check for all conditions
        if(s[i]== 'M')
            number+=1000;
        else if(s[i]=='C'&&s[j]=='M'){
            number+=900;i++;
        }
        else if(s[i]=='D')
            number+=500;
        else if(s[i]=='C'&&s[j]=='D'){
            number+=400;i++;
        }
        else if(s[i]=='C')
            number+=100;
        else if(s[i]=='X'&&s[j]=='C'){
            number+=90;i++;
        }
        else if(s[i]=='L')
            number+=50;
        else if(s[i]=='X'&&s[j]=='L'){
            number+=40;i++;
        }
        else if(s[i]=='X')
            number+=10;
        else if(s[i]=='I'&&s[j]=='X'){
            number+=9;i++;
        }
        else if(s[i]=='V')
            number+=5;
        else if(s[i]=='I'&&s[j]=='V'){
            number+=4;i++;
        }
        else
            number+=1;
    }
    return number;
}
int main(){
    char str[25];
    printf("Enter ROMAN DIGIT number : ");
    scanf("%[^\n]",str);
    printf("Your enter number in integer is : %d \n",romanToInt(str));
    
    return 0;
}
/*
OUTPUT : 
Enter ROMAN DIGIT number : LIV     
Your enter number in integer is : 54 
*/