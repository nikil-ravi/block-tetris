//
// Created by nikil on 4/24/2020.
//

#ifndef FINALPROJECT_GRID_H
#define FINALPROJECT_GRID_H

#include <array>
#include <tetris/point.h>

typedef std::array<std::array<bool, 8>, 8> BoolArrayGrid;
typedef std::array<std::array<bool, 3>, 3> BoolArrayBlock;


namespace tetris {

  const int kLengthOfGrid = 8;

  class Grid {
   private:
    // represents the state of the grid- as 0s and 1s- 0 if it
    // isn't occupied at that position and 1 if it is.
    BoolArrayGrid grid_arr;

   public:
    // constructor- sets all elements to 0.
    Grid();

    // gets the row and column on the grid
    // for a given x and y coordinate.
    Point GetPointForFloatCoords(float x, float y);

    // Updates the grid with the block array passed to it, at
    // the given row and column.
    // Returns true if any updates were made, and false otherwise.
    bool Update(int row, int column, BoolArrayBlock arr);

    // getter for the grid array.
    BoolArrayGrid GetGridArr();

    // TODO complete the following fns in the future to improve the game
    bool IsOccupied(int row, int column);
    int AreaRemaining();
    bool DoesFit(std::array<std::array<bool, 3>, 3>);
    bool CollisionExists(std::array<std::array<bool, 3>, 3>, int row,
                         int column);
    Point CanFit(float x, float y, BoolArrayBlock arr);
    bool GridCompleted();
  };
} // namespace tetris


#endif  // FINALPROJECT_GRID_H
