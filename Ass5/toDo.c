/*
 * CS 261 Assignment 5
 * Name: 
 * Date: 
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
     while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
    // FIXME: Implement
    
    
    if(command == 'l'){
        
        char fileName[100];
        
        printf("Enter the file name to open: ");
        fgets(fileName, 100, stdin);
        
        if(fileName[strlen(fileName)-1] == '\n'){
            fileName[strlen(fileName)-1] = '\0';
            
        }
        FILE* aFile;
        aFile = fopen(fileName, "r");
        
        if(aFile != NULL){
            listLoad(list, aFile);
            
            fclose(aFile);
            printf("The list has been saved into the file successfully.\n");
        }
        
        else
            printf("File failed to load.\n");
        
    }
    
    if(command == 's'){
        char fileName[100];
        
        printf("Enter the file name to create: ");
        fgets(fileName, 100, stdin);
        
        if(fileName[strlen(fileName)-1] == '\n'){
            fileName[strlen(fileName)-1] = '\0';
            
        }
        
        FILE* aFile;
        aFile = fopen(fileName, "w+");
        
        if(aFile != NULL){
            listSave(list, aFile);
            printf("The list has been saved to '%s' successfully.\n\n", fileName);
            fclose(aFile);
        }
        
        else
            printf("File failed to save.\n");
        
    }
    
    if(command == 'a'){
        char inputIn[TASK_NAME_SIZE];
        int taskPriority;
        
        printf("Enter the new task name: ");
        fgets(inputIn, TASK_NAME_SIZE, stdin);
        
        if(inputIn[strlen(inputIn)-1] == '\n'){
            inputIn[strlen(inputIn)-1] = '\0';
            
        }
        
        printf("Enter the new task priority (0-999): ");
        scanf("%d", &taskPriority);
        
        Task* newTask = taskNew(taskPriority, inputIn);
        dyHeapAdd(list, newTask, taskCompare);
        
        while ((getchar()) != '\n');
        
        printf("The task '%s' has been added to your to-do list.\n", inputIn);
        
        
    }
    
    if(command == 'g'){
        if(dySize(list) > 0){
            Task* task = dyHeapGetMin(list);
            printf("\n");
            taskPrint(task);
            printf("\n");
        }
        
        else
            printf("Your to-do list is empty! \n");
        
        printf("\n");
    }
    
    if(command == 'r'){
        if(dySize(list) >= 1){
            Task* taskIn = dyHeapGetMin(list);
            dyHeapRemoveMin(list, taskCompare);
            
            printf("The first task '%s' has been removed from the list\n", taskIn->name);
            
            taskDelete(taskIn);
        }
        
        else
            printf("Your to-do list is empty!\n");
        
        printf("\n");
    }
    
    if(command == 'p'){
        listPrint(list);
        printf("\n");
    }
    
}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
 /* free dynamically allocated List pointers in array to avoid memory leaks */
         /* Fix it */
    
    for(int i = 0; i < dySize(list); i++){
        Task* taskIn = dyGet(list, i);
        taskDelete(taskIn);
    }

    dyDelete(list);
    return 0;
}
