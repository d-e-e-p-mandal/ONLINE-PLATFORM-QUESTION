// LEETCODE - 2379 : Minimum Recolors to Get K Consecutive Black Blocks
#include <stdio.h>
#include <string.h>

int minimumRecolors(char* blocks, int k) {
    int i,current=0,min;
    for(i=0;i<k;i++)
        if(blocks[i] == 'W')
            current++;  //counting white
    min = current;  // total white in k blocks

    while(blocks[i]!='\0'){     // counting min white as sliding window
        if(blocks[i-k] == 'W')
            current--;
        if(blocks[i] ==  'W')
            current++;
        min = (current<min)?current:min;

        i++;
    }
    return min; // return min white int sliding k blocks
}

int main() {
    char blocks[] = "WBBWWBBWBW";
    int k = 7;
    printf("Minimum recolors needed: %d\n", minimumRecolors(blocks, k));
    return 0;
}
/*OUTPUT : Minimum recolors needed: 3 */

/*Time Complexity : O(N)
Space Complexity : O(1)*/