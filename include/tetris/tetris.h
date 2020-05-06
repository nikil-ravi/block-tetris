// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/app/MouseEvent.h>
#include <cinder/audio/audio.h>
#include <tetris/engine.h>
#include <tetris/blockgenerator.h>

#include "grid.h"

typedef std::array<std::array<bool, 8>, 8> BoolArrayGrid;
typedef std::array<std::array<bool, 3>, 3> BoolArrayBlock;

namespace tetrisapp {

class TetrisApp : public cinder::app::App {
 private:
  vector<int> mPointsX;
  vector<int> mPointsY;
  ci::audio::VoiceRef mVoice;
  tetris::Engine engine_;
  bool paused_;
  float final_point_X;
  float final_point_Y;
  //gl::Texture myImage;
  tetris::Grid* grid;
  bool block_fits;
  cinder::gl::Texture2dRef background;
  tetris::Block block;
  tetris::BlockGenerator block_generator;
  bool block_moved;
  bool tried_to_fit_block;
  bool grid_updated;

 public:
  TetrisApp();
  void setup() override;
  void update() override;
  void draw() override;
  void DrawBlock();
  void DrawSmallRect();
  void keyDown(cinder::app::KeyEvent) override;
  void TetrisApp::PlayMusic(std::string music_path);
  void mouseDrag( MouseEvent event ) override;
  void RenderGrid();
  void mouseUp( MouseEvent event ) override;

};

}  // namespace tetrisapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
