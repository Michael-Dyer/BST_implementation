#include <iostream>
#include <vector>
#include <string>
#include "tree.h"
#include "node.h"

using namespace std;
//this  is defining node and program functions
//for P0


//make new node
//this is a helper function to
//buildTree
struct node* newNode(string data){
	//allocate memory
	struct node* node = new(struct node);

       	//assign data
	node->data = data;	

	node->left = NULL;
	node->right = NULL;
	node->vector_empty = true;
	return(node);
}


//this will serve as the insert function
struct node* buildTree(struct node *node, string word){
	if (node == NULL) {
		return (newNode(word));
	}
	else {
		//this if block checks if the first letter of the 
		//word matches the first letter of the data
		//and if so appends it to an vector to be printed
		if (word[0] == node->data[0]){
			node->other_words.push_back(word);
			node->vector_empty = false;
		}
		else if (word < node->data) {
			node->left = buildTree(node->left, word);
		}
		else if (word > node->data){
			node->right = buildTree(node->right, word);
		}
		return (node);
		
	}


}//end of build tree

void printInorder(struct node *root) {
	if (root) {
		printInorder(root->left);
		cout << root->data << " ";
		for (int i = 0; i < root->other_words.size();i++){
			cout << root->other_words[i] << " ";
		}
		cout << endl;	
		printInorder(root->right);
	}
}

void printPreorder(struct node *root) {
	if (root) {
		cout << root->data << " ";
		for (int i = 0; i < root->other_words.size();i++){
			cout << root->other_words[i] << " ";
		}
		cout << endl;	
		printPreorder(root->left);
		printPreorder(root->right);
	}
}

void printPostorder(struct node *root) {
	if (root) {
		printPostorder(root->left);
		printPostorder(root->right);
		cout << root->data << " ";
		for (int i = 0; i < root->other_words.size();i++){
			cout << root->other_words[i] << " ";
		}
		cout << endl;	
	}
}
