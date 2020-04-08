#ifndef H_BST
#define H_BST
#include<iostream>

using namespace std;

template <class elemType>
struct nodeType {
	elemType info;
	nodeType<elemType>* lLink;
	nodeType<elemType>* rLink;
};

template <class elemType>
class BST {
public:
	BST();
	~BST();
	bool search(const elemType& searchItem)const;
	void insert(const elemType& insertItem);
	void deleteNode(const elemType& deleteItem);

	bool isEmpty()const;
	void inorderTraversal()const;
	void preorderTraversal()const;
	void postorderTraversal()const;
	void destroy(nodeType<elemType>*& p);
	nodeType<elemType> getRoot()const;
	/*
	//not needed - mistake
	bool operator==(const elemType&, const elemType&);
	bool operator<(const elemType&, const elemType&);
	*/
private:
	void inorder(nodeType<elemType>* p)const;
	void preorder(nodeType<elemType>* p)const;
	void postorder(nodeType<elemType>* p)const;
	nodeType<elemType>* root;
};

//implementation
/*
//not needed - mistake
template <class elemType>
bool BST<elemType>::operator==(elemType& leftHS, elemType& rightHS)
{
	return (strcmp(leftHS.info, rightHS) == 0);
}
template <class elemType>
bool BST<elemType>::operator<(elemType& leftHS, elemType& rightHS)
{
	return (strcmp(leftHS.info, rightHS) < 0);
}
*/
template <class elemType>
BST<elemType>::BST() {
	root = NULL;
}

template <class elemType>
BST<elemType>::~BST() {
	destroy(root);
}

template <class elemType>
void BST<elemType>::insert(const elemType& insertItem) {//insertItem is address to a struct
	nodeType<elemType>* current;
	nodeType<elemType>* trailCurrent = NULL;
	nodeType<elemType>* newNode;//

	newNode = new nodeType<elemType>;//invoke default construct
	newNode->info = insertItem;
	newNode->lLink = NULL;
	newNode->rLink = NULL;

	if (root == NULL)
		root = newNode;
	else {
		current = root;

		while (current != NULL) {
			trailCurrent = current;

			if (insertItem == current->info) {//compare struct needed 1
				/*cout << "dupplicate are not allowed"
					<< "value: " << insertItem << endl;*/
				return;
			}
			else
				if (insertItem < current->info)//compare string needed 2
					current = current->lLink;
				else
					current = current->rLink;
		}//end while

		if (insertItem < trailCurrent->info)//compare string needed 3
			trailCurrent->lLink = newNode;
		else
			trailCurrent->rLink = newNode;
	}
}

template <class elemType>
bool BST<elemType>::search(const elemType& searchItem)const {
	nodeType<elemType>* current;
	bool found = false;

	if (root == NULL)
		cout << "cannot search empty tree" << endl;
	else {
		current = root;

		while (current != NULL && !found) {
			if (searchItem == current->info)
				found = true;
			else if (searchItem < current->info)
				current = current->lLink;
			else
				current = current->rLink;
		}
	}
	return found;
}

template <class elemType>
void BST<elemType>::deleteNode(const elemType& deleteItem) {
	nodeType<elemType>* current;
	current = root;
	if (root == NULL) {
		cout << "empty node " << endl;
	}
	else {
		while (current != NULL) {
			if (deleteItem == current->info)
				current->info = NULL;
			else if (deleteItem < current->info)
				current = current->lLink;
			else
				current = current->rLink;
		}
	}
}

template <class elemType>
bool BST<elemType>::isEmpty() const {
	return (root == NULL);
}

template <class elemType>
void BST<elemType>::preorderTraversal() const {
	preorder(root);
}
template <class elemType>
void BST<elemType>::inorderTraversal()const {
	inorder(root);
}
template <class elemType>
void BST<elemType>::postorderTraversal()const {
	postorder(root);
}

template <class elemType>
void BST<elemType>::preorder(nodeType<elemType>* p)const {
	if (p != NULL) {
		cout << p->info << " ";
		preorder(p->lLink);
		inorder(p->rLink);
	}
}
template <class elemType>
void BST<elemType>::inorder(nodeType<elemType>* p)const {
	if (p != NULL) {
		preorder(p->lLink);
		cout << p->info << " ";
		inorder(p->rLink);
	}
}
template <class elemType>
void BST<elemType>::postorder(nodeType<elemType>* p)const {
	if (p != NULL) {
		preorder(p->lLink);
		inorder(p->rLink);
		cout << p->info << " ";
	}
}


template <class elemType>
void BST<elemType>::destroy(nodeType<elemType>*& p) {
	if (p != NULL) {
		destroy(p->lLink);
		destroy(p->rLink);
		delete p;
		p = NULL;
	}
}
template <class elemType>
nodeType<elemType> BST<elemType>::getRoot() const {
	return *root;
}
#endif //BST_H