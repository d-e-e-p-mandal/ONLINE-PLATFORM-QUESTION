#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  
  cin.tie(nullptr); 
  cout.tie(nullptr); 

  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  int t;
  cin >> t;

  int cur = 0, ans = 0;
  while (t--) {
    int a, b;
        cin >> a >> b;
        cur = cur - a + b;
        ans = max(ans, cur);
  }

  cout<<ans<<endl;
}