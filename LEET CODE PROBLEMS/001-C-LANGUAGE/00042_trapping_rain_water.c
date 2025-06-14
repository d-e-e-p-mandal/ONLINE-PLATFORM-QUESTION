//LEET CODE QUESTION 42 : Trappiing Rain Water : (better approach)
#include<stdio.h>
#include<stdlib.h>
#define min(a,b) (a<b ?a:b)   //minimum
#define max(a,b) (a>b ?a:b)   //maximum
int *LeftMax(int *height,int heightSize){
    int i,*leftMax=(int *)malloc(heightSize*sizeof(int));//memory allocate
    leftMax[0]=height[0];
    for(i=1;i<heightSize;i++)
        leftMax[i]=max(leftMax[i-1],height[i]);//stroing max data from left side
    return leftMax; //return address of leftMax array
}
int *RightMax(int *height,int heightSize){
    int i,*rightMax=(int *)malloc(heightSize*sizeof(int));//memory allocate
    rightMax[heightSize-1]=height[heightSize-1];
    for(i=heightSize-2;i>=0;i--)
        rightMax[i]=max(rightMax[i+1],height[i]);//stroing max data from right side
    return rightMax;//return address of rightMax array
}
int trap(int* height, int heightSize) {
    int i,total_water=0;
    int *left_max=LeftMax(height,heightSize);
    int *right_max=RightMax(height,heightSize);
    for(i=0;i<heightSize;i++)
        total_water+=min(left_max[i],right_max[i])-height[i];//adding water in total water
    free(left_max);
    free(right_max);
    return total_water;
}
int main(){
    int i,n,heightSize;
    printf("Enter height size : ");
    scanf("%d",&heightSize);
    int height[heightSize],totalWater;
    printf("Enter block height : \n");
    for(i=0;i<heightSize;i++)
       scanf("%d",&height[i]);
    
    totalWater=trap(height,heightSize);
    printf("Total water is : %d\n",totalWater);

    return 0;
}
/*
OUTPUT :
Enter height size : 6
Enter block height : 
4       2       0       3       2       5
Total water is : 9
*/