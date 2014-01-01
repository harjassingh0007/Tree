#include "treeIterator.h"

#ifndef _COMPARE_
#define _COMPARE_
typedef int (*cmpr)(void* firstElement, void* secondElement);
#endif
typedef struct {
        compare cmp;
        void *root;
} Tree;

typedef struct tn{
        void* data;
        struct tn* parent;
        DoubleList children;
} TreeNode;

Tree createTree(cmpr cmp);
int insertTree(Tree* tree, void* parentData, void* data);
Iterator getChildren(Tree* tree, void* parentData);
int deleteFromTree(Tree* tree, void* data);
int searchTreeNode(Tree* tree, void* data);