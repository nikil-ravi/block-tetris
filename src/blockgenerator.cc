//
// Created by nikil on 4/30/2020.
//

#include "tetris/blockgenerator.h"
#include <tetris/grid.h>
#include <random>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>

// Constructor- sets all the elements to 0 (or false).
tetris::BlockGenerator::BlockGenerator() {
  for (int i = 0; i < kMaxBlockSideLength; i++) {
    for (int j = 0; j < kMaxBlockSideLength; j++) {
      block_arr[i][j] = false;
    }
  }
}

// This function generates a random block- it generates a random boolean value
// (0 or 1), nine times and puts those values in the 3x3 boolean block array.
// It returns the block generated.
tetris::Block tetris::BlockGenerator::GetRandomBlock() {
  /*while (!IsBlockValid()) {*/
    bool val = 0;
    for (int i = 0; i < kMaxBlockSideLength; i++) {
      for (int j = 0; j < kMaxBlockSideLength; j++) {
        block_arr[i][j] = static_cast<bool>(rand() % 2);
        val = block_arr[i][j];
        std::cout << val << std::endl;
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
