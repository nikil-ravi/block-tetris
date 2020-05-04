//
// Created by nikil on 4/30/2020.
//

#include "tetris/blockgenerator.h"
#include <tetris/grid.h>
#include <random>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>


tetris::BlockGenerator::BlockGenerator() {
  for (int i = 0; i < kMaxBlockSideLength; i++) {
    for (int j = 0; j < kMaxBlockSideLength; j++) {
      block_arr[i][j] = 0;
    }
  }
}

tetris::Block tetris::BlockGenerator::GetRandomBlock() {
  /*while (!IsBlockValid()) {*/
    bool val = 0;
    for (int i = 0; i < kMaxBlockSideLength; i++) {
      for (int j = 0; j < kMaxBlockSideLength; j++) {
        srand(time(NULL));
        block_arr[i][j] = static_cast<bool>(rand() % 2);
        val = block_arr[i][j];
      }
    }
/*
  }
*/
  return Block(block_arr);
}

bool tetris::BlockGenerator::IsBlockValid() {
  //if (BlockWrapsAround()) return false;
  // TODO- complete this
  return false;
}

bool tetris::BlockGenerator::IsBlockContinuous() {
  return false;
}

bool tetris::BlockGenerator::BlockWrapsAround() {
  bool border_exists = true;
  for (int i = 0; i < kMaxBlockSideLength; i++) {
    for (int j = 0; j < kMaxBlockSideLength; j++) {
      if (i == 1 && j == 1) continue;
      if (block_arr[i][j] != 1) border_exists = false;
    }
  }
  return block_arr[1][1] == 0 && border_exists;
}

bool tetris::BlockGenerator::SegmentHasABlockPart() {
  return false;
}

bool tetris::BlockGenerator::ManhattanPathExists() {
  return false;
}
