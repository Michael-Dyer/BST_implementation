#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
#include <vector>


using namespace std;


struct node* buildTree(struct node *root, string word);

void printInorder(struct node *root);
void printPreorder(struct node *root);
void printPostorder(struct node *root);

struct node* newNode(string data);


#endif
