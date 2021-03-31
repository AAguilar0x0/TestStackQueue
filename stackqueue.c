#include<stdio.h>
#include<stdlib.h>
#include"stackqueue.h"

Nodeptr createNode(int item){
    Nodeptr node;
    node = (Nodeptr) malloc(sizeof(Node));
    node->data = item;
    node->next = NULL;
    return node;
}

// End of Node

Stackptr createStack(){
    Stackptr stack = (Stackptr) malloc(sizeof(Stack));
    stack->count = 0;
    stack->top = NULL;
    return stack;
}

int isEmptyStack(Stackptr stack){
    return stack->count == 0;
}

void push(Stackptr stack, int item){
    Nodeptr temp = createNode(item);
    temp->next = stack->top;
    stack->top = temp;
    stack->count++;
}

int pop(Stackptr stack){
    Nodeptr temp = stack->top;
    int item = stack->top->data;
    stack->top = temp->next;
    temp->next = NULL;
    free(temp);
    stack->count--;
    return item;
}

void dispStack(Stackptr stack){
    Nodeptr walker = stack->top;
    while(walker != NULL){
        printf("%d ",walker->data);
        walker = walker->next;
    }
}

void freeStack(Stackptr stack){
    Nodeptr temp;
    while(stack->top != NULL){
        temp = stack->top->next;
        free(stack->top);
        stack->top = temp;
    }
    free(stack);
}

// End of Stack

Queueptr createQueue(){
    Queueptr queue = (Queueptr) malloc(sizeof(Queue));
    queue->count = 0;
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmptyQueue(Queueptr queue){
    return queue->count == 0;
}

void enqueue(Queueptr queue, int item){
    Nodeptr temp = createNode(item);
    int isEmpty = isEmptyQueue(queue);
    queue->front = (Nodeptr)((isEmpty * (uintptr_t)temp) + 
        (!isEmpty * (uintptr_t)queue->front));
    if(queue->rear)
        queue->rear->next = (Nodeptr)((!isEmpty * (uintptr_t)temp) + 
            (isEmpty * (uintptr_t)queue->rear->next));
    queue->rear = temp;
    queue->count++;
}

int dequeue(Queueptr queue){
    Nodeptr temp = queue->front;
    int item = queue->front->data;
    queue->rear = (Nodeptr)((queue->count != 1) * 
        (uintptr_t)queue->rear);
    queue->front = queue->front->next;
    free(temp);
    queue->count--;
    return item;
}

void dispQueue(Queueptr queue){
    Nodeptr walker = queue->front;
    while(walker != NULL){
        printf("%d ",walker->data);
        walker = walker->next;
    }
}

void freeQueue(Queueptr queue){
    Nodeptr temp;
    while(queue->front != NULL){
        temp = queue->front->next;
        free(queue->front);
        queue->front = temp;
    }
    free(queue);
}