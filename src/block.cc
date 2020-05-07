//
// Created by nikil on 4/18/2020.
//

#include <cinder/app/AppBase.h>
#include <cinder/gl/gl.h>
#include <tetris/block.h>
#include <tetris/point.h>

typedef std::array<std::array<bool, 8>, 8> BoolArrayGrid;
typedef std::array<std::array<bool, 3>, 3> BoolArrayBlock;
using namespace ci;
using namespace ci::app;

namespace tetris {

  Block::Block() {
    BoolArrayBlock arr = {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
    block_arr = arr;
  }

  Block::Block(BoolArrayBlock block_spec) {
    for (int i = 0; i < kMaxBlockSideLength; i++) {
      for (int j = 0; j < kMaxBlockSideLength; j++) {
        block_arr[i][j] = block_spec[i][j];
      }
    }
  }

  BoolArrayBlock Block::GetBlockSpec() {
    return block_arr;
  }
} // namespace tetris