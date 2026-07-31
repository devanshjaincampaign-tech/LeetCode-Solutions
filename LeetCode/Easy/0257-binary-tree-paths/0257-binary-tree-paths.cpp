class Solution {
private:
    void backtrack(TreeNode* node, std::string& path, std::vector<std::string>& result) {
        if (!node) return;

        int originalLen = path.length();

        if (!path.empty()) {
            path += "->";
        }
        path += std::to_string(node->val);

        if (!node->left && !node->right) {
            result.push_back(path);
        } else {
            if (node->left) backtrack(node->left, path, result);
            if (node->right) backtrack(node->right, path, result);
        }

        path.erase(originalLen);
    }

public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> result;
        std::string path;
        backtrack(root, path, result);
        return result;
    }
};