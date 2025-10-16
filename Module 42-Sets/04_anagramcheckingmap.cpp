#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    // Function to check if two strings are anagrams
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> map;

        // Count frequency of each character in string s
        for (int i = 0; i < s.length(); i++) {
            map[s[i]]++;
        }

        // Subtract frequency for each character in string t
        for (int i = 0; i < t.length(); i++) {
            if (map.find(t[i]) != map.end()) {
                map[t[i]]--;
                if (map[t[i]] == 0)
                    map.erase(t[i]);
            } else {
                return false;
            }
        }

        // If map is empty, both strings are anagrams
        return map.empty();
    }
};

int main() {
    Solution sol;

    string s = "anagram";
    string t = "nagaram";

    if (sol.isAnagram(s, t))
        cout << "The strings are anagrams." << endl;
    else
        cout << "The strings are NOT anagrams." << endl;

    return 0;
}
