// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <tetris/block.h>

using namespace tetris;

TEST_CASE("Random sanity test", "[random]") {
  REQUIRE(0 <= 1);
}

TEST_CASE("Default Constructor sets all the elements to 0") {
  Block block;
  BoolArrayBlock block_array = block.GetBlockSpec();
  for (int i = 0; i < kMaxBlockSideLength; i++) {
    for (int j = 0; j < kMaxBlockSideLength; j++) {
      REQUIRE(block_array[i][j] == 0);
    }
  }
}

TEST_CASE("Copy constructor sets corresponding elements properly") {
  BoolArrayBlock block_array = {{{1, 1, 1}, {0, 0, 0}, {0, 0, 0}}};
  Block block(block_array);
  REQUIRE(block.GetBlockSpec() == block_array);
}