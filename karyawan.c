/*
 * Sebuah program database sederhana
 * dengan menggunakan singly linked list
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    unsigned int id;
    char name[30];
    char birthplace[30];
    char position[50];
    struct Node *next;

} node;

typedef struct list{
    node *head;
}linkedList;
