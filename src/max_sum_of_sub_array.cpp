#include <array>
#include <iostream>

int main(int argc, char const *argv[])
{
    // what the fuck ???
    std::array<int, 10> array{10, -2, 4, -8, 1, 8, 9, -7, 2, -8};
    std::array<int, 10> dp;
    dp.fill(0);
    dp[0] = array[0];

    int max = 0;

    for (int j = 1; j < array.size(); j++)
    {
        if (dp[j-1] > 0) {
            dp[j] = dp[j-1] + array[j];
        } else {
            dp[j] = array[j];
        }
        max = std::max(dp[j], max);
    }

    std::cout << max << std::endl;
}
