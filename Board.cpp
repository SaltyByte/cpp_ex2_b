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
        const int wordSize = word.size();
        switch (direction) {
            case Direction::Horizontal:
                if (mat.size() < row + wordSize + 1) {
                    mat.resize(row + wordSize + 1);
                    if (mat.at(row).size() < col + 1) {
                        for (int i = 0; i < mat.size(); ++i) {
                            mat.at(i).resize(col + 1);
                        }
                    }
                }
                break;
            case Direction::Vertical:
                if (mat.size() < row) {
                    mat.resize(row + 1);
                    if (mat.at(row).size() < col) {
                        for (int i = 0; i < row + 1; ++i) {
                            mat.at(i).resize(col + 1);
                        }
                    }
                }
        }


        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat.at(0).size(); ++j) {
                if (mat.at(i).at(j) == "") {
                    cout << "_";
                }
            }
            cout << endl;
        }
        cout << mat.size() << endl;
        cout << mat.at(0).size() << endl;
        cout << "Hello There, In Post" << endl;
    }

    void Board::show() {
        cout << "Hello There, In Show" << endl;
    }

}