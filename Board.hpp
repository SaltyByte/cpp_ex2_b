#ifndef EX_2_A_BOARD_HPP
#define EX_2_A_BOARD_HPP

#include <string>
#include <vector>
#include <map>
#include <climits>
#include "Direction.hpp"

namespace ariel {
    class Board {
    public:
        std::string read(int row, int col, Direction direction, int length);
        void post(int row, int col, Direction direction, const std::string &word);
        void show();

    private:
        std::map<int,std::map<int,std::string>> board;

        int rowStart = INT_MAX;
        int colStart = INT_MAX;
        int colEnd = 0;
        int rowEnd = 0;
    };
}


#endif
