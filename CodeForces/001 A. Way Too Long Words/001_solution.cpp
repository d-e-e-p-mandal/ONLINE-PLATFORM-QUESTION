#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s, ans;
    cin >> s;

    int len = s.length();

    if(len > 10) {
        ans = s[0] + to_string(len-2) + s[len-1];
        cout<<ans<<endl;
    }
    else cout<<s<<endl;
}

int main() {
  ios::sync_with_stdio(false);
  
  cin.tie(nullptr); //cin.tie(0); //cin.tie(NULL);
  cout.tie(nullptr); //cout.tie(0);

  // c style : input and output in file
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}