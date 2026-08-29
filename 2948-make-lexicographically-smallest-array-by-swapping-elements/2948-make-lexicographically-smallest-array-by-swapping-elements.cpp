class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // {value, original index}
        vector<pair<int,int>> v;

        for (int i = 0; i < n; i++)
            v.push_back({nums[i], i});

        sort(v.begin(), v.end());

        // Build connected components
        for (int i = 1; i < n; i++) {
            if (v[i].first - v[i - 1].first <= limit)
                unite(v[i].second, v[i - 1].second);
        }

        // Group indices and values by component
        unordered_map<int, vector<int>> indices;
        unordered_map<int, vector<int>> values;

        for (int i = 0; i < n; i++) {
            int root = find(i);
            indices[root].push_back(i);
            values[root].push_back(nums[i]);
        }

        // Put smallest values at smallest indices
        for (auto& [root, idx] : indices) {
            auto& val = values[root];

            sort(idx.begin(), idx.end());
            sort(val.begin(), val.end());

            for (int i = 0; i < idx.size(); i++)
                nums[idx[i]] = val[i];
        }

        return nums;
    }
};