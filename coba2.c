#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

struct Barang{
    int id;
    char nama[25];
    long jumlah;
    long harga;
};
struct node{
    struct Barang barang;
    struct node *next;
};

struct node *head = NULL;
struct node *last = NULL;

bool isEmpty();
char menu();
void insert(struct Barang barang);

void displayList();

bool isEmpty(){
    return head == NULL;
}
char menu(){
    char choice;
    printf("1. Input barang masuk\n");
    printf("2. Keluar Barang\n");
    printf("3. Cetak Barang\n");
    printf("4. Cari Barang\n");
    printf("5. Total Barang\n");
    printf("6. Exit\n\n");
    printf("Pilihan: ");
    scanf(" %c",&choice);
    return choice;
}
void insert(struct Barang barang){
    if(isEmpty(head)){
        struct node *temp = (struct node*) malloc(sizeof(struct node));
        temp->barang = barang;
        temp->next = NULL;
        head = temp;
        last = temp;
    }else{
        struct node *temp = (struct node*) malloc(sizeof(struct node));
        temp->barang = barang;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

}
void displayList(){
    if(isEmpty(head)){
        printf("Data kosong");
    }else{
        struct node*current = head;
        printf("|     Id|         Barang|Jumlah         |Harga          |Biaya\n");
        printf("------------------------------------------------------------------\n");
        while(current!=NULL){
            printf("|%7d|%15s|%ld\t\t|%ld\t\t|%ld\n", current->barang.id, current->barang.nama, current->barang.jumlah, current->barang.harga, current->barang.jumlah*current->barang.harga);
            current = current->next;
        }
    }
}

void Total(){
    if(isEmpty(head)){
        printf("Data kosong");
    }else{
        struct node*current = head;
        printf("|     Id|         Barang|Jumlah         |Harga\n");
        printf("-------------------------------------------------\n");
        while(current!=NULL){
            printf("|%7d|%15s|%ld\t\t|%ld\n", current->barang.id, current->barang.nama, current->barang.jumlah, current->barang.harga);
            current = current->next;
        }
    }
}

int main(){
    char choice;
    int jumlah;
    struct Barang barang;
    do{
        system("cls");
        //choice = menu();
        switch(menu()){
            case '1':
            printf("Masukkan Jumlah Barang : ");
            scanf("%d", &jumlah);
            for(int i =0; i<jumlah;i++){
                printf("Input Data Ke-%d\n", i+1);
                printf("Id Barang: ");
                scanf("%d", &(barang.id));
                printf("Nama Barang: ");
                scanf("%s",(barang.nama));
                printf("jumlah Barang: ");
                scanf("%ld", &(barang.jumlah));
                printf("Harga Barang: ");
                scanf("%ld", &(barang.harga));
                insert(barang);
                //break;
            }
            break;
            case '2':
                //barangKeluar();
                break;
            case '3':
                displayList(head);
                break;
            case '4':
                //searchId();
                break;
            case '5':
                //showTotal();
                break;
            case '6':
                printf("Exit");
                break;
            default:
                printf("Input salah");
                break;
        }
        getch();
    }while(choice!='6');
    return 0;
}