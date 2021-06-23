#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int data;
struct node *next;
}Node;

void push(int);
int pop();
void display();
void count_stack();
int peek();


Node *top=NULL;

int main()
{
    //viewing the stack before pushing any data
    display();
   //inserting random values to the stack to test
     int i=0;
    while( i<5){
        int input;
        printf("enter the value: ");
        scanf("%d",&input);
        push(input);
        i++;
    }

    puts("******************************************");
    printf("the value: %d popped\n",pop());
    count_stack();
    display();
    //popping test
    puts("******************************************");
    puts("deleting the first element");
    printf("the value: %d popped\n",pop());
    count_stack();
    display();
    printf("the top is: %d",peek());

    return 0;
}

void display(){
Node *currentNode = NULL;
if (top == NULL){
    printf("stack is underflow\n");
}
else{
currentNode = top;
while(currentNode != NULL){
   printf("%d \n",currentNode->data);
    currentNode=currentNode->next;
}
}
}

void push(int value){
Node *new_node = (Node *)malloc(sizeof(Node *));
new_node->data = value;
new_node->next = top;
top=new_node;
}

int pop(){
    if (top == NULL){
        printf("stack is underflow.\n");
        return -1;
    }
    else {
        int value;
        Node *first_node = top;
        top = first_node->next;
        value = first_node->data;
        free(first_node);
        return value ;
    }

}


void count_stack(){
int count=0;
if (top == NULL){
    puts("stack is underflow");
}
Node *ptr = NULL;
ptr=top;
while(ptr != NULL){
    count++;
    ptr=ptr->next;
}
printf("the stack have %d element\n",count);
}

int peek(){
if (top == NULL){
    puts("stack is underflow");
    return -1;
}
else {
    return top->data;
}
}
