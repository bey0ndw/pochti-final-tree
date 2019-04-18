#ifndef INPUT_H
#define INPUT_H

#define ARSEN 500

/*----------------------------------------------Функция ввода, включающая в себя удаление двойников------------------------------------------------------------*/
void insertNode(TREENODEPTR *treePtr, int value){
    if(*treePtr==NULL){
        *treePtr=malloc(sizeof(TREENODE));
        if (*treePtr!=NULL){
            (*treePtr)->data=value;
            (*treePtr)->leftPtr=NULL;
            (*treePtr)->rightPtr=NULL;
        }
        else
            printf("%d not insert. No memory available.\n", value);
    }
    //Ввод элемента отличного от корня
    else
        if (value<(*treePtr)->data)
            insertNode(&((*treePtr)->leftPtr), value);
        else
            if(value>(*treePtr)->data)
                insertNode(&((*treePtr)->rightPtr), value);
            else
            {
                printf("dup ");
                duplicates++;
            }
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------Функция ввода, включающие различные "фишки"----------------------------------------------------------*/
    TREENODEPTR insert_tree(void){
    int i, item,marker;
    TREENODEPTR rootPtr=NULL;
    printf("Введите кол-во элементов: ");
    scanf("%d", &n);
    printf("\nХотите ввести данные самостоятельно?(1-да,0-нет)");
    scanf("%d", &marker);
    if(marker == 0){
        srand((unsigned int)time(NULL));
       printf("The numbers degin placed in the tree are:\n");
        for(i=1; i<=n; i++){
            item=rand()%ARSEN;
            printf("%3d ", item);
            insertNode(&rootPtr, item);
        }
    }
    else {
        for(i=1; i<=n; i++){
            scanf("%d", &item);
            insertNode(&rootPtr, item);
        }
    }
    return rootPtr;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#endif // INPUT_H
