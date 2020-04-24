//
// Created by nikil on 4/18/2020.
//

#ifndef FINALPROJECT_BLOCK_H
#define FINALPROJECT_BLOCK_H

namespace tetris {
  enum class BlockSpec {
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

  class Block {
   private:
    BlockSpec block_spec;
   public:
    Block(BlockSpec block_spec);
    BlockSpec GetBlockSpec();
  };
} // namespace tetris

#endif  // FINALPROJECT_BLOCK_H
