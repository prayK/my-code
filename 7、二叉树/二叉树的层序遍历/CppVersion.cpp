#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

void CreateTree(TreeNode **root)
{
    (*root) = new TreeNode(1);
    (*root)->left = new TreeNode(2);
    (*root)->right = new TreeNode(3);

    (*root)->left->left = new TreeNode(4);
    (*root)->left->right = new TreeNode(5);

    (*root)->right->left = new TreeNode(6);
    (*root)->right->right = new TreeNode(7);

    (*root)->left->left->left = nullptr;
    (*root)->left->left->right = nullptr;
    (*root)->left->right->left = nullptr;
    (*root)->left->right->right = nullptr;

    (*root)->right->left->left = nullptr;
    (*root)->right->left->right = nullptr;
    (*root)->right->right->left = nullptr;
    (*root)->right->right->right = nullptr;
}

class Solution
{
public:
    vector<vector<int>> IterateLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if(root == nullptr)
        {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> vec;
            for(int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                vec.push_back(node->val);

                if(node->left != nullptr)
                {
                    q.push(node->left);
                }
                if(node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
    vector<vector<int>> CursionLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if(root == nullptr)
        {
            return res;
        }
        int depth = 3;
        for(int i = 0; i < depth; ++i)
        {
            vector<int> vec;
            CursionLevelOrderTraversal(root, vec, i);
            res.push_back(vec);
        }
        return res;
    }
    void CursionLevelOrderTraversal(TreeNode *root, vector<int> &vec, int i)
    {
        if(i == 0)
        {
            vec.push_back(root->val);
            return ;
        }
        CursionLevelOrderTraversal(root->left, vec, i - 1);
        CursionLevelOrderTraversal(root->right, vec, i - 1);
    }
};

int main()
{
    Solution MySolution;
    TreeNode *T;
    vector<vector<int>> res;

    CreateTree(&T);
    res = MySolution.CursionLevelOrder(T);

    for(vector<vector<int>>::iterator it = res.begin(); it != res.end(); ++it)
    {
        for(vector<int>::iterator it1 = it->begin(); it1 != it->end(); ++it1)
        {
            cout << *it1 << " ";
        }
        cout << endl;
    }

    return 0;
}
