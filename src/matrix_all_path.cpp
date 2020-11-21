#include <array>
#include <iostream>

int all_path = 0;
template <int M, int N>
void TraverseMatrix(std::array<std::array<int, M>, N> &matrix, int start_x, int start_y, int end_x, int end_y)
{

    if (start_x < 0 || start_y < 0 || start_x >= M, start_y >= N)
    {
        return;
    }

    if (matrix[start_x][start_y] != 1)
    {
        matrix[start_x][start_y] = 1;
    }
    else
    {
        return;
    }
    std::cout << start_x << "," << start_y << std::endl;

    if (start_x != end_x || start_y != end_y)
    {

        if (start_x == 0 && start_y == 0)
        {
            TraverseMatrix<M, N>(matrix, start_x, start_y + 1, end_x, end_y);
            TraverseMatrix<M, N>(matrix, start_x + 1, start_y, end_x, end_y);
        }
        else if (start_x == 0)
        {
            TraverseMatrix<M, N>(matrix, start_x, start_y + 1, end_x, end_y);
            TraverseMatrix<M, N>(matrix, start_x, start_y - 1, end_x, end_y);
            TraverseMatrix<M, N>(matrix, start_x + 1, start_y, end_x, end_y);
        }
        else if (start_y == 0)
        {
            TraverseMatrix<M, N>(matrix, start_x, start_y + 1, end_x, end_y);
            TraverseMatrix<M, N>(matrix, start_x - 1, start_y, end_x, end_y);
            TraverseMatrix<M, N>(matrix, start_x + 1, start_y, end_x, end_y);
        }
        else if (start_x == M)
        {
            TraverseMatrix<M, N>(matrix, start_x, start_y - 1, end_x, end_y);
            TraverseMatrix<M, N>(matrix, start_x, start_y + 1, end_x, end_y);
            TraverseMatrix<M, N>(matrix, start_x - 1, start_y, end_x, end_y);
        }
        else if (start_y == N)
        {
            TraverseMatrix<M, N>(matrix, start_x, start_y - 1, end_x, end_y);
            TraverseMatrix<M, N>(matrix, start_x + 1, start_y, end_x, end_y);
            TraverseMatrix<M, N>(matrix, start_x - 1, start_y, end_x, end_y);
        }
        else
        {
            TraverseMatrix<M, N>(matrix, start_x, start_y + 1, end_x, end_y);
            TraverseMatrix<M, N>(matrix, start_x, start_y - 1, end_x, end_y);
            TraverseMatrix<M, N>(matrix, start_x + 1, start_y, end_x, end_y);
            TraverseMatrix<M, N>(matrix, start_x - 1, start_y, end_x, end_y);
        }
    }
    else
    {
        all_path++;
        return;
    }
}

int main(int argc, char const *argv[])
{

    throw std::runtime_error("Unfinished");
    const int M = 5;
    const int N = 5;
    std::array<std::array<int, M>, N> matrix;
    for (int i = 0; i < matrix.size(); i++)
    {
        matrix[i].fill(0);
    }
    TraverseMatrix<M, N>(matrix, 0, 0, M - 1, N - 1);
    std::cout << all_path << std::endl;
    return 0;
}
