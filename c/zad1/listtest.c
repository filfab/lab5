#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

int main() {
    list_t list = malloc(sizeof(list_struct));
    list->first = list->last = NULL;
    int elem;

    bool cont = true;
    char command[20];
    int index;

    while (cont) {
        printf("<< Command: ");
        scanf("%s", command);

        if (!strcmp(command, "pop")) {
            if (!is_empty(list)) {
                elem = pop(list);
                printf(">> Result: %d\n", elem);
            } else {
                printf("Err - List is empty!\n");
            }
        }
        else if (!strcmp(command, "push")) {
            printf("<< Value: ");
            if (scanf("%d", &elem) != 1) {
                printf("Err - Bad value!\n");
                continue;
            }
            push(list, elem);
            printf(">> OK\n");
        }
        else if (!strcmp(command, "append")) {
            printf("<< Value: ");
            if (scanf("%d", &elem) != 1) {
                printf("Err - Bad value!\n");
                continue;
            }
            append(list, elem);
            printf(">> OK\n");
        }
        else if (!strcmp(command, "print")) {
            printf(">> ");
            print(list);
        }
        else if (!strcmp(command, "get")) {
            printf("<< Index: ");
            if (scanf("%d", &index) != 1) {
                printf("Err - Given index is not a number!\n");
            }
            else if ((index>0 && index<=length(list))
            || (index<0 && index>=-length(list))) {
                printf(">> Result: %d\n", get(list, index));
            } else {
                printf("Err - Bad index!\n");
            }
        }
        else if (!strcmp(command, "put")) {
            printf("<< Index: ");
            if (scanf("%d", &index) != 1) {
                printf("Err - Given index is not a number!\n");
            }
            else if ((index>0 && index<=length(list))
            || (index<0 && index>=-length(list))) {
                printf("<< Value: ");
                if (scanf("%d", &elem) != 1) {
                    printf("Err - Bad value!\n");
                } else {
                    put(list, index, elem);
                    printf(">> OK\n");
                }
            } else {
                printf("Err - Bad index!\n");
            }
        }
        else if (!strcmp(command, "insert")) {
            printf("<< Index: ");
            if (scanf("%d", &index) != 1) {
                printf("Err - Given index is not a number!\n");
            }
            else if (index>0 && index<=length(list)+1) {
                printf("<< Value: ");
                if (scanf("%d", &elem) != 1) {
                    printf("Err - Bad value!\n");
                } else {
                    insert(list, index, elem);
                    printf(">> OK\n");
                }
            } else {
                printf("Err - Bad index!\n");
            }
        }
        else if (!strcmp(command, "delete")) {
            printf("<< Index: ");
            if (scanf("%d", &index) != 1) {
                printf("Err - Given index is not a number!\n");
            }
            else if (index>0 && index<=length(list)) {
                del(list, index);
                printf(">> OK\n");
            } else {
                printf("Err - Bad index!\n");
            }
        }
        else if (!strcmp(command, "length")) {
            elem = length(list);
            printf(">> Result: %d\n", elem);
        }
        else if (!strcmp(command, "clean")) {
            clean(list);
            printf(">> List cleaned\n");
        }
        else if (!strcmp(command, "exit")) {
            cont = false;
        }
        else if (!strcmp(command, "test")) {
            test(list);
        }
        else
            printf("Err - Unknown command!\n");
        }

    clean(list);
    free(list);
    return 0;
}