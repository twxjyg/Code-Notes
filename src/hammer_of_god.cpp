#include <iostream>
#include <vector>
#include <map>


#define SET_GETTER(FunctionName) \
    template <typename T>     \
    std::string FunctionName(const T& value) { \
        return "Unknown"; \
    }

#define SET_NAME(type, name) \
    template <> \
    std::string GetTypeName(const type& value) { \
        return name; \
    }

#define AUTO_SET_NAME(type) SET_NAME(type, #type)

SET_GETTER(GetTypeName)

SET_NAME(char, "char") // just for fun, below is God !

AUTO_SET_NAME(int)
AUTO_SET_NAME(bool)
AUTO_SET_NAME(float)
AUTO_SET_NAME(double)
AUTO_SET_NAME(int16_t)
AUTO_SET_NAME(std::size_t)
AUTO_SET_NAME(std::vector<int>)


int main(int argc, char** argv) {
    std::cout << GetTypeName(10) << std::endl;
    std::cout << GetTypeName(10.0f) << std::endl;
    std::cout << GetTypeName(10.0) << std::endl;
    std::cout << GetTypeName('c') << std::endl;
    std::cout << GetTypeName(std::string("10")) << std::endl;
    std::cout << GetTypeName(std::is_array<std::vector<int>>::value) << std::endl;
    std::cout << GetTypeName((int16_t)10) << std::endl;
    std::cout << GetTypeName(std::vector<int>{10}) << std::endl;
    std::cout << GetTypeName(std::vector<int>{10}.size()) << std::endl;
    std::cout << __FILE__ << std::endl;
    return 0;
}
