#include <vector>
#include <iostream>

int FindMax(const std::vector<int> &data, int start, int end)
{
    int mid = (start + end) / 2;
    int max = mid;
    if (data[mid] > data[mid - 1] && data[mid] > data[mid + 1])
    {
        return mid;
    }
    else
    {
        if (data[mid] > data[mid + 1])
        {
            FindMax(data, start, mid);
        }
        else
        {
            FindMax(data, mid, end);
        }
    }
}
int BiSearch(const std::vector<int> &data, int start, int end, int target, bool up)
{
    int mid = (start + end) / 2;
    if (data[mid] == target)
    {
        return mid;
    }
    if (start == end)
    {
        return data.size();
    }
    if (up)
    {
        if (data[mid] > target)
        {
            BiSearch(data, start, mid, target, up);
        }
        else
        {
            BiSearch(data, mid, end, target, up);
        }
    } else {
        if (data[mid] > target)
        {
            BiSearch(data, mid, end, target, up);
        }
        else
        {
            BiSearch(data, start, mid, target, up);
        }
    }
}
std::vector<int> DoubleBiSearch(const std::vector<int> &data, const int &target)
{
    int max = FindMax(data, 0, data.size() - 1);
    std::cout << "max:" << max << std::endl;
    bool up = true;
    int ret1 = BiSearch(data, 0, max, target, up);
    int ret2 = BiSearch(data, max, data.size() - 1, target, !up);
    std::vector<int> rets;
    if (ret1 != data.size())
    {
        rets.push_back(ret1);
    }
    if (ret2 != data.size())
    {
        rets.push_back(ret2);
    }
    return rets;
}
int main(int argc, char const *argv[])
{
    std::vector<int> data = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> found = DoubleBiSearch(data, 5);
    for (auto ret : found)
    {
        std::cout << "found:" << ret << std::endl;
    }
    return 0;
}
