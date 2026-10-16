#ifndef TYPES_H
#define TYPES_H
#define MAXSIZE 100

typedef struct{
    char task_name[MAXSIZE];
    char task_description[MAXSIZE];
    _Bool completed;
}task_info;


typedef struct task_type{
    int task_number;
    task_info data;
    struct task_type *next_task;

}task;


#endif