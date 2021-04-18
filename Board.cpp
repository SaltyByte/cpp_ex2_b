#include <iostream>
#include <stdexcept>
#include "Board.hpp"
#include <string>
#include <algorithm>

using namespace std;

namespace ariel {
    string Board::read(unsigned int row, unsigned int col, Direction direction,unsigned int length) {
        // if board is empty return '_' times length
        if (board.empty()){
            string ret;
            for (int i = 0; i < length; ++i) {
                ret += '_';
            }
            return ret;
        }

        string ret;
        // switch case to switch between vertical or horizontal reading
        switch (direction) {
            case Direction::Vertical:{
                unsigned int boardCounter = row;
                // loop length times, if no char then append the string '_' else there is char so append the char.
                for (int i = 0; i < length; ++i) {
                    // because vertical, we need to go on the col of the board
                    if (board.find(boardCounter) == board.end() || board[boardCounter].find(col) == board[boardCounter].end()) {
                        ret.append("_");
                    }
                    else {
                        ret.append(board[boardCounter][col]);
                    }
                    // boardCounter is the index of the pointer in the board
                    boardCounter++;
                }
                break;
            }
            case Direction::Horizontal:{
                unsigned int boardCounter = col;
                // loop length times, if no char then append the string '_' else there is char so append the char.
                for (int i = 0; i < length; ++i) {
                    // because horizontal, we need to go on the row of the board
                    if (board.find(row) == board.end() || board[row].find(boardCounter) == board[row].end()) {
                        ret.append("_");
                    }
                    else {
                        ret.append(board[row][boardCounter]);
                    }
                    // boardCounter is the index of the pointer in the board
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
        // get word size in unsigned int, so no errors.
        const unsigned int wordSize = word.size();
        // we update col and row start by taking the min of already got row col and new row col, check if they are more left up.
        colStart = min(col,colStart);
        rowStart = min(row,rowStart);
        switch (direction) {
            // switch case to get the right way to post
            case Direction::Horizontal: {
                if (col + wordSize == UINT_MAX) { // check if the word size + starting col to post is higher than max unsigned int.
                    throw out_of_range("Too high range!");
                }
                unsigned int boardCounter = col; // start posting from col
                for (unsigned int i = 0; i < wordSize; ++i) { // start posting on the board, updating the map.
                    board[row][boardCounter] = word.at(i);
                    boardCounter++;
                }
                // check if after the posting we went higher than last right down most place, if so update.
                rowEnd = max(row,rowEnd);
                colEnd = max(boardCounter,colEnd);
                break;
            }
            case Direction::Vertical: {
                if (row + wordSize == UINT_MAX) { // check if the word size + starting row to post is higher than max unsigned int.
                    throw out_of_range("Too high range!");
                }
                unsigned int boardCounter = row; // start posting from row
                for (unsigned int i = 0; i < wordSize; ++i) { // start posting on the board, updating the map.
                    board[boardCounter][col] = word.at(i);
                    boardCounter++;
                } // check if after the posting we went higher than last right down most place, if so update.
                rowEnd = max(boardCounter,rowEnd);
                colEnd = max(col,colEnd);
                break;
            }
        }
    }

    void Board::show() {
        // if board is empty, print nice board saying its empty
        if (board.empty()) {
            cout << "_________\n__Empty__\n_________" << endl;
            return;
        }
        unsigned int rowCounter = rowStart - 1;
        // this is because we use unsigned int in the values so if we got word in place 0 we print -1 instead of max int
        if (rowStart == 0) {
            cout << -1 << ": ___";
            rowCounter++;
        }
        // else we are not in the start so we can go on in regular way
        // both ways print nice three lines before we print real words so it would look nice
        else {
            cout << rowCounter++ << ": ___";
        }
        // print '_' in the first row
        for (unsigned int i = colStart; i <= colEnd; ++i) {
            cout << "_";
        }
        cout << "___" << endl; // add three more

        // loop the board, if no char print '_' else print the char
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
            // print nice three lines
            cout << "___" << endl;
        }
        // end with three lines, len lines and three more, makes the board look nice
        cout << rowCounter++ << ": ___";
        for (unsigned int i = colStart; i <= colEnd; ++i) {
            cout << "_";
        }
        cout << "___" << endl;
    }
}