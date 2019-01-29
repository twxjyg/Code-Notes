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

  private:
    std::array<std::array<T, cols>, rows> data_;
};
int main(int argc, char const *argv[])
{
    Matrix<double, 3, 3> a(0), b(1);
    auto c = a * b;
    std::cout << c << std::endl;
    return 0;
}
