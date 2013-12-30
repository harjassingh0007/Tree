#include "../doublelist/doubleList.h"

typedef struct treeNode{
	void * data;
	struct treeNode* parentNode;
	DoubleList* children;
} TreeNode;

typedef int CompareFunc(void* first,void* second);

typedef struct{
	TreeNode* root;
	CompareFunc* compare;
} Tree;

Tree* createTree(CompareFunc* compare);
int insertTreeNode(Tree* tree,void* data,void* parentData);
Iterator getChildren(Tree* tree, void* parentData);


void disposeTree(Tree* tree);