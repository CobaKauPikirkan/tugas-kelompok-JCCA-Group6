#include <stdio.h>

int main () {
    int detik, jam, menit;
    printf("==============================\n");
    printf("            Group 6           \n");
    printf("==============================\n");
    printf("======= Konversi Detik =======\n");
    printf("==============================\n");
    printf("input total detik   : ");
    scanf("%d", &detik);

    jam = detik / 3600;
    menit = (detik % 3600) / 60;
    detik = (detik % 60);
    printf("==============================\n");
    printf("hasil konversi %d jam %d menit %d detik", jam, menit, detik);
    printf("==============================\n");
    
    return 0;
}