#ifndef SOLVER
#define SOLVER

#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <vector>
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

	void printSolution(std::string filename)
	{
		std::ofstream file;
		file.open(filename);
		for (std::set<std::string>::iterator it = solution.begin(); it != solution.end(); ++it)
		{
			file << *it << std::endl;
		}
		file.close();
	}
	
	void boardTraverse (const Dictionary *dict, const std::vector<std::vector<char>> boardBlueprint, int row, int col, std::string word) { //this is one full board traverse from selected starting position
		
		std::vector<std::vector<char>> board = boardBlueprint; //this makes a deep copy of boardBlueprint

		if (row < 0 || row >= parameters::ROW || col < 0 || col >= parameters::COL) {
			return;
		}
		if (board[row][col] == '*') {
			return;
		}
		word += board[row][col];
		if (dict->prefixExists(word)) {
			if (dict->wordExists(word)) {
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

	void solve(const Dictionary *dict, const std::vector<std::vector<char>> board) { //this calls boardTraverse for every starting position
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				boardTraverse(dict, board, i, j, "");
			}
		}
	}
};

#endif