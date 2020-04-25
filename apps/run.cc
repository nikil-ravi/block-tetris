// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

#include "cinder/gl/gl.h"
#include "tetris/tetris.h"

using cinder::app::App;
using cinder::app::RendererGl;

using namespace ci;
using namespace ci::app;


namespace tetrisapp {

const int kSamples = 8;
const int kWidth = 800;
const int kHeight = 800;

void SetUp(App::Settings* settings) {
  settings->setWindowSize(kWidth, kHeight);
  settings->setTitle("My CS 126 Application");
}

}  // namespace myapp


// This is a macro that runs the application.
CINDER_APP(tetrisapp::TetrisApp,
           RendererGl(RendererGl::Options().msaa(tetrisapp::kSamples)),
           tetrisapp::SetUp)

