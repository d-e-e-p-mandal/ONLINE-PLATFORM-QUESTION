//LEETCODE - 387 : First Unique Character in a String
#include <stdio.h>
#include <string.h>

int firstUniqChar(char* s) {
    int i, hash[26]={0}; // lower case only

    int len = strlen(s);
    for(i=0; i<len;i++){
        hash[s[i] - 97]++;
    }

    for(i=0;i<len; i++) {
        if(hash[s[i] - 97]==1)
            return i;
    }

    return -1;
}

int main() {
    char s[] = "leetcode";
    printf("Index of first unique character: %d\n", firstUniqChar(s));
    return 0;
}
/*OUTPUT :Index of first unique character: 0 */
/*Time Complexity : O(N)*/