
// formatted outut looks awful before c++20

#include <iostream>
#include <sstream>
#include <string>

int main() {
    double d = 50.0123456789;

    std::string s;
    std::stringstream sstream;
    sstream.setf(std::ios::fixed);
    sstream.precision(10);
    sstream << d;

    s = sstream.str();
    std::cout << d << std::endl;
    std::cout << s << std::endl;
    return 0;
}
