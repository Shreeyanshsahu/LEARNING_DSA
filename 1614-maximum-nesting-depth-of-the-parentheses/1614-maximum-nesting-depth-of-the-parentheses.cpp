class Solution {
public:
    int maxDepth(string s) {
        int maxdepth=INT_MIN;
        int depth=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                depth++;
            }
            else if(s[i]==')'){
                depth--;
            }
            maxdepth=max(maxdepth,depth);
        }
        return maxdepth;
    }
};