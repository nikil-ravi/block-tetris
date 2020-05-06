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
  class BlockGenerator {
   private:
    BoolArrayBlock block_arr;

   public:

    BlockGenerator();

    Block GetRandomBlock();

    bool IsBlockValid();

    bool IsBlockContinuous();

    bool BlockWrapsAround();

    bool SegmentHasABlockPart();

    bool ManhattanPathExists();
  };
}


#endif  // FINALPROJECT_BLOCKGENERATOR_H
