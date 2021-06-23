#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentMian
{
    char name[30];
    int age;
    int id;
    float grades[6] ;
    char level[10];
    char email[30];
} student;

typedef struct node
{
    student data;
    struct node *next;
} Node;

void insert_node(student);
void insert_beginning(char*);
void delete_beginning();
void delete_end();
void print_list();
void count_list();
void sort();
void save_in_File();
void save_in_File2();
void insert_node_from_file(student);
void sort_file_list();
void LoadFile();
void delete_node_in_file();
void update_node_in_file();

FILE * v1ptr;
FILE * v2ptr;
FILE * v3ptr;
FILE * v4ptr;


Node *head=NULL;
Node *head2=NULL;

int main()
{
    char value_to_delete[50];
    print_list();
//inserting random values to the linked list to test

    int i=0;
    student input;
    while( i<4)
    {
        printf("enter the name: ");
        scanf("\n%[^\n]s",input.name);
        printf("enter the id: ");
        scanf("\n%d",&input.id);
        printf("enter the level: ");
        scanf("\n%[^\n]s",input.level);
        printf("enter the email: ");
        scanf("\n%[^\n]s",input.email);
        printf("enter the age: ");
        scanf("\n%d",&input.age);
        printf("enter the grades: ");
        for(int x=0; x<=5; x++)
        {
            scanf("\n%f",&input.grades[x]);
        }
        insert_node(input);
        i++;
    }
    print_list();
    //deleting node from the list
      printf("enter the value to be deleted from the list: ");
      scanf("\n%[^\n]s",value_to_delete);
      delete_node(value_to_delete);
      count_list();
      print_list();
      //insert in the beginning
      puts("******************************************");
      char begin_var[50];
      printf("enter the value to add in the beginning: ");
      scanf("\n%[^\n]s",begin_var);
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
      
    puts("******************************************");
    puts("sorting the list");
    sort();
    print_list();
    save_in_File();
    LoadFile();
    delete_node_in_file();
    update_node_in_file();
    save_in_File2();
    return 0;
}


void insert_node(student studentInsert)
{
    Node *newNode, *last;
    newNode=(Node *)malloc(sizeof(Node));
    newNode->data=studentInsert;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {
        last = head;
        while(last->next !=NULL)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = NULL;
    }
}


void print_list()
{
    Node *currentNode = NULL;
    if (head == NULL)
    {
        printf("the linked list is empty\n");
    }
    else
    {
        currentNode = head;
        while(currentNode != NULL)
        {
            printf("%-15s ",currentNode->data.name);
            printf("%-15s ",currentNode->data.level);
            printf("%-15s ",currentNode->data.email);
            printf("%-10d ",currentNode->data.id);
            printf("%-5d ",currentNode->data.age);
            for(int x=0; x<=5; x++)
            {
                printf("\t%-3f",currentNode->data.grades[x]);
            }
            puts(" ");

            currentNode=currentNode->next;
        }
    }
}



void insert_beginning(char *value){
Node *new_node = (Node *)malloc(sizeof(Node *));
strcpy(new_node->data , value);
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

void count_list()
{
    int count=0;
    if (head == NULL)
    {
        printf("the linked list is empty\n");
    }
    Node *ptr = NULL;
    ptr=head;
    while(ptr != NULL)
    {
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

void sort(void)
{
    int i;
    student temp;
    Node *ptr2=NULL;
    Node *ptr=NULL;
    for(ptr=head; ptr!=NULL; ptr=ptr->next)
    {
        for(ptr2=ptr->next; ptr2!=NULL; ptr2=ptr2->next)
        {
            i=strcmp(ptr->data.name,ptr2->data.name);
            if(i==1)
            {
                //***************************swapping the data************
                strcpy(temp.name,ptr->data.name);
                strcpy(temp.email,ptr->data.email);
                strcpy(temp.level,ptr->data.level);
                temp.age=ptr->data.age;
                for (int x=0; x<=5; x++)
                {
                    temp.grades[x]=ptr->data.grades[x];
                }
                temp.id=ptr->data.id;
                //-------------------------------------
                strcpy(ptr->data.name,ptr2->data.name);
                strcpy(ptr->data.email,ptr2->data.email);
                strcpy(ptr->data.level,ptr2->data.level);
                ptr->data.age=ptr2->data.age;
                for (int x=0; x<=5; x++)
                {
                    ptr->data.grades[x]=ptr2->data.grades[x];
                }
                ptr->data.id=ptr2->data.id;
                //-------------------------------------
                strcpy(ptr2->data.name,temp.name);
                strcpy(ptr2->data.email,temp.email);
                strcpy(ptr2->data.level,temp.level);
                ptr2->data.age=temp.age;
                for (int x=0; x<=5; x++)
                {
                    ptr2->data.grades[x]=temp.grades[x];
                }
                ptr2->data.id=temp.id;


            }
        }
    }
    ptr2=NULL;
    ptr=NULL;
}

void save_in_File(void)
{
    Node *testPtr = head;
    v1ptr=(fopen("student1.txt","a+"));
    v2ptr=(fopen("student2.txt","a+"));
    v2ptr=(fopen("student3.txt","a+"));
    v2ptr=(fopen("student4.txt","a+"));

    for (; testPtr != NULL; testPtr = testPtr->next)
    {
        if (strcmp (testPtr->data.level,"level_1") == 0)
        {
            if(v1ptr==NULL)
            {
                printf("\nError!\n");
            }
            fprintf(v1ptr, "%-15d%-10s%-20s%-5d%-29s%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", testPtr->data.id,testPtr->data.level,testPtr->data.name,testPtr->data.age, testPtr->data.email,testPtr->data.grades[0],testPtr->data.grades[1],testPtr->data.grades[2],testPtr->data.grades[3],testPtr->data.grades[4],testPtr->data.grades[5] );

            printf("\nfile1\n");

        }
        else if( strcmp(testPtr->data.level,"level_2") == 0)
        {
            if(v2ptr==NULL)
            {
                printf("\nError!\n");
            }
            fprintf(v2ptr, "%-15d%-10s%-20s%-5d%-29s%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", testPtr->data.id,testPtr->data.level,testPtr->data.name,testPtr->data.age, testPtr->data.email,testPtr->data.grades[0],testPtr->data.grades[1],testPtr->data.grades[2],testPtr->data.grades[3],testPtr->data.grades[4],testPtr->data.grades[5] );

            printf("\nfile2\n");

        }

        else if ( strcmp(testPtr->data.level,"level_3") == 0)
        {
            if(v3ptr==NULL)
            {
                printf("\nError!\n");
            }

            fprintf(v3ptr, "%-15d%-10s%-20s%-5d%-29s%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", testPtr->data.id,testPtr->data.level,testPtr->data.name,testPtr->data.age, testPtr->data.email,testPtr->data.grades[0],testPtr->data.grades[1],testPtr->data.grades[2],testPtr->data.grades[3],testPtr->data.grades[4],testPtr->data.grades[5] );
            printf("\nfile3\n");


        }

        else if ( strcmp(testPtr->data.level,"level_4") == 0)
        {
            if(v4ptr==NULL)
            {
                printf("\nError!\n");
            }
            fprintf(v4ptr, "%-15d%-10s%-20s%-5d%-29s%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", testPtr->data.id,testPtr->data.level,testPtr->data.name,testPtr->data.age, testPtr->data.email,testPtr->data.grades[0],testPtr->data.grades[1],testPtr->data.grades[2],testPtr->data.grades[3],testPtr->data.grades[4],testPtr->data.grades[5] );

            printf("\nfile4\n");

        }

    }
    fclose(v1ptr);
    fclose(v2ptr);
    fclose(v3ptr);
    fclose(v4ptr);
    return ;
}

//----------------------------------كسم الارهاب-----------------------------------------

void insert_node_from_file(student studentInsert)
{
    Node *newNode, *last;
    newNode=(Node *)malloc(sizeof(Node));
    newNode->data=studentInsert;
    if (head2 == NULL)
    {
        head2 = newNode;
        newNode->next = NULL;
    }
    else
    {
        last = head2;
        while(last->next !=NULL)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = NULL;
    }
}




/*function LoadFile*/
void LoadFile()
{
    student stu;
    FILE *fPtr = fopen("student1.txt", "r");
while (!feof(fPtr))
    {
                    fscanf(fPtr, "%d", &(stu.id));
                    fscanf(fPtr, "%s", stu.level);
                    fgets(stu.name , 20 , fPtr );
                    fscanf(fPtr, "%d", &(stu.age));
                    fgets(stu.email , 29 , fPtr );
                    fscanf(fPtr, "%f", &(stu.grades[0]));
                    fscanf(fPtr, "%f", &(stu.grades[1]));
                    fscanf(fPtr, "%f", &(stu.grades[2]));
                    fscanf(fPtr, "%f", &(stu.grades[3]));
                    fscanf(fPtr, "%f", &(stu.grades[4]));
                    fscanf(fPtr, "%f", &(stu.grades[5]));
    insert_node_from_file(stu);
    }
fclose(fPtr);
}


void save_in_File2(void)
{
    Node *testPtr = head2;
    v1ptr=(fopen("student1.txt","w"));
    v2ptr=(fopen("student2.txt","w"));
    v3ptr=(fopen("student3.txt","w"));
    v4ptr=(fopen("student4.txt","w"));


    for (; testPtr != NULL; testPtr = testPtr->next)
    {
        if (strcmp (testPtr->data.level,"level_1") == 0)
        {
            if(v1ptr==NULL)
            {
                printf("\nError!\n");
            }
            fprintf(v1ptr, "%-15d%-10s%-20s%-5d%-29s%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", testPtr->data.id,testPtr->data.level,testPtr->data.name,testPtr->data.age, testPtr->data.email,testPtr->data.grades[0],testPtr->data.grades[1],testPtr->data.grades[2],testPtr->data.grades[3],testPtr->data.grades[4],testPtr->data.grades[5] );

        }
        else if( strcmp(testPtr->data.level,"level_2") == 0)
        {
            if(v2ptr==NULL)
            {
                printf("\nError!\n");
            }
            fprintf(v2ptr, "%-15d%-10s%-20s%-5d%-29s%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", testPtr->data.id,testPtr->data.level,testPtr->data.name,testPtr->data.age, testPtr->data.email,testPtr->data.grades[0],testPtr->data.grades[1],testPtr->data.grades[2],testPtr->data.grades[3],testPtr->data.grades[4],testPtr->data.grades[5] );

        }

        else if ( strcmp(testPtr->data.level,"level_3") == 0)
        {
            v3ptr=(fopen("student3.txt","w"));
            if(v3ptr==NULL)
            {
                printf("\nError!\n");
            }

            fprintf(v3ptr, "%-15d%-10s%-20s%-5d%-29s%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", testPtr->data.id,testPtr->data.level,testPtr->data.name,testPtr->data.age, testPtr->data.email,testPtr->data.grades[0],testPtr->data.grades[1],testPtr->data.grades[2],testPtr->data.grades[3],testPtr->data.grades[4],testPtr->data.grades[5] );

        }

        else if ( strcmp(testPtr->data.level,"level_4") == 0)
        {
            v4ptr=(fopen("student4.txt","w"));
            if(v4ptr==NULL)
            {
                printf("\nError!\n");
            }
            fprintf(v4ptr, "%-15d%-10s%-20s%-5d%-29s%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", testPtr->data.id,testPtr->data.level,testPtr->data.name,testPtr->data.age, testPtr->data.email,testPtr->data.grades[0],testPtr->data.grades[1],testPtr->data.grades[2],testPtr->data.grades[3],testPtr->data.grades[4],testPtr->data.grades[5] );

        }

    }
    fclose(v1ptr);
    fclose(v2ptr);
    fclose(v3ptr);
    fclose(v4ptr);
    return ;
}

void sort_file_list(void)
{
    int i;
    student temp;
    Node *ptr2=NULL;
    Node *ptr=NULL;
    for(ptr=head2; ptr!=NULL; ptr=ptr->next)
    {
        for(ptr2=ptr->next; ptr2!=NULL; ptr2=ptr2->next)
        {
            i=strcmp(ptr->data.name,ptr2->data.name);
            if(i==1)
            {
                //***************************swapping the data************
                strcpy(temp.name,ptr->data.name);
                strcpy(temp.email,ptr->data.email);
                strcpy(temp.level,ptr->data.level);
                temp.age=ptr->data.age;
                for (int x=0; x<=5; x++)
                {
                    temp.grades[x]=ptr->data.grades[x];
                }
                temp.id=ptr->data.id;
                //-------------------------------------
                strcpy(ptr->data.name,ptr2->data.name);
                strcpy(ptr->data.email,ptr2->data.email);
                strcpy(ptr->data.level,ptr2->data.level);
                ptr->data.age=ptr2->data.age;
                for (int x=0; x<=5; x++)
                {
                    ptr->data.grades[x]=ptr2->data.grades[x];
                }
                ptr->data.id=ptr2->data.id;
                //-------------------------------------
                strcpy(ptr2->data.name,temp.name);
                strcpy(ptr2->data.email,temp.email);
                strcpy(ptr2->data.level,temp.level);
                ptr2->data.age=temp.age;
                for (int x=0; x<=5; x++)
                {
                    ptr2->data.grades[x]=temp.grades[x];
                }
                ptr2->data.id=temp.id;

            }
        }
    }
    ptr2=NULL;
    ptr=NULL;
}

void delete_node_in_file(){

Node *current, *previous;
current = head2;
previous = head2;
int ID;

printf("\nplease enter the ID of the student to remove: ");
scanf("%d" , &ID);
int no_value = 1;
while(current != NULL){
    if (current->data.id == ID){
     no_value = 0;
     break;
    }
    current = current->next;
}
if (no_value == 1){
    printf("the Student not found! \n");
    return;
}
current = head2;
previous = head2;

if (current->data.id == ID){
    head = current->next;
    free(current);
    return;
}
while( current->data.id != ID){
    previous = current;
    current = current->next;
}
previous->next = current->next;
free(current);
printf("the student of ID: %d deleted successfully \n",ID);

sort_file_list();
}


void update_node_in_file(){

Node *current, *previous;
current = head2;
previous = head2;
student s;
printf("\nenter the ID of the student to update the information: ");
scanf("%d", &s.id);


int no_value = 1;
while(current != NULL){
    if (current->data.id == s.id){
     no_value = 0;
     break;
    }
    current = current->next;
}
if (no_value == 1){
    printf("the Student not found! \n");
    return;
}
current = head2;
previous = head2;

printf("\nenter the new name: ");
scanf("\n%[^\n]s", s.name);
printf("\nenter the new level: ");
scanf("\n%s", s.level);
printf("\nenter the new email: ");
scanf("\n%[^\n]s", s.email);
printf("\nenter the new age: ");
scanf("%d", &s.age);
for(int i=0;i<6;i++){
    printf("\nenter the new grade of subject[%d]: ",i);
    scanf("%f", &s.grades[i]);
}

if (current->data.id == s.id){
current->data = s;
    return;
}
while( current->data.id != s.id){
    previous = current;
    current = current->next;
}

printf("the student of ID: %d updated successfully \n",s.id);

sort_file_list();
}


