class Solution {
    bool check(int x, int y, int m, int n) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()<1) return 0;
        vector<int>dp(triangle[triangle.size()-1].size(),INT_MAX);
        dp[0]=triangle[0][0];
        for(int i =1;i<triangle.size();i++){
            vector<int>temp(triangle[triangle.size()-1].size(),INT_MAX);
            for(int j =0;j<triangle[i].size();j++){
                int minpath = triangle[i][j];
                if(j==0) {
                    minpath+=dp[j];
                }else if(j==triangle[i].size()-1){
                    minpath+=dp[j-1];
                }else{
                    minpath+=min(dp[j-1],dp[j]);
                }
                temp[j]=minpath;
            }
            dp=temp;
        }
        int minpath =INT_MAX;
        for(int i=0;i<dp.size();i++){
            minpath=min(dp[i],minpath);
        }
        return minpath;
    }
};