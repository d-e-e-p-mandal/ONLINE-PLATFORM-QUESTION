// LEET CODE 3271
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* stringHash(char* s, int k) {
    int i, len = strlen(s);
    char *res = (char *)calloc(((len/k)+1), sizeof(char));  // Initialize with 0
    int sum = 0;

    for(i = 0; i < len; i++) {
        sum += s[i] - 97;
        
        if((i % k) == (k-1) || i == len - 1) { // Store sum when before multiple of k
            res[i/k] = (sum % 26) + 97;    
            sum = 0;
        }
    }
    res[len/k] = '\0';    // Null character

    return res;
}

int main() {
    char str[] = "abcdefghijk";  // Example input string
    int k = 3;                    // Example k value
    
    char *hashedString = stringHash(str, k);
    
    printf("Original String: %s\n", str);
    printf("Hashed String: %s\n", hashedString);
    
    free(hashedString); // Free allocated memory
    return 0;
}
/*OUTPUT : 
Original String: abcdefghijk
Hashed String: dmv
*/
