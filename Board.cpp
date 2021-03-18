#include <iostream>
#include <stdexcept>
#include "Board.hpp"
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace ariel {
    string Board::read(int row, int col, Direction direction, int length) {
        return "in read";
    }

    void Board::post(int row, int col, Direction direction, const string &word) {
        if (row < 0 || col < 0) {
            throw std::out_of_range("Col or row cannot be negative");
        }
        const int size = word.size();
        if (mat.size() < row + size) {
            mat.resize(row + 1);
            if (mat.at(row).size() < col) {
                for (int i = 0; i < row + 1; ++i) {
                    mat.at(i).resize(col + 1);
                }
            }
        }

//        switch(direction) {
//            case Direction::Horizontal:
//
//
//
//        }

        cout << mat.size() << endl;
        cout << mat.at(0).size() << endl;
        cout << "Hello There, In Post" << endl;
    }

    void Board::show() {
        cout << "Hello There, In Show" << endl;
    }

}