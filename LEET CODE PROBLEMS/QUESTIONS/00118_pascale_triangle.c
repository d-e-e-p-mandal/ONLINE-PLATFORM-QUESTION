// LEETCODE QUESTION 118
#include<stdio.h>
#include<stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **pascale,i,j;
    pascale = (int **)malloc(numRows*sizeof(int *));
    *returnSize=numRows;   // number of row
    *returnColumnSizes = (int *)malloc(numRows*sizeof(int));   //generate column only for 1st row ,to store number of column for each row
    
    for(i=0;i<numRows;i++){
        pascale[i] = (int *)malloc((i+1)*sizeof(int));  // genetate integer memory for each row
        (*returnColumnSizes)[i]=i+1; // returnColumnSizes[0][i]=i+1;

        for(j=0;j<=i;j++){
            if(j==0 || j==i)
                pascale[i][j]=1;
            else
                pascale[i][j]=pascale[i-1][j-1]+pascale[i-1][j];
        }
    }
    return pascale;
}
int main(){
    int **pattern,*retunrnColumnSizes,returnSize,NofRow,i,j;
    printf("Enter number of row : ");
    scanf(" %d", &NofRow);
    pattern=generate(NofRow,&returnSize,&retunrnColumnSizes);
    printf("PATTERN : \n");
    for(i=0;i<returnSize;i++){
        for(j=0;j<(returnSize-i);j++)
            printf("   ");
        for(j=0;j<=i;j++)    //for(j=0;j<retunrnColumnSizes[i];j++)
            printf("%3d   ",pattern[i][j]);
        printf("\n");
    }

    //free memory
    for(i=0;i<returnSize;i++)
        free(pattern[i]);
    free(pattern);
    free(retunrnColumnSizes);
    return 0;
}
/*
OUTPUT :
Enter number of row : 5
PATTERN : 
                1   
             1     1   
          1     2     1   
       1     3     3     1   
    1     4     6     4     1 
*/
