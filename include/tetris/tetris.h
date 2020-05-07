// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/app/MouseEvent.h>
#include <cinder/audio/audio.h>
#include <tetris/blockgenerator.h>
#include <tetris/grid.h>

typedef std::array<std::array<bool, 8>, 8> BoolArrayGrid;
typedef std::array<std::array<bool, 3>, 3> BoolArrayBlock;

namespace tetrisapp {

class TetrisApp : public cinder::app::App {
 private:
  // used to keep track of mouse position during drag and drop.
  vector<float> mPointsX;
  vector<float> mPointsY;

  ci::audio::VoiceRef mVoice; // used for audio
  bool paused_;
  tetris::Grid* grid;
  cinder::gl::Texture2dRef background; // background image
  tetris::Block block;
  tetris::BlockGenerator block_generator;
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
