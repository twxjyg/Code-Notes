#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
    // given string: 12345123
    // output all posible ip address
    std::string ip = "1234512345";

    int count = 0;

    for (int s0 = 0; s0 <= 3; s0++)
    {
        for (int s1 = s0 + 1; s1 <= s0 + 3; s1++)
        {
            for (int s2 = s1 + 1; s2 <= s1 + 3; s2++)
            {
                for (int s3 = s2 + 1; s3 <= s2 + 3; s3++)
                {
                    const int l0 = s1 - s0;
                    const int l1 = s2 - s1;
                    const int l2 = s3 - s2;
                    const int l3 = ip.size() - s3;
                    if (l0 > 0 && l0 <= 3 && l1 > 0 && l1 <= 3 && l2 > 0 && l2 <= 3 && l3 > 0 && l3 <= 3)
                    {
                        const std::string &i0 = ip.substr(0, l0);
                        const std::string &i1 = ip.substr(s1, l1);
                        const std::string &i2 = ip.substr(s2, l2);
                        const std::string &i3 = ip.substr(s3, l3);
                        const int n0 = std::stoi(i0);
                        const int n1 = std::stoi(i1);
                        const int n2 = std::stoi(i2);
                        const int n3 = std::stoi(i3);
                        if (n0 >=0 && n0 <= 255 && n1 >= 0 && n1 <= 255 && n2 >=0 && n2 <= 255 && n3 >=0 && n3 <= 255) {
                            std::cout << i0 << "." << i1 << "." << i2 << "." << i3 << std::endl;
                            count++;
                        }
                    }
                }
            }
        }
    }

    std::cout << "Given string:" << ip << std::endl;
    std::cout << "total number of possible IP address:" << count << std::endl;

    return 0;
}
