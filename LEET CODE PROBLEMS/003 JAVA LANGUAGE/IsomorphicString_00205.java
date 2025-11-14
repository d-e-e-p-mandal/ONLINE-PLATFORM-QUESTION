import java.util.*;

class Solution {

    // Function to check if two strings are isomorphic
    public boolean isIsomorphic(String s, String t) {

        int n = s.length();

        HashMap<Character, Character> mp1 = new HashMap<>(); // map s → t
        HashMap<Character, Character> mp2 = new HashMap<>(); // map t → s

        for (int i = 0; i < n; i++) {

            char a = s.charAt(i);
            char b = t.charAt(i);

            // Check forward mapping (s → t)
            if (mp1.containsKey(a)) {
                if (mp1.get(a) != b) return false;
            } else {
                mp1.put(a, b);
            }

            // Check backward mapping (t → s)
            if (mp2.containsKey(b)) {
                if (mp2.get(b) != a) return false;
            } else {
                mp2.put(b, a);
            }
        }

        return true; // Strings are isomorphic
    }
}

// ------------------------------------------
// Main Function (Example Usage)
// ------------------------------------------
public class IsomorphicString_00205 {
    public static void main(String[] args) {

        Solution obj = new Solution();

        String s = "egg";
        String t = "add";

        boolean result = obj.isIsomorphic(s, t);

        System.out.println("Are the strings isomorphic? " + result);
    }
}

/*
-------------------------------------------
Example Output:
-------------------------------------------
Are the strings isomorphic? true

-------------------------------------------
Explanation:
-------------------------------------------
egg → add
e → a
g → d
Mapping works both ways, so strings are isomorphic.

-------------------------------------------
Time Complexity: O(n)
    - Single scan of both strings.
    - HashMap operations are O(1) amortized.

Space Complexity: O(1)
    - At most 256 character mappings stored.
-------------------------------------------
*/