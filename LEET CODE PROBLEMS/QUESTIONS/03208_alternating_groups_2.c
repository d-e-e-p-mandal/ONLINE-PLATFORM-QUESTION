// LEETCODE 3208 : Alternating Groups 2
#include <stdio.h>
//METHOD 1 : (MYCODE)
int numberOfAlternatingGroups(int* arr, int len, int k) { 
    int i,length= 1 ,res=0;

    for(i=1;i<k-1;i++) {    // circular condition check 1st
        if(arr[i]==arr[i-1]){   //compare with previous
            length = 1;
            break;
        }
        else if(++length>=k){
            res++;
        }
    }
    int st = i; //stroe value of i
    
    while(i <len) {     // after circular condition
        if(arr[i]==arr[i-1]){
            length = 1;
        }
        else if(++length>=k){
            res++;
        }
        i++;
    }

    if(arr[len-1]==arr[0])
        return res;
    else if(++length>=k){
        res++;  
    }

    int temp = length + st  - k;  // circular

     if(length<k)   // circular condition add
        res+=(temp<0)?0:temp;
    else
        res+= st - 1;  
        
    return res;
}

int main() {
    int arr[] = {0, 1, 0, 1, 0}; // Example test case
    int len = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    
    printf("Number of Alternating Groups: %d\n", countAlternatingGroups(arr, len, k));
    return 0;
}
/*METHOD 2 : EASY (YOUTUBE) 
int numberOfAlternatingGroups(int* arr, int len, int k) {
    int i,length= 1 ,res=0;
    int last = arr[0];

    for(i=1;i<len;i++) {
        if(arr[i]==last){
            length = 1;
        }
        else if(++length>=k){
            res++;
        }
        last = arr[i];
    }

    for(i=0;i<k-1 ;i++) {
        if(arr[i]==last){
            length = 1;
        }
        else if(++length>=k){
            res++;
        }
        last = arr[i];
    }

    return res;
}
    //TIME COMPEXITY : O(N+K-1)
    //SPACE COMPLEXITY : 0(1)
*/
/*Method 3 : (chatgpt)
int countAlternatingGroups(int* arr, int len, int k) {
    int res = 0, length = 1;
    
    // Traverse the array considering the circular condition
    for (int j = 1; j < len + k - 1; j++) {
        int curr = arr[j % len];  // Wrap-around using modulo

        if (curr == arr[(j - 1) % len]) {
            length = 1;  // Reset length on repetition
        } else {
            length++;
            if (length >= k) res++;  // Count valid alternating group
        }
    }

    return res;

    //TIME COMPEXITY : O(N+K-1)
    //SPACE COMPLEXITY : 0(1)
}*/
/*METHOD 4 : MYCODE
int breakPoint(int *colors, int colorSize, int k){
    int i;
    for(i=0;i<k-2;i++){
        if(colors[i]==colors[i+1])
            return i;
    }
    return i;
}
int numberOfAlternatingGroups(int* colors, int colorsSize, int k) {

    int i,group= 0,break_point,block = 1;
    break_point = breakPoint(colors,colorsSize,k);

    block = break_point+1; 
    
    for(i = break_point; i<colorsSize - 1; i++){
        if(colors[i]==colors[i+1]){
            block = 1;
        }
        else if(++block>=k){
            group++;
        }
    }
    if(colors[colorsSize-1]==colors[0])
        return group;
    else if(++block>=k){
        group++;  
    }
   
    int temp = block+break_point + 1 - k;
    if(block<k)
        group+=(temp<0)?0:temp;
    else
        group+=break_point;
        
    // for(i=0;i<break_point;i++){
    //     if(colors[colorsSize-1]==colors[0])
    //         return group;
    //     else if(++block>=k)
    //         group++;
    // }

    return group;
}*/