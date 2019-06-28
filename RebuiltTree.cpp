#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
  int val;
  TreeNode*left;
  TreeNode*right;
};
int Find(int *inorder,int val,int size)
{
  int i;
  for(i = 0;i < size;i++)
  {
    if(inorder[i] == val)
      return i;
  }
  return -1;
}
TreeNode *Rebuild(int *preorder,int *inorder,int size)
{
  if(size == 0 || preorder == NULL || inorder == NULL)
    return NULL;
  TreeNode *root = new TreeNode;
  root->val=preorder[0];
  int leftsize = Find(inorder,preorder[0],size);
  if(leftsize < 0)
  {
    cout<<"Find leftsize error"<<endl;
    cout<<leftsize<<endl;
    return NULL;
  }
  root->left = Rebuild(preorder+1,inorder,leftsize);
  root->right = Rebuild(preorder+leftsize+1,inorder+leftsize+1,size-leftsize-1);
  return root;
}
int main()
{
  int preorder[8] = {1,2,4,7,3,5,6,8};
  int inorder[8] = {4,7,2,1,5,3,8,6};
  Rebuild(preorder,inorder,8);
}
