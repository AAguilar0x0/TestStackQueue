#include<stdio.h>
#include"myTools.h"
#include"stackqueue.h"

int optionMenu(){
    printf("\t\tOptions\n");
    printf("\t1. Insert\n");
    printf("\t2. Delete\n");
    printf("\tInput> ");
    int choice;
    scanf("%1d",&choice);
    return choice;
}

int endMenu(Stackptr outStack, Queueptr outQueue){
    char endChoice;
    gotoxy(0,2);
    delline(9);
    gotoxy(0,2);
    printf("\tOut-Stack: ");
    dispStack(outStack);
    printf("\n\tOut-Queue: ");
    dispQueue(outQueue);
    printf("\n\tDo you want to run again? [y/n]: ");
    fflush(stdin);
    scanf("%c",&endChoice);
    endChoice = tolower(endChoice);
    gotoxy(0,2);
    delline((endChoice == 'y') * 5);
    freeStack(outStack);
    freeQueue(outQueue);
    return endChoice;
}

int main(void){
    printf("\t\tStack and Queue Test Driver");
    Stackptr inStack = createStack();
    Queueptr inQueue = createQueue();
    Stackptr outStack = createStack();
    Queueptr outQueue = createQueue();
    char endChoice = 'y';
    int optChoice;
    int item;
    int flag = 0;
    while(endChoice == 'y'){
        gotoxy(0,2);
        optChoice = optionMenu();
        optChoice = (optChoice != 2 || inStack->count || inQueue->count) * optChoice;
        gotoxy(0,7);
        delline(3);
        gotoxy(0,7);
        switch(optChoice){
            case 1:
                flag = 1;
                printf("\t\tInsert\n");
                printf("\tItem: ");
                int item;
                scanf("%d",&item);
                push(inStack,item);
                enqueue(inQueue,item);
                break;
            case 2:
                printf("\t\tDelete\n");
                printf("\tData deleted");
                enqueue(outQueue,pop(inStack));
                push(outStack,dequeue(inQueue));
                break;
            default:
                printf("\t\tError\n");
                printf("\tPossible cause: nothing was inserted yet, or option is not available.");
                break;
        }
        if(flag && !inStack->count && !inQueue->count){
            flag = 0;
            endChoice = endMenu(outStack,outQueue);        
            freeStack(inStack);
            freeQueue(inQueue);
            if(endChoice == 'y'){
                inStack = createStack();
                inQueue = createQueue();
                outStack = createStack();
                outQueue = createQueue();
            }
        }
        gotoxy(15,5);
        delline(1);
        gotoxy(15,5);
    }
    printf("\n\t\tProgram Terminated");

    return 0;
}