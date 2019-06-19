#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
  public:
    vector<int> postorderTraversal(TreeNode* root) {
      stack<TreeNode*>s;
      vector<int>v;
      TreeNode *cur = root;
      TreeNode *last = NULL;
      while(cur != NULL || !s.empty())
      {
        while(cur != NULL)
        {
          s.push(cur);
          cur = cur->left;
        }
        TreeNode *top = s.top();
        if(top->right == NULL)
        {
          s.pop();
          v.push_back(top->val);
          last = top;
        }else if(top->right == last)
        {
          s.pop();
          v.push_back(top->val);
          last = top; 
        }else{
          cur = top->right;
        }
      }
      return v;
    }
};
