#include <stdio.h>
#include "types.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


#define MAX 100
int amount_of_elems = 0;


task task_list[MAX];
task temp_task_list[MAX];

int welcome(void){
  while (true){
    int response = 0;
    printf("\n========================================\n");
    printf("    Welcome to Task Manager®!\n");
    printf("========================================\n");
    printf("1. View tasks\n");
    printf("2. Make a new task\n");
    printf("3. Delete a task\n");
    printf("4. Exit\n");
    printf("========================================\n");
    printf("Enter your choice (1-4): ");

        if (scanf("%d", &response) != 1) {
            while (getchar() != '\n');
            printf("\nInvalid answer, please try again.\n");
            continue;
        }

        while (getchar() != '\n');
        if (response >= 1 && response <=4 ){
            return response;
            }
    }


}


void task_init(task *tasks, task_info infos, int number){
    if (tasks == NULL){
        return;
    }

    tasks->tasknumber = number;
    strncpy(tasks->data.task_name, infos.task_name, MAXSIZE - 1);
    tasks->data.task_name[MAXSIZE - 1] = '\0';
    strncpy(tasks->data.task_description, infos.task_description, MAXSIZE - 1);
    tasks->data.task_description[MAXSIZE - 1] = '\0';
    

}


void append_task(task task, int i){
    task_list[i] = task;

}


void task_printer(task tasks, int i){
 
 printf("Task number: %d\nTask title: %s\nTask description: %s\n\n",task_list[i].tasknumber, task_list[i].data.task_name, task_list[i].data.task_description);

}


void create_and_append_task(task *task, task_info task_info, int number, int idx){
    if (task == NULL || idx < 0 || idx >= MAX) {
        return;
    }
    task_init(task, task_info, number);
    append_task(*task,idx);

}



void add_a_task(void){

    
 while (true){

    if (amount_of_elems >= MAX) {
    printf("Task list is full (Maximum %d tasks)\n", MAX);
    return;
}

    printf("\nLets create a task.\nTask name? (100 char limit): ");
    char name[MAXSIZE];
    //scanf(" %99[^\n]", name);
   
      if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("Error reading input.\n");
        return;
    }
    
    if (strchr(name, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    
    name[strcspn(name,"\n")] = '\0';
       
    if (strlen(name) == 0) {
        printf("Task name cannot be empty.\n");
        continue;
    }


    printf("Task description? (100 char limit): ");
    char description[MAXSIZE];
    //scanf(" %99[^\n]", description);
    fgets(description, sizeof(description), stdin);
    
    if (strchr(description, '\n') == NULL) {
            
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    
    description[strcspn(description,"\n")] = '\0';
    
    task temp_task;
    
    task_info temp_task_info;
    strncpy(temp_task_info.task_name, name, MAXSIZE - 1);
    temp_task_info.task_name[MAXSIZE - 1] = '\0';
    strncpy(temp_task_info.task_description, description, MAXSIZE -1);
    temp_task_info.task_description[MAXSIZE - 1] = '\0';



    temp_task.tasknumber = amount_of_elems+1;

    
    create_and_append_task(&temp_task, temp_task_info, temp_task.tasknumber, amount_of_elems);
    printf("\nTask created.\n\n");
    amount_of_elems++;
   


    printf("\033[4mTasks list:\033[0m\n");
    for (int i = 0; i < amount_of_elems; i++){
    task_printer(temp_task, i);
    }
    


   char cont; 
   while (true) {
   printf("Would you like to continue? (Y/N): ");
   scanf(" %c", &cont);

    while (getchar() != '\n');
   
   if (cont == 'n' || cont == 'N'){
    printf("\nExiting to menu...\n\n");
    return;
   }
   else if (cont == 'y' || cont == 'Y'){
    break;
   }

    else {
        printf("Invalid response, try again.\n");
    }
    }
   
   }



}




void view_tasks(void){
    printf("\n\033[4mTasks list:\033[0m\n");
    if (amount_of_elems == 0) {
        printf("No tasks found. Create one to get started.\n\n");
        return;
    }
    for (int i = 0; i < amount_of_elems; i++){
        printf("Task number: %d\nTask title: %s\nTask description: %s\n\n",task_list[i].tasknumber, task_list[i].data.task_name, task_list[i].data.task_description);

    }
    return;


}


void delete_a_task(){
    view_tasks();
    while(true){
    if (amount_of_elems == 0){
        printf("No tasks to delete.\n\n");
        return;
    }
    else {
        int index_to_remove = 0;
        printf("What index would you like to remove?: ");
        if (scanf("%d", &index_to_remove) != 1) {
            while (getchar() != '\n');
            printf("Invalid input, please enter a number.\n");
            continue;
        }
        while (getchar() != '\n');
        index_to_remove--;
        if (index_to_remove < 0 || index_to_remove >= amount_of_elems){
            printf("Error: index must be in range\n");
            continue;
        }
        else {
            int temp_index = 0;
            for (int i = 0; i < amount_of_elems; i++){
                if (i != index_to_remove){
                    temp_task_list[temp_index] = task_list[i];
                    temp_index++;
                }
            }
            
            amount_of_elems--;


            for (int i = 0; i < amount_of_elems; i++){
                    task_list[i] = temp_task_list[i];
                    task_list[i].tasknumber = i+1;


                }
            printf("New task list:\n");
            view_tasks();
            return;
            
            }


        }


    }
}
