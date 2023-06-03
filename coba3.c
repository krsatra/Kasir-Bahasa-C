#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

struct Barang{
    int id;
    char nama[25];
    long jumlah;
    long harga;
    long total;
};
struct node{
    struct Barang barang;
    struct node *next;
};

struct node *head = NULL;
struct node *last = NULL;

 int jumlah;

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
void List(){
    int total, bayar;
    int totalmak=0;
    if(isEmpty(head)){
        printf("Data kosong");
    }else{
        struct node*current = head;
        printf("|------------------------------------------------------------------|\n");
        printf("|\t\t                Transaksi                          |\n");
        printf("|\t\t             Pembelian Barang                      |\n");
        printf("|------------------------------------------------------------------|\n");
        printf("|Id     |Barang         |Jumlah         |Harga          |Biaya     |\n");
        printf("------------------------------------------------------------------\n");
        for(int i = 0; i<jumlah; i++){
            printf("|%d\t|%s\t\t|%ld\t\t|%ld\t\t|%ld\n", current->barang.id, current->barang.nama, current->barang.jumlah, current->barang.harga, current->barang.jumlah*current->barang.harga);
            total = current->barang.harga * current->barang.jumlah;
            totalmak += total;
            current = current->next;
            //printf("\n");
        }
        printf("\n\nTotal Biaya : %d", totalmak);
        printf("\n\n");
        balik:
        printf("Bayar : ");
        scanf("%d", &bayar);

        if(bayar < totalmak){
            printf("Maaf Uang Anda Kurang!!\n\n");
            goto balik;
        }else{
            printf("Kembalian Anda : %d\n\n", bayar- totalmak);
        }
        printf("Terima kasih telah membeli barang di Toko kami");
        
    }
}



int main(){
   
    struct Barang barang;
    
        system("cls");
        //choice = menu();
        
            
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
                printf("\n\n");
                List(head);
                //Total();

}