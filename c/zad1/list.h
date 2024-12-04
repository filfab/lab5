#pragma once
#include <stdbool.h>

typedef struct node
 {
    int elem;
    struct node* next;
} node;
typedef node* node_ptr;

typedef struct list_struct {
    node_ptr first;
    node_ptr last;
    int length;
} list_struct;
typedef list_struct* list_t;

bool is_empty(list_t l);
int pop(list_t l);
void push(list_t l, int e);
void append(list_t l, int e);

int get(list_t l, int i);
void put(list_t l, int i, int e);
void insert(list_t l, int i, int e);
void del(list_t l, int i);

void print(list_t l);
int length(list_t l);
void clean(list_t l);

node_ptr find(list_t l, int i);
void test(list_t l);
