// LEETCODE 509 : Fibonacci Number
int fun(int n, int *arr){
    if(n==0 || n==1)
        return n;
    if(arr[n] != -1)return arr[n]; //store previous calculated value
    arr[n] = fun(n-1,arr) + fun(n-2,arr);
    return arr[n];
}
int fib(int n){
    int arr[n+1] ;
    for(int i=0; i<n+1; i++){  //memset(arr, -1, sizeof(arr)); // This initializes the whole array to -1, this function include at string.h header file
        arr[i]= -1;
    }
    return fun(n,arr);
}

int main() {
    int n = 5;  // Example: Calculate Fibonacci of 5
    printf("Fibonacci of %d is: %d\n", n, fib(n));
    return 0;
}