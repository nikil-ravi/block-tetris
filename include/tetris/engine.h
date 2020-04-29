//
// Created by nikil on 4/24/2020.
//

#ifndef FINALPROJECT_ENGINE_H
#define FINALPROJECT_ENGINE_H

#include <tetris/block.h>

#include <array>
#include <random>
#include <set>

#include "location.h"

using namespace std;

namespace tetris {


// This is the game engine which is primary way to interact with the game.
class Engine {
 private:
  Block block;

 public:

  Engine();

  Engine(Block block);

  void SetBlock(Block block);

  void StartGame();

  // Executes a time step: moves the block, etc.
  void Step();

  // Start the game over.
  void Reset();

  size_t GetScore() const;

  void RenderBlock(Block block);

  Block GetBlock();

  void DrawSmallRect();

  void MoveBlock();
};

}  // namespace tetris


#endif  // FINALPROJECT_ENGINE_H
