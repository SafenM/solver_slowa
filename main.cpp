#include <iostream>
#include <fstream>
#include "dictionary.hpp"

int main() {
    Dictionary dict("slowa.txt");
    std::cout << dict.wordExists("kot") << std::endl;
    std::cout << dict.wordExists("g©˜la") << std::endl;
    std::cout << dict.wordExists("g©˜") << std::endl;
    std::cout << dict.wordExists("asdafdgfsdfgˆ¥˜¢¥˜") << std::endl;
    return 0;
}