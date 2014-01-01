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

TreeNode* getTreeNode(DoubleList list,void *dataToFind,compare cmp){
    Iterator it = dList_getIterator(&list);
    TreeNode *treenode;
    while(it.hasNext(&it)){
        treenode = (TreeNode*)it.next(&it);
        if(0 == cmp(treenode->data,dataToFind)){
            return treenode;
        }
        if(treenode->children.head)
            return getTreeNode(treenode->children, dataToFind, cmp);
    }
    return NULL;
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
    parentNode = getTreeNode(root->children, parentData, tree->cmp);
    nodeToInsert = createTreeNode(childData, parentNode);
    insert(&parentNode->children, 0, nodeToInsert);
    return 1;
}

void* treeNext(Iterator *it){
    TreeNode *node;
    Iterator treeIterator = dList_getIterator(it->list);
    treeIterator.position = it->position;
    node = treeIterator.next(&treeIterator);
    it->position = treeIterator.position;
    return node->data;
}

Iterator getChildren(Tree* tree, void *parent) {
    TreeNode *temp,*root = (TreeNode*)tree->root;
    Iterator it;
    if(0 == tree->cmp(root->data,parent))
        temp = root;
    else 
        temp = getTreeNode(root->children, parent, tree->cmp);
    it = dList_getIterator(&temp->children);
    it.next = &treeNext;
    return it;
}

