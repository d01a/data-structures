#include <stdio.h>
#include <stdlib.h>

typedef struct node {
int data;
struct node *next;
}Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int );
void dequeue();
int peek();
void display();

int main()
{
    enqueue(1);
    enqueue(11);
    enqueue(111);
    enqueue(1111);
    enqueue(11111);
    enqueue(111111);
    enqueue(1111111);
    display();
    dequeue();
    display();
    printf("%d\n", peek());
    return 0;
}


void enqueue (int value){
Node *new_node;
new_node = (Node *)malloc(sizeof(Node));
new_node->data = value;
new_node->next = NULL;

//first node
if (front == NULL){
    front = rear = new_node;
}
//not first node
else{
    rear->next = new_node;
    rear = new_node ;
}
}

void dequeue(){
   // empty queue
    if (rear == NULL){
        puts("the queue is empty");
    }
    // one element queue
    else if ( front == rear){
        Node *ptr = front ;
        front = rear = NULL;
        free(ptr);
    }
    // many elements
    else {
        Node *ptr = front;
        front = front->next;
        free(ptr);
    }
}

int peek(){
if (front == NULL){
    puts("queue is empty");
    return -1;
}
else {
    return front->data;
}
}

void display(){
if (front == NULL){
    puts("queue is empty");
}
else {
    Node *ptr = front;
    while(ptr != NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    puts("");
}
}
