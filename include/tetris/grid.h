//
// Created by nikil on 4/24/2020.
//

#ifndef FINALPROJECT_GRID_H
#define FINALPROJECT_GRID_H

#include <array>

using namespace std;


namespace tetris {

  const int kLengthOfGrid = 8;

  class Grid {
   private:
    std::array<std::array<bool, 8>, 8> block_arr;
   public:
    bool IsOccupied(int row, int column);

    int AreaRemaining();

    bool DoesFit(std::array<std::array<bool, 3>, 3>);
  };

} // namespace tetris


#endif  // FINALPROJECT_GRID_H
