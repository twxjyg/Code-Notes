#include <iostream>
#include <vector>

namespace print_utils
{

    template <typename T>
    std::ostream& operator<<(std::ostream &out, const std::vector<T> &list)
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
} // namespace print_utils