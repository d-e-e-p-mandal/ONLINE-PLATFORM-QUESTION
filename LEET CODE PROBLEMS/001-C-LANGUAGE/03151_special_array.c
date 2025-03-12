// LEETCODE QUESTION 3151
#include<stdio.h>
#include<stdbool.h>
bool isArraySpecial(int* nums, int numsSize) {
   int i;
   for(int i=0;i<numsSize-1;i++){
        if(nums[i]%2==0){   //if consecutive two number odd or even then return false
            if(nums[i+1]%2==0)return false;
        }
        else
            if(nums[i+1]%2!=0)return false;
    }
   return true; // check all conditions then return true
}
void inputArr(int *arr,int size){
    int i;
    printf("Enter array element\n");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
}
int main(){
    int size;
    printf("Enter sizer of array : ");
    scanf("%d",&size);
    int arr[size];
    inputArr(arr,size);
    if(isArraySpecial(arr,size)==true)
        printf("True\n");
    else
        printf("False\n");
    return 0;
}
/*
OUTPUT : 
Enter sizer of array : 3
Enter array element
2       1       4
True

Enter sizer of array : 4
Enter array element
6       1       9       4
False
*/