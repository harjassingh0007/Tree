#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInteger(void* first,void* second){
return *(int*)first - *(int*)second;
}

void test_insert_root_node_in_tree(){
	Tree* tree = createTree(compareInteger);
	int _10 = 10;
	ASSERT(insertTreeNode(tree, &_10,NULL));
}
void test_insert_child_node_to_root_in_tree(){
	Tree* tree = createTree(compareInteger);
	int _10 = 10,_20 = 20;
	ASSERT(insertTreeNode(tree, &_10,NULL));
	ASSERT(insertTreeNode(tree, &_20, &_10));
}
void test_insert_two_child_node_to_root_in_tree(){
	Tree* tree = createTree(compareInteger);
	int _10 = 10,_20 = 20,_30 = 30;
	ASSERT(insertTreeNode(tree, &_10,NULL));
	ASSERT(insertTreeNode(tree, &_20, &_10));
	ASSERT(insertTreeNode(tree, &_30, &_10));
}

void test_insert_child_node_to_random_parent_in_tree(){
	Tree* tree = createTree(compareInteger);
	Iterator it;
	int _10 = 10,_20 = 20,_30 = 30,_40 = 40;
	it = getChildren(tree, &_10);
	ASSERT(insertTreeNode(tree, &_10,NULL));
	ASSERT(insertTreeNode(tree, &_20, &_10));
	ASSERT(insertTreeNode(tree, &_30, &_10));

}