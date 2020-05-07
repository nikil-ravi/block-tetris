//
// Created by nikil on 5/6/2020.
//

#include <tetris/block.h>
#include <tetris/grid.h>

#include <catch2/catch.hpp>

using namespace tetris;

TEST_CASE("Random sanity test", "[random]") {
REQUIRE(0 <= 1);
}

TEST_CASE("Constructor sets elements to 0") {
  Grid grid;
  BoolArrayGrid grid_array = grid.GetGridArr();
  for (int i = 0; i < kLengthOfGrid; i++) {
    for (int j = 0; j < kLengthOfGrid; j++) {
      REQUIRE(grid_array[i][j] == 0);
    }
  }
}

TEST_CASE("Update grid") {
  SECTION("An empty block changes nothing in the grid") {
    Block block;
    Grid grid;
    grid.Update(3, 3, block.GetBlockSpec());
    BoolArrayGrid grid_array = grid.GetGridArr();
    for (int i = 0; i < kLengthOfGrid; i++) {
      for (int j = 0; j < kLengthOfGrid; j++) {
        REQUIRE(grid_array[i][j] == 0);
      }
    }
  }
  SECTION("A row-block is updated in the grid properly") {
    BoolArrayBlock block_array = {{{1, 1, 1}, {0, 0, 0}, {0, 0, 0}}};
    Grid grid;
    grid.Update(0, 0, block_array);
    BoolArrayGrid grid_array = grid.GetGridArr();
    for (int i = 0; i < kMaxBlockSideLength; i++) {
      REQUIRE(grid_array[0][i] == 1);
    }
  }
  SECTION("A column block is updated in the grid properly") {
    BoolArrayBlock block_array = {{{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}};
    Grid grid;
    grid.Update(0, 0, block_array);
    BoolArrayGrid grid_array = grid.GetGridArr();
    for (int i = 0; i < kMaxBlockSideLength; i++) {
      REQUIRE(grid_array[i][0] == 1);
    }
  }
  Grid grid;
  SECTION("A block that is partly outside grid") {
    BoolArrayBlock block_array = {{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}};
    grid.Update(6, 6, block_array);
    BoolArrayGrid grid_array = grid.GetGridArr();
    REQUIRE(grid_array[6][6] == 1);
    REQUIRE(grid_array[6][7] == 1);
    REQUIRE(grid_array[7][6] == 1);
    REQUIRE(grid_array[7][7] == 1);
  }
  SECTION("Collisions are handled properly") {
    // at this point, the grid already has some 1s, as done in
    // the previous section
    BoolArrayBlock block_array = {{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}};
    grid.Update(6, 6, block_array);
    BoolArrayGrid grid_array = grid.GetGridArr();
    REQUIRE(grid_array[6][6] == 1);
    REQUIRE(grid_array[6][7] == 1);
    REQUIRE(grid_array[7][6] == 1);
    REQUIRE(grid_array[7][7] == 1);
  }
  SECTION("Block is completely out of grid") {
    BoolArrayBlock block_array = {{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}};
    Grid grid;
    REQUIRE(grid.Update(0, 12, block_array) == false);
  }
}

TEST_CASE("Get point from float coords") {
  SECTION("Coords are valid") {

  }
  SECTION("Only one coordinate is valid") {

  }
  SECTION("Both coordinates are invalid") {

  }
  SECTION("Negative point is returned when necessary") {

  }
}