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
int isIdValid(unsigned int id){
    if (id <= 99999){
        return 1;
    } else return 0;
}

void pushKaryawan(linkedList *listKaryawan){
    node *newNode = (node *) malloc(sizeof(node));
    if(newNode == NULL){
        printf("%s\n", "memory allocation error");
        return;
    }

    unsigned int id;
    printf("%s", "ID: ");
    scanf("%d", &id);
    getchar();

    if(!isIdValid(id)){
        printf("%s\n", "invalid ID");
        return;
    }

    char name[30];
    printf("%s", "Nama: ");
    scanf("%s", name);
    getchar();

    char birthplace[30];
    printf("%s", "Birthplace: ");
    scanf("%s", birthplace);
    getchar();
    
    char position[50];
    printf("%s", "Jabatan: ");
    scanf("%s", position);
    getchar();

    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->birthplace, birthplace);
    strcpy(newNode->position, position);

    

    if(listKaryawan->head==NULL){
        listKaryawan->head = newNode;
    } else {
        newNode->next = listKaryawan->head;
        listKaryawan->head = newNode;
    }
}

void displayList(linkedList *listKaryawan){
    if (listKaryawan->head == NULL){
        printf("%s\n", "No Data");
    } else {
        node *curr = listKaryawan->head;
        while (curr != NULL){
            printf("ID : %5.d\n", curr->id);
            printf("Nama lengkap : %s\n", curr->name);
            printf("Tempat lahir : %s\n", curr->birthplace);
            printf("Jabatan : %s\n", curr->position);
            curr = curr->next;
        }
    }
}


int main(){
    int menu;
    linkedList listKaryawan;
    while (1){
        system("clear");
        printf("%s\n", "1. Push Data");
        printf("%s\n", "1. Display daftar karyawan");

        scanf("%d", &menu);

        switch(menu){
            case 1 :
                pushKaryawan(&listKaryawan);
                break;
            case 2 :
                displayList(&listKaryawan);
            case 99 :
                return 0;
        }
    }
}
