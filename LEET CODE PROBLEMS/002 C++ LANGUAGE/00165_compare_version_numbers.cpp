#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        // i, j are indices for version1 and version2
        for(int i=0,j=0; i<version1.length() || j<version2.length(); i++, j++) {
            string s1=""; 
            string s2 ="";

            // extract number from version1 until '.'
            while(i < version1.length() && version1[i] != '.') {
                s1 += version1[i];
                i++;
            } 

            // extract number from version2 until '.'
            while(j < version2.length() && version2[j] != '.') {
                s2 += version2[j];
                j++;
            } 

            int x = (s1=="")? 0 : stoi(s1); // convert string to int
            int y = (s2=="")? 0 : stoi(s2);

            if(x < y) return -1; // version1 < version2
            if(x > y) return 1;  // version1 > version2
        }

        return 0; // equal versions
    }
};

int main() {
    Solution sol;

    string v1 = "1.01";
    string v2 = "1.001";

    int result = sol.compareVersion(v1, v2);

    cout << "Comparison result: " << result << endl; 
    // Output: 0 (since 1.01 == 1.001 after ignoring leading zeros)

    return 0;
}

/*
Time Complexity: O(n + m), where n = length of version1, m = length of version2
- Each character is visited once.

Space Complexity: O(maxSegmentLength)
- Temporary strings s1, s2 store each numeric segment.
- Overall, space is proportional to the length of the longest segment between dots.
*/