#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SANSLI_SAYI 1
#define KUM_SAATI 2
#define DAG_YOLU 3
#define CIKIS 4

void make_a_guess();
void draw_hourglass();
void puan();
void draw_mountain_road ();

void menu() {
    int secim;
    do {
        printf("1. Sansli Sayi Oyna\n");
        printf("2. Kum Saati Ciz\n");
        printf("3. Dag Yolu Ciz\n");
        printf("4. Cikis\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);
        
        switch (secim) {
            case 1:
                make_a_guess();
                break;
            case 2:
                draw_hourglass();
                break;
            case 3:
                draw_mountain_road();
                break;
            case 4:
                break;
        }
    } while (secim != CIKIS);
}

void make_a_guess() {
    int max = 1024;
    int min = 1;
    int ln;
    int tahmin=1;
    int tahminler=0;
    int mesafe;
    int tahmin2;
    srand(time(0)); 
    ln = (rand() % (max)) + min;
    do {  
        printf("Tahmininizi yapiniz (%d - %d):",min,max);
        scanf("%d",&tahmin);
        if (tahmin<ln)
        {
            printf("Tahmininizi yapiniz (%d - %d):\n",tahmin,max);
            min=tahmin;
        }
        else if (tahmin>ln)
        {
            printf("Tahmininizi yapiniz (%d - %d):\n",min,max);
            max=tahmin;
        }
        if (ln>=tahmin)
            {
                mesafe=ln-tahmin;
            }
        else if(tahmin>ln)
            {
                mesafe=tahmin-ln;
            }
        if (ln == tahmin) {
            puan();
        } else if (mesafe<= 1) {
            printf("Mesafe 1\n");
        } else if (mesafe<=3) {
            printf("Mesafe 2\n");
        } else if (mesafe<=7) {
            printf("Mesafe 3\n");
        } else if (mesafe<=15) {
            printf("Mesafe 4\n");
        } else if (mesafe<=31) {
            printf("Mesafe 5\n");  
        } else if (mesafe<=63) {
            printf("Mesafe 6\n");
        } else if (mesafe<=127) {
            printf("Mesafe 7\n");
        } else if (mesafe<=511) {
            printf("Mesafe 8\n");
        } else if (mesafe<=1023) {
            printf("Mesafe 9\n");
        } else {
            printf("Mesafe 10\n");
        }
        tahminler++;
        printf("Tahmin sayiniz :%d\n",tahminler);
    } while (ln != tahmin);
}

void puan(){
    int puan1 = 0;   
    int puan2 = 0;
    int oyunsayici = 0;    
    char tekrar;
    int height;
    char e='e';
    char h='h';

    do {
        oyunsayici++;

        int kazanan = 1; 

        if (kazanan == 1) {
            puan1++;
            printf("Oyunu kazandin, tebrikler!\n");
            printf("Siz: %d - Bot: %d\n", puan1, puan2);
        } else {
            puan2++;
            printf("Oyunu bot kazandi!\n");
            printf("Siz: %d - Bot: %d\n", puan1, puan2);
        }
        printf("Tekrar oyna? : (e/h): ");
        scanf(" %c", &oyunsayici);
        if(oyunsayici==e){
           make_a_guess(); 
        }
        else
            main();
        
    } while (tekrar == e || tekrar == e);
}

void draw_hourglass(){
    int height;
    printf("Bir yukseklik giriniz: ");
    scanf("%d", &height); 

    for (int j = 2 * height + 1; j >= 1; j -= 2) {
        for (int boa = 0; boa <= height - j / 2; ++boa) {
            printf(" ");
        }
        for (int i = 1; i <= j; ++i) {
            printf("*");
        }
        printf("\n");
    }
    for (int j = 3; j <= 2 * height + 1; j += 2) {
        for (int boa = 0; boa <= height - j / 2; ++boa) {
            printf(" ");
        }
        for (int i = 1; i <= j; ++i){
            printf("*");
        }
        printf("\n");
    }
}

void draw_mountain_road()
{   
    int sayi;
    int length;
    int max_radius1;
    int max_radius2;
    int max_radius3;
    printf("Olusturmak istediginiz yari capin maksimum degerlerini giriniz :");
    scanf("%d",&max_radius1);
    srand(time(0)); 
    sayi = (rand() % (max_radius1)) + 0;
    
    for (int i = 1; i <= max_radius1; i++) {
        printf("\\\n");
        for (int j = 1; j <= i; j++) {
            printf(" ");
        }
    }
    printf("| ");
    printf("\n");
    for (int a = 1; a <= max_radius1; a++) {
        for (int b = a; b <= max_radius1; b++) {
            printf(" ");      
        }
        printf("/ ");
        printf("\n");
    }
    main();
}

int main() {
    menu();
}
