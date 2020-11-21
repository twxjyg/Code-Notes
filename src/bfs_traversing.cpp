#include "data_struct_types.h"
#include <vector>
#include <deque>
#include <iostream>

using namespace data_struct_types;

std::vector<int> output;
void TraverseBFS(BinaryTreeNode<int> *root)
{
    std::deque<BinaryTreeNode<int> *> level_queue;
    if (root != nullptr)
    {
        level_queue.push_front(root);
        output.push_back(root->data);
    }
    while (!level_queue.empty())
    {
        auto num = level_queue.size();
        while (num--)
        {
            auto node = level_queue.back();
            level_queue.pop_back();
            if (node->left != nullptr)
            {
                output.push_back(node->left->data);
                level_queue.push_front(node->left);
            }
            if (node->right != nullptr)
            {
                output.push_back(node->right->data);
                level_queue.push_front(node->right);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(0);
    root->left = new BinaryTreeNode<int>(1);
    root->right = new BinaryTreeNode<int>(2);
    root->left->left = new BinaryTreeNode<int>(3);
    root->left->right = new BinaryTreeNode<int>(4);

    TraverseBFS(root);

    std::cout << "[";
    for (auto data : output) {
        std::cout << data << ",";
    }
    std::cout << "]" << std::endl;
    return 0;
}
