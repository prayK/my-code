#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void CreateBiTree(TreeNode **T)
{
  *T = (TreeNode *)malloc(sizeof(TreeNode));
  (*T)->val = 1;
  (*T)->left = (TreeNode *)malloc(sizeof(TreeNode));
  (*T)->right = (TreeNode *)malloc(sizeof(TreeNode));

  (*T)->left->val = 2;
  (*T)->left->left = (TreeNode *)malloc(sizeof(TreeNode));
  (*T)->left->right = (TreeNode *)malloc(sizeof(TreeNode));
  (*T)->left->right->val = 5;
  (*T)->left->right->left = NULL;
  (*T)->left->right->right = NULL;

  (*T)->right->val = 3;
  (*T)->right->left = (TreeNode *)malloc(sizeof(TreeNode));
  (*T)->right->left->val = 6;
  (*T)->right->left->left = NULL;
  (*T)->right->left->right = NULL;

  (*T)->right->right = (TreeNode *)malloc(sizeof(TreeNode));
  (*T)->right->right->val = 7;
  (*T)->right->right->left = NULL;
  (*T)->right->right->right = NULL;

  (*T)->left->left->val = 4;
  (*T)->left->left->left = NULL;
  (*T)->left->left->right = NULL;
}

class Solution
{
public:
  vector<int> PreorderTraversal(TreeNode *root)
  {
    stack<TreeNode *> st;
    vector<int> result;
    if (root == nullptr)
      return result;
    st.push(root);
    while (!st.empty())
    {
      TreeNode *node = st.top(); //先将栈顶元素保存下来，因为弹栈时不会返回  //中
      st.pop();
      result.push_back(node->val);
      if (node->right) //右(空节点不入栈)
        st.push(node->right);
      if (node->left) //左(空节点不入栈)
        st.push(node->left);
    }
    return result;
  }

  vector<int> InorderTraversal(TreeNode *root)
  {
    vector<int> result;
    if (root == nullptr)
      return result;
    stack<TreeNode *> st;
    TreeNode *cur = root;

    while ((cur != nullptr) || (!st.empty())) //当cur为NULL或者栈为空时，表明树遍历完成
    {
      while (cur != nullptr)
      {
        st.push(cur);
        cur = cur->left;
      }

      cur = st.top();
      st.pop();
      res.push_back(cur->val);
      cur = cur->right;
    }
    return result;
  }

  //只需要调整一下先序遍历的代码顺序，就变成中右左的遍历顺序，然后在反转result数组，输出的结果顺序就是左右中
  vector<int> PostderTraversal(TreeNode *root)
  {
    vector<int> result;
    stack<TreeNode *> st;
    if (root == nullptr)
      return result;
    st.push(root);
    while (!st.empty())
    {
      TreeNode *node = st.top();
      st.pop();
      result.push_back(node->val);
      if (node->left) //左(空节点不入栈)
        st.push(node->left);
      if (node->right) //右(空节点不入栈)
        st.push(node->right);
    }
    reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
    return result;
  }
};

int main(int argc, char *argv[])
{
  Solution s;
  TreeNode *T;
  vector<int> res;

  CreateBiTree(&T);
  res = s.PostderTraversal(T);

  for (auto &i : res)
  {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}