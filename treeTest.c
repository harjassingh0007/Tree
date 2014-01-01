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

void test_get_child_after_inserting_under_parent(){
    Tree tree = createTree(compareInteger);
    int arr[] = {1,2,3,4};
    Iterator result;
    insertTree(&tree, NULL, &arr[0]);
    insertTree(&tree, &arr[0], &arr[1]);
    insertTree(&tree, &arr[1], &arr[2]);
    insertTree(&tree, &arr[2], &arr[3]);
    result = getChildren(&tree, &arr[1]);
    ASSERT(3 == *(int*)result.next(&result));
}

void test_get_children_from_two_different_(){
    Tree tree = createTree(compareInteger);
    int arr[] = {1,2,3,4};
    Iterator result;
    insertTree(&tree, NULL, &arr[0]);
    insertTree(&tree, &arr[0], &arr[1]);
    insertTree(&tree, &arr[1], &arr[2]);
    insertTree(&tree, &arr[2], &arr[3]);
    result = getChildren(&tree, &arr[1]);
    ASSERT(3 == *(int*)result.next(&result));
    result = getChildren(&tree, &arr[2]);
    ASSERT(4 == *(int*)result.next(&result));
}

void test_search_element_in_the_tree(){
    Tree tree = createTree(compareInteger);
    Iterator result;
    int data[5] = {1,2,3,4,5};
    ASSERT(insertTree(&tree, NULL, &data[0]));
    ASSERT(insertTree(&tree, &data[0], &data[1]));
    ASSERT(insertTree(&tree, &data[1], &data[2]));
    ASSERT(insertTree(&tree, &data[2], &data[3]));
    ASSERT(insertTree(&tree, &data[3], &data[4]));
    ASSERT(searchTreeNode(&tree,&data[4]));
    ASSERT(searchTreeNode(&tree,&data[2]));
    ASSERT(searchTreeNode(&tree,&data[0]));
}



















