#include <iostream>

void foo(int& a)
{
    std::cout << "call lvalue version" << std::endl;
    ++a;
}
void foo(int&& a)
{
    std::cout << "call rvalue version" << std::endl;
    ++a;
}
class Data {
public:
    Data(int a) :a_{a} {
        std::cout << "normal constructor called" << std::endl;
    }
    Data(Data& a) : a_{a.Get()} {
        std::cout << "copy constructor called" << std::endl;
    }
    Data(Data&& a): a_{std::move(a.Get())} {
        std::cout << "move constructor called" << std::endl;
    }
    int Get() { return a_; }
private:
    int a_;
};
Data Builder() {
    Data data(11);
    return data;
}
void Process(Data&& d) {
    std::cout << "Process data by rvalue ref version" << std::endl;
}
void Process(const Data& d) {
    std::cout << "Process data by const lvalue ref version" << std::endl;
}

int main(int argc, char const *argv[])
{
    std::cout << "1. rvalue reloaded function" << std::endl;
    int a = 10;
    foo(a);
    foo(10);
    std::cout << "a:" << a << std::endl;

    std::cout << "2. explicity call rvalue version" << std::endl;

    foo(std::move(a));
    std::cout << "a:" << a << std::endl;
    std::cout << "3. Customer move constructor" << std::endl;
    Data data(10);
    Data data_1 = std::move(data);
    Data data_2 = data;
    std::cout << "4. pass data to process" << std::endl;
    Process(data);
    Process(Data(10));
    Process(std::move(data_2));
    Process(Builder());

    return 0;
}
