#pragma once

#include <stdint.h>

#include "RB_Tree_Node.h"

typedef RB_Tree_Node Node;

class RB_Tree {
public:
  RB_Tree(INT32 data);
  ~RB_Tree();

public:
  void Left_Rotate(Node *parent);
  void Right_Rotate(Node *parent);

  bool Insert(INT32 data);
  bool Delete(INT32 data);

  void Destory(Node* root);

  Node* Find(INT32 data);

  // 寻找当前节点的中序后继节点
  Node* Find_Successor(Node* node);

public:
  Node* _root;
  INT32 _data;
};