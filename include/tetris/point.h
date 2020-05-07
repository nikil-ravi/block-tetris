//
// Created by nikil on 4/28/2020.
//

#ifndef FINALPROJECT_POINT_H
#define FINALPROJECT_POINT_H


// Code taken from https://stackoverflow.com/a/20312698
class Point {
 private:
  int row,column;
 public:
  // default constructor- (default point is invalid.)
  Point() { row = -1; column = -1; }
  Point(int _x, int _y) : row(_x), column(_y) {}
  int GetRow();
  int GetColumn();
};

#endif  // FINALPROJECT_POINT_H
