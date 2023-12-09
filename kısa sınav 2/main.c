#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // Maksimum metin boyutu

// Þifreleme fonksiyonu oluþturulur
void sifreleme(char cumle[] , int anahtarDegeri){  

	int i, j;
	
    // Kaydýrma miktarý ingilizce alfabesindeki harf sayýsýna göre düzenlenir
    anahtarDegeri = anahtarDegeri % 26;
    
    // Eðer anahtar pozitifse
    if(anahtarDegeri > 0){  
    	
    	// Cümle döngüye alýnýr.  ('\0' ifadesi karakter dizisinin sonlandýðý noktayý ifade eder)
   		for(i = 0; cumle[i] != '\0'; i++){
   	
   			// Harf ise
   			if(isalpha(cumle[i])){
   			
   				// Anahtar deðeri kadar arttýrmak için döngüye alýnýr
   				for(j = 1; j <= anahtarDegeri; j++){
   				
   					// Eðer z ise a yap
   					if(cumle[i] == 'z' || cumle[i] == 'Z'){
   					
   						cumle[i] = 'a';
					}else{  // Deðilse bir arttýr 
					
						cumle[i]++;
					}
				}
			}
   	
  		}
	}
	else if(anahtarDegeri == 0){  // Sýfýr ise ayný þekilde yazdýrýr
		
		printf("Sifrelenmis cumle: %s", cumle);
	}
	else{  // Anahtar deðeri negatifse
		
		// Cümle döngüye alýnýr
   		for(i = 0; cumle[i] != '\0'; i++){
   	
   			// Harf ise
   			if(isalpha(cumle[i])){
   			
   				// Anahtar deðeri kadar azaltmak için döngüye alýnýr
   				for(j = -1; j >= anahtarDegeri; j--){
   				
   					// Eðer a ise z yap
   					if(cumle[i] == 'a' || cumle[i] == 'A'){
   					
   						cumle[i] = 'z';
					}else{  // Deðilse bir azalt 
					
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
    char satir1[MAX_SIZE], satir2[MAX_SIZE]; // Ýki satýrý tutacak diziler
    
	// "input.txt" adýndaki dosyasý okuma modunda açýlýr
    dosya = fopen("input.txt", "r"); 

    if (dosya == NULL) {
        printf("Dosya acma hatasi!\n");
        return 1; // Hata durumunda programý sonlandýr
    }

    // Ýlk satýr okunur ve satir1 dizisine kopyalanýr
    if (fgets(satir1, MAX_SIZE, dosya) == NULL) {
        printf("Dosyadan ilk satir okunamiyor!\n");
        fclose(dosya);
        return 1;
    }

    // Ýkinci satýr okunur ve satir2 dizisine kopyalanýr
    if (fgets(satir2, MAX_SIZE, dosya) == NULL) {
        printf("Dosyadan ikinci satir okunamiyor!\n");
        fclose(dosya);
        return 1;
    }

	// Satýrlar ekrana yazdýrýlýr
    printf("Sifrenilecek metin: %s%s\n", satir1, satir2);

    fclose(dosya); // Dosyayý kapat
    
    // Kullanýcýdan anahtar deðeri istenir
    printf("Lutfen harf kaydirma miktarini giriniz: ");
    scanf("%d", &anahtarDegeri);
    
    // Satýrlar için þifreleme fonksiyonu kullanýlýr ve yazdýrýlýr
    sifreleme(satir1, anahtarDegeri);
    sifreleme(satir2, anahtarDegeri);
    
    printf("\n\nMetnin sifrelenmis hali: %s%s\n", satir1, satir2);
  
    
	// Dosya iþaretçisi
	FILE *dosya2; 
	
	// "cozum.txt" adýnda bir dosya oluþturulur ve yazma modunda açýlýr
    dosya2 = fopen("cozum.txt", "w"); 

    if (dosya2 == NULL) {
        perror("Dosya oluþturma hatasý");
        return 1; // Hata durumunda programý sonlandýr
    }
    
	// Þifrelenmiþ metin dosyaya eklenir
	fprintf(dosya2, "%s\n%s", satir1, satir2);

    printf("Metin sifrelendi ve dosyaya eklendi, dosya adi: cozum.txt\n");
    
    fclose(dosya2); // Dosyayý kapat
    
	return 0;	
}
