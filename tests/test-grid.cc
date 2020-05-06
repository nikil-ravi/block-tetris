//
// Created by nikil on 5/6/2020.
//

#include <catch2/catch.hpp>

TEST_CASE("Random sanity test", "[random]") {
REQUIRE(0 <= 1);
}

TEST_CASE("Update grid") {
  SECTION("An empty block changes nothing in the grid") {

  }
  SECTION("A row-block is updated in the grid properly") {

  }
  SECTION("A column block is updated in the grid properly") {

  }
  SECTION("A block that is partly outside grid") {

  }
  SECTION("Collisions are handled properly") {

  }
  SECTION("Block is completely out of grid") {

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