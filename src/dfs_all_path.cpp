#include "data_struct_types.h"
#include <vector>
#include <iostream>
#include <deque>
#include "print_utils.h"

using namespace data_struct_types;
using namespace print_utils;

std::vector<int> path;
std::vector<std::vector<int>> all_path;
int tree_height = 0;

void TraverseDFS(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    path.push_back(root->data);
    if (root->left == nullptr || root->left == nullptr)
    {
        all_path.push_back(path);
        std::cout << path << std::endl;
        tree_height = std::max(static_cast<int>(path.size()), tree_height);
    }

    TraverseDFS(root->left);
    if (root->left != nullptr || root->right != nullptr)
    {
        path.pop_back();
    }

    TraverseDFS(root->right);
    if (root->left != nullptr || root->right != nullptr)
    {
        path.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(0);
    root->left = new BinaryTreeNode<int>(1);
    root->right = new BinaryTreeNode<int>(2);
    root->left->left = new BinaryTreeNode<int>(3);
    root->left->right = new BinaryTreeNode<int>(4);

    TraverseDFS(root);

    std::cout << tree_height << std::endl;

    return 0;
}
