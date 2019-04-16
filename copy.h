#ifndef COPY_H
#define COPY_H
void dublicate(TREENODEPTR ptr, TREENODEPTR *copy)
{
    if (ptr == NULL){
        *copy = NULL;
        return;
    }

    *copy = (TREENODEPTR)malloc(sizeof(TREENODE));
    (*copy)->data = ptr->data;
    dublicate(ptr->leftPtr, &((*copy)->leftPtr));
    dublicate(ptr->rightPtr, &((*copy)->rightPtr));
}
#endif // COPY_H
