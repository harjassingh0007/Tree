#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInteger(void* first,void* second){
	return *(int*)first - *(int*)second;
}

void test_insert_root_node(){
    Tree tree = createTree(compareInteger);
    int data = 2;
    int result = insertTree(&tree, NULL, &data);
    ASSERT(1 == result);
}