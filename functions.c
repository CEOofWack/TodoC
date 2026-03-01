#include <stdio.h>
#include "types.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>


#define MAX 100
int amount_of_elems = 0;



task *allocate_memory(){
    task *task_address = malloc(sizeof(task));
    if (task_address == NULL){
        puts("Malloc Error, exiting");
        exit(EXIT_FAILURE);
    }
    return task_address;

}


task *reallocate_memory(task* ptr_to_task){
    task* new_ptr_to_task = realloc(ptr_to_task, sizeof(task) * (amount_of_elems + 1));
    if(new_ptr_to_task == NULL){
        puts("Error reallocating memory");
        exit(EXIT_FAILURE);
    }
    return new_ptr_to_task;

}


void task_append(task* task_to_append_to, char *name_to_add, char* desc_to_add, int task_num){
    task_to_append_to[task_num].tasknumber = task_num + 1;
    strncpy(task_to_append_to[task_num].data.task_name,name_to_add, MAXSIZE - 1);
    task_to_append_to[task_num].data.task_name[MAXSIZE - 1] = '\0';
    strncpy(task_to_append_to[task_num].data.task_description, desc_to_add, MAXSIZE - 1);
    task_to_append_to[task_num].data.task_description[MAXSIZE - 1] = '\0';
    task_to_append_to[task_num].data.completed = false;

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
    printf("\033[1;36m║\033[0m   \033[1;33m[4]\033[0m  Edit Task                                 \033[1;36m║\033[0m\n");
    printf("\033[1;36m║\033[0m   \033[1;33m[5]\033[0m  Exit Program                              \033[1;36m║\033[0m\n");
    printf("\033[1;36m║\033[0m                                                  \033[1;36m║\033[0m\n");
    printf("\033[1;36m╚══════════════════════════════════════════════════╝\033[0m\n");
    printf("\n  \033[1;37m▸ Select an option:\033[0m ");
}


int welcome(void){
  while (true){
    int response = 0;

        if (scanf("%d", &response) != 1) {
            while (getchar() != '\n');
            printf("\n  \033[1;31m✗ Invalid input. Please enter a number between 1-4.\033[0m\n");
            continue;
        }

        while (getchar() != '\n');
        if (response >= 1 && response <=5 ){
            return response;
            }
    }
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
        printf("  \033[1;36m│\033[0m  \033[1;37mCompleted:\033[0m %s\n", task_list_to_display[i].data.completed ? "true" : "false");
        printf("  \033[1;36m└──────────────────────────────────────────────┘\033[0m\n");
        
    }
    printf("\n");
    return;


}





task* task_init(task* task_array){

    while (true){

    if (amount_of_elems >= MAX) {
    printf("\n  \033[1;31m✗ Task list is full (Maximum %d tasks)\033[0m\n", MAX);
    return task_array;
        }

    printf("\n\033[1;36m╔══════════════════════════════════════════════════╗\033[0m\n");
    printf("\033[1;36m║\033[0m            \033[1;37m✚  CREATE NEW TASK\033[0m                    \033[1;36m║\033[0m\n");
    printf("\033[1;36m╚══════════════════════════════════════════════════╝\033[0m\n\n");
    printf("  \033[1;37mTask Title\033[0m (max 100 characters): ");
    
    char name[MAXSIZE];
    char description[MAXSIZE];
    
      if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("  \033[1;31m✗ Error reading input.\033[0m\n");
        return task_array;
    }
    
    if (strchr(name, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    
    name[strcspn(name,"\n")] = '\0';
       
    if (strlen(name) == 0) {
        printf("  \033[1;31m✗ Task title cannot be empty.\033[0m\n");
        continue;
    }


    printf("  \033[1;37mTask Description\033[0m (max 100 characters): ");
    fgets(description, sizeof(description), stdin);
    
    if (strchr(description, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    
    description[strcspn(description,"\n")] = '\0';



        
    task_array = reallocate_memory(task_array);

    
    task_append(task_array, name, description, amount_of_elems);
    printf("\n  \033[1;32m✓ Task created successfully!\033[0m\n");
    amount_of_elems++;

   
    

   view_tasks(task_array);

   char cont; 
   while (true) {
   printf("  \033[1;37m▸ Would you like to add another task? (Y/N):\033[0m ");
   scanf(" %c", &cont);

    while (getchar() != '\n');
   
   if (cont == 'n' || cont == 'N'){
    printf("\n  \033[0;37mReturning to main menu...\033[0m\n\n");
    return task_array;
   }
   else if (cont == 'y' || cont == 'Y'){
    break;
   }

    else {
        printf("  \033[1;31m✗ Invalid response. Please enter Y or N.\033[0m\n");
    }
    }
   
   }

    }



void edit_a_task(task* task_to_edit){

    view_tasks(task_to_edit);

    while (true) {
        if (amount_of_elems == 0) {
            printf("  \033[1;33m\u26a0  No tasks available to edit.\033[0m\n\n");
            return;
        }

        int index_to_change = 0;
        printf("  \033[1;31m\u25b8 Enter task number to change status:\033[0m ");
        if (scanf("%d", &index_to_change) != 1) {
            while (getchar() != '\n')
                ;
            printf("  \033[1;31m\u2717 Invalid input. Please enter a valid number.\033[0m\n");
            continue;
        }
        while (getchar() != '\n')
            ;
        index_to_change--;

        if (index_to_change < 0 || index_to_change >= amount_of_elems) {
            printf("  \033[1;31m\u2717 Error: Task number must be between 1 and %d\033[0m\n", amount_of_elems);
            continue;
        }

        char completed;
        while (true) {
            printf("Have you completed the task? (Y/N): ");
            scanf(" %c", &completed);
            while (getchar() != '\n')
                ;
            if (completed == 'Y' || completed == 'y') {
                task_to_edit[index_to_change].data.completed = true;
                break;
            } else if (completed == 'N' || completed == 'n') {
                task_to_edit[index_to_change].data.completed = false;
                break;
            } else {
                printf("  \033[1;31m\u2717 Invalid input. Type 'Y' or 'N'.\033[0m\n");
            }
        }

        printf("\n  \033[1;32m✓ Task status changed successfully!\033[0m\n");
        printf("\n\033[1;36m╔══════════════════════════════════════════════════╗\033[0m\n");
        printf("\033[1;36m║\033[0m           \033[1;37m📋  UPDATED TASK LIST\033[0m                  \033[1;36m║\033[0m\n");
        printf("\033[1;36m╚══════════════════════════════════════════════════╝\033[0m\n");
        view_tasks(task_to_edit);
        return;
    }
}

    






void delete_a_task(task* task_address){
    
    view_tasks(task_address);
    while(true){
    if (amount_of_elems == 0){
        printf("  \033[1;33m⚠  No tasks available to delete.\033[0m\n\n");
        return;
    }
    else {
        int index_to_remove = 0;
        printf("  \033[1;31m▸ Enter task number to delete:\033[0m ");
        if (scanf("%d", &index_to_remove) != 1) {
            while (getchar() != '\n');
            printf("  \033[1;31m✗ Invalid input. Please enter a valid number.\033[0m\n");
            continue;
        }
        while (getchar() != '\n');
        index_to_remove--;
        if (index_to_remove < 0 || index_to_remove >= amount_of_elems){
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
            return;
            
            }


        }


    }
}
