#include <iostream>
#include <stack>
#include <string>
#include <algorithm> // for reverse()

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        stack<char> st;

        // First pass: remove adjacent duplicates using a stack
        for (int i = 0; i < static_cast<int>(s.length()); i++) {
            char c = s[i];

            if (!st.empty() && c == st.top()) {
                st.pop(); // remove duplicate
            } else {
                st.push(c); // push new char
            }
        }

        // Second stack to reverse the order of characters
        stack<char> st1;
        while (!st.empty()) {
            st1.push(st.top());
            st.pop();
        }

        // Build the answer string from the reversed stack
        while (!st1.empty()) {
            ans.push_back(st1.top());
            st1.pop();
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Test cases
    string s1 = "abbaca";
    string s2 = "azxxzy";
    string s3 = "aaabccddd";

    cout << "Input: " << s1 << " -> Output: " << sol.removeDuplicates(s1) << "\n";
    cout << "Input: " << s2 << " -> Output: " << sol.removeDuplicates(s2) << "\n";
    cout << "Input: " << s3 << " -> Output: " << sol.removeDuplicates(s3) << "\n";

    return 0;
}
