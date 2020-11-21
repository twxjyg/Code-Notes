namespace data_struct_types
{
    template <typename T>
    struct BinaryTreeNode
    {
        BinaryTreeNode(T data): data{data}, left{nullptr}, right{nullptr} {}
        T data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;
    };

    template <typename T>
    struct LinkListNode
    {
        T data;
        LinkListNode *next;
    };
} // namespace data_struct_types
