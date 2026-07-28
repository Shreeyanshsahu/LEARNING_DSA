class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>hash(26,0);
        for(int i = 0;i<s.length();i++){
            hash[s[i] - 97]++;
        }
        string left="";
        string middle="";
        string right="";
        for(int i = 0;i<hash.size();i++){
            left.append(hash[i] / 2, char(i + 'a'));
            if(hash[i]%2!=0 && middle==""){
                middle=(char)(i+97);
            }
        }
        right = left;
        reverse(right.begin(),right.end());
        return left+middle+right;
    }
};