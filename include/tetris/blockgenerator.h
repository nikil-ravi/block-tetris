//
// Created by nikil on 4/30/2020.
//

#ifndef FINALPROJECT_BLOCKGENERATOR_H
#define FINALPROJECT_BLOCKGENERATOR_H

#include <array>
#include <tetris/block.h>

typedef std::array<std::array<bool, 8>, 8> BoolArrayGrid;
typedef std::array<std::array<bool, 3>, 3> BoolArrayBlock;

namespace tetris {

  // This class is used to generates random block(s) to display on the screen.
  class BlockGenerator {
   private:

    // represents the block- as 0s and 1s.
    BoolArrayBlock block_arr;

   public:

    // Constructor- sets all the elements to 0 (or false).
    BlockGenerator();

    // This function generates a random block- it generates a random boolean value
    // (0 or 1), nine times and puts those values in the 3x3 boolean block array.
    // It returns the block generated.
    Block GetRandomBlock();

    // TODO: implement these- functions after this point *can* be
    //  implemented to improve/extend the game

    bool IsBlockValid();

    bool IsBlockContinuous();

    bool BlockWrapsAround();

    bool SegmentHasABlockPart();

    bool ManhattanPathExists();
  };
}

#endif  // FINALPROJECT_BLOCKGENERATOR_H
