#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "types.h"
/*Function prototypes*/

void flush_input_buffer();
void welcome(void);
int choice_handling(void);
void view_task_list(task* task_list);
task *task_init(int *tasknumber, char* taskname, char* taskdescription);
void task_append(task* task_to_append, task* head);
_Bool create_task(int *tasknumber, task* head);
void clear_list(task* head);

void display_task(task * curr);
void edit_task(task* head, int *tasknumber);
_Bool delete_task(task* head, int* px);




#endif




