#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "types.h"

task *allocate_memory(void);
void task_append(task* task_to_append_to, char *name_to_add, char* desc_to_add, int task_num);
void display_greeting(void);
int welcome(void);
task* task_init(task* task_array);
void view_tasks(task* task_list_to_display);
void edit_a_task(task* task_to_edit);
void delete_a_task(task* task_address);

#endif
