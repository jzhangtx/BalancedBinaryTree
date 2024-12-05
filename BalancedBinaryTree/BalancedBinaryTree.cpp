// BalancedBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>

class Node
{
public:
    Node* left;
    Node* right;
    int data;

    Node(int d)
        : data(d)
        , left(nullptr)
        , right(nullptr)
    {}
};

Node* ArrayToTree(const std::vector<int>& v)
{
    if (v.size() == 0)
        return nullptr;
    Node* root = new Node(v[0]);
    std::queue<Node*> q;
    q.push(root);
    bool l = true;
    for (size_t i = 1; i < v.size(); ++i, l = !l)
    {
        Node* pNode = q.front();
        if (!l)
            q.pop();
        if (v[i] != -1)
        {
            if (l)
            {
                pNode->left = new Node(v[i]);
                q.push(pNode->left);
            }
            else
            {
                pNode->right = new Node(v[i]);
                q.push(pNode->right);
            }
        }
    }

    return root;
}

void FreeTree(Node* pNode)
{
    if (pNode == nullptr)
        return;

    FreeTree(pNode->left);
    FreeTree(pNode->right);

    delete pNode;
}

int GetHeight(Node* pNode)
{
    if (pNode == nullptr)
        return 0;

    int l = GetHeight(pNode->left);
    int r = GetHeight(pNode->right);

    return 1 + std::max(l, r);
}

bool IsBinaryTreeBalanced(Node* root)
{
    if (root == nullptr)
        return true;

    if (!IsBinaryTreeBalanced(root->left))
        return false;
    if (!IsBinaryTreeBalanced(root->right))
        return false;

    int difference = GetHeight(root->left) - GetHeight(root->right);
    if (difference >= -1 && difference <= 1)
        return true;

    return false;
}

int main()
{
    while (true)
    {
        std::cout << "Number of nodes in the tree: ";
        int count = 0;
        std::cin >> count;
        if (count == 0)
            break;

        std::cout << "Values of the tree nodes: ";
        std::vector<int> v(count, 0);
        for (int i = 0; i < count; ++i)
            std::cin >> v[i];

        Node* root = ArrayToTree(v);

        std::cout << "The binary tree is " << (IsBinaryTreeBalanced(root) ? "" : "not ") << "balanced!" << std::endl;
        FreeTree(root);
    }
}
