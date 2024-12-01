// Pascal triangle

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter numer : ";
    cin>>n;
    for(int i = 0 ; i< n ; i++){
        for(int j = 1 ; j<n-i; j++){
            cout<<"  ";
        }
        for(int j = 0 ; j<=i; j++){
            int x=(j==0)?1:x*(i-j+1)/j;
            (x<10)?cout<<x<<"   ":cout<<x<<"  ";
        }
        cout<<endl;
    }
return 0;
}

/*
OUTPUT
Enter numer : 4
      1   
    1   1   
  1   2   1   
1   3   3   1   

||
Enter numer : 7
            1   
          1   1   
        1   2   1   
      1   3   3   1   
    1   4   6   4   1   
  1   5   10  10  5   1   
1   6   15  20  15  6   1   

*/