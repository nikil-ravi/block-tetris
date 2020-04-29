// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/app/MouseEvent.h>
#include <cinder/audio/audio.h>
#include <tetris/engine.h>

namespace tetrisapp {

class TetrisApp : public cinder::app::App {
 private:
  vector<int> mPointsX;
  vector<int> mPointsY;
  ci::audio::VoiceRef mVoice;
  tetris::Engine engine_;
  bool paused_;

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
};

}  // namespace tetrisapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
