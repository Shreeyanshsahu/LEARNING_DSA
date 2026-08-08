class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>mp;
        for(int i = 0;i<wordList.size();i++){
            mp[wordList[i]]++;
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto [word,level]=q.front();
            q.pop();
            for(int i =0;i<word.length();i++){
                string temp = word;
                for(int j=0;j<26;j++){
                    temp[i]=(char)('a'+j);
                    if(mp.count(temp)){
                        q.push({temp,level+1});
                        mp.erase(temp);
                        if(temp==endWord) return level+1;
                    }
                }
            }
        }
        return 0;
    }
};