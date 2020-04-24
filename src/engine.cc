//
// Created by nikil on 4/24/2020.
//

#include "tetris/engine.h"
#include <Windows.h>
#include <cinder/Font.h>
#include <cinder/Text.h>
#include <cinder/Vector.h>
#include "cinder/gl/gl.h"
#include <cinder/app/App.h>



using cinder::TextBox;
using cinder::Color;
using cinder::ColorA;
using namespace ci;
using namespace ci::app;
using namespace std;

namespace tetris {

  const char kNormalFont[] = "Arial";

  Engine::Engine() {}

  void tetris::Engine::StartGame() {
    auto box = TextBox()
        .alignment(TextBox::CENTER)
        .font(cinder::Font(kNormalFont, 30))
        .size({500, 50})
        .backgroundColor(ColorA(0, 0, 0, 0))
        .text("Game Started");
    
    const auto box_size = box.getSize();
    const cinder::vec2 locp = {getWindowCenter().x - box_size.x / 2, getWindowCenter().y - box_size.y / 2};
    const auto surface = box.render();
    const auto texture = cinder::gl::Texture::create(surface);
    cinder::gl::draw(texture, locp);
    gl::drawSolidRect( Rectf( getWindowWidth()/2-20.0f,
                              getWindowHeight()/2-20.0f,
                              getWindowWidth()/2+20.0f,
                              getWindowHeight()/2+20.0f ) );
  }

  void Engine::Reset() {}

}

