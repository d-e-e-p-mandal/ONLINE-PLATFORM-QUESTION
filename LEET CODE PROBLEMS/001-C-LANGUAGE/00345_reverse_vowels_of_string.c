// LEETCODE - 345 : Reverse Vowels of a String

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Method - 1 : (mycode)
bool isVowel(char ch) {
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O'  || ch == 'U')
        return true;
    return false;
}

void swap(char *a, char *b) { // swap function
    char temp = *a;
    *a = *b;
    *b = temp;
}

char* reverseVowels(char* s) {
    
    int left = 0 ,right = strlen(s)-1;

    while(left<right) {
        while(!isVowel(s[left]) && left < right)left++; // skip until left will point vowel
        while(!isVowel(s[right]) && left < right)right--;   // skip until right will point vowel
        if(left<right)
            swap((s+left),(s+right));
        left++;right--;
    }
    return s;
}
int main() {
    char s[] = "IceCreAm";
    reverseVowels(s);
    printf("%s\n", s); 
    return 0;
}

/* OUTPUT : AceCreIm*/

/*Method - 2 : mycode 
bool isVowel(char ch) {
    ch = tolower(ch);   //convert in lower case
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}

void swap(char *a, char *b) {   //swap function
    char temp = *a;
    *a = *b;
    *b = temp;
}

char* reverseVowels(char* s) {
    
    int left = 0 ,right = strlen(s)-1;

    while(left<right) {
        if(!isVowel(s[left])) {left++; continue;}   //skip when it is not vowel
        if(!isVowel(s[right])) {right--; continue;}

        swap((s+left),(s+right)); 
        left++;right--;
    }
    return s;
}*/

/*Time Complexity : O(N)
Space Complexity : O(1)*/