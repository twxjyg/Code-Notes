#include "data_struct_types.h"
#include <vector>
#include <iostream>
#include <deque>

using namespace data_struct_types;

std::vector<int> output;

void TraverseDFS(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    output.push_back(root->data);
    TraverseDFS(root->left);
    TraverseDFS(root->right);
}

void FastTraverseDFS(BinaryTreeNode<int> *root)
{
    std::deque<BinaryTreeNode<int> *> stack;

    if (root != nullptr)
    {
        stack.push_front(root);
    }
    while (!stack.empty())
    {
        auto node = stack.front();
        stack.pop_front();
        output.push_back(node->data);
        if (node->right != nullptr)
        {
            stack.push_front(node->right);
        }
        if (node->left != nullptr)
        {
            stack.push_front(node->left);
        }
    }
}

int main(int argc, char const *argv[])
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(0);
    root->left = new BinaryTreeNode<int>(1);
    root->right = new BinaryTreeNode<int>(2);
    root->left->left = new BinaryTreeNode<int>(3);
    root->left->right = new BinaryTreeNode<int>(4);

    output.clear();
    TraverseDFS(root);
    std::cout << "Recursive version:" << std::endl;
    std::cout << "[";
    for (auto data : output)
    {
        std::cout << data << ",";
    }
    std::cout << "]" << std::endl;
    output.clear();
    FastTraverseDFS(root);

    std::cout << "Normal version:" << std::endl;
    std::cout << "[";
    for (auto data : output)
    {
        std::cout << data << ",";
    }
    std::cout << "]" << std::endl;

    return 0;
}
