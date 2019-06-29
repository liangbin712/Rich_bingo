#include<iostream>
using namespace std;
struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *parent;
};
TreeNode* InorderFind(TreeNode *node)
{
  if(node == NULL || node->right == NULL)
    return NULL; 
  if(node->right == NULL)
  {
    if(node->parent->left == node)
    {
      if(node->right != NULL)
      {
        return node->right;
      }else{
        return node->parent;
      }
    }else{
      TreeNode *last = node->parent;
      while(last->parent->left != last)
      {
        last = last->parent;
        if(last == NULL)
        {
          return NULL;
        }
      }
      return last->parent;
    }
  }
  else{
      TreeNode *next = node->right;
      while(next->left != NULL)
      {
        next = next->left;
      }
      return next;
  }
}
int main()
{
  TreeNode *a = new TreeNode;
  TreeNode *b = new TreeNode;
  TreeNode *c = new TreeNode;
  TreeNode *d = new TreeNode;
  TreeNode *e = new TreeNode;
  TreeNode *f = new TreeNode;
  TreeNode *g = new TreeNode;
  TreeNode *h = new TreeNode;
  TreeNode *i = new TreeNode;
  a->parent = NULL;
  a->left = b;
  a->right = c;
  b->parent = a;
  b->left = d;
  b->right = e;
  c->parent = a;
  c->left = f;
  c->right = g;
  d->parent = b;
  d->left = NULL;
  d->right = NULL;
  e->parent = b;
  e->left = h;
  e->right = i;
  f->parent = c;
  f->left = NULL;
  f->right = NULL;
  g->parent = c;
  g->left = NULL;
  g->right = NULL;
  h->parent = e;
  h->left = NULL;
  h->right = NULL;
  i->parent = e;
  i->left = NULL;
  i->right = NULL;
  a->val = 1;
  b->val = 2;
  c->val = 3;
  d->val = 4;
  e->val = 5;
  f->val = 6;
  g->val = 7;
  h->val = 8;
  i->val = 9;
  TreeNode * p = InorderFind(a);
  cout<<p->val<<endl;
}
