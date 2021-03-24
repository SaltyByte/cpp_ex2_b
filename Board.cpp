#include <iostream>
#include <stdexcept>
#include "Board.hpp"
#include <string>
#include <algorithm>

using namespace std;

namespace ariel {
    string Board::read(unsigned int row, unsigned int col, Direction direction, int length) {
        if (length < 0) {
            throw std::out_of_range("length cannot be negative");
        }
        if (board.empty()){
            string ret;
            for (int i = 0; i < length; ++i) {
                ret += '_';
            }
            return ret;
        }

        string ret;
        switch (direction) {
            case Direction::Vertical:{
                unsigned int boardCounter = row;
                for (int i = 0; i < length; ++i) {
                    if (board.find(boardCounter) == board.end() || board[boardCounter].find(col) == board[boardCounter].end()) {
                        ret.append("_");
                    }
                    else {
                        ret.append(board[boardCounter][col]);
                    }
                    boardCounter++;
                }
                break;
            }
            case Direction::Horizontal:{
                unsigned int boardCounter = col;
                for (int i = 0; i < length; ++i) {
                    if (board.find(row) == board.end() || board[row].find(boardCounter) == board[row].end()) {
                        ret.append("_");
                    }
                    else {
                        ret.append(board[row][boardCounter]);
                    }
                    boardCounter++;
                }
                break;
            }
        }
        return ret;
    }

    void Board::post(unsigned int row,unsigned  int col, Direction direction, const string &word) {
        if (word.empty()) {
            return;
        }
        const unsigned int wordSize = word.size();
        colStart = std::min(col,colStart);
        rowStart = std::min(row,rowStart);
        switch (direction) {
            case Direction::Horizontal: {
                if (col + wordSize == UINT_MAX) {
                    throw std::out_of_range("Too high range!");
                }
                unsigned int boardCounter = col;
                for (unsigned int i = 0; i < wordSize; ++i) {
                    board[row][boardCounter] = word.at(i);
                    boardCounter++;
                }
                rowEnd = std::max(row,rowEnd);
                colEnd = std::max(boardCounter,colEnd);
                break;
            }
            case Direction::Vertical: {
                if (row + wordSize == UINT_MAX) {
                    throw std::out_of_range("Too high range!");
                }
                unsigned int boardCounter = row;
                for (unsigned int i = 0; i < wordSize; ++i) {
                    board[boardCounter][col] = word.at(i);
                    boardCounter++;
                }
                rowEnd = std::max(boardCounter,rowEnd);
                colEnd = std::max(col,colEnd);
                break;
            }
        }
    }

    void Board::show() {
        if (board.empty()) {
            cout << "_________\n__Empty__\n_________" << endl;
            return;
        }
        unsigned int rowCounter = rowStart - 1;
        if (rowStart == 0) {
            cout << -1 << ": ___";
            rowCounter++;
        }
        else {
            cout << rowCounter++ << ": ___";
        }
        for (unsigned int i = colStart; i <= colEnd; ++i) {
            cout << "_";
        }
        cout << "___" << endl;

        for (unsigned int i = rowStart; i <= rowEnd; ++i) {
            cout << rowCounter++ <<": ___";
            for (unsigned int j = colStart; j <= colEnd; ++j) {
                if (!board[i][j].empty()) {
                    cout << board[i][j];
                }
                else {
                    cout << "_";
                }
            }
            cout << "___" << endl;
        }
        cout << rowCounter++ << ": ___";
        for (unsigned int i = colStart; i <= colEnd; ++i) {
            cout << "_";
        }
        cout << "___" << endl;
    }
}