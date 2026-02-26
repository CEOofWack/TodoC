#ifndef TYPES_H
#define TYPES_H
#define MAXSIZE 100

typedef struct{
    char task_name[MAXSIZE];
    char task_description[MAXSIZE];
}task_info;


typedef struct{
    int tasknumber;
    task_info data;

}task;



#endif