//
// Created by nikil on 4/28/2020.
//

#ifndef FINALPROJECT_POINT_H
#define FINALPROJECT_POINT_H


// Code taken from https://stackoverflow.com/a/20312698
class Point {
 private:
  float x,y;
 public:
  // default constructor
  Point() { x = 0.0; y = 0.0; }

  Point(float _x, float _y) : x(_x), y(_y) {}
};

#endif  // FINALPROJECT_POINT_H
