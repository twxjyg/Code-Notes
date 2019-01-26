#include <iostream>

int foo()
{
    return 10;
}
int main(int argc, char const *argv[])
{
    int a = foo();
    int b = std::move(foo());
    int c = std::move(a);

    const int *ca = nullptr;
    ca = &a;
    std::cout << "a:" << a << ","
              << "b:" << b << ","
              << "c:" << c << std::endl;
    return 0;
}
