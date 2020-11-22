#include "data_struct_types.h"
#include "print_utils.h"
using namespace print_utils;
using namespace data_struct_types;

template <typename T>
LinkListNode<T>* ReverseLinkList(LinkListNode<T> *root)
{
    LinkListNode<T> *head = nullptr;
    LinkListNode<T> *next = nullptr;
    LinkListNode<T> *curr = root;

    while (curr != nullptr)
    {
        next = curr->next;

        curr->next = head;

        head = curr;
        curr = next;
    }
    return head;
}

int main(int argc, char const *argv[])
{
    LinkListNode<int> *root = new LinkListNode<int>(0);
    root->next = new LinkListNode<int>(1);
    root->next->next = new LinkListNode<int>(2);
    root->next->next->next = new LinkListNode<int>(3);
    root->next->next->next->next = new LinkListNode<int>(4);

    std::cout << "given link list:" << std::endl;
    std::cout << root << std::endl;

    auto new_root = ReverseLinkList(root);
    std::cout << "output reversed link list:" << std::endl;
    std::cout << new_root << std::endl;
    return 0;
}
