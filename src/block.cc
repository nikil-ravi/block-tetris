//
// Created by nikil on 4/18/2020.
//

#include <tetris/block.h>
#include <tetris/block.h>

namespace tetris {


  Block::Block(BlockSpec blockspec){
    block_spec = blockspec;
  }

  BlockSpec Block::GetBlockSpec() {
    return block_spec;
  }



} // namespace tetris