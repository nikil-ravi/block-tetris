//
// Created by nikil on 4/30/2020.
//

#ifndef FINALPROJECT_BLOCKGENERATOR_H
#define FINALPROJECT_BLOCKGENERATOR_H

#include <array>
#include <tetris/block.h>

namespace tetris {
  class BlockGenerator {
   private:
    std::array<std::array<bool, 3>, 3> block_arr;

   public:
    Block GetRandomBlock();

    bool IsBlockValid();

    bool IsBlockContinuous();

    bool BlockWrapsAround();

    bool SegmentHasABlockPart();

    bool ManhattanPathExists();
  };
}


#endif  // FINALPROJECT_BLOCKGENERATOR_H
