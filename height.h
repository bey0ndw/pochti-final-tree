#ifndef HEIGHT_H
#define HEIGHT_H
extern int n, duplicates;
extern struct stageCounter *stage_number;
int stageSort1(void){
    int i, j;
    for(i = 0 ; i < n-duplicates; i++){
        for(j = n-1 - duplicates; j>i ; j--){
            if((stage_number[j-1].stage) > (stage_number[j].stage) )
            {
                stage_number[n] = stage_number[j-1];
                stage_number[j-1] = stage_number[j] ;
                stage_number[j] = stage_number[n];
            }
        }
    }
    return (stage_number[n-1-duplicates].stage + 1);
}
void heightTree(TREENODEPTR treePtr) {
    stageBypass(treePtr, 0, 0);
    printf("\n The height is: %d stages. \n", stageSort1());

}
#endif // HEIGHT_H
