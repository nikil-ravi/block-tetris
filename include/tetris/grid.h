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

    Grid();

    bool IsOccupied(int row, int column);

    int AreaRemaining();

    bool DoesFit(std::array<std::array<bool, 3>, 3>);

    bool CollisionExists(std::array<std::array<bool, 8>, 8>, int row, int column);

    bool CanFit(float x, float y);
  };

} // namespace tetris


#endif  // FINALPROJECT_GRID_H
