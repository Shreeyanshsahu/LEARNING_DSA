#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        if (s.length() % 2 != 0) return false; // odd length cannot be valid

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            // Push opening brackets
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                // If stack empty when closing bracket found → invalid
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                // Check matching
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // If stack empty at the end, all brackets matched
        return st.empty();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Test cases
    string s1 = "(())()";
    string s2 = "(()";
    string s3 = "{[()]}";

    cout << s1 << " -> " << (sol.isValid(s1) ? "true" : "false") << "\n";
    cout << s2 << " -> " << (sol.isValid(s2) ? "true" : "false") << "\n";
    cout << s3 << " -> " << (sol.isValid(s3) ? "true" : "false") << "\n";

    return 0;
}
