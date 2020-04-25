//
// Created by nikil on 4/18/2020.
//

#include <tetris/block.h>

namespace tetris {

  Block::Block(std::array<std::array<bool, 3>, 3> block_spec) {
    block_arr = block_spec;
  }

  std::array<std::array<bool, 3>, 3> Block::GetBlockSpec() {
    return block_arr;
  }

} // namespace tetris