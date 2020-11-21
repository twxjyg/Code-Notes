#include <array>
#include <iostream>

int main(int argc, char const *argv[])
{
    const int M = 4;
    const int N = 4;
    std::array<std::array<int, N>, M> matrix;

    matrix[0] = {1, 2, 3, 4};
    matrix[1] = {12, 2, 31, 4};
    matrix[2] = {1, 2, 3, 422};
    matrix[3] = {1, 2, 32, 2};

    std::array<std::array<int, N>, M> dp;

    int sum = 0;
    for (int i = 0; i < M; i++)
    {
        sum += matrix[i][0];
        dp[i][0] += sum;
    }

    sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += matrix[0][i];
        dp[0][i] += sum;
    }

    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j < N; j++)
        {
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
        }
    }
    std::cout << dp[M - 1][N - 1] << std::endl;
    return 0;
}
