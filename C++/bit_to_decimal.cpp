#include <iostream>
#include <string>

int converBitToDecimal(const std::string &str) {
    int decimal = 0;
    int bit = 1;

    for(int i = str.size() - 1; i >= 0; i--) {
        if(str[i] == '1')
            decimal += bit;
        bit *= 2;
    }

    return decimal;
}

int main() {
    std::string byte = "100";
    std::cout << converBitToDecimal(byte);
}