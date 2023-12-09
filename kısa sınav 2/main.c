#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // Maksimum metin boyutu

// �ifreleme fonksiyonu olu�turulur
void sifreleme(char cumle[] , int anahtarDegeri){  

	int i, j;
	
    // Kayd�rma miktar� ingilizce alfabesindeki harf say�s�na g�re d�zenlenir
    anahtarDegeri = anahtarDegeri % 26;
    
    // E�er anahtar pozitifse
    if(anahtarDegeri > 0){  
    	
    	// C�mle d�ng�ye al�n�r.  ('\0' ifadesi karakter dizisinin sonland��� noktay� ifade eder)
   		for(i = 0; cumle[i] != '\0'; i++){
   	
   			// Harf ise
   			if(isalpha(cumle[i])){
   			
   				// Anahtar de�eri kadar artt�rmak i�in d�ng�ye al�n�r
   				for(j = 1; j <= anahtarDegeri; j++){
   				
   					// E�er z ise a yap
   					if(cumle[i] == 'z' || cumle[i] == 'Z'){
   					
   						cumle[i] = 'a';
					}else{  // De�ilse bir artt�r 
					
						cumle[i]++;
					}
				}
			}
   	
  		}
	}
	else if(anahtarDegeri == 0){  // S�f�r ise ayn� �ekilde yazd�r�r
		
		printf("Sifrelenmis cumle: %s", cumle);
	}
	else{  // Anahtar de�eri negatifse
		
		// C�mle d�ng�ye al�n�r
   		for(i = 0; cumle[i] != '\0'; i++){
   	
   			// Harf ise
   			if(isalpha(cumle[i])){
   			
   				// Anahtar de�eri kadar azaltmak i�in d�ng�ye al�n�r
   				for(j = -1; j >= anahtarDegeri; j--){
   				
   					// E�er a ise z yap
   					if(cumle[i] == 'a' || cumle[i] == 'A'){
   					
   						cumle[i] = 'z';
					}else{  // De�ilse bir azalt 
					
						cumle[i]--;
					}
				}
			}
  		}
	}
}
	
int main() {
    
    int anahtarDegeri;
    
    printf("          SIFRELEME\n\n");
    
	FILE *dosya; 
    char satir1[MAX_SIZE], satir2[MAX_SIZE]; // �ki sat�r� tutacak diziler
    
	// "input.txt" ad�ndaki dosyas� okuma modunda a��l�r
    dosya = fopen("input.txt", "r"); 

    if (dosya == NULL) {
        printf("Dosya acma hatasi!\n");
        return 1; // Hata durumunda program� sonland�r
    }

    // �lk sat�r okunur ve satir1 dizisine kopyalan�r
    if (fgets(satir1, MAX_SIZE, dosya) == NULL) {
        printf("Dosyadan ilk satir okunamiyor!\n");
        fclose(dosya);
        return 1;
    }

    // �kinci sat�r okunur ve satir2 dizisine kopyalan�r
    if (fgets(satir2, MAX_SIZE, dosya) == NULL) {
        printf("Dosyadan ikinci satir okunamiyor!\n");
        fclose(dosya);
        return 1;
    }

	// Sat�rlar ekrana yazd�r�l�r
    printf("Sifrenilecek metin: %s%s\n", satir1, satir2);

    fclose(dosya); // Dosyay� kapat
    
    // Kullan�c�dan anahtar de�eri istenir
    printf("Lutfen harf kaydirma miktarini giriniz: ");
    scanf("%d", &anahtarDegeri);
    
    // Sat�rlar i�in �ifreleme fonksiyonu kullan�l�r ve yazd�r�l�r
    sifreleme(satir1, anahtarDegeri);
    sifreleme(satir2, anahtarDegeri);
    
    printf("\n\nMetnin sifrelenmis hali: %s%s\n", satir1, satir2);
  
    
	// Dosya i�aret�isi
	FILE *dosya2; 
	
	// "cozum.txt" ad�nda bir dosya olu�turulur ve yazma modunda a��l�r
    dosya2 = fopen("cozum.txt", "w"); 

    if (dosya2 == NULL) {
        perror("Dosya olu�turma hatas�");
        return 1; // Hata durumunda program� sonland�r
    }
    
	// �ifrelenmi� metin dosyaya eklenir
	fprintf(dosya2, "%s\n%s", satir1, satir2);

    printf("Metin sifrelendi ve dosyaya eklendi, dosya adi: cozum.txt\n");
    
    fclose(dosya2); // Dosyay� kapat
    
	return 0;	
}
