// PROBLEM LINK
// https://leetcode.com/problems/binary-tree-level-order-traversal/

/*
    Solution : 
    Time complexity : O(N) 
    Space Complexity : O(N) 
*/


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        while(!q.empty()){
            int levSize = size(q);
            vector<int> curr;
            for(int i=0;i<levSize;i++){
                auto top = q.front();
                q.pop();
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
                curr.push_back(top->val);
                
            }
            ans.push_back(curr);
        }
        return ans;
    }
};