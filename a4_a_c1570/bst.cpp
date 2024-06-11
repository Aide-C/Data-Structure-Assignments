#include <iostream>
using namespace std;

struct BinNode {
       int key;
       BinNode *left;
       BinNode *right;
};

class myBST {
public:
	myBST () { root = NULL; }
	~myBST ();
	BinNode* findInBST(int k); // return NULL if not found
	void insertToBST(int k);
	void preOrderTraversal();
	void postOrderTraversal();
	void inOrderTraversal();
	void rotatedPrintTree();
private:

    BinNode* root;

	void free_helper(BinNode* node);
	BinNode* find_helper(BinNode* node, int k);  //optional helper function for findInBST
	void insert_helper(BinNode* &node, int k);  //optional helper function for insertToBST
	void preOrder(BinNode* node);
	void postOrder(BinNode* node);
	void inOrder(BinNode* node);
	void rotatedPrint(BinNode* node, int d);
};

myBST::~myBST() {
	free_helper(root);
}

void myBST::free_helper(BinNode* node) {
	if(node != NULL) {
		free_helper(node->left);
		free_helper(node->right);
		delete node;
	}
}



// //***************************
// //recursive implementation***
// //***************************
BinNode* myBST::findInBST(int k) {
    find_helper(root, k);
}

BinNode* myBST::find_helper(BinNode* node, int k) {
    if (node == NULL){
        return NULL;
    }else if (k < node->key){
        find_helper(node->left, k);
    }else if (node->key < k){
        find_helper(node->right, k);
    }else{
        return node;
    }
}



// //***************************
// //recursive implementation***
// //***************************
void myBST::insertToBST(int k) {
    insert_helper(root, k);
}


void myBST::insert_helper(BinNode* &node, int k){
    BinNode* check = new BinNode;
    check = findInBST(k);

    if (check != NULL){
        cout << k << " is an existing key. No new node has been inserted" << endl;
        return;
    }else{
        if (node == NULL){
            node = new BinNode;
            node->key = k;
            node->left = NULL;
            node->right = NULL;
            return;
        }else if (k < node->key){
            return insert_helper(node->left, k);
        }else{
            return insert_helper(node->right, k);
        }
    }
}


//***********************************
//preOrderTraversal implementation***
//***********************************
void myBST::preOrderTraversal() {
	preOrder(root);
	cout << endl;
}

void myBST::preOrder(BinNode* node) {
    //print out root then recursively print all data in left tree then all data in right tree
    //node, left, right
    //pre-fix expression
    if (node != NULL){
        cout << node->key << " ";
        preOrder(node->left);
        preOrder(node->right);
    }else{
        return;
    }
}


//************************************
//postOrderTraversal implementation***
//************************************
void myBST::postOrderTraversal() {
	postOrder(root);
	cout << endl;
}

void myBST::postOrder(BinNode* node) {
    //left, right, node
    //post-fix expression
    if (node != NULL){
        postOrder(node->left);
        postOrder(node->right);
        cout << node->key << " ";
    }else{
        return;
    }
}



//**********************************
//inOrderTraversal implementation***
//**********************************
void myBST::inOrderTraversal() {
	inOrder(root);
	cout << endl;
}

void myBST::inOrder(BinNode* node) {
    //Prints it out sorted from least to greatest
    //left, node, right
    //infix expression
    if (node != NULL){
        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }else{
        return;
    }
}


//***********************************
//print the tree (left rotated)******
//***********************************
void myBST::rotatedPrintTree() {
	rotatedPrint(root, 0);
}

void myBST::rotatedPrint(BinNode* node, int d) {
	if(node == NULL)
		return;

	if (node->right != NULL)
		rotatedPrint(node->right, d+1);

	for(int i = 0; i < d; i++)
		cout << "\t";
	cout << node->key << endl;

	if (node->left != NULL)
		rotatedPrint(node->left, d+1);
}



int main()
{
    myBST testTree;

	int user_input = 0;

	while (user_input != -1) {
		cout << "Inserting a new node...." << endl;
		cout << "Please enter an integer between 0 and 99 as the key, ";
		cout << "and enter -1 to stop and to see the resulting tree: ";
		cin >> user_input;
		if (user_input >= 0 && user_input <= 99)
			testTree.insertToBST(user_input);
		else if (user_input != -1)
			cout << "Invalid input value (" << user_input << ") !" << endl;
	}

	cout << "Print the resulting tree (left-rotated):" << endl;
	testTree.rotatedPrintTree();

	cout << "preOrderTraversal: ";
	testTree.preOrderTraversal();
	cout << "postOrderTraversal: ";
	testTree.postOrderTraversal();
	cout << "inOrderTraversal: ";
	testTree.inOrderTraversal();


	user_input = 0;

	while (user_input != -1) {
		cout << "Searching a key...." << endl;
		cout << "Please enter an integer between 0 and 99 as the key to search, ";
		cout << "and enter -1 to stop searching: ";
		cin >> user_input;

		if (user_input >= 0 && user_input <= 99) {
			BinNode* temp = testTree.findInBST(user_input);
			if(temp == NULL)
				cout << user_input << " is not in this BST." << endl;
			else {
				cout << user_input << " is in this BST." << endl;
				if(temp->left != NULL)
					cout << user_input << " has a left child " << temp->left->key << endl;
				if(temp->right != NULL)
					cout << user_input << " has a right child " << temp->right->key << endl;
			}
		}
		else if (user_input != -1)
			cout << "Invalid input value (" << user_input << ") !" << endl;
	}

	return 0;
}
