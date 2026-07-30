class Solution {
public:
    int minimumPushes(string word) {
        vector<int>position(26,0);
        for(int i =0;i<word.length();i++){
            if(i<8){
                if(position[word[i]-97]==0)
                position[word[i]-97]=1;
            }
            else if(i<16){
                if(position[word[i]-97]==0)
                position[word[i]-97]=2;
            }else if(i<24){
                if(position[word[i]-97]==0)
                position[word[i]-97]=3;
            }else{
                if(position[word[i]-97]==0)
                position[word[i]-97]=4;
            }
        }
        int ans =0;
        for(auto it:position){
            ans+=it;
        }
        return ans;
    }
};
