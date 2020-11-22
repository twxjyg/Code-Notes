#ifndef DATA_STRUCT_TYPES_H_
#define DATA_STRUCT_TYPES_H_

namespace data_struct_types
{
    template <typename T>
    struct BinaryTreeNode
    {
        BinaryTreeNode(T data) : data{data}, left{nullptr}, right{nullptr} {}
        T data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;
    };

    template <typename T>
    struct LinkListNode
    {
        LinkListNode(T data) : data{data}, next{nullptr} {}
        T data;
        LinkListNode *next;
    };
} // namespace data_struct_types

#endif // DATA_STRUCT_TYPES_H_