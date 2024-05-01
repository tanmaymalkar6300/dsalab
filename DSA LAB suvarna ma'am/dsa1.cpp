#include<iostream>
#include<string.h>
using namespace std;
struct node{
	char label[10];           // TO STORE CHAPTER HEAD,SECTION HEAD
	int ch_count;              // To store no of child ele
	struct node *child[10];            //Array of pointers to store addresses of child nodes
}*root;                        // To store the address of root

// Class Declaration

class BST{
public:
	void create_tree(); 
	void display(node * r1);
	BST(){
		root = NULL;
	}
};

void BST::create_tree(){
	int tbooks, tchapters, i, j, k;
	root = new node(); // root node is created
	cout << "Enter name of book: ";
	cin >> root->label;
	cout << "Enter no. of chapters in book: ";
	cin >> tchapters; 
	root->ch_count = tchapters;
	for (i = 0; i < tchapters; i++) { // chapters
		root->child[i] = new node; // chapter is created
		cout << "Enter Chapter name: ";
		cin >> root->child[i]->label;
		cout << "Enter no. of sections in this Chapter: ";
		cin >> root->child[i]->ch_count;
		for (j = 0; j < root->child[i]->ch_count; j++) { // sections
			root->child[i]->child[j] = new node;
			cout << "Enter section head: ";
			cin >> root->child[i]->child[j]->label;
			cout << "Enter no. of subsections in this section: ";
			cin >> root->child[i]->child[j]->ch_count;
			for (k = 0; k < root->child[i]->child[j]->ch_count; k++) { // subsections
				root->child[i]->child[j]->child[k] = new node;
				cout << "Enter subsection head: ";
				cin >> root->child[i]->child[j]->child[k]->label;
			}
		}
	}
}

void BST::display(node * r1){
	if (r1 != NULL){
		cout << "\n-----Book Hierarchy---";
		cout << "\n Book title : " << r1->label;
		int tchapters = r1->ch_count; // how many chapters are there
		for (int i = 0; i < tchapters; i++) {
			cout << "\n Chapter " << i + 1;
			cout << "  " << r1->child[i]->label;
			cout << "\n  Sections";
			int tsections = r1->child[i]->ch_count; // how many sections in this chapter
			for (int j = 0; j < tsections; j++) {
				cout << "\n   " << r1->child[i]->child[j]->label;
				cout << "\n   Subsections";
				int tsubsections = r1->child[i]->child[j]->ch_count; // how many subsections in this section
				for (int k = 0; k < tsubsections; k++) {
					cout << "\n    " << r1->child[i]->child[j]->child[k]->label;
				}
			}
		}
	}
}

int main(){
	int choice;
	BST bst;
	while(1){
		cout<<"\n-----------------"<<endl;
		cout<<"Book Tree Creation"<<endl;
		cout<<"-----------------"<<endl;
		cout<<"1.Create"<<endl;
		cout<<"2.Display"<<endl;
		cout<<"3.Quit"<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice){
		case 1:
			bst.create_tree();
			break;
		case 2:
			bst.display(root);
			break;
		case 3:
			exit(1);
		default:
			cout<<"Wrong choice"<<endl;
		}
	}
	return 0; 
}
