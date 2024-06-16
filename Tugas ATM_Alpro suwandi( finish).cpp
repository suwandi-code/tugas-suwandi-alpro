#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// PIN ATM
#define PIN "203040"

// Saldo awal ATM
float saldo = 5000000; // Saldo dalam Rupiah

// Jumlah maksimum percobaan salah
const int MAX_PERCOBAAN_SALAH = 3;
int percobaanSalah = 0;

// Fungsi untuk memasukkan PIN
int masukkanPIN() {
    char inputPIN[5];
    printf("\n");
    printf("          SELAMAT DATANG     \n ");
    printf("    SILAKAN MASUKKAN PIN ANDA      \n ");
    printf("\n");
    printf("masukkan PIN :");
    scanf("%s", inputPIN);
    if (strcmp(inputPIN, PIN) == 0) {
        return 1;
    } else {
        percobaanSalah++;
        if (percobaanSalah >= MAX_PERCOBAAN_SALAH) {
            printf("PIN yang Anda masukkan salah lebih dari 3 kali. Kartu Anda diblokir.\n");
            exit(0);
        } else {
            printf("PIN yang Anda masukkan salah. Sisa percobaan: %d\n", MAX_PERCOBAAN_SALAH - percobaanSalah);
            return 0;
        }
    }
}

// Fungsi untuk menampilkan menu ATM
void tampilkanMenu() {
	printf("\n");
    printf("=== Menu ATM ===\n");
    printf("1. info Rekening\n");
    printf("2. Trasnsfer\n");
    printf("3. Tarik Tunai\n");
    printf("4. Pembayaran\n");
    printf("5. Top up\n");
    printf("0. Kembali\n");
    printf("Pilih opsi: ");
}

void tampilkanMenuinfoRekening() {
	printf("\n");
    printf("=== Menu info Rekening ===\n");
    printf("1. cek saldo\n");
    printf("0. Kembali\n");
    printf("Pilih opsi: ");
}

void tampilkanMenuceksaldo() {
	printf("\n");
    printf("      APAKAH ANDA INGIN MELAKUKAN TRANSAKSI LAGI:      \n");
    printf("\n");
    printf("1. YA\n");
    printf("2. TIDAK\n");
    printf("Pilih opsi: ");
}

void tampilkanMenuTrasnfer(){
	printf("\n");
	printf("=== Menu trasnfer ===\n");
    printf("0. Kembali\n");
    printf("Pilih opsi: ");
}

void tampilkanMenuInstitusi(){
	printf("\n");
	printf("=== Menu Institusi ===\n");
    printf("0. Kembali\n");
    printf("Pilih opsi: ");
}

void tampilkanMenuTopup(){
	printf("\n");
	printf("=== Menu ATM ===\n");
	printf("1. Dana\n");
    printf("2. Ovo\n");
    printf("0. Kembali\n");
    printf("Pilih opsi: ");
}

void tampilkanMenuTopupDana(){
	printf("\n");
	printf("=== Menu Dana ===\n");
	printf("1. Dana\n");
    printf("2. Ovo\n");
    printf("0. Kembali\n");
    printf("Pilih opsi: ");

}

void tampilkanMenuTopupOvo(){
	printf("\n");
	printf("=== Menu Ovo ===\n");
	printf("1. Dana\n");
    printf("2. Ovo\n");
    printf("0. Kembeli\n");
    printf("Pilih opsi: ");
}

void tampilkanMenuTarikTunai(){
	printf("\n");
	printf("=== menu pilihan ===\n");
	printf("1. Rp:100.000\n");
    printf("2. Rp:300.000\n");
    printf("3. Rp:500.000\n");
    printf("4. Rp:1.000.000\n");
    printf("Pilih opsi: ");

}
// Fungsi untuk mengecek info rekening
void infoRekening() {
    int pilihan;
    do {
        tampilkanMenuinfoRekening();
        scanf("%d", &pilihan);
        system("cls");

        switch (pilihan) {
            case 1:
                printf("Sisa Saldo Anda: Rp%.2f\n", saldo);
                break;
            case 0:
                printf("\n");
                printf("Terima kasih. Telah melakukan transaksi ini!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
      
        if (pilihan != 0) {
            tampilkanMenuceksaldo();
            scanf("%d", &pilihan);
            system("cls");
            
            switch (pilihan) {
                case 1:
                    break;
                case 2:
                    printf("\n");
                    printf("Terima kasih. Telah melakukan transaksi ini!\n");
                    break;
                default:
                    printf("Pilihan tidak valid.\n");
            }
        }
      
    } while (pilihan != 0);
}

// Fungsi untuk tarik tunai
void tarikTunai(float jumlah) {
    if ((int)jumlah % 100 != 0 || jumlah > saldo) {
        printf("Penarikan uang gagal. Silakan masukkan jumlah yang valid (hanya dalam pecahan 100.000).\n");
        system("cls");
    } else {
        saldo -= jumlah;
        printf("Anda menarik Rp%.2f\nSaldo Anda sekarang: Rp%.2f\n.", jumlah, saldo);
    }
int pilihan;
    do {
        tampilkanMenuTrasnfer();
        scanf("%d", &pilihan);
        system("cls");

        switch (pilihan) {
            case 0:
                printf("Terima kasih.Telah melakukan transaksi ini!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);
}

// Fungsi untuk transfer uang
void transferUang(float jumlah) {
    char nomorTujuan[20];
    int a =123456789;
	int b;
	char nama [20];
	
    printf("Masukkan nomor rekening tujuan: ");
    scanf("%i",&b);
    printf("nama tujuan : %s\n" , "suwandi");
    
    if (jumlah > saldo) {
        printf("Saldo tidak mencukupi untuk melakukan transfer.\n");
    } else {
        saldo -= jumlah;
        printf("Transfer sejumlah Rp%.2f ke rekening %ssuwandi berhasil\nSaldo Anda sekarang: Rp%.2f\n", jumlah, nomorTujuan, saldo);
    }
int pilihan;
    do {
        tampilkanMenuTrasnfer();
        scanf("%d", &pilihan);
        system("cls");

        switch (pilihan) {
            case 0:
                printf("Terima kasih.Telah melakukan transaksi ini!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);
}

// Fungsi untuk membayar tagihan institusi
void bayarTagihan(char *institusi, float jumlah) {
    if (jumlah > saldo) {
        printf("Saldo tidak mencukupi.\n");
    } else {
        saldo -= jumlah;
        printf("Pembayaran kepada %s sejumlah Rp%.2f berhasil\nSaldo Anda sekarang: Rp%.2f\n", institusi, jumlah, saldo);
    }

int pilihan;
    do {
        tampilkanMenuInstitusi();
        scanf("%d", &pilihan);
        system("cls");

        switch (pilihan) {
            case 0:
                printf("Terima kasih.Telah melakukan transaksi ini!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);
}

// Fungsi untuk top up Dana
void topUpDana(float jumlah, char *nomorTujuan, float biayaAdmin) {
	printf("Masukkan nomor tujuan: ");
    scanf("%s", nomorTujuan);
    printf("Masukkan jumlah yang ingin Anda top up: Rp");
    scanf("%f", &jumlah);
    printf("Masukkan biaya admin: Rp");
    scanf("%f", &biayaAdmin);
    if (saldo < jumlah + biayaAdmin) {
        printf("Saldo tidak mencukupi untuk melakukan top up Dana.\n");
    } else {
        saldo -= (jumlah + biayaAdmin);
        printf("Top up Dana ke nomor %s sejumlah Rp%f berhasil. Biaya admin: Rp%.2f\nSaldo Anda sekarang: Rp%.2f\n", nomorTujuan, jumlah, biayaAdmin, saldo);
    } 
int pilihan;
    do {
        tampilkanMenuTopupDana();
        scanf("%d", &pilihan);
        system("cls");

        switch (pilihan) {
        	case 1:
        		printf("Dana\n");
        		break;
        	case 2:
        		printf("Ovo\n");
        		break;
            case 0:
                printf("Terima kasih.Silakan Datang Kembali!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);
}

// Fungsi untuk top up Ovo
void topUpOvo(float jumlah, char *nomorTujuan, float biayaAdmin) {
	printf("Masukkan nomor tujuan: ");
    scanf("%s", nomorTujuan);
    printf("Masukkan jumlah yang ingin Anda top up: Rp");
    scanf("%f", &jumlah);
    printf("Masukkan biaya admin: Rp");
    scanf("%f", &biayaAdmin);
    if (saldo < jumlah + biayaAdmin) {
        printf("Saldo tidak mencukupi untuk melakukan top up Ovo.\n");
    } else {
        saldo -= (jumlah + biayaAdmin);
        printf("Top up Ovo ke nomor %s sejumlah Rp%f berhasil. Biaya admin: Rp%f\nSaldo Anda sekarang: Rp%.2f\n", nomorTujuan, jumlah, biayaAdmin, saldo);
    }
int pilihan;
    do {
        tampilkanMenuTopupOvo();
        scanf("%d", &pilihan);
        system("cls");

        switch (pilihan) {
        	case 1:
        		printf("Dana\n");
        		break;
        	case 2:
        		printf("Ovo\n");
        		break;
            case 0:
                printf("Terima kasih.Silakan Datang Kembali!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);
}


void menu() {
    int pilihan;
    float jumlah;
    char institusi[50];
    char nomorTujuan[20];
    float biayaAdmin;
    
    do {
        tampilkanMenu();
        scanf("%d", &pilihan);
        system("cls");

        switch (pilihan) {
            case 1:
                infoRekening ();
                break;
            case 2:
                printf("Masukkan jumlah yang ingin Anda transfer: Rp");
                scanf("%f", &jumlah);
                transferUang(jumlah);
                break;
            case 3:
                tampilkanMenuTarikTunai();
            	scanf("%d", &pilihan);
        		system("cls");

		        switch (pilihan) {
					case 1:
						if (saldo <= 0) {
					    printf("Saldo Anda kosong. Tidak dapat melakukan tarik tunai.\n");
					    } else {
					        jumlah = 100000; 
					        if (jumlah > saldo) {
					        printf("Saldo tidak mencukupi untuk melakukan tarik tunai.\n");
					        } else {
					        saldo -= jumlah;
					        printf("Anda menarik uang tunai sejumlah: Rp%.2f berhasil.\n", jumlah);
					        printf("Saldo Anda sekarang: Rp%.2f\n", saldo);
					        }
					    }
					    break;
		            case 2:
		               if (saldo <= 0) {
					    printf("Saldo Anda kosong. Tidak dapat melakukan tarik tunai.\n");
					    } else {
					        jumlah = 200000; 
					        if (jumlah > saldo) {
					        printf("Saldo tidak mencukupi untuk melakukan tarik tunai.\n");
					        } else {
					        saldo -= jumlah;
					        printf("Anda menarik uang tunai sejumlah: Rp%.2f berhasil.\n", jumlah);
					        printf("Saldo Anda sekarang: Rp%.2f\n", saldo);
					        }
					    }
					    break;
		            case 3:
		                if (saldo <= 0) {
					    printf("Saldo Anda kosong. Tidak dapat melakukan tarik tunai.\n");
					    } else {
					        jumlah = 500000; 
					        if (jumlah > saldo) {
					        printf("Saldo tidak mencukupi untuk melakukan tarik tunai.\n");
					        } else {
					        saldo -= jumlah;
					        printf("Anda menarik uang tunai sejumlah: Rp%.2f berhasil.\n", jumlah);
					        printf("Saldo Anda sekarang: Rp%.2f\n", saldo);
					        }
					    }
					    break;
					case 4:
		                if (saldo <= 0) {
					    printf("Saldo Anda kosong. Tidak dapat melakukan tarik tunai.\n");
					    } else {
					        jumlah = 1000000; 
					        if (jumlah > saldo) {
					        printf("Saldo tidak mencukupi untuk melakukan tarik tunai.\n");
					        } else {
					        saldo -= jumlah;
					        printf("Anda menarik uang tunai sejumlah: Rp%.2f berhasil.\n", jumlah);
					        printf("Saldo Anda sekarang: Rp%.2f\n", saldo);
					        }
					    }
					    break;
		            case 0:
		                printf("Terima kasih.Silakan Datang Kembali!\n");
		                break;
		            default:
		                printf("Pilihan tidak valid.\n");
		
		        int pilihan;
			    do {
			        tampilkanMenuTrasnfer();
			        scanf("%d", &pilihan);
			        system("cls");
			
			        switch (pilihan) {
			            case 0:
			                printf("Terima kasih.Silakan Datang Kembali!\n");
			                break;
			            default:
			                printf("Pilihan tidak valid.\n");
			        }
			    } while (pilihan != 0);
			}break;
			
            case 4:
                fflush(stdin); 
                printf("Masukkan nama institusi: ");
                fgets(institusi, 50, stdin);
                institusi[strcspn(institusi, "\n")] = '\0';
                printf("Masukkan jumlah yang ingin Anda bayar: Rp");
                scanf("%f", &jumlah);
                bayarTagihan(institusi, jumlah);
                break;
            case 5:
                tampilkanMenuTopup();
                int topUpOption;
                scanf("%d", &topUpOption);
                system("cls");
                switch (topUpOption) {
                    case 1:
                        topUpDana(jumlah, nomorTujuan, biayaAdmin);
                        break;
                    case 2:
                        topUpOvo(jumlah, nomorTujuan, biayaAdmin);
                        break;
                    default:
                        printf("Pilihan tidak valid.\n");
	                }
	                break;
			        case 0:
			            printf("Terima kasih. Sampai jumpa!");
			            break;
			        default:
			            printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);
}

int main() {
    printf("|===============================|\n");
    printf("===========BANK WANDI============\n");
    printf("|===============================|\n");
    printf("\n");
    printf("\n"); 

    // Meminta pengguna untuk memasukkan PIN
    while (!masukkanPIN()) {}
    system("cls");
    menu();

    return 0;
}


    
