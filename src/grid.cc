//
// Created by nikil on 4/24/2020.
//

#include "tetris/grid.h"

namespace tetris {

  Grid::Grid() {}

  bool tetris::Grid::IsOccupied(int row, int column) {
    return block_arr[row][column];
  }

  int Grid::AreaRemaining() {
    int empty_count = 0;
    for (int i = 0; i < kLengthOfGrid; i++) {
      for (int j = 0; j < kLengthOfGrid; j++) {
        if (block_arr[i][j] == 0) {
          empty_count++;
        }
      }
    }
    return empty_count;
  }

  // TODO see if Rabin Karp can be used somehow to make this more efficient
  bool Grid::DoesFit(std::array<std::array<bool, 3>, 3>) {

    return false;
  }

  // TODO see if Rabin Karp can be used somehow to make this more efficient
  bool Grid::CanFit(float x, float y) {
    return true;
  }

  bool CollisionExists(std::array<std::array<bool, 3>, 3>, int row, int column) {

    return false;
  }




}

