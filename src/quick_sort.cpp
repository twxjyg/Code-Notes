#include <vector>
#include <iostream>
#include "print_utils.h"

template <typename T>
int Partition(std::vector<T> *collection, int lowest, int highest)
{
    T mid_value = collection->at(lowest);
    bool scan_direction = false; // false: right to left, true: left to right
    while (lowest != highest)
    {
        if (scan_direction == false)
        {
            if (collection->at(highest) < mid_value)
            {
                collection->at(lowest) = collection->at(highest);
                collection->at(highest) = mid_value;
                scan_direction = true;
            }
            else
            {
                highest--;
            }
        }
        if (scan_direction == true)
        {
            if (collection->at(lowest) > mid_value)
            {
                collection->at(highest) = collection->at(lowest);
                collection->at(lowest) = mid_value;
                scan_direction = false;
            }
            else
            {
                lowest++;
            }
        }
    }
    return lowest;
}

template <typename T>
void QuickSort(std::vector<T> *collection, int lowest, int highest)
{
    if (lowest < highest)
    {
        int mid = Partition(collection, lowest, highest);
        QuickSort(collection, lowest, mid - 1);
        QuickSort(collection, mid + 1, highest);
    }
}

template <typename T>
void QuickSort(std::vector<T> *collection)
{
    QuickSort(collection, 0, collection->size() - 1);
}


int main(int argc, char const *argv[])
{
    using namespace print_utils;
    std::vector<int> data = {10, 2, 5, 2, 4, 88, 23, 34, 11, 54, 222, 3};
    std::vector<int> collection = data;
    std::cout << "Quick Sort:" << data << std::endl;
    QuickSort(&collection);
    std::cout << "Result:" << collection << std::endl;
    return 0;
}
