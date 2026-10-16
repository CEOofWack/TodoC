#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include <string.h>
#include <assert.h>

/*Moves cursor in stdin to ignore irrelevant user input.*/
void flush_input_buffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


/*Displays welcome message.*/
void welcome(void){
    printf("Welcome to task Manager!!!\n");
    printf("Options:\n 1. View All Tasks\n 2. Add New Task\n 3. Delete Task\n 4. Edit Task\n 5. Exit program\n");
    printf("Answer: ");
}

/*Handles user input. Presents choices 1-5 and responds accordingly to invalid input.*/
int choice_handling(void){
    while(true){
        welcome();
        int response = 0;
        response = getchar() - '0';

    if ((response >= 1 && response <= 5)){
        if (getchar() == '\n'){
            return response;
        }
    }

    printf("\nInvalid input. Please enter a number between 1-5.\n\n");
    flush_input_buffer();
    }
        
}



/*Displays full task list.*/
void view_task_list(task* task_list){
    task *curr = task_list;
    curr = curr->next_task;
    task_list = task_list->next_task;

    printf("\n");
    while (curr != NULL){
        printf("\n\nTask Number %d\nTask name: %s\nTask Description: %s\nCompleted: %s ", curr->task_number, curr->data.task_name, curr->data.task_description, curr->data.completed ? "true" : "false");
        curr = curr->next_task;
    }
    printf("\n-----End of Task list-----\n\n");

}

/*Initializes task structure and returns reference to new heap allocated struct of "task" type.*/
task *task_init(int* tasknumber, char* taskname, char* taskdescription){
    task *temp_task = malloc(sizeof(task));
    if(temp_task == NULL){
        printf("Error with memory allocation");
        exit(EXIT_FAILURE);
    }
    temp_task->task_number = *tasknumber;
    strncpy(temp_task->data.task_name, taskname, MAXSIZE - 1);
    strncpy(temp_task->data.task_description, taskdescription, MAXSIZE - 1);
    temp_task->next_task = NULL;
    (*tasknumber)++;
    
    return temp_task;

}

/*Appends task struct to linked list.*/
void task_append(task* task_to_append, task* head){
    while (true){
        if(head->next_task == NULL){
            break;
        }
        head = head->next_task;
    }
    
    task_to_append->next_task = NULL;
    head->next_task = task_to_append;  
}

/*Handles the creation and addition to linked list of a new task struct. Takes user input to initialize required fields and handles invalid input accordingly.*/
_Bool create_task(int *tasknumber, task* head){
   
    while (true){

    printf("\nEnter task name (max 100 characters): ");
    
    
    char name[MAXSIZE];
    char description[MAXSIZE];
    
      if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("Error reading input.");
        return false;
    }
    
    if (strchr(name, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    
    name[strcspn(name,"\n")] = '\0';
       
    if (strlen(name) == 0) {
        printf("\nTask title cannot be empty.\n");
        continue;
    }


    printf("\nTask Description (max 100 characters): ");
    fgets(description, sizeof(description), stdin);
    
    if (strchr(description, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    
    description[strcspn(description,"\n")] = '\0';

    if(*tasknumber == 1){
        strncpy(head->next_task->data.task_name, name, MAXSIZE - 1);
        strncpy(head->next_task->data.task_description, description, MAXSIZE - 1);
        head->next_task->next_task = NULL;
        head->next_task->task_number = 1;
        (*tasknumber)++;
        

    }
    else{
        task_append(task_init(tasknumber, name, description), head);

    }
    
    printf("\nTask created successfully!\n");


   char cont; 
   //int end_check;

   while (true) {
   printf("\nWould you like to add another task? (Y/N): ");

   cont = getchar();

   if ((cont == 'n' || cont == 'N')){
    if (getchar() == '\n'){
        printf("\nReturning to main menu...\n\n");
        return true;
        }
   }
   else if ((cont == 'y' || cont == 'Y')){
       if (getchar() == '\n'){
        break;
        }
   }

    printf("\nInvalid response. Please enter Y or N.\n");
    flush_input_buffer();
    
    }
   
   }
    
}

/*Frees all heap allocated structs from memory.*/
void clear_list(task* head){
    task* temp = head;

    while(head != NULL){
        head = head->next_task;
        free(temp);
        temp = head;
    }

}




/*Displays an individual task.*/
void display_task(task * curr){
     printf("\nTask Number %d\nTask name: %s\nTask Description: %s\nCompleted: %s \n", curr->task_number, curr->data.task_name, curr->data.task_description, curr->data.completed ? "true" : "false");

}



/*Handles task editing.*/
void edit_task(task* head, int *tasknumber){
    int idx_to_edit;
    char cont, cont2;

    task* curr = head->next_task;
    if((*tasknumber) == 1){
        printf("\nNo tasks to edit.\n\n");
        return;
    }
   
    // Re-check indexing just 2 be sure
    while(true){
        printf("\nEnter task index to edit: ");
        idx_to_edit = getchar() - '0';

        if((idx_to_edit > ((*tasknumber)-1)) || (idx_to_edit < 1)){
        printf("\nError: Index to edit must be within range\n\n");
        flush_input_buffer();
        }
        else if(getchar() == '\n'){
            break;
        }
        else{
            printf("\nInvalid input: index must be int and within range.\n\n");
            flush_input_buffer();
        }
            

        
    

    }
    
    // Indexing problem fixed for now, keep checking though
    if (idx_to_edit != 1){
        for(int x = 1; x < idx_to_edit; x++){
            curr = curr->next_task;
        }
            }

    while (true) {

        display_task(curr);
        printf("\nWould you like to edit this task? (Y or N): ");

        cont = getchar();

        if ((cont == 'n' || cont == 'N')){
            if (getchar() == '\n'){
                printf("\nReturning to main menu...\n\n");
                return;
            }
        }      
        else if ((cont == 'y' || cont == 'Y')){
            if (getchar() == '\n'){
                printf("Is this task complete? (Y or N): ");
                cont2 = getchar();

                if ((cont2 == 'n' || cont2 == 'N')){
                    if (getchar() == '\n'){
                        curr->data.completed = false;
                        display_task(curr);
                        printf("\nTask set as incomplete. Returning to main menu...\n\n");
                        return;
                    }
                }      
                else if ((cont == 'y' || cont == 'Y')){
                    if (getchar() == '\n'){
                        curr->data.completed = true;
                        printf("\nTask set as complete. Returning to main menu...\n\n");
                        display_task(curr);
                        return;
                    }
                }

                printf("\nInvalid response. Please enter Y or N.\n");
                flush_input_buffer();
            }
        }
        printf("\nInvalid response. Please enter Y or N.\n");
        flush_input_buffer();
        
        }
         
}

void shift_indecies(task* head){
    task* temp = head;
    while (temp != NULL){
        temp->task_number--;
        temp = temp->next_task;
    }
}



/*INCOMPLETE: deletes task and shifts indexes of tasks accordingly.*/
_Bool delete_task(task* head, int* px){
    int idx_to_delete = 0;

    // First node by default
    task* curr = head->next_task;
    // Second node by default
    task* next = curr->next_task;

    task* temp;

    while (true){
        if(*px == 1){
            printf("Empty task list. Make a new task.\n\n");
            return false;
        }
        printf("\nEnter item to delete: ");
        idx_to_delete = getchar() - '0';
        if ((idx_to_delete > ((*px) - 1)) || (idx_to_delete < 1)){
            if(getchar() == '\n'){
                printf("\nError: Index to delete must be within bounds.\n");
                flush_input_buffer();
                continue;
            }
        }
        if (idx_to_delete == 1){
            head->next_task = next;
            free(curr);
            shift_indecies(head);
            printf("\nTask 1 sucessfuly deleted!\n"); 
            (*px)--;
            flush_input_buffer(); 
            return true; 
        }
        else{
            //segfault here likely
            for(int i = 0; i < idx_to_delete; i++){
                curr = curr->next_task;
                next = next->next_task;
            }
            temp = curr;
            shift_indecies(curr);
            curr->next_task = next;
            free(temp);
            (*px)--;
            printf("\nTask %d sucessfuly deleted!\n\n", idx_to_delete);
            return true;
        }
        printf("\nInvalid input. Try again.\n\n");
        flush_input_buffer();
        
    }
    

}