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
    fgets(name, 30, stdin);
    if ((strlen(name) > 0) && (name[strlen (name) - 1] == '\n')){
        name[strlen (name) - 1] = '\0';
    }

    char birthplace[30];
    printf("%s", "Birthplace: ");
    fgets(birthplace, 30, stdin);
    if ((strlen(birthplace) > 0) && (birthplace[strlen (birthplace) - 1] == '\n')){
        birthplace[strlen (birthplace) - 1] = '\0';
    }
    
    char position[50];
    printf("%s", "Jabatan: ");
    fgets(position, 50, stdin);
    if ((strlen(position) > 0) && (position[strlen (position) - 1] == '\n')){
        position[strlen (position) - 1] = '\0';
    }

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
