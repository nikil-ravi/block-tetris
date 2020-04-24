// Copyright (c) 2020 Nikil. All rights reserved.

#include "tetris.h"

#include <cinder/app/App.h>
#include <tetris/block.h>

#include <iostream>
#include <cinder/audio/Exception.h>
#include <cinder/audio/audio.h>

#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace tetris;
using namespace ci::audio;

namespace tetrisapp {

using cinder::app::KeyEvent;

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
}

void TetrisApp::update() {
  if (!mVoice->isPlaying()) {PlayMusic("uncan.wav");}
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

}

void DrawBlockOnTop() {
  gl::color( 0, 1, 1 );
  bool a[3][3] = {{1, 1, 1}, {0, 0, 0}, {0, 0, 0}};

  Block block(BlockSpec::Horizontal);
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
  }
}

}  // namespace myapp
