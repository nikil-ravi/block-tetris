//
// Created by nikil on 4/18/2020.
//

#include <cinder/app/AppBase.h>
#include <cinder/gl/gl.h>
#include <tetris/block.h>
#include <tetris/point.h>

using namespace ci;
using namespace ci::app;

namespace tetris {

  Block::Block() {
    std::array<std::array<bool, 3>, 3> arr = {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
    block_arr = arr;
  }

  Block::Block(std::array<std::array<bool, 3>, 3> block_spec) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        block_arr[i][j] = block_spec[i][j];
      }
    }
  }

  std::array<std::array<bool, 3>, 3> Block::GetBlockSpec() {
    return block_arr;
  }
} // namespace tetris