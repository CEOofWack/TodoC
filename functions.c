#include <stdio.h>
#include "types.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <assert.h>
=======
>>>>>>> origin/main


#define MAX 100
int amount_of_elems = 0;


<<<<<<< HEAD

task *allocate_memory(){
    task *task_address = malloc(MAX * sizeof(task));
    if (task_address == NULL){
        puts("Malloc Error, exiting");
        exit(EXIT_FAILURE);
    }
    return task_address;

}


void task_append(task* task_to_append_to, char *name_to_add, char* desc_to_add, int task_num){
    task_to_append_to[task_num].tasknumber = task_num + 1;
    strncpy(task_to_append_to[task_num].data.task_name,name_to_add, MAXSIZE - 1);
    task_to_append_to[task_num].data.task_name[MAXSIZE - 1] = '\0';
    strncpy(task_to_append_to[task_num].data.task_description, desc_to_add, MAXSIZE - 1);
    task_to_append_to[task_num].data.task_description[MAXSIZE - 1] = '\0';

}




void display_greeting(){
    printf("\n");
    printf("\033[1;36m╔══════════════════════════════════════════════════╗\033[0m\n");
    printf("\033[1;36m║\033[0m        \033[1;37m✦  TASK MANAGER 2.0  ✦\033[0m                    \033[1;36m║\033[0m\n");
    printf("\033[1;36m╠══════════════════════════════════════════════════╣\033[0m\n");
    printf("\033[1;36m║\033[0m                                                  \033[1;36m║\033[0m\n");
    printf("\033[1;36m║\033[0m   \033[1;33m[1]\033[0m  View All Tasks                            \033[1;36m║\033[0m\n");
    printf("\033[1;36m║\033[0m   \033[1;33m[2]\033[0m  Create New Task                           \033[1;36m║\033[0m\n");
    printf("\033[1;36m║\033[0m   \033[1;33m[3]\033[0m  Delete Task                               \033[1;36m║\033[0m\n");
    printf("\033[1;36m║\033[0m   \033[1;33m[4]\033[0m  Exit Program                              \033[1;36m║\033[0m\n");
    printf("\033[1;36m║\033[0m                                                  \033[1;36m║\033[0m\n");
    printf("\033[1;36m╚══════════════════════════════════════════════════╝\033[0m\n");
    printf("\n  \033[1;37m▸ Select an option:\033[0m ");
}


// Welcome
int welcome(void){
  while (true){
    int response = 0;

        if (scanf("%d", &response) != 1) {
            while (getchar() != '\n');
            printf("\n  \033[1;31m✗ Invalid input. Please enter a number between 1-4.\033[0m\n");
=======
task task_list[MAX];
task temp_task_list[MAX];

int welcome(void){
  while (true){
    int response = 0;
    printf("\n");
    printf("\033[1;36m╔════════════════════════════════════════════════════════╗\033[0m\n");
    printf("\033[1;36m║                                                        ║\033[0m\n");
    printf("\033[1;36m║\033[0m           \033[1;37mWELCOME TO TASK MANAGER\033[0m                      \033[1;36m║\033[0m\n");
    printf("\033[1;36m║                                                        ║\033[0m\n");
    printf("\033[1;36m╠════════════════════════════════════════════════════════╣\033[0m\n");
    printf("\033[1;36m║                                                        ║\033[0m\n");
    printf("\033[1;36m║\033[0m   \033[1;32m[1]\033[0m  View All Tasks                                  \033[1;36m║\033[0m\n");
    printf("\033[1;36m║                                                        ║\033[0m\n");
    printf("\033[1;36m║\033[0m   \033[1;33m[2]\033[0m  Create New Task                                 \033[1;36m║\033[0m\n");
    printf("\033[1;36m║                                                        ║\033[0m\n");
    printf("\033[1;36m║\033[0m   \033[1;31m[3]\033[0m  Delete Task                                     \033[1;36m║\033[0m\n");
    printf("\033[1;36m║                                                        ║\033[0m\n");
    printf("\033[1;36m║\033[0m   \033[1;90m[4]\033[0m  Exit Program                                    \033[1;36m║\033[0m\n");
    printf("\033[1;36m║                                                        ║\033[0m\n");
    printf("\033[1;36m╚════════════════════════════════════════════════════════╝\033[0m\n");
    printf("\n  \033[1mEnter your choice (1-4):\033[0m ");

        if (scanf("%d", &response) != 1) {
            while (getchar() != '\n');
            printf("\n  \033[1;31m Invalid input. Please enter a number between 1-4.\033[0m\n");
>>>>>>> origin/main
            continue;
        }

        while (getchar() != '\n');
        if (response >= 1 && response <=4 ){
            return response;
            }
    }
<<<<<<< HEAD
}


void view_tasks(task* task_list_to_display){
    printf("\n\033[1;36m╔══════════════════════════════════════════════════╗\033[0m\n");
    printf("\033[1;36m║\033[0m              \033[1;37m📋  ALL TASKS\033[0m                       \033[1;36m║\033[0m\n");
    printf("\033[1;36m╚══════════════════════════════════════════════════╝\033[0m\n");
    
    if (amount_of_elems == 0) {
        printf("\n  \033[1;33m⚠  No tasks found.\033[0m\n");
        printf("  \033[0;37mCreate a new task to get started.\033[0m\n\n");
        return;
    }
    for (int i = 0; i < amount_of_elems; i++){
        printf("\n  \033[1;36m┌──────────────────────────────────────────────┐\033[0m\n");
        printf("  \033[1;36m│\033[0m  \033[1;33mTask #%d\033[0m\n", task_list_to_display[i].tasknumber);
        printf("  \033[1;36m│\033[0m  \033[1;37mName:\033[0m %s\n", task_list_to_display[i].data.task_name);
        printf("  \033[1;36m│\033[0m  \033[1;37mDescription:\033[0m %s\n", task_list_to_display[i].data.task_description);
        printf("  \033[1;36m└──────────────────────────────────────────────┘\033[0m\n");
        
    }
    printf("\n");
    return;

=======


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
 
 printf("  \033[1;36m┌─────────────────────────────────────────────────────┐\033[0m\n");
 printf("  \033[1;36m│\033[0m \033[1;37mTask #%-2d\033[0m                                            \033[1;36m│\033[0m\n", task_list[i].tasknumber);
 printf("  \033[1;36m├─────────────────────────────────────────────────────┤\033[0m\n");
 printf("  \033[1;36m│\033[0m \033[1;33mTitle:\033[0m %-43s\033[1;36m  │\033[0m\n", task_list[i].data.task_name);
 printf("  \033[1;36m│\033[0m \033[1;32mDescription:\033[0m %-36s   \033[1;36m│\033[0m\n", task_list[i].data.task_description);
 printf("  \033[1;36m└─────────────────────────────────────────────────────┘\033[0m\n");
 printf("\n");

}


void create_and_append_task(task *task, task_info task_info, int number, int idx){
    if (task == NULL || idx < 0 || idx >= MAX) {
        return;
    }
    task_init(task, task_info, number);
    append_task(*task,idx);
>>>>>>> origin/main

}



<<<<<<< HEAD


void task_init(task* task_array){

    while (true){

    if (amount_of_elems >= MAX) {
    printf("\n  \033[1;31m✗ Task list is full (Maximum %d tasks)\033[0m\n", MAX);
    return;
}

    printf("\n\033[1;36m╔══════════════════════════════════════════════════╗\033[0m\n");
    printf("\033[1;36m║\033[0m            \033[1;37m✚  CREATE NEW TASK\033[0m                    \033[1;36m║\033[0m\n");
    printf("\033[1;36m╚══════════════════════════════════════════════════╝\033[0m\n\n");
    printf("  \033[1;37mTask Title\033[0m (max 100 characters): ");
    
    char name[MAXSIZE];
    char description[MAXSIZE];
    
      if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("  \033[1;31m✗ Error reading input.\033[0m\n");
=======
void add_a_task(void){

    
 while (true){

    if (amount_of_elems >= MAX) {
    printf("\n  \033[1;31m Task list is full (Maximum %d tasks)\033[0m\n", MAX);
    return;
}

    printf("\n\033[1;36m╔════════════════════════════════════════════════════════╗\033[0m\n");
    printf("\033[1;36m║\033[0m                  \033[1;37mCREATE NEW TASK\033[0m                       \033[1;36m║\033[0m\n");
    printf("\033[1;36m╚════════════════════════════════════════════════════════╝\033[0m\n\n");
    
    printf("  \033[1;33m▸ Task Title\033[0m (max 100 characters)\n  ");
    char name[MAXSIZE];
    
   
      if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("  \033[1;31m Error reading input.\033[0m\n");
>>>>>>> origin/main
        return;
    }
    
    if (strchr(name, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    
    name[strcspn(name,"\n")] = '\0';
       
    if (strlen(name) == 0) {
<<<<<<< HEAD
        printf("  \033[1;31m✗ Task title cannot be empty.\033[0m\n");
=======
        printf("  \033[1;31m Task title cannot be empty.\033[0m\n");
>>>>>>> origin/main
        continue;
    }


<<<<<<< HEAD
    printf("  \033[1;37mTask Description\033[0m (max 100 characters): ");
=======
    printf("\n  \033[1;32m▸ Task Description\033[0m (max 100 characters)\n  ");
    char description[MAXSIZE];
    
>>>>>>> origin/main
    fgets(description, sizeof(description), stdin);
    
    if (strchr(description, '\n') == NULL) {
            
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    
    description[strcspn(description,"\n")] = '\0';
<<<<<<< HEAD


    task_append(task_array, name, description, amount_of_elems);
    printf("\n  \033[1;32m✓ Task created successfully!\033[0m\n");
    amount_of_elems++;

    view_tasks(task_array);

    char cont; 
   while (true) {
   printf("  \033[1;37m▸ Would you like to add another task? (Y/N):\033[0m ");
=======
    
    task temp_task;
    
    task_info temp_task_info;
    strncpy(temp_task_info.task_name, name, MAXSIZE - 1);
    temp_task_info.task_name[MAXSIZE - 1] = '\0';
    strncpy(temp_task_info.task_description, description, MAXSIZE -1);
    temp_task_info.task_description[MAXSIZE - 1] = '\0';



    temp_task.tasknumber = amount_of_elems+1;

    
    create_and_append_task(&temp_task, temp_task_info, temp_task.tasknumber, amount_of_elems);
    printf("\n  \033[1;32m  Task created successfully!\033[0m\n\n");
    amount_of_elems++;
   


    printf("\033[1;36m─────────────────────────────────────────────────────────\033[0m\n");
    printf("  \033[1;37mCURRENT TASKS\033[0m\n");
    printf("\033[1;36m─────────────────────────────────────────────────────────\033[0m\n\n");
    for (int i = 0; i < amount_of_elems; i++){
    task_printer(temp_task, i);
    }
    


   char cont; 
   while (true) {
   printf("  \033[1mWould you like to add another task? (Y/N):\033[0m ");
>>>>>>> origin/main
   scanf(" %c", &cont);

    while (getchar() != '\n');
   
   if (cont == 'n' || cont == 'N'){
<<<<<<< HEAD
    printf("\n  \033[0;37mReturning to main menu...\033[0m\n\n");
=======
    printf("\n  \033[1;90m← Returning to main menu...\033[0m\n\n");
>>>>>>> origin/main
    return;
   }
   else if (cont == 'y' || cont == 'Y'){
    break;
   }

    else {
<<<<<<< HEAD
        printf("  \033[1;31m✗ Invalid response. Please enter Y or N.\033[0m\n");
=======
        printf("  \033[1;31m Invalid response. Please enter Y or N.\033[0m\n");
>>>>>>> origin/main
    }
    }
   
   }

<<<<<<< HEAD
    }
=======


}
>>>>>>> origin/main




<<<<<<< HEAD
void delete_a_task(task* task_address){
    
    view_tasks(task_address);
    while(true){
    if (amount_of_elems == 0){
        printf("  \033[1;33m⚠  No tasks available to delete.\033[0m\n\n");
=======
void view_tasks(void){
    printf("\n\033[1;36m╔════════════════════════════════════════════════════════╗\033[0m\n");
    printf("\033[1;36m║\033[0m                   \033[1;37mALL TASKS\033[0m                            \033[1;36m║\033[0m\n");
    printf("\033[1;36m╚════════════════════════════════════════════════════════╝\033[0m\n\n");
    
    if (amount_of_elems == 0) {
        printf("  \033[1;90mNo tasks found.\033[0m\n");
        printf("  \033[1;90mCreate a new task to get started.\033[0m\n\n");
        return;
    }
    for (int i = 0; i < amount_of_elems; i++){
        task_printer(task_list[i], i);

    }
    return;


}


void delete_a_task(){
    view_tasks();
    while(true){
    if (amount_of_elems == 0){
        printf("  \033[1;90mNo tasks available to delete.\033[0m\n\n");
>>>>>>> origin/main
        return;
    }
    else {
        int index_to_remove = 0;
        printf("  \033[1;31m▸ Enter task number to delete:\033[0m ");
        if (scanf("%d", &index_to_remove) != 1) {
            while (getchar() != '\n');
<<<<<<< HEAD
            printf("  \033[1;31m✗ Invalid input. Please enter a valid number.\033[0m\n");
=======
            printf("  \033[1;31m  Invalid input. Please enter a valid number.\033[0m\n");
>>>>>>> origin/main
            continue;
        }
        while (getchar() != '\n');
        index_to_remove--;
        if (index_to_remove < 0 || index_to_remove >= amount_of_elems){
<<<<<<< HEAD
            printf("  \033[1;31m✗ Error: Task number must be between 1 and %d\033[0m\n", amount_of_elems);
            continue;
        }
        else {
            for (int i = index_to_remove; i < amount_of_elems - 1; i++) {
            task_address[i] = task_address[i + 1];
            task_address[i].tasknumber = i + 1;
    }
    amount_of_elems--;


            printf("\n  \033[1;32m✓ Task deleted successfully!\033[0m\n");
            printf("\n\033[1;36m╔══════════════════════════════════════════════════╗\033[0m\n");
            printf("\033[1;36m║\033[0m           \033[1;37m📋  UPDATED TASK LIST\033[0m                  \033[1;36m║\033[0m\n");
            printf("\033[1;36m╚══════════════════════════════════════════════════╝\033[0m\n");
            view_tasks(task_address);
=======
            printf("  \033[1;31m  Error: Task number must be between 1 and %d\033[0m\n", amount_of_elems);
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
            printf("\n  \033[1;32m Task deleted successfully!\033[0m\n");
            printf("\n\033[1;36m─────────────────────────────────────────────────────────\033[0m\n");
            printf("  \033[1;37mUPDATED TASK LIST\033[0m\n");
            printf("\033[1;36m─────────────────────────────────────────────────────────\033[0m\n");
            view_tasks();
>>>>>>> origin/main
            return;
            
            }


        }


    }
}
