//
// Created by nikil on 4/18/2020.
//

#ifndef FINALPROJECT_BLOCK_H
#define FINALPROJECT_BLOCK_H

#include <array>

using namespace std;

namespace tetris {

  const int kMaxBlockSideLength = 3;
  /*enum class BlockSpec {
    Horizontal,
    Vertical,
    LShapedBottomLeft,
    LShapedBottomRight,
    LShapedTopLeft,
    LShapedTopRight,
    ModifiedLShapedBottomLeft,
    ModifiedLShapedBottomRight,
    ModifiedLShapedTopLeft,
    ModifiedLShapedTopRight,
    ModifiedInvalidInput,
    TwoSquare,
    ThreeSquare,
    TwoVertical,
    ThreeVertical,
    TwoHorizontal,
    ThreeHorizontal,
  };
*/
  class Block {
   private:
    std::array<std::array<bool, 3>, 3> block_arr;
    //BlockSpec block_spec;
   public:
    //Block(BlockSpec block_spec);
    Block(std::array<std::array<bool, 3>, 3> block_spec);
    std::array<std::array<bool, 3>, 3> GetBlockSpec();

  };
} // namespace tetris

#endif  // FINALPROJECT_BLOCK_H
