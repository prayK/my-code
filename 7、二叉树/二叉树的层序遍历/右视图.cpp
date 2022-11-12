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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                if (i == (size - 1))
                    res.push_back(node->val); // 将每一层的最后元素放入res数组中
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}