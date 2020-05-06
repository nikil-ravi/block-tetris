//
// Created by nikil on 4/24/2020.
//

#ifndef FINALPROJECT_GRID_H
#define FINALPROJECT_GRID_H

#include <array>

#include "point.h"

typedef std::array<std::array<bool, 8>, 8> BoolArrayGrid;
typedef std::array<std::array<bool, 3>, 3> BoolArrayBlock;
using namespace std;


namespace tetris {

  const int kLengthOfGrid = 8;

  class Grid {
   private:
    BoolArrayGrid grid_arr;

   public:

    Grid();

    bool IsOccupied(int row, int column);

    int AreaRemaining();

    bool DoesFit(std::array<std::array<bool, 3>, 3>);

    bool CollisionExists(std::array<std::array<bool, 3>, 3>, int row, int column);

    Point CanFit(float x, float y, BoolArrayBlock arr);

    Point GetPointForFloatCoords(float x, float y);

    bool Update(int row, int column, BoolArrayBlock arr);

    BoolArrayGrid GetGridArr();

    bool GridCompleted();
  };

} // namespace tetris


#endif  // FINALPROJECT_GRID_H
