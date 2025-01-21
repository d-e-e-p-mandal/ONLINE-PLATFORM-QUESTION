//LEET CODE QUESTION 283
#include<stdio.h>
void swap(int *x,int *y){
    *x=*x^*y;
    *y=*x^*y;
    *x=*x^*y;
}
void moveZeroes(int* nums, int numsSize) {
    int i,j=0;
    for(i=0;i<numsSize;i++)
        if(nums[i]){    //when 0 element found i and j vlalue will be different
            if(i!=j)    // skip until 0 element found
                swap(&nums[i],&nums[j++]);  // swap((nums+i),(nums+(j++)))
            else j++;
        }
    printf("After move all zero at end\n");  
    for(i=0;i<numsSize;i++)
        printf("%d\t",nums[i]);
}
int main(){
    int size,i;
    printf("Enter array size : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter array element : \n");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    moveZeroes(arr,size);
    return 0;
}
/*
OUTPUT :
Enter array size : 6
Enter array element : 
1       1       0       3       0       6
After move all zero at end
1       1       3       6       0       0 
*/