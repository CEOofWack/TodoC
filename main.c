#include <stdio.h>
#include "functions.h"
#include "types.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~TASK MANAGER~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Simple C task manager. Uses structures to store task information in arrays. Functions
to append and remove from array defined in functions.c file, structures used defined 
in types.h header file. Allows users to list, add and remove tasks


*/


int main(){

    task* task_list1 = allocate_memory();

    while (true){
    display_greeting();

    int begin = welcome();

     if(begin == 1){
        view_tasks(task_list1);

    }

    else if(begin == 2){
       task_list1 = task_init(task_list1);

    }

     else if(begin == 3){
        delete_a_task(task_list1);

    }

    else if (begin == 4){
        printf("\n\033[1;36m══════════════════════════════════════════════════════\033[0m\n");
        printf("  \033[1;37m  Goodbye! Thanks for using Task Manager 2.0\033[0m\n");
        printf("\033[1;36m══════════════════════════════════════════════════════\033[0m\n\n");
        break;

    }

    }



    free(task_list1);
    task_list1 = NULL;

    return 0;
}
