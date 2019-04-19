#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;


struct node {
	string data;
	struct node *left;
	struct node *right;
	vector<string> other_words;
	bool vector_empty;
};





#endif
//EOF
