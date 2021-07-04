#pragma once
#include"Node.h"
#include<iostream>
using namespace std;
class Tree
{
public:
	Node* root;
	Tree();
};
Tree::Tree()
{
	root = nullptr;
}