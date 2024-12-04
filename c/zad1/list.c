#include <stdio.h>
#include <stdlib.h>
#include "list.h"

bool is_empty(list_t l) {
    return l->length == 0;
}

int pop(list_t l) {
    node_ptr n = l->first;
    int e = n->elem;
    l->first = l->first->next;
    if (l->first == NULL) { // last element
        l->last = NULL;
    }
    free(n);
    l->length--;
    return e;
}

void push(list_t l, int e) {
    node_ptr n = malloc(sizeof(node));
    n->elem = e;
    n->next = l->first;
    l->first = n;
    if (l->last == NULL) { // first element
        l->last = n;
    }
    l->length++;
}

void append(list_t l, int e) {
    node_ptr n = malloc(sizeof(node));
    n->elem = e;
    if (l->first == NULL) { // first element
        l->first = n;
    } else {
        l->last->next = n;
    }
    l->last = n;
    l->length++;
}

int get(list_t l, int i) {
    node_ptr n = find(l, i);
    return n->elem;
}

void put(list_t l, int i, int e) {
    node_ptr n = find(l, i);
    n->elem = e;
}

void insert(list_t l, int i, int e) {
    if (i == 1) {
        push(l, e);
    } else if (i == l->length+1) {
        append(l, e);
    } else {
        node_ptr nn = malloc(sizeof(node));
        node_ptr on = find(l, i-1);
        nn->elem = e;
        nn->next = on->next;
        l->length++;
    }
}

void del(list_t l, int i) {
    node_ptr pn = find(l, i-1);
    node_ptr n = pn->next;
    if (i == 1) {
        pop(l);
    } else {
        pn->next = n->next;
        if (i == l->length) { l->last = pn; }
        free(n);
        l->length--;
    }
}

void print(list_t l) {
    node_ptr n = l->first;
    while (n != NULL) {
        printf("%d ", n->elem);
        n = n->next;
    }
    printf("| %d\n", length(l));
}

int length(list_t l) {
    return l->length;
}

void clean(list_t l) {
    while (!is_empty(l)) {
        pop(l);
    }
}

node_ptr find(list_t l, int i) {
    node_ptr n = l->first;
    int ii = i;
    if (ii==-1 || ii==l->length) {
        n = l->last;
    } else if (ii < -1) {
        ii = l->length + ii + 1;
    }
    for (int j=1; j<ii; j++) {
        n = n->next;
    }
    return n;
}

void test(list_t l) {
    clean(l);
    for (int i=1; i<=5; i++) {
        append(l, i);
    }
    printf(">> ");
    print(l);
}