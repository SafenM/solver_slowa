#ifndef SOLVER
#define SOLVER

#include <iostream>
#include <set>
#include <string>
#include "dictionary.hpp"
#include "parameters.hpp"

class Solver {
private:
	
	std::set<std::string> solution;
	
public:
	
	void printSolution()
	{
		for (std::set<std::string>::iterator it = solution.begin(); it != solution.end(); ++it)
		{
			std::cout << *it << std::endl;
		}
	}
	
	void boardTraverse (const Dictionary &dict, const char boardBlueprint[parameters::ROW][parameters::COL], int row, int col, std::string word) {
		char board[parameters::ROW][parameters::COL];
	
		for (int i = 0; i < parameters::ROW; i++) {
			for (int j = 0; j < parameters::COL; j++) {
				board[i][j] = boardBlueprint[i][j];
			}
		}
	
		if (row < 0 || row >= parameters::ROW || col < 0 || col >= parameters::COL) {
			//cout << "out of bounds" << endl;
			return;
		}
		if (board[row][col] == '*') {
			//cout << "star" << endl;
			return;
		}
		word += board[row][col];
		if (dict.prefixExists(word)) {
			//cout << "found" << endl;
			if (dict.wordExists(word)) {
				solution.insert(word);
			}
			board[row][col] = '*';
			boardTraverse(dict, board, row, col + 1, word);
			boardTraverse(dict, board, row, col - 1, word);
			boardTraverse(dict, board, row + 1, col, word);
			boardTraverse(dict, board, row - 1, col, word);
			boardTraverse(dict, board, row + 1, col + 1, word);
			boardTraverse(dict, board, row + 1, col - 1, word);
			boardTraverse(dict, board, row - 1, col + 1, word);
			boardTraverse(dict, board, row - 1, col - 1, word);
			board[row][col] = '.';
		}
	}
};

#endif