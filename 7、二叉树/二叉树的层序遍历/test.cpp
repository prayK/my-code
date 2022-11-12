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
    //迭代法
    vector<vector<int>> LevelOrderTraversal(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> vec;
            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的(这个size用的好，刚好是某一层的深度)
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front(); //还是要将即将要出队列的元素转存一下，因为出队列时不会返回
                q.pop();
                vec.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
    //递归法
    vector<vector<int>> CursionLevelOrderTraversal(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        int Depth = 3; //get the depth of the tree

        for (int i = 0; i < Depth; ++i)
        {
            vector<int> rec;
            LevelOrder(root, rec, i);
            res.push_back(rec);
        }
        return res;
    }
    void LevelOrder(TreeNode *root, vector<int> &rec, int i)
    {
        if (i == 0)
        {
            rec.push_back(root->val);
            return;
        }
        LevelOrder(root->left, rec, i - 1);
        LevelOrder(root->right, rec, i - 1);
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    TreeNode *T;
    vector<vector<int>> res;

    CreateBiTree(&T);
    res = s.LevelOrderTraversal(T);

    for (vector<vector<int>>::iterator it = res.begin(); it != res.end(); ++it)
    {
        for (vector<int>::iterator it1 = (*it).begin(); it1 != (*it).end(); ++it1)
        {
            cout << *it1 << " ";
        }
        cout << endl;
    }

    /*
    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = 0; j < res.size(); ++j)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
*/
    return 0;
}