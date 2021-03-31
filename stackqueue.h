typedef struct Node_s* Nodeptr;

typedef struct Node_s{
    int data;
    Nodeptr next;
}Node;

Nodeptr createNode(int);

// End of Node

typedef struct Stack_s* Stackptr;

typedef struct Stack_s{
    int count;
    Nodeptr top;
}Stack;

Stackptr createStack();
int isEmptyStack(Stackptr);
void push(Stackptr,int);
int pop(Stackptr);
void dispStack(Stackptr);
void freeStack(Stackptr);

// End of Stack

typedef struct Queue_s* Queueptr;

typedef struct Queue_s{
    int count;
    Nodeptr front;
    Nodeptr rear;
}Queue;

Queueptr createQueue();
int isEmptyQueue(Queueptr);
void enqueue(Queueptr,int);
int dequeue(Queueptr);
void dispQueue(Queueptr);
void freeQueue(Queueptr);

// End of Queue