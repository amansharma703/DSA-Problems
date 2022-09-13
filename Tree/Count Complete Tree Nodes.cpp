// PROBLEM LINK
// https://leetcode.com/problems/count-complete-tree-nodes/

/*
    Solution : 
    Time complexity : O(N) 
    Space Complexity : O(N) 
*/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};