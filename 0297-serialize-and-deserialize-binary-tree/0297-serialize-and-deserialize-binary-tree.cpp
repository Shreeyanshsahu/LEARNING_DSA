class Codec {
public:
    int i =0;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "#";

        string ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                ans += "#,";
                continue;
            }

            ans += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }

        return ans;
    }
    string nextToken(string data) {
        string value = "";
        while (i < data.length() && data[i] != ',') {
            value += data[i];
            i++;
        }
        i++;
        return value;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string &data) {
        if (data == "#")
            return nullptr;
        string token = nextToken(data);
        TreeNode* root = new TreeNode(stoi(token));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // left child
            token = nextToken(data);
            if (token != "#") {
                curr->left = new TreeNode(stoi(token));
                q.push(curr->left);
            }

            // right child
            token = nextToken(data);
            if (token != "#") {
                curr->right = new TreeNode(stoi(token));
                q.push(curr->right);
            }
        }

        return root;
    }
};
