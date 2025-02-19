#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>

bool isPalindrome(char *s) {
    int left = 0, right = strlen(s) - 1;

    while (left < right) {
        // Move left pointer to the next alphanumeric character
        while (left < right && !isalnum(s[left])) left++;
        // Move right pointer to the previous alphanumeric character
        while (left < right && !isalnum(s[right])) right--;

        // Compare characters (case insensitive)
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }
    
    return true;
}

int main() {
    char s[] = "A man, a plan, a canal: Panama";
    printf("%s\n", isPalindrome(s) ? "true" : "false");

    return 0;
}
// OUTPUT: true


/* 2 - logic : 
bool isPalindrome(char* s) {
    int i = 0 , j = strlen(s)-1, x, y;
    while(i<j) {
        if(s[i]==s[j]){
            i++;j--;
            continue;
        }
        //skip special character
        if(s[i]<48 || (s[i]>57 && s[i]<65) || (s[i]>90 && s[i]<97) || s[i]>122){
            i++;
            continue;
        }
        if(s[j]<48 || (s[j]>57 && s[j]<65) || (s[j]>90 && s[j]<97) || s[j]>122){
            j--;
            continue;
        }
        // check upper-case and lower case
        if(s[i]>=65 && s[i]< 91){
            x = s[i]- 65 ;
        }
        else if(s[i]>=97 && s[i]< 123){
            x = s[i]- 97 ;
        }

        if(s[j]>=65 && s[j]< 91){
            y = s[j]- 65 ;
        }
        else if(s[j]>=97 && s[j]< 123){
            y = s[j]- 97 ;
        }

        if(x!=y)
            return false;

        i++;j--;
    }
    return true;
}*/