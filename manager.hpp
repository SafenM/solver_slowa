#ifndef MANAGER
#define MANAGER

#include <iostream>
#include <fstream>
#include <vector>
#include "dictionary.hpp"
#include "solver.hpp"

namespace manager
{
    void get_board_from_file(std::string filename, std::vector<std::vector<char>> &board)
    {
        std::ifstream file;
        file.open(filename);
        for (int i = 0; i < 4; i++)
        {
            std::vector<char> row;
            for (int j = 0; j < 4; j++)
            {
                char c;
                file >> c;
                row.push_back(c);
            }
            board.push_back(row);
        }
        file.close();

    }

    void generate_random_board(std::vector<std::vector<char>> &board)
    {
        for (int i = 0; i < 4; i++)
        {
            std::vector<char> row;
            for (int j = 0; j < 4; j++)
            {
                char c;
                int ch_index = rand() % 32;
                if (ch_index == 26)
                {
                    c = 'ˆ';
                } 
                else if (ch_index == 27)
                {
                    c = 'ä';
                }
                else if (ch_index == 28)
                {
                    c = '¢';
                }
                else if (ch_index == 29)
                {
                    c = '˜';
                }
                else if (ch_index == 30)
                {
                    c = '«';
                }
                else if (ch_index == 31)
                {
                    c = '¾';
                }
                else
                {
                    c = 'a' + ch_index;
                    if (c == 'q')
                        c = '¥';
                    else if (c == 'v')
                        c = '†';
                    else if (c == 'x')
                        c = '©';
                }
                row.push_back(c);
            }
            board.push_back(row);
        }
    }

    void main_loop()
    {
        std::cout << "Witaj w programie do znajdowania slow w grze Boggle" << std::endl;
        Dictionary dict("slowa.txt");
        while(true)
        {
            std::vector<std::vector<char>> board;
            std::cout << "Podaj nazwe pliku z plansza(albo \"q\" aby zamkn¥† program, albo \"r\" aby wygenerowa† losow¥ plansz©): ";
            std::string board_filename;
            std::cin >> board_filename;

            if (board_filename == "q")
            {
                break;
            }
            else if (board_filename == "r")
            {
                generate_random_board(board);
                //print board
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        std::cout << board[i][j] << " ";
                    }
                    std::cout << std::endl;
                }
            }
            //check for file
            else
            {
                std::ifstream file;
                file.open(board_filename);
                if (!file.is_open())
                {
                    std::cout << "Nie mozna otworzyc pliku" << std::endl;
                    continue;
                }
                file.close();
                get_board_from_file(board_filename, board);
            }

            Solver solver;
            solver.solve(&dict, board);
            std::cout << "Podaj nazwe pliku do zapisania wyniku: ";
            std::string solution_filename;
            std::cin >> solution_filename;
            solver.printSolution(solution_filename);
        }
        
    }
}

#endif