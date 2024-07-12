#pragma once

#include <cstddef>
#include <stdint.h>

typedef int32_t INT32;

enum Color {
  BLACK = 0,
  RED = 1
};

class RB_Tree_Node {
public:
  RB_Tree_Node(int data);
  ~RB_Tree_Node();

public:
  RB_Tree_Node* _left;
  RB_Tree_Node* _right;
  RB_Tree_Node* _parent;

  INT32 _data;
  Color _color;
};