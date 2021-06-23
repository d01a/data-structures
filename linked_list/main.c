#include <stdio.h>
#include <stdlib.h>

typedef struct node{
char data;
struct node *next;
}Node;

void insert_node(int);
void insert_beginning(int);
void delete_node(int);
void delete_beginning();
void delete_end();
void print_list();
void count_list();
void sortlist();
void save_in_File(int );


Node *head=NULL;

int main()
{
  int value_to_delete;
    print_list();
//inserting random values to the linked list to test
     int i=0;
    while( i<5){
        int input;
        printf("enter the value: ");
        scanf("%d",&input);
        insert_node(input);
        i++;
    }

    count_list();
    print_list();
    //deleting node from the list
    printf("enter the value to be deleted from the list: ");
    scanf("%d",&value_to_delete);
    delete_node(value_to_delete);
    count_list();
    print_list();
    //insert in the beginning
    puts("******************************************");
    int begin_var;
    printf("enter the value to add in the beginning: ");
    scanf("%d",&begin_var);
    insert_beginning(begin_var);
    count_list();
    print_list();
    //delete from the beginning
    puts("******************************************");
    puts("deleting the first node");
    delete_beginning();
    count_list();
    print_list();
    puts("******************************************");
    puts("deleting the last node");
    delete_end();
    count_list();
    print_list();
    return 0;
}


void insert_node(int value){
Node *newNode , *last;
newNode=(Node *)malloc(sizeof(Node));
newNode->data = value;
if (head == NULL){
    head = newNode;
    newNode->next = NULL;
}
else {
        last = head;
    while(last->next !=NULL){
        last = last->next;
    }
    last->next = newNode;
    newNode->next = NULL;
}
}


void print_list(){
Node *currentNode = NULL;
if (head == NULL){
    printf("the linked list is empty\n");
}
else{
currentNode = head;
while(currentNode != NULL){
   printf("%d \n",currentNode->data);
    currentNode=currentNode->next;
}
}
}


void delete_node(int value){
Node *current, *previous;
current = head;
previous = head;

int no_value = 1;
while(current != NULL){
    if (current->data == value){
     no_value = 0;
     break;
    }
    current = current->next;
}
if (no_value == 1){
    printf("the list is not containing the value: %d\n",value);
    return;
}
current = head;
previous = head;

if (current->data == value){
    head = current->next;
    free(current);
    return;
}
while(current->data != value){
    previous = current;
    current = current->next;
}
previous->next = current->next;
free(current);
printf("the value %d deleted from the list\n",value);
}

void insert_beginning(int value){
Node *new_node = (Node *)malloc(sizeof(Node *));
new_node->data = value;
new_node->next = head;
head=new_node;
}

void delete_beginning(){
    if (head == NULL){
        printf("the linked list is empty.\n");
    }
    else {
        Node *first_node = head;
        head = first_node->next;
        free(first_node);
    }

}


void count_list(){
int count=0;
if (head == NULL){
    printf("the linked list is empty\n");
}
Node *ptr = NULL;
ptr=head;
while(ptr != NULL){
    count++;
    ptr=ptr->next;
}
printf("the linked list have %d element\n",count);
}


void delete_end(){
if (head == NULL){
    puts("the linked list is empty ");
}

else if (head->next == NULL){
    free(head);
    head = NULL;
}

else {
    Node *ptr = head;
    while (ptr->next->next != NULL){
       ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
}
}

void sortlist(){
    char *t;
     Node *last = head;
     Node *current = head->next;
    while(current != NULL){
        if(strcmp(last->name,current->name)>0){  // NOTICE: Dereference of temp1
            strcpy(t,current->name);
            strcpy(current->name,last->name);
            strcpy(last->name,t);
        }
        last = last->next;
    }
}


void save_in_File(int level){
switch level:
case 1: {
    FILE *fptr1;
        fptr1=(fopen("D:\c\data_structure\linked_list\student1.txt","a2"));
        if(fptr1==NULL) {
                printf("\nError!\n");
        }
        for (i=0;i<n;++i) {

                fprintf(fptr1,"\nName: %s \nMarks=%d \n",name,marks);
        fclose(fptr1);
break;
break;
}

case 2: {
    FILE *fptr2;
        fptr2=(fopen("D:\c\data_structure\linked_list\student1.txt","a+"));
        if(fptr2==NULL) {
                printf("\nError!\n");
        }
        for (i=0;i<n;++i) {

                fprintf(fptr2,"\nName: %s \nMarks=%d \n",name,marks);
        fclose(fptr2);
break;
}

case 3: {
        FILE *fptr3;
        fptr3=(fopen("D:\c\data_structure\linked_list\student1.txt","a+"));
        if(fptr3==NULL) {
                printf("\nError!\n");
        }
        for (i=0;i<n;++i) {

                fprintf(fptr3,"\nName: %s \nMarks=%d \n",name,marks);
        fclose(fptr3);
break;
}

case 4: {
    FILE *fptr4;
        fptr4=(fopen("D:\c\data_structure\linked_list\student1.txt","a+"));
        if(fptr4==NULL) {
                printf("\nError!\n");
        }
        for (i=0;i<n;++i) {

                fprintf(fptr4,"\nName: %s \nMarks=%d \n",name,marks);
        fclose(fptr4);
break;
}
default:
    printf("\t\tplease, enter a valid choice\n");
}
