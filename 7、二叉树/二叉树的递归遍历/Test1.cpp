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
    //前序遍历
    vector<int> Preorder(TreeNode *root)
    {
        vector<int> result;
        if (root == nullptr)
        {
            return res;
        }
        Preordertraversal(root, result);
        return result;
    }
    void Preordertraversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == nullptr)
            return;
        vec.push_back(cur->val);            //中
        Preordertraversal(cur->left, vec);  //左
        Preordertraversal(cur->right, vec); //右
    }
    //中序遍历
    vector<int> Inorder(TreeNode *root)
    {
        vector<int> result;
        if (root == nullptr)
        {
            return res;
        }
        Inordertraversal(root, result);
        return result;
    }
    void Inordertraversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == nullptr)
            return;
        Inordertraversal(cur->left, vec);  //左
        vec.push_back(cur->val);           //中
        Inordertraversal(cur->right, vec); //右
    }
    //后序遍历
    vector<int> Postorder(TreeNode *root)
    {
        vector<int> result;
        if (root == nullptr)
        {
            return res;
        }
        Postordertraversal(root, result);
        return result;
    }
    void Postordertraversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == nullptr)
            return;
        Postordertraversal(cur->left, vec);  //左
        Postordertraversal(cur->right, vec); //右
        vec.push_back(cur->val);             //中
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    TreeNode *T;
    vector<int> res;

    CreateBiTree(&T);
    res = s.Postorder(T);

    for (auto &i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
