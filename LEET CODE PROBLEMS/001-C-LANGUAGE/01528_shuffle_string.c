// LEETCODE - 1528 :
#include <stdio.h>
#include <stdlib.h>

// Function to restore the string based on indices
char* restoreString(char* s, int* indices, int indicesSize) {
    char *res = (char *)malloc((indicesSize + 1) * sizeof(char));
    if (!res) return NULL;  // Safety check

    for (int i = 0; i < indicesSize; i++) {
        res[indices[i]] = s[i];
    }
    res[indicesSize] = '\0';  // Null-terminate the string

    return res;
}

int main() {
    char s[] = "codeleet";
    int indices[] = {4, 5, 6, 7, 0, 2, 1, 3};
    int size = sizeof(indices) / sizeof(indices[0]);

    // Call restoreString and get result
    char* result = restoreString(s, indices, size);

    if (result) {
        printf("Restored string: %s\n", result);
        free(result);  // Free allocated memory
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}