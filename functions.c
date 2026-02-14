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

}



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
        return;
    }
    
    if (strchr(name, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    
    name[strcspn(name,"\n")] = '\0';
       
    if (strlen(name) == 0) {
        printf("  \033[1;31m Task title cannot be empty.\033[0m\n");
        continue;
    }


    printf("\n  \033[1;32m▸ Task Description\033[0m (max 100 characters)\n  ");
    char description[MAXSIZE];
    
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
   scanf(" %c", &cont);

    while (getchar() != '\n');
   
   if (cont == 'n' || cont == 'N'){
    printf("\n  \033[1;90m← Returning to main menu...\033[0m\n\n");
    return;
   }
   else if (cont == 'y' || cont == 'Y'){
    break;
   }

    else {
        printf("  \033[1;31m Invalid response. Please enter Y or N.\033[0m\n");
    }
    }
   
   }



}




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
        return;
    }
    else {
        int index_to_remove = 0;
        printf("  \033[1;31m▸ Enter task number to delete:\033[0m ");
        if (scanf("%d", &index_to_remove) != 1) {
            while (getchar() != '\n');
            printf("  \033[1;31m  Invalid input. Please enter a valid number.\033[0m\n");
            continue;
        }
        while (getchar() != '\n');
        index_to_remove--;
        if (index_to_remove < 0 || index_to_remove >= amount_of_elems){
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
            return;
            
            }


        }


    }
}
