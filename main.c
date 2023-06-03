//Anggota Kelompok:
//Bahar Lanang Prakosa / 672020046
//Krisna Adi Saputra /672020178
//Ryan Agung Iskandar / 672020236

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct list {
		int x;
    char *barang[100][100];
    int banyak[100];
    int harga[100];
		struct list *next;
	};

void main () {

	struct list *head = NULL, *curr = NULL, *node = NULL;
	int i;
  int jumlah;
  char barang[100][100];
  int banyak[100];
  int harga[100];
  int total[100];
  int totalmak = 0;
  int bayar;

  printf("Berapa banyak barang yang ingin dibeli? : ");
  scanf("%d", &jumlah);

  for (i = 0; i < jumlah ; i++) {
    printf("Input data ke-%d : \n", i+1);
    printf("Nama barang : ");
    scanf("%s", &barang[i]);
    printf("Jumlah barang : ");
    scanf("%d", &banyak[i]);
    printf("Harga barang : ");
    scanf("%d", &harga[i]);
    printf("\n");
  }
    
  for (i = 0; i < jumlah; i++) {
    node = (struct list *) malloc (sizeof(struct list));
    node -> x = i;
    // strcpy(node -> barang[i][100], barang[i]);
    node -> barang[i][100] = barang[i];
    node -> banyak[i] = banyak[i];
    node -> harga[i] = harga[i];

    if (head == NULL) {
      head = node;
      curr = node;
    } else {
      curr -> next = node;
      curr = node;
    }
  }
  curr -> next = NULL;
  curr = head;

  printf("===========================================================\n");
	printf("|                       Transaksi                         |\n");
	printf("|                   Pembelian Barang                      |\n");
	printf("===========================================================\n");
	printf("|Barang\t\t|Jumlah\t\t|Harga\t\t|Biaya	  |\n");
	printf("===========================================================\n");
	for (i = 0; i < jumlah; i++){
	total[i] =  curr -> harga[i]*curr -> banyak[i];
	totalmak += total[i];
	
	printf("|%s\t\t|%d\t\t|%d\t\t|%d\t  |\n", curr -> barang[i][100], curr -> banyak[i], curr -> harga[i], total[i]);

    curr = curr -> next;
  }
	printf("==========================================================\n");
	printf("Total Biaya :\t\t\t\t\t|%d	  |\n", totalmak);
	printf("==========================================================\n");
	printf("\n");
  
bayar :
printf("Bayar : ");
scanf("%d", &bayar);

  if (bayar < totalmak) {
    printf("Maaf uang anda kurang!!!\n\n");
    goto bayar;
  }

  printf("Kembalian Anda : %d\n\n", bayar - totalmak);

  printf("Terima kasih telah membeli barang di Toko kami");
  
}