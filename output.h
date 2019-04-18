#ifndef OUTPUT_H
#define OUTPUT_H

#define COUNT 10
void showLine(char* c, int p, int s) {
    int i;
    int t=s; for(i=0; i<p; i++) {printf(t&1 ? "| " : " "); t/=2;} printf(c);
}
void showTree(TREENODEPTR wood, int p, int s) {
    if( wood->data == ARSEN + 1) {
        printf("Дерево пусто");
        return;
    }
    if (wood == NULL) return;
    printf("%d", wood->data); printf("\n");
    if (wood->leftPtr != NULL) {
        showLine("|\n", p, s); showLine("L:", p, s);
        showTree(wood->leftPtr, p+1, s + ((wood->rightPtr == NULL ? 0 : 1)<<p));
    }
    if (wood->rightPtr != NULL) {
        showLine("|\n", p, s); showLine("R: ", p, s);
        showTree(wood->rightPtr, p+1, s);
    }
}

#endif // OUTPUT_H
