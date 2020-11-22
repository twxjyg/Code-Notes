#ifndef PRINT_UTILS_H_
#define PRINT_UTILS_H_

#include <iostream>
#include <vector>
#include "data_struct_types.h"

namespace print_utils
{
    using namespace data_struct_types;
    template <typename T>
    std::ostream &operator<<(std::ostream &out, const std::vector<T> &list)
    {
        out << "[";
        for (int i = 0; i < list.size(); i++)
        {
            out << list[i];
            if (i != list.size() - 1)
            {
                out << ",";
            }
        }
        out << "]";
        return out;
    }

    template <typename T>
    std::ostream& operator<<(std::ostream &out, const LinkListNode<T> *root)
    {
        auto it = root;
        bool first = true;
        while (it != nullptr)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                out << "->";
            }
            out << it->data;
            it = it->next;
        }
        out << "->" << "null";
        return out;
    }
} // namespace print_utils

#endif // PRINT_UTILS_H_