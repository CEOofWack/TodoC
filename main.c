#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "types.h"
#include "functions.h"

/* TaskManager 2
 * Author: Bisher Almazloum
 * New version of previous task manager with linked list as underlying data structure. 
 * Allows users to view tasks, create/delete, as well as edit tasks.
 * Handles invalid input and enforces basic memory safety.
 * Multi-file structure to avoid long, confusing code.
 * 
 * Try to break this as much as possible
*/


int main(void){

    int tasknumber = 1;
    int* px = &tasknumber;

    task *head;

    head->next_task = malloc(sizeof(task));
    strcpy(head->next_task->data.task_description, "empty");

// Options:\n 1. View All Tasks\n 2. Add New Task\n 3. Delete Task\n 4. Edit Task\n 5. Exit program\n
while(true){

    int choice = choice_handling();

    switch (choice){

    case 1:
        if ((*px) == 1){
            printf("\nEmpty task list, make a new task.\n\n");
            continue;
        }
        view_task_list(head);
        break;

    case 2:
        ;
        _Bool b = create_task(px, head);
        if(b){
            break;
        }
        else{
            puts("Error");
            exit(EXIT_FAILURE);
        }
    

    case 3:
        ;
        _Bool cont = delete_task(head, px);
        break;
    //puts("inclomplete feature");
    //exit(EXIT_SUCCESS);
    
    
     case 4: 
     if(*px != 1){
        view_task_list(head);
     }
     edit_task(head, px);
     break;


    case 5:
        clear_list(head->next_task);
        puts("Goodbye!");
        exit(EXIT_SUCCESS);
        

    default:
        puts("Caught by the default, something wrong");
        exit(EXIT_FAILURE);
    }


}


    
    return 0; 
}
