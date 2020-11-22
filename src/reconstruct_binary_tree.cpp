#include <vector>
#include "data_struct_types.h"
#include <iostream>
using namespace data_struct_types;

template <typename T>
BinaryTreeNode<T> *ReconstructBinaryTree(const std::vector<T> &pre_order, const std::vector<T> &in_order)
{
    if (pre_order.empty() || in_order.empty())
    {
        return nullptr;
    }
    BinaryTreeNode<T> *root = new BinaryTreeNode<T>(pre_order.front());
    std::cout << root->data << std::endl;

    for (int i = 0; i < in_order.size(); i++)
    {
        if (in_order[i] == root->data)
        {
            root->left = ReconstructBinaryTree(std::vector<T>{pre_order.begin() + 1, pre_order.begin() + i + 1}, std::vector<T>{in_order.begin(), in_order.begin() + i});
            root->right = ReconstructBinaryTree(std::vector<T>{pre_order.begin() + i + 1, pre_order.end()}, std::vector<T>{in_order.begin() + i + 1, in_order.end()});
        }
    }
    return root;
}

template <typename T>
std::vector<T> BinaryTreeToVector(BinaryTreeNode<T> *root)
{
}

int main(int argc, char const *argv[])
{
    std::vector<int> pre_order = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> in_order = {3, 2, 4, 1, 6, 5, 7};

    BinaryTreeNode<int> *root = ReconstructBinaryTree<int>(pre_order, in_order);

    return 0;
}
