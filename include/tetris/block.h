//
// Created by nikil on 4/18/2020.
//

#ifndef FINALPROJECT_BLOCK_H
#define FINALPROJECT_BLOCK_H

#include <array>
#include <tetris/point.h>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

typedef std::array<std::array<bool, 8>, 8> BoolArrayGrid;
typedef std::array<std::array<bool, 3>, 3> BoolArrayBlock;
using namespace ci;
using namespace ci::app;
using namespace std;

namespace tetris {

  const int kMaxBlockSideLength = 3;

  class Block {
   private:
    BoolArrayBlock block_arr;
   public:
    Block();
    Block(BoolArrayBlock block_spec);
    BoolArrayBlock GetBlockSpec();
  };
} // namespace tetris

#endif  // FINALPROJECT_BLOCK_H
