//
// Created by nikil on 4/24/2020.
//

#include "tetris/grid.h"
#include <cinder/app/App.h>
#include <cinder/audio/Exception.h>
#include <cinder/audio/audio.h>
#include <tetris/block.h>
#include <tetris/grid.h>
#include <math.h>

#include "cinder/ImageIo.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/gl.h"

namespace tetris {

  Grid::Grid() {
    for (int i = 0; i < kLengthOfGrid; i++) {
      for (int j = 0; j < kLengthOfGrid; j++) {
        grid_arr[i][j] = false;
      }
    }
  }

  bool tetris::Grid::IsOccupied(int row, int column) {
    return grid_arr[row][column];
  }

  int Grid::AreaRemaining() {
    int empty_count = 0;
    for (int i = 0; i < kLengthOfGrid; i++) {
      for (int j = 0; j < kLengthOfGrid; j++) {
        if (grid_arr[i][j] == 0) {
          empty_count++;
        }
      }
    }
    return empty_count;
  }

  // TODO see if Rabin Karp can be used somehow to make this more efficient
  Point Grid::CanFit(float x, float y,
                     std::array<std::array<bool, 3>, 3> blockarray) {
    x = x - (getWindowWidth()/2-240.0f);
    y = y - (getWindowHeight()/2-240.0f);

    int column = std::floor(x / 80.0f);
    int row = std::floor(y / 80.0f);

    Point point(row, column);
    if (row < 0 || column < 0) {
      return point;
    } else {
      if (!CollisionExists(blockarray, point.GetRow(), point.GetColumn())) {
        return point;
      } else {
        return Point(-1, -1);
      }
    }
  }

  Point Grid::GetPointForFloatCoords(float x, float y) {
    x = x - (getWindowWidth()/2-240.0f);
    y = y - (getWindowHeight()/2-240.0f);

    int column = std::floor(x / 80.0f);
    int row = std::floor(y / 80.0f);

    Point point(row, column);
    return point;
  }

  bool Grid::CollisionExists(std::array<std::array<bool, 3>, 3> arr, int row,
                             int column) {
    for (int i = row; i < row + 3; i++) {
      for (int j = column; j < column + 3; j++) {
        if (i >= 8) {
          if (arr[i - row][0] == 1 || arr[i - row][1] == 1 ||
              arr[i - row][2] == 1) {
            return false;
          }
        }
        if (j >= 8) {
          if (arr[0][j - column] == 1 || arr[1][j - column] == 1 ||
              arr[2][j - column] == 1) {
            return false;
          }
        }
        if (arr[i - row][j - column] && grid_arr[i][j]) {
          return false;
        }
      }
    }
    return true;
  }

  bool Grid::Update(int row, int column,
                    std::array<std::array<bool, 3>, 3> arr) {
    for (int i = 0; i < kMaxBlockSideLength; i++) {
      for (int j = 0; j < kMaxBlockSideLength; j++) {
        if (row + i < kLengthOfGrid && column + j < kLengthOfGrid) {
          if (arr[i][j] == 1 && grid_arr[row + i][column + j] == 0) {
            grid_arr[row + i][column + j] = 1;
          }
        } else {
          return 0;
        }
      }
    }
  }
}

