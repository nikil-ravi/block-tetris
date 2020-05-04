// Copyright (c) 2020 Nikil. All rights reserved.

#include "tetris/tetris.h"
#include <cinder/app/App.h>
#include <cinder/audio/Exception.h>
#include <cinder/audio/audio.h>
#include <tetris/block.h>
#include <tetris/grid.h>
#include "cinder/ImageIo.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/Texture.h"
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

TetrisApp::TetrisApp()
    : engine_{},
      paused_{false},
      grid{},
      block_fits{false},
      block{},
      block_generator{},
      block_moved{false},
      tried_to_fit_block{false} {}

void TetrisApp::PlayMusic(std::string music_path) {
  try {
    SourceFileRef sourceFile = load( ci::app::loadAsset(music_path) );
    mVoice = Voice::create( sourceFile );
    mVoice->start();
  } catch (cinder::audio::AudioFileExc e) {}
}

void TetrisApp::setup() {
  PlayMusic("uncan.wav");
  // block = block_generator.GetRandomBlock();
  std::array<std::array<bool, 3>, 3> blockarray = {{{1, 0, 0}, {1, 1, 0}, {1, 0, 0}}};
  block = Block(blockarray);
}

void TetrisApp::update() {
  gl::enableAlphaBlending();
  if (!mVoice->isPlaying()) {PlayMusic("uncan.wav");}
  if (block_moved) {
    //block = block_generator.GetRandomBlock();
    std::array<std::array<bool, 3>, 3> blockarray = {{{0, 0, 0}, {0, 1, 0}, {1, 0, 1}}};
    block = Block(blockarray);
    block_fits = false;
    block_moved = false;
    //mPointsX.clear();
    //mPointsY.clear();
  }
}

void TetrisApp::DrawSmallRect() {
  gl::color( 1, 0, 0 ); // set color to red
  gl::drawStrokedRect( Rectf( getWindowWidth()/2-40.0f,
                              getWindowHeight()/9-40.0f,
                              getWindowWidth()/2+40.0f,
                              getWindowHeight()/9+40.0f ) );
}

void DrawGameRect() {
  gl::color( 0, 1, 1 ); // set color to blue
  gl::drawStrokedRect( Rectf( getWindowWidth()/2-240.0f,
                              getWindowHeight()/2-240.0f,
                              getWindowWidth()/2+240.0f,
                              getWindowHeight()/2+240.0f ) );
  gl::drawStrokedRect( Rectf( getWindowWidth()/2-242.0f,
                              getWindowHeight()/2-242.0f,
                              getWindowWidth()/2+242.0f,
                              getWindowHeight()/2+242.0f ) );
}

void TetrisApp::RenderGrid() {
  cinder::gl::color(0, 1, 1);
  try {
    for (float x = (getWindowWidth()/2-240.0f) + 80; x < getWindowWidth()/2+240.0f; x += 80) {
      float y1 = getWindowHeight()/2-240.0f;
      float line_vertex[] = { x, y1, x + 480.0f, y1};
      glVertexPointer(2, GL_FLOAT, 0, line_vertex);
      glDrawArrays(GL_LINES, 0, 2);
    }
    for (float y = (getWindowHeight()/2-240.0f) + 80; y < getWindowWidth()/2+240.0f; y += 80) {
      float x1 = getWindowWidth()/2-240.0f;
      float line_vertex[] = { x1, y, x1, y + 480.0f};
      glVertexPointer(2, GL_FLOAT, 0, line_vertex);
      glDrawArrays(GL_LINES, 0, 2);
    }
  } catch (std::exception e) {}
}

void TetrisApp::DrawBlock() {
  std::array<std::array<bool, 3>, 3> block_spec = block.GetBlockSpec();

  float x, y;

  if (!mPointsX.empty()) {
    x = mPointsX[mPointsX.size() - 1];
    y = mPointsY[mPointsY.size() - 1];
  } else {
    x = getWindowWidth()/2 - 50.0f;
    y = getWindowWidth()/9 - 50.0f;
  }


  block_moved = true;

  /*if (!block_fits) {
    x = getWindowWidth()/2;
    y = getWindowWidth()/9;
    block_moved = false;
  }*/

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (block_spec[i][j] == 1) {
        gl::drawSolidRect( Rectf( 40 * i + x - 20.0f,
                                  40 * j + y - 20.0f,
                                  40 * i + x + 20.0f,
                                  40 * j + y + 20.0f ) );
      }
    }
  }
}

void TetrisApp::draw() {

  gl::clear();

  gl::enableAlphaBlending();

  /*background = gl::Texture2d::create(loadImage(loadAsset("tetris3.jpg")));
  gl::draw(background, getWindowBounds());*/

  DrawGameRect();

  DrawSmallRect();

  //RenderGrid();

  auto box = TextBox()
      .alignment(TextBox::CENTER)
      .font(cinder::Font(kNormalFont, 30))
      .size({700, 100})
      .backgroundColor(ColorA(0, 1, 1, 0))
      .text("Welcome to Block Tetris! Press the 's' key to begin.\n Instructions:"
                     " p: Pause   r: Reset  spacebar: Stop/Quit");

  const auto box_size = box.getSize();
  const cinder::vec2 locp = {getWindowCenter().x - box_size.x / 2, getWindowCenter().y - box_size.y / 2 + 300.0f};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);

  DrawBlock();
}

void TetrisApp::mouseDrag(MouseEvent event) {
  mPointsX.push_back(event.getX());
  mPointsY.push_back(event.getY());
}

void TetrisApp::mouseUp(MouseEvent event) {

  final_point_X = mPointsX[mPointsX.size() - 1];
  final_point_Y = mPointsY[mPointsY.size() - 1];

  block_fits = true;

  /*Point point = grid->CanFit(event.getX(), event.getY(), block.GetBlockSpec());

  if (point.GetRow() >= 0 && point.GetColumn() >= 0) {
    // TODO update grid class, other variables that need to be updated
    block_fits = true;
  } else {
    block_fits = false;
  }*/
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

    }
  }
}

}  // namespace tetrisapp
