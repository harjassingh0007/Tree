typedef struct iterator{
    void *position;
    void *list;
    void* (*next)(struct iterator *it);
    int (*hasNext)(struct iterator *it);
} Iterator;