#include "tree.h"
#include <stdlib.h>

Tree* createTree(CompareFunc* compare){
	Tree* tree = calloc(1,sizeof(Tree));
	tree->root = NULL;
	tree->compare = compare;
	return tree;
}

TreeNode* getParentNode(Tree* tree,void* parentData){
	TreeNode* nextNode = tree->root;
	return nextNode;
}

Iterator getChildren(Tree *tree, void *parentData){
	Iterator it;
	return it;
}

int insertTreeNode(Tree *tree, void *data, void *parentData){
	TreeNode* parentNode;
	DoubleList linkedList = create();
	TreeNode* childNode = calloc(1, sizeof(TreeNode));
	childNode->data = data;
	childNode->children = &linkedList;
	if(parentData == NULL){
		childNode->parentNode = NULL;
		tree->root = childNode;
		return 1;
	}
	parentNode = getParentNode(tree,parentData);
	childNode->parentNode = parentNode;
	return insert(parentNode->children,parentNode->children->length,childNode);
}