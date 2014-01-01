#include "tree.h"
#include <stdlib.h>

TreeNode* createTreeNode(void *data,TreeNode *parent){
    TreeNode *treeNode = malloc(sizeof(TreeNode));
    treeNode->data = data;
    treeNode->parent = parent;
    treeNode->children = create();
    return treeNode;
}

Tree createTree(cmpr cmp){
    Tree tree = {cmp,NULL};
    return tree;
}

int insertTree(Tree* tree, void* parentData, void* childData) {
    TreeNode *root = (TreeNode*)tree->root;
    TreeNode *nodeToInsert, *parentNode;
    if(NULL == tree->root){
        tree->root = createTreeNode(childData, NULL);
        return 1;
    }
    if(0 == tree->cmp(root->data,parentData)){
        parentNode = root;
        nodeToInsert = createTreeNode(childData, parentNode);
        insert(&root->children, 0, nodeToInsert);
        return 1;
    }
    return 1;
}