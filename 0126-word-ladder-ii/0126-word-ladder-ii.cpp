class Solution {
    unordered_map<string, int> level_map;

public:

    void mapbuild(string beginWord, string endWord,
                  vector<string>& wordList) {

        unordered_map<string, int> mp;

        for (int i = 0; i < wordList.size(); i++) {
            mp[wordList[i]]++;
        }

        queue<pair<string, int>> q;

        q.push({beginWord, 1});
        level_map[beginWord] = 1;
        mp.erase(beginWord);
        bool found = false;

        while (!q.empty()) {

            int size = q.size();

            // Words discovered during THIS level
            unordered_set<string> toErase;

            while (size--) {

                auto [word, level] = q.front();
                q.pop();

                for (int i = 0; i < word.length(); i++) {

                    string temp = word;

                    for (int j = 0; j < 26; j++) {

                        temp[i] = 'a' + j;

                        if (mp.count(temp) && !toErase.count(temp)) {

                            q.push({temp, level + 1});
                            level_map[temp] = level + 1;

                            toErase.insert(temp);

                            if (temp == endWord) {
                                found = true;
                            }
                        }
                    }
                }
            }

            // Erase only AFTER the whole level
            for (auto& word : toErase) {
                mp.erase(word);
            }

            // We found endWord at this level.
            // Don't process the next level.
            if (found)
                return;
        }
    }

    void dfs(string beginWord,
             string word,
             vector<string>& seq,
             vector<vector<string>>& ans) {

        if (word == beginWord) {

            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());

            return;
        }

        int level = level_map[word];

        for (int i = 0; i < word.length(); i++) {

            string temp = word;

            for (int j = 0; j < 26; j++) {

                temp[i] = 'a' + j;

                if (level_map.count(temp) &&
                    level_map[temp] == level - 1) {

                    seq.push_back(temp);

                    dfs(beginWord, temp, seq, ans);

                    seq.pop_back();
                }
            }
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList) {

        mapbuild(beginWord, endWord, wordList);

        vector<vector<string>> ans;

        if (!level_map.count(endWord))
            return ans;

        vector<string> seq = {endWord};

        dfs(beginWord, endWord, seq, ans);

        return ans;
    }
};