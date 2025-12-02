#include <string>
#include <sstream>
using namespace std;

// ./precompiled/TreeNode.h

#ifndef TREENODE_H
#define TREENODE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif // TREENODE_H

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "# ";
        return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return decode(ss);
    }
    
    TreeNode* decode(stringstream& ss) {
        string val;
        ss >> val;
        if (val == "#") return nullptr;
        
        TreeNode* node = new TreeNode(stoi(val));
        node->left = decode(ss);
        node->right = decode(ss);
        return node;
    }
};
