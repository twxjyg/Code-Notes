#include <iostream>
#include <array>

template <typename T, std::size_t rows, std::size_t cols>
class Matrix
{
  public:
    Matrix(const T &default_value)
    {
        for (unsigned int i = 0; i < rows; i++)
        {
            for (unsigned int j = 0; j < cols; j++)
            {
                data_[i][j] = default_value;
            }
        }
    }
    template <std::size_t other_rows, std::size_t other_cols, std::size_t new_rows, std::size_t new_cols>
    Matrix<T, new_rows, new_cols> dot(const Matrix<T, other_rows, other_cols> &other)
    {
        Matrix<T, rows, other_cols> data(0.0);
        for (unsigned int row_index = 0; row_index < rows; row_index++)
        {
            for (unsigned int col_index = 0; col_index < other_cols; col_index++)
            {
                for (unsigned int index = 0; index < cols; index++)
                {
                    data[row_index][col_index] += data_[row_index][index] * other[index][col_index];
                }
            }
        }
        return data;
    }

  private:
    std::array<std::array<T, cols>, rows> data_;
};

int main(int argc, char const *argv[])
{
    Matrix<double, 3, 3> a(0), b(1);
    auto c = a.dot(b);
    std::cout << c << std::endl;
    return 0;
}
