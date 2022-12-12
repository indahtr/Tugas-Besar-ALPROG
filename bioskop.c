#include <stdio.h>
#include <string.h>
#include <time.h>

void menu();
void selesai();

int main(){
// tampilan menu login
	char nama[100];
	char username [15];
	char password [15];

	printf("\nMasukkan nama petugas: ");
	fgets(nama,100,stdin);
	printf("\nMasukkan username: ");
	scanf("%s", &username);
	printf("\nMasukkan password: ");
	fflush(stdin);
	scanf("%s", &password);
	if ((strcmp(username, "admin") == 0) && (strcmp(password, "metropole") ==0)){
    getchar();
    system ("cls");
	printf("\n\t==============================================================\n");
	printf("\n\t||                M E T R O P O L E   X X I                 ||\n");
	printf("\n\t``````````````````````````````````````````````````````````````\n");
	printf("\n\t||               S E L A M A T  D A T A N G                 ||\n");
	printf("\n\t||\t\t%s||", nama);
	printf("\n\t==============================================================\n");
	printf("\n\n\tTekan Enter untuk melanjutkan");
    getchar();
    system ("cls");
	menu();
	}else {
        printf("\n--------------------------------");
		printf("\nPassword atau Username Salah!\n");
        getchar();
        printf("\nTEKAN ENTER UNTUK KEMBALI");
         printf("\n-------------------------------");
        getchar();
        system ("cls");
        main();

	}
}

void menu(){
// tampilan menu dan transaksi
    struct tm *local;
    time_t now;
    now = time (NULL);
    local = localtime(&now);
    float jam1[6]= {0,12.00, 14.20, 16.40, 19.00, 21.20};
    float jam2[6]= {0,12.40, 14.40, 15.50, 17.50, 19.00};
    int hari, film, jamtayang, tiket, h, i, angka_kursi[50];
    float harga_tiket, total_harga, bayar, kembalian;
    char judul [5][50]= {"Error", "MIRACLE IN CELL NO 7", "PREY FOR THE DEVIL ", "MENCURI RADEN SALEH", "KKN DI DESA PENARI"};
    char seat [10][12] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
    char huruf_kursi[30], cetak, pesan;

    printf("\n=========================================================================\n");
    printf("\n\t\t\t M E T R O P O L E   X X I\n");
    printf("\n==================================== || =================================");
    printf("\n|                                                                       |");
    printf("\n|\t\t\t      DAFTAR FILM\t\t\t\t|\n");
    printf("|-----------------------------------------------------------------------|\n");
    printf("|\t  |\t\t\t|    \t\t    Jam \t\t| \n");
    printf("| Studio  |         Film\t| --------------------------------------| \n");
    printf("|\t  |\t\t\t|   1   |   2   |   3   |   4   |   5   | \n");
    printf("|-----------------------------------------------------------------------|\n");
    printf("|    1    | MIRACLE IN CELL NO 7| 12.00 | 14.20 | 16.40 | 19.00 | 21.20 | \n");
    printf("|    2    | PREY FOR THE DEVIL \t| 12.40 | 14.40 | 15.50 | 17.50 | 19.00 | \n");
    printf("|    3    | MENCURI RADEN SALEH | 12.40 | 14.40 | 15.50 | 17.50 | 19.00 |\n");
    printf("|    4    | KKN DI DESA PENARI \t| 12.00 | 14.20 | 16.40 | 19.00 | 21.20 |\n");
    printf("-------------------------------------------------------------------------\n");
    printf("HARGA TIKET :\n\n [1] Senin-Jumat\t Rp. 50.000\n [2] Sabtu-Minggu\t Rp. 75.000\n");
    printf("------------------------------------------------------------------------\n");

    hari = local->tm_wday;
    if(hari==0){
        printf("Sekarang hari Minggu");
    }else if(hari==1){
        printf("Sekarang hari Senin");
    }else if(hari==2){
        printf("Sekarang hari Selasa");
    }else if(hari==3){
        printf("Sekarang hari Rabu");
    }else if(hari==4){
        printf("Sekarang hari Kamis");
    }else if(hari==5){
        printf("Sekarang hari Jumat");
    }else {
        printf("Sekarang hari Sabtu");
    } printf(",%d/%d/%d.\n",local->tm_mday, local->tm_mon+1, local->tm_year+1900);

    switch(hari)
    {
        case 0 : harga_tiket=75.000; break;
        case 6 : harga_tiket=75.000; break;
        default : harga_tiket=50.000; break;
    }
    printf("Harga Tiket = Rp. %.3f\n", harga_tiket);
    printf("========================================================================\n");

    printf("\nPilih Film (1/2/3/4): ");
    scanf("%d",&film);
    printf("\nPilih Jam ke-(1/2/3/4/5): ");
    scanf("%d",&jamtayang);
    system ("cls");


    printf("\n````````````````````````````");
    printf("\n  TIKET FILM YANG DIPESAN  \n");
    printf("\n````````````````````````````");
    printf("\n FILM : %s \n", judul[film]);
        if(film==1|film==4){
            printf(" JAM  : %.2f\n",jam1[jamtayang]);
        }else if(film==2|film==3){
            printf(" JAM  : %.2f\n",jam2[jamtayang]);
        }
    puts("");
    printf("Jumlah tiket yang dipesan : ");
    scanf("%d", &tiket);

    printf("\nPilih Seat Yang Tersedia!\n\n");
    printf("======================================================================\n\n");
    for(i=0; i<10; i++){
        for(h=1;h<=20;h++)
        {
            printf("%s%d ",seat[i],h);
        }
        printf("\n\n");
        printf("======================================================================\n\n");
    }
    //pilihseat;
    printf("Pilih Seat (A-J) : ");
    scanf("%S", &huruf_kursi);
    printf("\nAnda memilih seat %s, Selanjutnya silahkan pilih nomor kursi\n", huruf_kursi);
    for(h=0;h<tiket;h++){
        cekkursi:
        printf("Pilih Nomor kursi ke-%d : ",h+1);
        scanf("%d", &angka_kursi[h]);
        for(i=0; i<h; i++){
            if(angka_kursi[h]==angka_kursi[i]){
                printf("Maaf, Kursi %s%d telah terisi, silahkan pilih kembali\n",huruf_kursi, angka_kursi[i]);
                goto cekkursi;
            }
        }
    }
system("cls");
printf("================================================================\n");
printf("| NO |\t\tFILM\t\t|\tSEAT\t|\tHarga  |\n");
printf("================================================================\n");
for (i=0; i<tiket; i++){
    printf("\n| %d |\t%s\t|\t%s%d\t|\t%.3f  |\n", i+1, judul[film], huruf_kursi, angka_kursi[i],harga_tiket);
}

printf("\n================================================================\n");
total_harga = harga_tiket*tiket;
printf("Total Harga \t\t Rp. %.3f\n", total_harga);
printf("Dibayar Sebesar\t\t Rp. ");
scanf("%f", &bayar);
kembalian = bayar - total_harga;
printf("Kembalian\t\t Rp. %.3f", kembalian);
puts("");
printf("\n\nCetak Tiket (Y/N)? ");
scanf("%s", &cetak );
puts("");

system("cls");
if(cetak=='y' | cetak=='Y'){
    for(i=0;i<tiket;i++){
        printf("==================================\n");
        printf("|\tMETROPOLE XXI\t\t|\n");
        printf("==================================\n");
        printf("|\t%s\t|\n", judul[film]);
        printf("| date  : %d/%d/%d \t\t|\n",local->tm_mday, local->tm_mon+1, local->tm_year+1900);
        if(film==1|film==4){
            printf("| time  : %.2f\t\t\t|\n",jam1[jamtayang]);
        }else if(film==2|film==3){
            printf("| time  : %.2f\t\t\t|\n",jam2[jamtayang]);
        }
        printf("| row   : %c  seat : %d\t\t| \n", huruf_kursi, angka_kursi[i]);
        printf("| price : %.3f \t\t|\n", harga_tiket);
        printf("==================================");
        printf("\n\n");
    }
     printf("Ingin memesan lagi(Y/N)");
     scanf("%s", &pesan);

     if (pesan=='y' | pesan=='Y'){
        system("cls");
        getchar();
        main();
     }else if(pesan=='n' | pesan=='N'){
        selesai ();
    }
}else if (cetak=='n' | cetak=='N' ){
    printf("ingin memesan lagi (Y/N)? ");
    scanf("%s", &pesan);
    if (pesan=='y' | pesan=='Y'){
        main();
     }else if(pesan=='n' | pesan=='N'){
        selesai ();
    }
}


}
void selesai(){
    system("cls");
    printf("\n\n\t==========================================================\n");
            printf("\t|                                                        |\n");
            printf("\t|                T E R I M A   K A S I H                 |\n");
            printf("\t|                                                        |\n");
            printf("\t|         ----------SELAMAT MENONTON----------           |\n");
            printf("\t|                                                        |\n");
            printf("\t==========================================================\n");
}







