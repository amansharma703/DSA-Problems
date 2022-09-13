// PROBLEM LINK
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/

/*
    Solution : 
    Time complexity : O(N) 
    Space Complexity : O(N) 
*/


class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int qSize = size(q);
            int maxElem = INT_MIN;
            for(int i=0;i<qSize;i++){
                auto top = q.front();
                maxElem = max(maxElem,top->val);
                q.pop();
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
            ans.push_back(maxElem);
        }
            
        return ans;
    }
};