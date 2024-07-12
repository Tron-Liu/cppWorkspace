#include "RB_Tree_Node.h"

RB_Tree_Node::RB_Tree_Node(int data)
    : _left(nullptr)
    , _right(nullptr)
    , _parent(nullptr)
    , _data(data),
      _color(RED)
{}

RB_Tree_Node::~RB_Tree_Node() {}