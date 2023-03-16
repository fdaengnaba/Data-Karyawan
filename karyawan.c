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
    char birthday[30];
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

    char name[32];
    printf("%s", "Nama: ");
    fgets(name, 32, stdin);
    if ((strlen(name) > 0) && (name[strlen (name) - 1] == '\n')){
        name[strlen (name) - 1] = '\0';
    }
    if (strlen(name) > 30){
        printf("%s\n", "Nama terlalu panjang\n");
        return;
    }

    char birthplace[32];
    printf("%s", "Birthplace: ");
    fgets(birthplace, 32, stdin);
    if ((strlen(birthplace) > 0) && (birthplace[strlen (birthplace) - 1] == '\n')){
        birthplace[strlen (birthplace) - 1] = '\0';
    }
    if (strlen(birthplace) > 32){
        printf("%s\n", "birthplace terlalu panjang\n");
        return;
    }

    char birthday[32];
    printf("%s", "Birthday: ");
    fgets(birthday, 32, stdin);
    if ((strlen(birthday) > 0) && (birthday[strlen (birthday) - 1] == '\n')){
        birthday[strlen (birthday) - 1] = '\0';
    }
    if (strlen(birthday) > 30){
        printf("%s\n", "Birthday terlalu panjang\n");
        return;
    }
    
    char position[52];
    printf("%s", "Jabatan: ");
    fgets(position, 52, stdin);
    if ((strlen(position) > 0) && (position[strlen (position) - 1] == '\n')){
        position[strlen (position) - 1] = '\0';
    }
    if (strlen(position) > 50){
        printf("%s\n", "Jabatan terlalu panjang\n");
        return;
    }

    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->birthplace, birthplace);
    strcpy(newNode->birthday, birthday);
    strcpy(newNode->position, position);

    
    node *curr = listKaryawan->head;
    if(listKaryawan->head==NULL){
        listKaryawan->head = newNode;
    } else { 
        if ( curr->id > id ){
            newNode->next = curr;
            listKaryawan->head = newNode;
        } else {
            while (curr->next != NULL && curr->next->id < id){
                curr = curr->next;
            }
            if (curr->id == id){
                printf("%s\n", "ID sudah digunakan");
            } else if (curr->next == NULL){
                curr->next = newNode;
            } else {
                newNode->next = curr->next;
                curr->next = newNode;
            }
        }
    }
    printf("\n%s", "berhasil ditambahkan\n\n");
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
            printf("Jabatan : %s\n\n", curr->position);
            curr = curr->next;
        }
    }
}

void hapusKaryawan(linkedList *listKaryawan, int id){
    node *curr = listKaryawan->head;
    node *prev = NULL;

    if (listKaryawan->head == NULL){
        printf("Tidak ada data karyawan\n");
    } 

    do {
        if(curr->id == id){
            /* kalo ada di depan */
            if (prev == NULL){
                listKaryawan->head = curr->next;
                free(curr);
                printf("Data karyawan dengna ID %d telah dihapus\n", id);
                return;
            } else {
                prev->next = curr->next;
                free(curr);
                printf("Data karyawan dengna ID %d telah dihapus\n", id);
                return;
            }
        }
        prev = curr;
        curr = curr->next;
    } while(curr->next != NULL);
    if (curr->id == id){
        prev->next = curr->next;
        free(curr);
        printf("Data karyawan dengna ID %d telah dihapus\n", id);
    } else {
        printf("Data karyawan dengan ID %d tidak ditemukan\n", id);
    }
}

void freeList(node *curr){
    if (curr->next != NULL){
        freeList(curr->next);
    }
    free(curr);
}


int main(){
    int menu;
    linkedList listKaryawan;
    system("clear");
    while (1){
        printf("%s\n", " 1 - Push Data");
        printf("%s\n", " 2 - Display daftar karyawan");
        printf("%s\n", " 3 - Hapus karyawan berdasarkan ID");
        printf("%s\n", " 4 - Hapus Seluruh Data Karyawan");
        printf("%s\n", "-1 - quit\n");

        scanf("%d", &menu);

        switch(menu){
            case 1 :
                system("clear");
                pushKaryawan(&listKaryawan);
                break;
            case 2 :
                system("clear");
                displayList(&listKaryawan);
                break;
            case 3 :
                int id;
                printf("ID karyawan yang akan dihapus: ");
                scanf("%d", &id);
                hapusKaryawan(&listKaryawan, id);
                break;
            case 4 :
                freeList(listKaryawan.head);
                listKaryawan.head = NULL;
                printf("Seluruh data karyawan telah di hapus\n");
                break;
            case -1 :
                return 0;
            default :
                printf("%s\n", "menu invalid");
        }
    }
}
