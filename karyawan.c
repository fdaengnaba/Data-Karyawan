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

void pushKaryawan(linkedList *listKaryawan){
    node *newNode = (node *) malloc(sizeof(node));
    if(newNode == NULL){
        printf("%s\n", "memory allocation error");
        return;
    }
    unsigned int id;
    printf("%s", "ID: ");
    scanf("%d", &id);
    

    if(listKaryawan->head==NULL){
        listKaryawan->head = newNode;
    }
}

int main(){
    int menu;
    while (1){
        system("clear");
        printf("%s\n", "1. Push Data");
        scanf("%d", &menu);

        switch(menu){
            case 1 :
                printf("menu 1\n");
                break;
            case 99 :
                return 0;
        }
    }
}
