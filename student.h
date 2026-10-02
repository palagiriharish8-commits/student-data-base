#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
} ssl;

void add(ssl **);
void del(ssl **);
void display(ssl *);
void modify(ssl **);
void save_file(ssl *);
void sort(ssl **);
void del_all(ssl **);
void rev(ssl **);