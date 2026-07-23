class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        queue<int>q;
        vector<bool>vis(isConnected.size(),false);
        int province=0;
        for(int i =0;i<isConnected.size();i++){
            if(!vis[i]){
                q.push(i);
                while(!q.empty()){
                    vis[q.front()]=true;
                    for(int x =0;x<isConnected.size();x++){
                        if(x!=q.front()&&!vis[x]&&isConnected[q.front()][x]){
                            q.push(x);
                        }
                    }
                    q.pop();
                }
                province++;
            }
        }
        return province;
    }
};