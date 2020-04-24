//
// Created by nikil on 4/24/2020.
//

#ifndef FINALPROJECT_ENGINE_H
#define FINALPROJECT_ENGINE_H

#include <random>
#include <set>
namespace tetris {

// This is the game engine which is primary way to interact with the game.
class Engine {
 public:
  Engine();

  void StartGame();

  // Executes a time step: moves the block, etc.
  void Step();

  // Start the game over.
  void Reset();

  size_t GetScore() const;
};

}  // namespace tetris


#endif  // FINALPROJECT_ENGINE_H
