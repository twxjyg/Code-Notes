#include "data_struct_types.h"
#include "print_utils.h"
#include <deque>

using namespace data_struct_types;
using namespace print_utils;

bool IsBinaryTreeSymmetrical(BinaryTreeNode<int> *root)
{
    std::deque<BinaryTreeNode<int> *> level_queue;
    std::deque<int> stack;
    level_queue.push_front(root);
    stack.push_front(root->data);
    while (!level_queue.empty())
    {
        auto node = level_queue.back();
        level_queue.pop_back();
        if (!stack.empty() && node->data == stack.front())
        {
            stack.pop_front();
        }
        else
        {
            stack.push_front(node->data);
        }

        if (node->left != nullptr)
        {
            level_queue.push_front(node->left);
        }

        if (node->right != nullptr)
        {
            level_queue.push_front(node->right);
        }
    }
    return stack.empty();
}

int main(int argc, char const *argv[])
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(0);
    root->left = new BinaryTreeNode<int>(1);
    root->right = new BinaryTreeNode<int>(1);
    root->left->left = new BinaryTreeNode<int>(3);
    root->left->right = new BinaryTreeNode<int>(4);

    root->right->left = new BinaryTreeNode<int>(4);
    root->right->right = new BinaryTreeNode<int>(3);

    bool symmetrical = IsBinaryTreeSymmetrical(root);
    std::cout << symmetrical << std::endl;

    return 0;
}
