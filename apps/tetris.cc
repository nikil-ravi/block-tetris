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
      grid{new Grid()},
      block_fits{false},
      block{},
      block_generator{},
      block_moved{false},
      tried_to_fit_block{false},
      grid_updated{false} {}

void TetrisApp::PlayMusic(std::string music_path) {
  try {
    SourceFileRef sourceFile = load( ci::app::loadAsset(music_path) );
    mVoice = Voice::create( sourceFile );
    mVoice->start();
  } catch (cinder::audio::AudioFileExc e) {}
}

void TetrisApp::setup() {
  PlayMusic("uncan.wav");

  // set the current block of the game to a randomly generated one.
  block = block_generator.GetRandomBlock();
}

void TetrisApp::update() {
  gl::enableAlphaBlending();

  // if music has stopped, play again.
  if (!mVoice->isPlaying()) {PlayMusic("uncan.wav");}

  // update all the variables if the user has placed a block successfully
  if (grid_updated) {
    block = block_generator.GetRandomBlock();
    tried_to_fit_block = false;
    grid_updated = false;
    mPointsX.clear();
    mPointsY.clear();
  }
}

void TetrisApp::DrawSmallRect() {
  gl::color( 1, 0, 0 ); // set color to red

  // draw a stroked (non-solid, only border) rectangle at top of screen
  // to display new blocks.
  gl::drawStrokedRect( Rectf( getWindowWidth()/2-120.0f,
                              getWindowHeight()/9-120.0f,
                              getWindowWidth()/2+120.0f,
                              getWindowHeight()/9+120.0f ) );
}

void DrawGameRect() {
  gl::color( 0, 1, 1 ); // set color to blue

  // draw two stroked (non-solid, only border) rectangles close to each other
  // to make the game rectangle appear thicker.
  gl::drawStrokedRect( Rectf( getWindowWidth()/2-160.0f,
                              getWindowHeight()/2-160.0f,
                              getWindowWidth()/2+160.0f,
                              getWindowHeight()/2+160.0f ) );
  gl::drawStrokedRect( Rectf( getWindowWidth()/2-162.0f,
                              getWindowHeight()/2-162.0f,
                              getWindowWidth()/2+162.0f,
                              getWindowHeight()/2+162.0f ) );
}

void TetrisApp::RenderGrid() {
  /*cinder::gl::color(0, 1, 1);
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
  } catch (std::exception e) {}*/

  cinder::gl::color(0, 1, 1);

  BoolArrayGrid grid_array = grid->GetGridArr();

  // set coordinates to the beginning of the grid on the UI.
  float x = getWindowWidth()/2 - 160.0f;
  float y = getWindowHeight()/2 - 160.0f;

  // for each element of the grid array, draw a solid square if it is 1.
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (grid_array[i][j] == 1) {
        gl::drawSolidRect( Rectf( 40 * i + x,
                                  40 * j + y,
                                  40 * i + x + 40.0f,
                                  40 * j + y + 40.0f ) );
      }
    }
  }


}

void TetrisApp::DrawBlock() {

  cinder::gl::color(1, 0, 0);

  BoolArrayBlock block_spec = block.GetBlockSpec();

  // if the mPoints vector isn't empty, then set coords to the last element of
  // mPoints vectors. Else, user hasn't dragged and dropped- so set coords
  // to the usual position at the top of the screen.
  float x, y;
  if (!mPointsX.empty()) {
    x = mPointsX[mPointsX.size() - 1];
    y = mPointsY[mPointsY.size() - 1];
  } else {
    x = getWindowWidth()/2 - 50.0f;
    y = getWindowWidth()/9 - 50.0f;
  }

  // for each element of the block array, draw a solid square if the element
  // is a 1.
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

  // load and display bg image.
  background = gl::Texture2d::create(loadImage(loadAsset("tetris3.jpg")));
  gl::draw(background, getWindowBounds());

  DrawGameRect();

  DrawSmallRect();

  RenderGrid();

  DrawBlock();

  // print helpful text for the user.
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
}

void TetrisApp::mouseDrag(MouseEvent event) {
  // store the points that the user drags the mouse over.
  mPointsX.push_back(event.getX());
  mPointsY.push_back(event.getY());
}

void TetrisApp::mouseUp(MouseEvent event) {

  tried_to_fit_block = true;

  Point point = grid->GetPointForFloatCoords(event.getX(), event.getY());

  // this means the user dragged the block to an invalid location.
  if (point.GetColumn() < 0 || point.GetRow() < 0) {
    return;
  }

  // update the grid with new block.
  grid_updated = grid->Update(point.GetRow(), point.GetColumn(), block.GetBlockSpec());
}

void TetrisApp::keyDown(KeyEvent event) {
  switch (event.getCode()) {
    case KeyEvent::KEY_s: {
      engine_.StartGame();
    }
    case KeyEvent::KEY_r: {
      TetrisApp();
    }
    case KeyEvent::KEY_p: {
      // TODO do whatever is necessary to deal with paused/not paused
    }
    case KeyEvent::KEY_DOWN: {

    }
  }
}

}  // namespace tetrisapp
