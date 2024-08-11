#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

/*--------Define a structure to represent the Data in a linked list-----*/
typedef struct student
{
    char name[50];
    int id;
    int age;
    float GPA;

} student;

/*--------Define a structure to represent a node in a linked list-----*/
typedef struct node
{

    struct student data; // /*--------Data part of the node-----*/
    struct node *next; // /*--------Pointer to the next node-----*/

} node;

node *head = NULL; // /*--------Pointer to the head of the linked list-----*/

unsigned short user_input = 0; // /*--------Variable to store user input-----*/

void main_menu(void); // /*--------Function to display the main menu-----*/
void Add_Student(void); // /*--------Function to add a new student-----*/
void Display_All_Students(void); // /*--------Function to display all students-----*/
void Calculate_Average_GPA(void); // /*--------Function to calculate the average GPA-----*/
void Find_Student_with_Highest_GPA(void); // /*--------Function to find the student with the highest GPA-----*/
void Search_for_Student_by_ID(void); // /*--------Function to search for a student by ID-----*/
void Update_Student_Information(void); // /*--------Function to update student information-----*/
void Delete_Student_by_ID(void); // /*--------Function to delete a student by ID-----*/
int IS_ID_Exits(int ID); /* return the index of node of required ID */ /*--------Function to check if a given ID exists in the list-----*/


/*-------------------------------------------Main function--------------------------------------------------*/
int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0); // /*--------Disable buffering for stdout-----*/
    setvbuf(stderr, NULL, _IONBF, 0); // /*--------Disable buffering for stderr-----*/

    while (1) // /*--------Infinite loop to continuously display the menu until the program is terminated-----*/
    {
        main_menu(); // /*--------Display the main menu-----*/

        switch (user_input) // /*--------Handle user input-----*/
        {
        case 1:
            Add_Student(); // /*--------Add a new student-----*/
            break;

        case 2:
            Display_All_Students(); // /*--------Display all students-----*/
            break;

        case 3:
            Search_for_Student_by_ID(); // /*--------Search for a student by ID-----*/
            break;

        case 4:
            Update_Student_Information(); // /*--------Update student information-----*/
            break;

        case 5:
            Delete_Student_by_ID(); // /*--------Delete a student by ID-----*/
            break;

        case 6:
            Calculate_Average_GPA(); // /*--------Calculate the average GPA-----*/
            break;

        case 7:
            Find_Student_with_Highest_GPA(); // /*--------Find the student with the highest GPA-----*/
            break;

        case 8:
            printf("Terminated .......\n"); // /*--------Terminate the program-----*/
            return 0;

        default:
            printf("< invalid input >\n"); // /*--------Handle invalid input-----*/
            printf("*******************************************************************\n");
        }
    }

    return 0; // /*--------Return from main function-----*/
}


/*------------------------------------------------Function to display the main menu--------------------------------------------*/
void main_menu(void)
{
    printf("1) Add a Student \n");
    printf("2) Display All Students \n");
    printf("3) Search for a Student by ID \n");
    printf("4) Update Student Information \n");
    printf("5) Delete a Student \n");
    printf("6) Calculate Average GPA \n");
    printf("7) Find Student with Highest GPA \n");
    printf("8) Terminate the program \n");

    printf("-> Enter Your choice : ");

    scanf(" %hd", &user_input); // /*--------Get user input-----*/

    return;
}



/*------------------------------Function to add a new student to the linked list---------------------------------------*/
void Add_Student(void)
{
    printf("*******************************************************************\n");

    printf("Don't write spaces in name, replace it by underscore :) \n");

    node *link = (node *)malloc(sizeof(node)); // /*--------Allocate memory for the new student-----*/
    assert(link != NULL); // /*--------Ensure memory allocation was successful-----*/

    printf("-> Enter the student ID : ");
    scanf(" %d", &(link->data.id)); // /*--------Get the student's ID-----*/

    printf("-> Enter the student Name : ");
    scanf("%s", (link->data.name)); // /*--------Get the student's name-----*/

    printf("-> Enter the student Age : ");
    scanf(" %d", &(link->data.age)); // /*--------Get the student's age-----*/

    printf("-> Enter the student GPA : ");
    scanf(" %f", &(link->data.GPA)); // /*--------Get the student's GPA-----*/

    if (-1 == IS_ID_Exits(link->data.id)) // which means that the ID isn't exist
    {
        if (head == NULL)
        {
            head = link; // /*--------Insert the first student in the list-----*/
            head->next = NULL;
        }
        else
        {
            link->next = head; // /*--------Insert the new student at the beginning of the list-----*/
            head = link;
        }
    }

    else
    {
        printf("The ID is already Exists :( \n"); // /*--------Handle duplicate ID-----*/
    }

    printf("*******************************************************************\n");
    return;
}



/*------------------------------------Function to display all students in the linked list-----------------------------------*/
void Display_All_Students(void)
{
    printf("*******************************************************************\n");

    node *current;
    if (head == NULL) // /*--------Check if the list is empty-----*/
    {
        printf("Empty list \n");
    }

    else
    {
        current = head;
        while (current != NULL) // /*--------Traverse the list and display each student's information-----*/
        {
            printf("[ ID : %d , Name : %s , ", current->data.id, current->data.name);
            printf("Age : %d , GPA : %f ] \n", current->data.age, current->data.GPA);

            current = current->next;
        }
    }

    printf("*******************************************************************\n");
    return;
}



/*-------------------------------Function to search for a student by ID-------------------------------------------*/
void Search_for_Student_by_ID(void)
{
    printf("*******************************************************************\n");

    int ID;
    printf("-> Enter the ID :");
    scanf(" %d", &ID); // /*--------Get the ID to search for-----*/

    int index = IS_ID_Exits(ID); // /*--------Check if the ID exists-----*/
    if (-1 == index)
    {
        printf("the student isn't exists \n");
    }
    else
    {
        node *current = head;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }

        printf("[ ID : %d , Name : %s , ", current->data.id, current->data.name); // /*--------Display the student's information-----*/
        printf("Age : %d , GPA : %f ] \n", current->data.age, current->data.GPA);
    }

    printf("*******************************************************************\n");
    return;
}



/*-------------------------------------------Function to update a student's information---------------------------------------*/
void Update_Student_Information(void)
{
    printf("*******************************************************************\n");

    printf("Don't write spaces in name, replace it by underscore :) \n");

    int ID;
    printf("-> Enter the ID :");
    scanf(" %d", &ID); // /*--------Get the ID to update-----*/

    int index = IS_ID_Exits(ID); // /*--------Check if the ID exists-----*/
    if (-1 == index)
    {
        printf("this ID isn't exist");
    }

    else
    {
        node *current = head;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        printf("-> Enter the New ID : ");
        scanf(" %d", &(current->data.id)); // /*--------Update the student's ID-----*/

        printf("-> Enter the New Name : ");
        scanf("%s", (current->data.name)); // /*--------Update the student's name-----*/

        printf("-> Enter the New Age : ");
        scanf(" %d", &(current->data.age)); // /*--------Update the student's age-----*/

        printf("-> Enter the New GPA : ");
        scanf(" %f", &(current->data.GPA)); // /*--------Update the student's GPA-----*/
    }

    printf("The new information is updated successfully \n");
    printf("******************************************************************* \n");
    return;
}



/*--------------------------------Function to delete a student by ID-------------------------------------------*/
void Delete_Student_by_ID(void)
{
    int ID;
    printf("-> Enter the ID :");
    scanf(" %d", &ID); // /*--------Get the ID to delete-----*/

    int index = IS_ID_Exits(ID); // /*--------Check if the ID exists-----*/

    if (-1 == index)
    {
        printf("This ID isn't exist \n");
    }

    else if (0 == index)
    {
        node *current = head;
        head = head->next; // /*--------Delete the first node-----*/
        free(current);
    }

    else
    {
        node *current = head;

        for (int i = 0; i < (index - 1); ++i) // Exit at the node just before the one that needs to be deleted.
        {
            current = current->next;
        }
        node *temp = current->next; // /*--------Temporary pointer to the node to be deleted-----*/
        current->next = current->next->next; // /*--------Unlink the node to be deleted-----*/

        free(temp); // /*--------Free the memory of the deleted node-----*/
    }
    printf("The student is deleted successfully \n");
    printf("******************************************************************* \n");
    return;
}



/*-----------------------------------------Function to calculate the average GPA---------------------------------------*/
void Calculate_Average_GPA(void)
{
    printf("*******************************************************************\n");

    if (head == NULL) // /*--------Check if the list is empty-----*/
    {
        printf("Empty List \n");
        return;
    }

    node *current = head;
    float sum = 0, size = 0;

    while (current != NULL) // /*--------Traverse the list to calculate the sum of GPAs-----*/
    {
        sum += current->data.GPA;
        ++size;
        current = current->next;
    }

    printf("The average GPA : %f \n", (sum / size)); // /*--------Calculate and display the average GPA-----*/
    printf("*******************************************************************\n");
    return;
}


/*-----------------------------------Function to find the student with the highest GPA-------------------------------------*/
void Find_Student_with_Highest_GPA(void)
{
    printf("*******************************************************************\n");

    if (head == NULL)
        {
            printf("Empty list \n");
            return ;
        }

        node *current = head;
        node *max_node = head;  // Pointer to the node with the highest GPA

    while (current != NULL) // /*--------Traverse the list to find the node with the highest GPA-----*/
    {
        if ( (current->data.GPA) > (max_node->data.GPA) )
        {
            max_node = current;
        }
        current = current->next;
    }

    printf("[ ID : %d , Name : %s , ", max_node->data.id, max_node->data.name);
    printf("Age : %d , GPA : %f ] \n", max_node->data.age, max_node->data.GPA);

    printf("******************************************************************* \n");
    return;
}


/*----------------------------------Function to check if a given ID exists in the linked list-----------------------------------*/
int IS_ID_Exits(int ID)
{
    if (head == NULL) // /*--------Check if the list is empty-----*/
    {
        return -1; /* indicates that the ID is not Exists*/
    }

    node *current = head;
    int index = 0;

    while (current != NULL) // /*--------Traverse the list to find the node with the given ID-----*/
    {
        if (current->data.id == ID)
        {
            return index; // /*--------Return the index if ID exists-----*/
        }
        current = current->next;
        ++index;
    }

    return -1; /* indicates that the ID is not Exists*/
}
