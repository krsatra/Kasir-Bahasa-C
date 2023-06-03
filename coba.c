#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
struct Barang{
    int id;
    char nama[25];
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
        printf("|     Id|         Barang|Harga\n");
        printf("-------------------------------------------------\n");
        while(current!=NULL){
            printf("|%7d|%15s|%ld\n", current->barang.id, current->barang.nama, current->barang.harga);
            current = current->next;
        }
    }
}
void searchId(){
    int tempid;
    if(!isEmpty(head)){
        printf("id barang yang dicari: ");
        scanf("%d", &tempid);
        struct node *temp = head;
        while(temp->next!=NULL){
            if(temp->barang.id==tempid){
                break;
            }
            temp = temp->next;
        }
        if(temp->barang.id==tempid){
            printf("Nama barang: %s\n",temp->barang.nama);
        }else{
            printf("data id %d gaada", tempid);
        }
    }else{
        printf("Data kosong");
    }
}
void showTotal(){
    struct node *temp = head;
    int total = 0;
    while(temp!=NULL){
        total += 1;
        temp = temp->next;
    }
    printf("Total barang yang ada di gudang: %d\n", total);
}
void barangKeluar(){
    int tempid;
    if(isEmpty()){
        printf("Data kosong");
    }else{
        printf("id barang yang keluar: ");
        scanf("%d", &tempid);
        struct node *temp = head;
        while(temp->next!=NULL){
            if(temp->barang.id==tempid){
                break;
            }
            temp = temp->next;
        }
        if(temp->barang.id==tempid){
            printf("Barang %d telah keluar gudang\n",temp->barang.id);
            printf("Detail: \n");
            printf("Id barang: %d\n", temp->barang.id);
        }else{
            printf("data id %d gaada", tempid);
        }
    }
}
int main()
{
    char choice;
    struct Barang barang;
    do{
        system("cls");
        choice = menu();
        switch(choice){
            case '1':
                printf("Id Barang: ");
                scanf("%d", &(barang.id));
                printf("Nama Barang: ");
                scanf("%s",(barang.nama));
                printf("Harga Barang: ");
                scanf("%ld", &(barang.harga));
                insert(barang);
                break;
            case '2':
                barangKeluar();
                break;
            case '3':
                displayList(head);
                break;
            case '4':
                searchId();
                break;
            case '5':
                showTotal();
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

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>


// struct list {
// 		int x;
//     char barang[100];
//     int banyak;
//     int harga;
// 	struct list *next;
// };

// void main () {

// 	struct list *head = NULL, *curr = NULL, *node = NULL;
// 	int i;
//   int jumlah;
//   char barang[100];
//   int banyak;
//   int harga;
//   int total;
//   int totalmak = 0;

//   printf("Berapa banyak barang yang ingin dibeli? : ");
//   scanf("%d", &jumlah);

//   for (i = 0; i < jumlah ; i++) {
//     printf("Input data ke-%d : \n", i+1);
//     printf("Nama barang : ");
//     scanf("%s", &barang);
//     printf("Jumlah barang : ");
//     scanf("%d", &banyak);
//     printf("Harga barang : ");
//     scanf("%d", &harga);
//   }
    
//   for (i = 0; i < jumlah; i++) {
//     node = (struct list *) malloc (sizeof(struct list));
//     node -> x = i;
//     // strcpy(node -> barang[i][100], barang[i]);
//     // node -> barang = barang;
//     node -> banyak = banyak;
//     node -> harga = harga;

//     if (head == NULL) {
//       head = node;
//       curr = node;
//     } else {
//       curr -> next = node;
//       curr = node;
//     }
//   }
//   curr -> next = NULL;
//   curr = head;
  
//   // for (i = 0; i < jumlah; i++)
//   // {
//   //     printf("%s\n", curr -> barang[i]);
//   //     printf("%d\n", curr -> banyak[i]);
//   //     printf("%d\n", curr -> harga[i]);
//   //     // printf("\n");
//   //     curr = curr -> next;
//   // }
//   // printf("\n");

//   	        printf("=================================================\n");
// 	printf("|                   Transaksi                   |\n");
// 	printf("|               Pembelian Barang                |\n");
// 	printf("=================================================\n");
// 	printf("|Barang		|Jumlah		|Harga	|Biaya	    |\n");
// 	printf("=================================================\n");
// 	for (i = 0; i < jumlah; i++){
//         total =  curr -> harga * curr -> banyak;
//         totalmak += total;
        
//         printf("|%1s  		|%d		|%d	|%d	        |\n",curr -> barang, curr -> banyak, curr -> harga, total);

//         curr = curr -> next;
//      }
// 	printf("=================================================\n");
// 	printf("Total Biaya :				        |%d	|\n", totalmak);
// 	printf("=================================================\n");
// 	printf("\n");
  
// }

