#pragma once

#include "RB_Tree.h"
#include "RB_Tree_Node.h"

RB_Tree::RB_Tree(INT32 data) : _root(nullptr) {
  if (_root == nullptr) {
    _root = new RB_Tree_Node(data);
  }
}

RB_Tree::~RB_Tree() {
  Destory(_root);
  _root = nullptr;
}

//   g           p
//  p u    ->   c g
// c               u
void RB_Tree::Right_Rotate(Node *parent) {
  Node *child = parent->_left;
  Node *grandchild_right = child->_right;

  parent->_left = grandchild_right;
  if (grandchild_right)
    grandchild_right->_parent = parent;

  Node *pparent = parent->_parent;

  child->_right = parent;
  parent->_parent = child;

  if (pparent == nullptr) {
    _root = child;
    _root->_parent = nullptr;
  } else {
    if (pparent->_left == parent)
      pparent->_left = child;
    else
      pparent->_right = child;

    child->_parent = pparent;
  }
}

//  g           p
// u p    ->   g c
//    c       u
void RB_Tree::Left_Rotate(Node *parent) {
  Node *child = parent->_right;
  Node *grandChild_left = child->_left;

  parent->_right = grandChild_left;
  if (grandChild_left)
    grandChild_left->_parent = parent;

  Node *pparent = parent->_parent;

  child->_left = parent;
  parent->_parent = child;

  if (pparent == nullptr) {
    _root = child;
    _root->_parent = nullptr;
  } else {
    if (pparent->_left == parent)
      pparent->_left = child;
    else
      pparent->_right = child;

    child->_parent = pparent;
  }
}

bool RB_Tree::Insert(INT32 data) {
  if (_root == nullptr) {
    _root = new Node(data);
    _root->_color = BLACK;

    return true;
  }

  Node *parent = nullptr;
  Node *cur = _root;

  while (cur) {
    if (cur->_data < data) {
      parent = cur;
      cur = cur->_right;
    } else if (cur->_data > data) {
      parent = cur;
      cur = cur->_left;
    } else {
      return false;
    }
  }

  // 链接
  cur = new Node(data);
  if (parent->_data > data)
    parent->_left = cur;
  else
    parent->_right = cur;

  // 更新节点的父节点
  cur->_parent = parent;

  while (parent && parent->_color == RED) {
    Node *grandfather = parent->_parent;

    if (grandfather->_left == parent) {
      Node *uncle = grandfather->_right;
      // uncle 存在且为红色，
      if (uncle && uncle->_color == RED) {
        parent->_color = BLACK;
        uncle->_color = BLACK;
        grandfather->_color = RED;

        cur = grandfather;
        parent = cur->_parent;
      } else { // uncle 不存在或者 uncle 节点存在且为黑
        //       grandfather
        //    parent      uncle
        // cur
        if (parent->_left == cur) {
          Right_Rotate(grandfather);
          parent->_color = BLACK;
          grandfather->_color = RED;
        } else {
          //    g
          //  p   u
          //    c
          Left_Rotate(parent);
          Right_Rotate(grandfather);
          cur->_color = BLACK;
          grandfather->_color = RED;
        }

        break;
      }
    }

    if (grandfather->_right == parent) {
      Node *uncle = grandfather->_left;

      if (uncle && uncle->_color == RED) {
        parent->_color = BLACK;
        uncle->_color = BLACK;
        grandfather->_color = RED;

        cur = grandfather;
        parent = cur->_parent;
      } else {
        if (parent->_right == cur) {
          Left_Rotate(grandfather);
          grandfather->_color = RED;
          parent->_color = BLACK;
        } else {
          Right_Rotate(parent);
          Left_Rotate(grandfather);
          cur->_color = BLACK;
          grandfather->_color = RED;
        }

        break;
      }
    }
  }

  _root->_color = BLACK;
  return true;
}

bool RB_Tree::Delete(INT32 data) {
  Node *tmp_node = Find(data);

  if (tmp_node) {
    int color = tmp_node->_color;

    if (tmp_node->_left == nullptr && tmp_node->_right == nullptr) {
      delete tmp_node;
    } else if (tmp_node->_left == nullptr && tmp_node->_right != nullptr) {
      if (tmp_node != _root) {
        if (tmp_node->_parent->_left == tmp_node) {
          tmp_node->_parent->_left = tmp_node->_right;
          tmp_node->_right->_parent = tmp_node->_parent;
        } else {
          tmp_node->_parent->_right = tmp_node->_right;
          tmp_node->_right->_parent = tmp_node->_parent;
        }
      } else {
        _root = tmp_node->_right;
        tmp_node->_right->_parent = nullptr;
      }
    } else if (tmp_node->_left != nullptr && tmp_node->_right == nullptr) {
      if (tmp_node != _root) {
        if (tmp_node->_parent->_left == tmp_node) {
          tmp_node->_parent->_left = tmp_node->_left;
          tmp_node->_left->_parent = tmp_node->_parent;
        } else {
          tmp_node->_parent->_right = tmp_node->_left;
          tmp_node->_left->_parent = tmp_node->_parent;
        }
      } else {
        _root = tmp_node->_left;
        tmp_node->_left->_parent = nullptr;
      }
    } else if (tmp_node->_left != nullptr && tmp_node->_right != nullptr) {
      Node *successor_node = Find_Successor(tmp_node);
      if (tmp_node == tmp_node->_parent->_left) {
        tmp_node->_parent->_left = successor_node;
        successor_node->_right = tmp_node->_right;
        successor_node->_left = tmp_node->_left;
        successor_node->_parent = tmp_node->_parent;
        successor_node->_color = tmp_node->_color;

        if (successor_node->_right) {
          successor_node->_parent->_left = successor_node->_right;
          successor_node->_right->_parent = successor_node->_parent;
        }
      } else {
        tmp_node->_parent->_right = successor_node;
        successor_node->_right = tmp_node->_right;
        successor_node->_left = tmp_node->_left;
        successor_node->_parent = tmp_node->_parent;
        successor_node->_color = tmp_node->_color;

        if (successor_node->_right) {
          successor_node->_parent->_left = successor_node->_right;
          successor_node->_right->_parent = successor_node->_parent;
        }
      }
    }

    if (color == BLACK) {
      
    }
  } else
    return false;

  return true;
}

Node *RB_Tree::Find_Successor(Node *node) {
  Node *tmp = node->_right;
  while (tmp->_left != nullptr) {
    tmp = tmp->_left;
  }
  return tmp;
}

void RB_Tree::Destory(RB_Tree_Node *root) {
  if (root == nullptr)
    return;

  if (root->_left != nullptr)
    Destory(root->_left);
  if (root->_right != nullptr)
    Destory(root->_right);

  delete root;
}

Node *RB_Tree::Find(INT32 data) {
  Node *cur = _root;
  while (cur) {
    if (cur->_data < data)
      cur = cur->_right;
    else if (cur->_data > data)
      cur = cur->_left;
    else
      return cur;
  }

  return nullptr;
}