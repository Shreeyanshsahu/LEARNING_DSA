class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int high = INT_MIN;
        int lo = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            lo = min(nums[i],lo);
            high = max(nums[i],high);
        }
        vector<bool>missing(high-lo+1,false);
        for(int i = 0;i<nums.size();i++){
            missing[nums[i]-lo]=true;
        }
        vector<int>ans;
        for(int i = 0;i<missing.size();i++){
            if(!missing[i]){
                ans.push_back(i+lo);
            }
        }
        return ans;
    }
};