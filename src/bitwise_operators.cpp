#include <bitset>
#include <iostream>

template <typename Container, typename Data>
void BitwisePush(const Data data, const int length, Container* container) {
    *container <<= length;
    *container+= data;
}

template <typename Container, typename Data>
void BitwisePop(Container* container, int length, Data* data) {
    Container temp1 = *container;
    *container >>= length;
    Container temp2 = *container << length;
    *data = temp1 - temp2;
}

int main(int argc, char** argv) {
    int32_t container = 0;
    BitwisePush(3, 8, &container);
    std::cout << "========push 3 to container======" << std::endl;
    std::cout << "container decimal value:" << container << std::endl;
    std::cout << "container binay value:" << std::bitset<32>(container) << std::endl;
    std::cout << "========after pop 8 bit==========" << std::endl;
    uint8_t data;
    BitwisePop(&container, 8, &data);
    std::cout << "data decimal value:" << static_cast<int>(data) << std::endl;
    std::cout << "container binary value:" << std::bitset<32>(container) << std::endl;
}