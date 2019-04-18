#include<final.h>


int main()
{
    picture();
    TREENODEPTR rootPtr, *copy=malloc(sizeof (TREENODEPTR));
    int choice, value;
    instructions();
    printf ("? ");
    scanf("%d", &choice) ;
    while (choice !=9) {
    switch (choice) {

    case 1:
    rootPtr = insert_tree();
    break;
    case 2:
    printf("Какое дерево вывести?(1-основное,0-копия)");
    scanf("%d", &value);
    //if (value == 1) showTree(rootPtr,0,0);
    //    else showTree(*copy,0,0);
    print2D(rootPtr);
    break;
    case 3:
    printf("Какое дерево удалить?(1-основное,0-копия)");
    scanf("%d", &value);
    if(value == 1) FreeTree(rootPtr);
    else FreeTree(*copy);
    printf("Дерево удалено!");
    break;
    case 4:
        printf("Порядковый обход:\n");
        inOrder(rootPtr);
        printf("Прямой обход:\n");
        preOrder(rootPtr);
        printf("Обратный обход:\n");
        postOrder(rootPtr);
        printf("\n Обходы окончены");
        break;
     case 5:
    printf("Поэтажный обход:\n");
    stageOrder(rootPtr);
        break;
    case 6:
        heightTree(rootPtr);
        break;
    case 7:
        dublicate(rootPtr, copy);
        break;
     case 8:
        printf("Введите элемент для удаления: ");
        scanf("%d", &value);
        dtree(rootPtr, value);
        --n;
        break;
    default:
    printf("Invalid choice.\n\n");
    instructions ();
    break;
    }
    printf("\n? ");
    scanf("%d", &choice);
    }
    FreeTree(*copy);
    FreeTree(rootPtr);
    free(stage_number);
    printf("End of run.\n");
    return 0;
}

