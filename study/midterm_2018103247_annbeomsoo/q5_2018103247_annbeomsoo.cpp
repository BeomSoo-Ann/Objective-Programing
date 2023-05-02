#include <iostream>

void generate_permutations(std::string &str, int start, int end)
{
    std::cout << str[0] << str[1] << str[2] << std::endl;
    std::cout << str[0] << str[2] << str[1] << std::endl;
    std::cout << str[1] << str[0] << str[2] << std::endl;
    std::cout << str[1] << str[2] << str[0] << std::endl;
    std::cout << str[2] << str[1] << str[0] << std::endl;
    std::cout << str[2] << str[0] << str[1] << std::endl;
}

int main()
{
    std::string str = "IVE";
    generate_permutations(str, 0, str.length() - 1);
    return 0;
}