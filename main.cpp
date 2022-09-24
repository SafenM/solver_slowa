#include <iostream>
#include <fstream>
#include "dictionary.hpp"
#include "solver.hpp"

int main() {
    Dictionary dict("slowa.txt");
    //std::cout << dict.wordExists("kot") << std::endl;
    //std::cout << dict.wordExists("g©˜la") << std::endl;
    //std::cout << dict.wordExists("g©˜") << std::endl;
    //std::cout << dict.wordExists("asdafdgfsdfgˆ¥˜¢¥˜") << std::endl;

    Solver solver;
    const char board[4][4] = {
        {'a', 'b', 'c', 'd'},
        {'e', '¥', 'g', 'h'},
        {'i', '†', 'k', 'l'},
        {'m', 'n', 'o', 'p'}
    };
    for (int i = 0; i < parameters::ROW; i++) {
		for (int j = 0; j < parameters::COL; j++) {
			solver.boardTraverse(&dict, board, i, j, "");
		}
	}
    solver.printSolution();

    return 0;
}