#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "node.h"
#include "tree.h"


using namespace std;



int main(int argc, char **argv) {
//argc is int count 
//argc will be 1 by running ./a.out by default
//
//argv is an array of chars 



	string file;	
	string word;	

	//this temp file is for writing temp words
	//into a file will be deleted at end of file
	ofstream temp_file;
	temp_file.open("temp");


	bool flag = true;



	//user enters too many args	
	if (argc > 2) {
		cout <<"Error: too many arguments" << endl;
		exit(1);
	}
	// user enters words at cl
	if (argc == 1){
		cout << "Please enter words to send to tree ";
		cout << ", press ctrl-d when done." << endl;
		
		while(flag) {
			getline(cin, word);
			if (cin.eof()==1){
				flag = false;
			}//exits out of input loop
			
		temp_file << word << endl;	
		
		
		}//end of input loop	
		temp_file.close();
		file = "temp";
	}

	//user enters file
	else if (argc == 2) {
		file= argv[1];			
		//file = file + ".input1";
	}


	//this code will open up the proper file
	//and send each line to a node
	ifstream infile(file);
	string line;

	//initialize a root node
	int itr = 0;
	struct node *root;

	//start of begining of file read each line
	while( getline(infile, line)){

		for (int i =0; i<line.length();i++){
			line[i]=tolower(line[i]);
		}//this loop makes every char lower


		if (itr==0){
			root = newNode(line);
			itr++;
		}
		else {
			buildTree(root, line);	
		}

	}
	infile.close();

	printInorder(root);


	return 0;
}
