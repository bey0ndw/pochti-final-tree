#ifndef BYPASS_H
#define BYPASS_H
//Порядковый обход
void inOrder(TREENODEPTR treePtr){
    if(treePtr!=NULL){
    inOrder(treePtr->leftPtr);
    printf("%3d", treePtr->data);
    inOrder(treePtr->rightPtr);
    }
}
//Прямой обход
void preOrder(TREENODEPTR treePtr){
if(treePtr!=NULL){
printf("%3d", treePtr->data);
preOrder(treePtr->leftPtr);
preOrder(treePtr->rightPtr);
    }
}
//Обратный обход
void postOrder(TREENODEPTR treePtr){
    if(treePtr!=NULL){
    postOrder(treePtr->leftPtr);
    postOrder(treePtr->rightPtr);
    printf("%3d", treePtr->data);
    }
}
//Поэтажный обход
//Cтруктура для хранения этажа узла дерева
extern int duplicates,n;
//Создаем структру, содержащую информацию об этаже ключа
struct stageCounter{
    int stage;
    struct treeNode *Ptr;
};
struct stageCounter *stage_number;
void stageBypass(TREENODEPTR treePtr, int i, int j){
    if(j == 0 && i == 0){
        stage_number=(struct stageCounter *)calloc(n,sizeof(struct stageCounter));
    }
    if( treePtr !=NULL ){
        if (j==0){
            stage_number[j].stage = i;
            stage_number[j].Ptr = treePtr;
            j++;
        }
        while(stage_number[j].stage != NULL){
            j++;
        }
        stage_number[j].stage = i;
        stage_number[j].Ptr = treePtr;
        stageBypass(treePtr->leftPtr, i+1, j);
        stageBypass(treePtr->rightPtr, i+1, j);
    }
}
void stageSort(void){
    int i, j;
    for(i = 0 ; i < n-duplicates; i++)
    {
        for(j = n-1 - duplicates; j>i ; j--)
        {
            if((stage_number[j-1].stage) > (stage_number[j].stage) )
            {
                stage_number[n] = stage_number[j-1];
                stage_number[j-1] = stage_number[j] ;
                stage_number[j] = stage_number[n];
            }
        }
    }

    for (i=0; i<=n-1-duplicates; i++){
      printf("%d (st_%d); ", stage_number[i].Ptr->data, stage_number[i].stage+1);
        if(i ==n-1-duplicates )
            printf("\n");
    }
}
void stageOrder(TREENODEPTR treePtr){
    stageBypass(treePtr, 0, 0);
    stageSort();
}
#endif // BYPASS_H
