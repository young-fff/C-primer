/*
*File : ch13/13.2/Tree.h
*Date : 2022-08-08
*Page : 457
*/

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <new>

class TreeNode {
public:
    TreeNode() : value(std::string()), count(new int(1)), left(nullptr), right(nullptr) { }
    TreeNode(const TreeNode &rhs) : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { }
    TreeNode& operator=(const TreeNode&);
    ~TreeNode();
private:
    std::string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};

TreeNode::~TreeNode()
{
    if (0 == --*count) {
        delete left;
        delete right;
        delete count;
    }
}

TreeNode& TreeNode::operator=(const TreeNode &rhs)
{
    ++*rhs.count;
    if (0 == --*count) {
        delete left;
        delete right;
        delete count;
    }
    value = rhs.value;
    count = rhs.count;
    left = rhs.left;
    right = rhs.right;
    return *this;
}

class BinStrTree {
public:
    BinStrTree() : root(new TreeNode()) { }
    BinStrTree(const BinStrTree &bst) : root(bst.root) { }
    BinStrTree& operator=(const BinStrTree &rhs);
    ~BinStrTree() { delete root; }
private:
    TreeNode *root;
};

BinStrTree& BinStrTree::operator=(const BinStrTree &rhs)
{
    TreeNode *new_root = new TreeNode(*rhs.root);
    delete root;
    root = new_root;
    return *this;
}

#endif