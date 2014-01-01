#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInteger(void* first,void* second){
	return *(int*)first - *(int*)second;
}

void test_insert_root_node(){
    Tree tree = createTree(compareInteger);
    int data = 1;
    int result = insertTree(&tree, NULL, &data);
    ASSERT(1 == result);
}

void test_insert_node_at_different_levels(){
    Tree tree = createTree(compareInteger);
    int arr[] = {1,2,3};
    Iterator result;
    insertTree(&tree, NULL, &arr[0]);
    insertTree(&tree, &arr[0], &arr[1]);
    insertTree(&tree, &arr[0], &arr[2]);
}

void test_insert_node_under_child_node(){
    Tree tree = createTree(compareInteger);
    int arr[] = {1,2,3,4,5};
    Iterator result;
    insertTree(&tree, NULL, &arr[0]);
    insertTree(&tree, &arr[0], &arr[1]);
    insertTree(&tree, &arr[0], &arr[2]);
    insertTree(&tree, &arr[1], &arr[3]);
    insertTree(&tree, &arr[1], &arr[4]);

}