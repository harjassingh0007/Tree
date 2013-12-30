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

TreeNode* createTreeNode(void *data,TreeNode *parent){
	DoubleList Node = create();
    TreeNode *treeNode = malloc(sizeof(TreeNode));
    treeNode->data = data;
    treeNode->parentNode = parent;
    treeNode->children = &Node;
    return treeNode;
}

// TreeNode* getTreeNode(DoubleList *list,void *dataToFind,compare cmp){
//     Iterator it = getIterator(list);
//     TreeNode *tn;
//     DoubleList Node;
//     while(it.hasNext(&it)){
//         tn = (TreeNode*)it.next(&it);
//         if(0 == cmp(tn->data,dataToFind))
//             return tn;
//         if(tn->children->head){
//             Node =  getTreeNode(tn->children, dataToFind, cmp);
        	
//         }
//     }
//     return NULL;
// }

int insertTreeNode(Tree *tree, void *data, void *parentData){
	TreeNode *root = (TreeNode*)tree->root;
    TreeNode *nodeToInsert, *parentNode;
    if(NULL == tree->root){
            tree->root = createTreeNode(data, NULL);
            return 1;
    }
    if(0 == tree->compare(root->data,parentData)){
            parentNode = root;
            nodeToInsert = createTreeNode(data, parentNode);
            insert(root->children, 0, nodeToInsert);
            return 1;
    }
    // parentNode = getTreeNode(root->children, parentData, tree->compare);
    // nodeToInsert = (data, parentNode);
    // insert(&parentNode->children, 0, nodeToInsert);
    return 1;
}