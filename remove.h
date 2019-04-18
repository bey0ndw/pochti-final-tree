#ifndef REMOVE_H
#define REMOVE_H
void FreeTree( TREENODEPTR  w ) {
    if (w == NULL) // Если удалять нечего, то выходим от греха подальше
        return;
    FreeTree(w->leftPtr);
    FreeTree(w->rightPtr);
    free(w);
    //w = NULL;
    w->leftPtr = NULL;
    w->rightPtr = NULL;
    w->data = ARSEN + 1;
}
/*TREENODEPTR parent(TREENODEPTR root, int a){
    if(a == 0){
        root->parent =NULL;
        ++a;
        //parent(root->leftPtr, a);
        //parent(root->rightPtr,a);
    }

        if(root->leftPtr != NULL){
            (root->leftPtr)->parent = root;

        }
        if(root->rightPtr != NULL){
            (root->rightPtr)->parent = root;
        }
        if(root->leftPtr != NULL)
        parent(root->leftPtr, a);
         if(root->rightPtr != NULL)
        parent(root->rightPtr,a);


    return root;
}*/
/*TREENODEPTR search_tree(TREENODEPTR root, int data){
    if(!root) return root;
    while(root->data != data){
        if(data < root->data) root=root->leftPtr;
        else root = root->rightPtr;
        if(root == NULL) break;
    }
    return root;
}*/
TREENODEPTR dtree(TREENODEPTR root, int key)
{
    TREENODEPTR p,p2;

    if(!root) return root; /* вершина не найдена */

    if(root->data == key) { /* удаление корня */
        /* это означает пустое дерево */
        if(root->leftPtr == root->rightPtr){
            free(root);
            return NULL;
        }
        /* или если одно из поддеревьев пустое */
        else if(root->leftPtr == NULL) {
            p = root->rightPtr;
            free(root);
            return p;
        }
        else if(root->rightPtr == NULL) {
            p = root->leftPtr;
            free(root);
            return p;
        }
        /* или есть оба поддерева */
        else {
            p2 = root->rightPtr;
            p = root->rightPtr;
            while(p->leftPtr) p = p->leftPtr;
            p->leftPtr = root->leftPtr;
            free(root);
            return p2;
        }
    }
if(root->data < key) root->rightPtr = dtree(root->rightPtr, key);
else root->leftPtr = dtree(root->leftPtr, key);
return root;
}

#endif // REMOVE_H
