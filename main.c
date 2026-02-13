#include <stdio.h>
#include "types.h"
#include "functions.c"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~TASK MANAGER~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Simple C task manager. Uses structures to store task information in arrays. Functions
to append and remove from array defined in functions.c file, structures used defined 
in types.h header file. Allows users to list, add and remove tasks


*/



int main(){

while (true) {
 int begin = welcome();

    if (begin == 1){
        view_tasks();
    }
    else if (begin == 2){
        add_a_task();
    }
    else if (begin == 3){
       delete_a_task();
    }
    else if (begin == 4){
        puts("Goodbye!");
        break;
    }


}


return 0;

}