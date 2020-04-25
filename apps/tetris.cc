// Copyright (c) 2020 Nikil. All rights reserved.

#include "tetris/tetris.h"

#include <cinder/app/App.h>
#include <cinder/audio/Exception.h>
#include <cinder/audio/audio.h>
#include <tetris/block.h>

#include <iostream>

#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace tetris;
using namespace ci::audio;

namespace tetrisapp {

using cinder::app::KeyEvent;
using cinder::app::MouseEvent;

const char kNormalFont[] = "Arial";

bool box1_clicked = false, box2_clicked = false, box3_clicked = false;

TetrisApp::TetrisApp()
    : engine_{},
      paused_{false} {}


void TetrisApp::PlayMusic(std::string music_path) {
  try {
    SourceFileRef sourceFile = load( ci::app::loadAsset(music_path) );
    mVoice = Voice::create( sourceFile );
    mVoice->start();
  } catch (cinder::audio::AudioFileExc e) {}
}

void TetrisApp::setup() {
  PlayMusic("uncan.wav");
  std::array<std::array<bool, 3>, 3> arr = {{{1, 1, 1}, {0, 0, 0}, {0, 0, 0}}};
  Block block(arr);
  engine_.RenderBlock(block);
}

void TetrisApp::update() {
  if (!mVoice->isPlaying()) {PlayMusic("uncan.wav");}

  std::array<std::array<bool, 3>, 3> arr = {{{1, 1, 1}, {0, 0, 0}, {0, 0, 0}}};
  Block block(arr);
  engine_.RenderBlock(block);
}

void DrawSmallRects() {
  gl::color( 1, 0, 0 ); // set color to red
  gl::drawStrokedRect( Rectf( getWindowWidth()/4-40.0f,
                              getWindowHeight()/9-40.0f,
                              getWindowWidth()/4+40.0f,
                              getWindowHeight()/9+40.0f ) );

  gl::drawStrokedRect( Rectf( getWindowWidth()/2-40.0f,
                              getWindowHeight()/9-40.0f,
                              getWindowWidth()/2+40.0f,
                              getWindowHeight()/9+40.0f ) );

  gl::drawStrokedRect( Rectf( 3*getWindowWidth()/4-40.0f,
                              getWindowHeight()/9-40.0f,
                              3*getWindowWidth()/4+40.0f,
                              getWindowHeight()/9+40.0f ) );
}

void DrawGameRect() {
  gl::color( 0, 1, 1 ); // set color to blue
  /*gl::drawSolidRect( Rectf( getWindowWidth()/2-20.0f,
                            getWindowHeight()/2-20.0f,
                            getWindowWidth()/2+20.0f,
                            getWindowHeight()/2+20.0f ) );*/
  gl::drawStrokedRect( Rectf( getWindowWidth()/2-240.0f,
                              getWindowHeight()/2-240.0f,
                              getWindowWidth()/2+240.0f,
                              getWindowHeight()/2+240.0f ) );
}

void TetrisApp::draw() {

  DrawGameRect();

  DrawSmallRects();

  auto box = TextBox()
      .alignment(TextBox::CENTER)
      .font(cinder::Font(kNormalFont, 30))
      .size({500, 50})
      .backgroundColor(ColorA(0, 1, 1, 0))
      .text("Welcome to Block Tetris! Press the 's' key to begin.");

  const auto box_size = box.getSize();
  const cinder::vec2 locp = {getWindowCenter().x - box_size.x / 2, getWindowCenter().y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);
}

void TetrisApp::keyDown(KeyEvent event) {
  switch (event.getCode()) {
    case KeyEvent::KEY_s: {
      engine_.StartGame();
    }
    case KeyEvent::KEY_r: {
      engine_.Reset();
    }
    case KeyEvent::KEY_p: {
      paused_ = !paused_;
      // TODO do whatever is necessary to deal with paused/not paused
    }
    case KeyEvent::KEY_DOWN: {
      if (box1_clicked) {
        engine_.MoveBlock();
      }
    }
  }
}

void TetrisApp::mouseDown(MouseEvent event) {
  box1_clicked = true;
}


}  // namespace tetrisapp
