#include "DoubleList.h"

typedef struct {
        node* current;
        DoubleList* list;

} TreeIterator;

void* next(TreeIterator* it);
int hasNext(TreeIterator* it);