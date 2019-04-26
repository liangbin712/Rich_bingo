#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
  TreeNode *left;
  TreeNode *right;
  int value;
}Node;
//二叉树前序遍历
TreeNode *root;
int i = 0;
TreeNode *Preorder(TreeNode *root,int arr[])
{
  if(root == NULL)
  {
    return NULL;
  }
  arr[i] = root->value;
  i++;
  Preorder(root->left,arr);
  Preorder(root->right,arr);
  return root;
}
TreeNode *Inorder(TreeNode *root,int arr[])//二叉树中序遍历
{
  if(root == NULL)
  {
    return NULL;
  }
  Inorder(root->left,arr);
  arr[i] = root->value;
  i++;
  Inorder(root->right,arr);
  return root;
}
TreeNode *Tailorder(TreeNode *root,int arr[])//二叉树后序遍历
{
  if(root == NULL)
  {
    return NULL;
  }
  Tailorder(root->left,arr);
  Tailorder(root->right,arr);
  arr[i] = root->value;
  i++;
  return root;
}
Node *Find(TreeNode *root,int v)//找是否含有数据V的结点
{
  if(root == NULL)
  {
    return NULL;
  }
  if(root->value == v)
  {
    return root;
  }
  Node *node = Find(root->left,v);
  if(node != NULL)
  {
    return node;
  }
  node = Find(root->right,v);
  if(node != NULL)
  {
    return node;
  }else{
    return NULL;
  }
}
int GetHeight(Node *root)//二叉树高度
{
  if(root == NULL)
  {
    return 0;
  }
  int left = GetHeight(root->left) + 1;
  int right = GetHeight(root->right) + 1;
  return (left >right?left:right); 
}
int GetleafSize(Node *root)//二叉树叶子个数
{
  if(root == NULL)
  {
    return 0;
  }
  if(root->left == NULL && root->right == NULL)
  {
    return 1;
  }
  int leafsize = GetleafSize(root->left) + GetleafSize(root->right);
  return leafsize;
}
int nodeSize(Node *root)//二叉树结点个数
{
  if(root == NULL)
  {
    return 0;
  }
  int left = nodeSize(root->left);
  int right = nodeSize(root->right);
  return left + right +1;
}
bool isSame(Node *root,Node *t)//两树是否相同
{
  if(root == NULL && t == NULL)
  {
    return true;
  }
  if(root == NULL || t == NULL)
  {
    return false;
  }
  return root->value == t->value &&isSame(root->left,t->left) && isSame(root->right,t->right);
}
bool preorder(Node *root,Node *t)//判断是否是子数
{
  if(root == NULL)
  {
    return false;
  }
  if(t == NULL)
  {
    return true;
  }
  if(isSame(root,t) == true)
  {
    return true;
  }
  if(preorder(root->left,t) == true)
  {
    return true;
  }
  if(preorder(root->right,t) == true)
  {
    return true;
  }
}
Node *Createtree(char arr[],int size,int *used)//表示了空的创建树
{
  if(size == 0)
  {
    *used = 0;
    return NULL;
  }
  if(*arr == '#' )
  {
    *used = 1;
    return NULL;
  }
  Node *root = (Node *)malloc(sizeof(Node));
  root->value = arr[0];
  int leftused,rightused;
  root->left = Createtree(arr+1,size-1,&leftused);
  root->right = Createtree(arr+1+leftused,size-1-leftused,&rightused);
  *used = leftused + rightused + 1;
  return root;
}
int dFind(char arr[],char size,char num)
{
  int i;
  for(i = 0;i < size;i++)
  {
    if(arr[i] == num)
    {
      return i;
    }
  }
  return -1;
}
Node *build(char preorder[],char inorder[],char size)//无空前序中序创建树
{
  if(size == 0)
  {
    return NULL;
  }
  char num = preorder[0];
  int leftused = dFind(preorder,size,num);
  Node *root = (Node *)malloc(sizeof(Node));
  root->value = preorder[0];
  root->left = build(preorder + 1,inorder,leftused);
  root->right = build(preorder + 1 + leftused,inorder+1+leftused,size-leftused-1);
  return root;
}
int dFind(int array[],int size,int num)
{
  for(int i = 0;i < size;i++)
  {
    if(array[i] == num)
    {
      return i;
    }
  }
  return -1;
}
Node *build2(char inorder[],char posorder[],char size) //无序中序后序创建树
{
  if(size == 0)
  {
    return NULL;
  }
  char num = posorder[size -1];
  int leftused = dFind(inorder,size,num);
  Node *root = (Node *)malloc(sizeof(Node));
  root->value = num;
  root->left = build2(inorder,posorder,leftused);
  root->right = build2(inorder+1+leftused,posorder+leftused,size-leftused-1);
  return root;
}
void LevelOrder(Node * root)
{
  if(root == NULL)
  {
    printf("NULL\n");
  }
  std::queue<Node*> q;
  q.push(root);
  while(!q.empty())
  {
    Node *front = q.front();
    printf("%d ",front->value);
    q.pop();
    if(front->left != NULL)
    {
      q.push(front->left);
      //printf("%d ",front->val);
    }
    if(front->right != NULL)
    {
     q.push(front->right);
    }
  }
  printf("\n");
}
bool isComplete(Node *root)
{
  if(root == NULL)
  {
    return true;
  }
  std::queue<Node *> q;
  q.push(root);
  while(true)
  {
    Node *front = q.front();
    if(front->left != NULL)
    {
      q.push(front->left);
    }else if(front->right == NULL)
    {
      continue;
    }else if(front->right != NULL)
    {
      q.push(front->left);
    }
    if(front->left == NULL && front->right == NULL)
    {
      while(!q.empty())
      {
        q.pop();
      }
      break;
    }
    if(front->left == NULL && front->right != NULL)
    {
      while(!q.empty())
      {
        q.pop();
      }
      return false;
    }
  }
  return true;
}



















