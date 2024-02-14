#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>


void yazdir(int matris[][40],int n, int m,int puan){
		int i,j;
		for(i=0;i<n+1;i++){
				
				if(i!=0){
					printf("\n %d-",i-1);
				}
				for(j=0;j<m;j++){
					if(i==0){
						for(j=0;j<m;j++){
							printf("\t%d",j);
						}
						
						printf("\n");
						for(j=0;j<m;j++){
							printf("\t-");
						}
						
					}
					else
						printf("\t%d",matris[i-1][j]);
					if(i==n/2 && j==m-1){
					
						printf("\t\tPUANINIZ:%d",puan);
					}
				}
			}
	
}

int main(){
	
	
	int matris[40][40]={{0}
	
	
	};
	int n,m,i,j,x,y,Blok,z=1,control,hak,x1,say,k,l,puan=0;	
	printf("\t\t\t              TETRIS GAME    \n1-OYNA\n2-CIKIS\n\t\t\t");
	scanf("%d",&z);
	if(z==2){
		goto son;
	}
	
	printf("Matrisin boyutlarini giriniz:");
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		printf("\n");
		for(j=0;j<m;j++){
			
		printf("%d",matris[i][j]);
		}
	}
	
	while(z==1){
		
		
		srand(time(NULL));
		Blok=rand()%8;
		
		
		
		for(i=n-1;i>x1;i--){
			say=0;
			for(j=0;j<m;j++){
				if(matris[i][j]==1){
					
					say++;
					if(say==m){
						for(k=0;k<m;k++){
							matris[i][k]=0;
							
						}
						for(k=0;k<m;k++){
						
							for(l=i;l>x1-1;l--){
								matris[l][k]=matris[l-1][k];
							}
						}
						puan=puan+25;
						printf("\nMATRISIN YENI HALI:\n");
						yazdir(matris,n,m,puan);
					}
					
				}
				
				
			}
		}
		
	
		switch (Blok){
			
			case 0:
				hak=6;
				bas:  
				hak=hak-1;
				
				printf("\nHamle Hakkiniz:%d",hak);
				if(hak==0){
					goto son;
				}
				printf("\nBlok: \n\t[1]");
				printf("\n Satir ve sutunlar 0'dan baslamaktadýr.\n Koordinatlarinizi giriniz:");
				scanf("%d %d",&x,&y);
				if(x>n-1 || y>m){
						printf("\n Sinirdan buyuk sayi girdiniz!:");
						goto bas;
				}
				
				for(i=x;i>0;i--){
					
					if(matris[i][y]==1){
						printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
						goto bas; 
					}
					
				}	
				while(matris[x+1][y]==0 && x<n-1){
					x++;
					
					
				}
				if(x<x1){
					x1=x;
				}
				matris[x][y]=1;
				puan=puan+2;
				yazdir(matris,n,m,puan);
				if(x==0){
					
					goto son;
				}	
				break;
			case 1:
				hak=6;
				bas1:
				
				hak=hak-1;
				
				printf("\nHamle Hakkiniz:%d",hak);
				if(hak==0){
					goto son;
				}
				printf("\nBlok: \n\t[1][1]");
				printf("90 derece dondurmek icin 1 giriniz,devam etmek icin 0 giriniz!:");
				scanf("%d",&control);
				if(control!=0 && control!= 1){
					printf("0 yada 1 giriniz!");
					goto bas1;
				}
				if(control==1){
					
					goto bas2;
				}
				printf("\n Satir ve sutunlar 0'dan baslamaktadýr.\n Koordinatlarinizi giriniz:");
				scanf("%d %d",&x,&y);
				if(x>n-1 || y>=m-1){
						printf("\n Sinirdan buyuk sayi girdiniz!:");
						goto bas1;
				}
				
				
				for(i=x;i>0;i--){
					
					if(matris[i][y]==1 || matris[i][y+1]==1){
						printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
						goto bas1; 
					}
					
				}	
				while(matris[x+1][y]==0 && matris[x+1][y+1]==0 && x<n-1){
					x++;
					
					
				}
				if(x<x1){
					x1=x;
				}
				matris[x][y]=1;
				matris[x][y+1]=1;
				puan=puan+2;
				yazdir(matris,n,m,puan);
				if(x==0){
					
					goto son;
				}
				break;
			case 2:
				hak=6;
				bas2:
				hak=hak-1;
				
				printf("\nHamle Hakkiniz:%d",hak);
				if(hak==0){
					goto son;
				}
				printf("\nBlok: \n\t \n\t[1]\n\t[1]");
				printf("90 derece dondurmek icin 1 giriniz,devam etmek icin 0 giriniz!:");
				scanf("%d",&control);
				if(control!=0 && control!= 1){
					printf("0 yada 1 giriniz!");
					goto bas2;
				}
				
				if(control==1){
					
					goto bas1;
				}	
				
				printf("\n Satir ve sutunlar 0'dan baslamaktadýr.\n Koordinatlarinizi giriniz:");
				scanf("%d %d",&x,&y);
				
				if(x>n-2 || y>m){
						printf("\n Sinirdan buyuk sayi girdiniz!:");
						goto bas2;
				}
				if(matris[x+1][y]==1){
					printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
					goto bas2;				
				}
				for(i=x;i>0;i--){
					
					if(matris[i][y]==1 ){
						printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
						goto bas2; 
					}
					
				}	
				
				while(matris[x+2][y]==0 && x<n-2){
					x++;
					
					
				}
				if(x<x1){
					x1=x;
				}
				matris[x][y]=1;
				matris[x+1][y]=1;
				puan=puan+2;
				yazdir(matris,n,m,puan);
				if(x==0){
					
					goto son;
				}
				break;
			case 3:
				hak=6;
				bas3:
				hak=hak-1;
				
				printf("\nHamle Hakkýnýz:%d",hak);
				if(hak==0){
					goto son;
				}
				printf("\nBlok:\n\t[1][1][1]");
				printf("90 derece dondurmek icin 1 giriniz,devam etmek icin 0 giriniz!:");
				scanf("%d",&control);
				if(control!=0 && control!= 1){
					printf("0 yada 1 giriniz!");
					goto bas3;
				}
				if(control==1){
					
					goto bas4;
				}
				printf("\n Satir ve sutunlar 0'dan baslamaktadýr.\n Koordinatlarinizi giriniz:");
				scanf("%d %d",&x,&y);
				if(x>n-1 || y>=m-2 ){
						printf("\n Sinirdan buyuk sayi girdiniz!:");
						goto bas3;
				}
				
			
				for(i=x;i>0;i--){
					
					if(matris[i][y]==1 || matris[i][y+1]==1 || matris[i][y+2]==1){
						printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
						goto bas3; 
					}
					
				}	
				while(matris[x+1][y]==0 && matris[x+1][y+1]==0 && matris[x+1][y+2]==0 && x<n-1){
					x++;
					
					
				}
				if(x<x1){
					x1=x;
				}
				matris[x][y]=1;
				matris[x][y+1]=1;
				matris[x][y+2]=1;
				puan=puan+2;
				yazdir(matris,n,m,puan);
				if(x==0){
					
					goto son;
				}
				break;
			case 4:
				hak=6;
				bas4:
				hak=hak-1;
				
				printf("\nHamle Hakkýnýz:%d",hak);
				if(hak==0){
					goto son;
				}
				printf("\nBlok: \n\t[1]\n\t[1]\n\t[1]");
				printf("90 derece dondurmek icin 1 giriniz,devam etmek icin 0 giriniz!:");
				scanf("%d",&control);
				if(control!=0 && control!= 1){
					printf("0 yada 1 giriniz!");
					goto bas4;
				}
				if(control==1){
					
					goto bas3;
				}
				printf("\n Satir ve sutunlar 0'dan baslamaktadýr.\n Koordinatlarinizi giriniz:");
				scanf("%d %d",&x,&y);
				if(x>n-3 || y>m){
						printf("\n Sinirdan buyuk sayi girdiniz!:");
						goto bas4;
				}
				if(matris[x+1][y]==1 || matris[x+2][y]==1){
						printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
						goto bas4; 
				}
				for(i=x;i>0;i--){
					
					if(matris[i][y]==1){
						printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
						goto bas4; 
					}
					
				}
				
				while(matris[x+3][y]==0 && x<n-3){
					x++;
					
					
				}
				matris[x][y]=1;
				matris[x+1][y]=1;
				matris[x+2][y]=1;
				puan=puan+2;
				yazdir(matris,n,m,puan);
				if(x==0){
					
					goto son;
				}
				break;	
			case 5:
				hak=6;
				bas5:
				hak=hak-1;
				
				printf("\nHamle Hakkýnýz:%d",hak);
				if(hak==0){
					goto son;
				}
				printf("\nBlok:\n\t[1][1]\n\t[1][1]");
				printf("\n Satir ve sutunlar 0'dan baslamaktadýr.\n Koordinatlarinizi giriniz:");
				scanf("%d %d",&x,&y);
				if(x>n || y>=m-1){
						printf("\n Sinirdan buyuk sayi girdiniz!:");
						goto bas5;
				}
				if( matris[x+1][y]==1 || matris[x+1][y+1]==1  ){
					printf("\nGirilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:\n");
					goto bas5;
				}
				for(i=x;i>0;i--){
					
					if(matris[i][y]==1 || matris[i][y+1]==1 ){
						printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
						goto bas5; 
					}
					
				}
				while(matris[x+2][y]==0 && matris[x+2][y+1]==0 && x<n-2){
					x++;
					
					
				}
				if(x<x1){
					x1=x;
				}
				matris[x][y]=1;
				matris[x][y+1]=1;
				matris[x+1][y]=1;
				matris[x+1][y+1]=1;
				puan=puan+2;
				yazdir(matris,n,m,puan);
				if(x==0){
					
					goto son;
				}
				break;	
			case 6:
				hak=6;
				bas6:
				hak=hak-1;
				
				printf("\nHamle Hakkýnýz:%d",hak);
				if(hak==0){
					goto son;
				}
				printf("\nBlok: \n\t[1]\n\t[1]\n\t[1][1]");
				control=0;
				printf("90 derece dondurmek icin 1 giriniz,devam etmek icin 0 girebilirsiniz:");
				scanf("%d",&control);
				if(control!=0 && control!= 1){
					printf("0 yada 1 giriniz!");
					goto bas6;
				}
				switch(control){
						
					case 0:
						don0:
						printf("\nBlok: \n\t[1][0]\n\t[1][0]\n\t[1][1]");
						printf("90 derece dondurmek icin 1 giriniz,devam etmek icin 0 girebilirsiniz:");
						scanf("%d",&control);
						if(control!=0 && control!= 1){
							printf("0 yada 1 giriniz!");
							goto don0;
						}
						if(control==1){
							
							goto don1;
							
						}
						printf("\n Satir ve sutunlar 0'dan baslamaktadýr.\n Koordinatlarinizi giriniz:");
						scanf("%d %d",&x,&y);
						if(x>n-3 || y>=m-1){
								printf("\n Sinirdan buyuk sayi girdiniz!:");
								goto don0;
						}
						if( matris[x+1][y]==1  || matris[x+2][y+1]==1 ){
							printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
							goto don0;
						}
						for(i=x;i>0;i--){
					
							if(matris[i][y]==1 || matris[i+2][y+1]==1 ){
								printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
								goto don0; 
							}
					
						}
						while(matris[x+3][y]==0 && matris[x+3][y+1]==0 && x<n-3){
							x++;
					
					
						}
						if(x<x1){
							x1=x;
						}
						matris[x][y]=1;
						matris[x+1][y]=1;
						matris[x+2][y]=1;
						matris[x+2][y+1]=1;
						puan=puan+2;
						yazdir(matris,n,m,puan);
						if(x==0){
					
							goto son;
						}
						break;
						
					
					case 1:
						don1:
						printf("\nBlok: \n\t[1][1][1]\n\t[1][ ][ ]");
						printf("90 derece dondurmek icin 1 giriniz,devam etmek icin 0 girebilirsiniz:");
						scanf("%d",&control);
						if(control!=0 && control!= 1){
							printf("0 yada 1 giriniz!");
							goto don1;
						}
						if(control==1){
							
							goto don2;
							
						}
						printf("\n Satir ve sutunlar 0'dan baslamaktadýr.\n Koordinatlarinizi giriniz:");
						scanf("%d %d",&x,&y);
						if(x>n-2 || y>=m-2){
								printf("\n Sinirdan buyuk sayi girdiniz!:");
								goto don1;
						}
						if(matris[x+1][y]==1   ){
							printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
							goto don1;
						}
						for(i=x;i>0;i--){
					
							if(matris[i][y]==1 || matris[i][y+1]==1 || matris[i][y+2] ){
								printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
								goto don1; 
							}
					
						}
						while(matris[x+2][y]==0 && matris[x+1][y+1]==0 && matris[x+1][y+2]==0 && x<n-2){
							x++;
					
						}
						if(x<x1){
							x1=x;
						}
						matris[x][y]=1;
						matris[x][y+1]=1;
						matris[x+1][y]=1;
						matris[x][y+2]=1;
						puan=puan+2;
						yazdir(matris,n,m,puan);
						if(x==0){
					
							goto son;
						}
						break;
					case 2:
						don2:
						printf("\nBlok: \n\t[1][1]\n\t[0][1]\n\t[0][1]");
						printf("90 derece dondurmek icin 1 giriniz,devam etmek icin 0 girebilirsiniz:");
						scanf("%d",&control);
						if(control!=0 && control!= 1){
							printf("0 yada 1 giriniz!");
							goto don2;
						}
						if(control==1){
							
							goto don3;
							
						}
						printf("\n Satir ve sutunlar 0'dan baslamaktadýr.\n Koordinatlarinizi giriniz:");
						scanf("%d %d",&x,&y);
						if(x>n-3 || y>=m-1){
								printf("\n Sinirdan buyuk sayi girdiniz!:");
								goto don2;
						}
						if( matris[x+1][y+1]==1 || matris[x+2][y+1]==1  ){
							printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
							goto don2;
						}
						for(i=x;i>0;i--){
					
							if(matris[i][y]==1 || matris[i][y+1]==1 ){
								printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
								goto don2; 
							}
					
						}
						while(matris[x+1][y]==0 && matris[x+3][y+1]==0 && x<n-3){
							x++;
					
						}
						if(x<x1){
							x1=x;
						}
						matris[x][y]=1;
						matris[x][y+1]=1;
						matris[x+1][y+1]=1;
						matris[x+2][y+1]=1;
						puan=puan+2;
						yazdir(matris,n,m,puan);
						if(x==0){
					
							goto son;
						}
						break;
						
					case 3:
						don3:
						printf("\nBlok: \n\t[1][0][0]\n\t[1][1][1]");
						printf("90 derece dondurmek icin 1 giriniz,devam etmek icin 0 girebilirsiniz:");
						scanf("%d",&control);
						if(control!=0 && control!= 1){
							printf("0 yada 1 giriniz!");
							goto don3;
						}
						if(control==1){
							
							goto don0;
							
						}
						printf("\n Satir ve sutunlar 0'dan baslamaktadýr.\n Koordinatlarinizi giriniz:");
						scanf("%d %d",&x,&y);
						if(x>n-2 || y>=m-2){
								printf("\n Sinirdan buyuk sayi girdiniz!:");
								goto don3;
						}
						if(matris[x+1][y]==1  ){
							printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
							goto don3;
						}
						for(i=x;i>0;i--){
					
							if(matris[i][y]==1 || matris[i+1][y+1]==1 || matris[i+1][y+2]==1){
								printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
								goto don3; 
							}
					
						}
						while(matris[x+2][y]==0 && matris[x+2][y+1]==0 && matris[x+2][y+2] && x<n-2){
							x++;
					
						}
						if(x<x1){
							x1=x;
						}
						matris[x][y]=1;
						matris[x+1][y]=1;
						matris[x+1][y+1]=1;
						matris[x+1][y+2]=1;
						puan=puan+2;
						yazdir(matris,n,m,puan);
						if(x==0){
					
							goto son;
						}
						break;
						
						
				}
				break;
				
			case 7:
				hak=6;
				bas7:
				hak=hak-1;
				
				printf("\nHamle Hakkiniz:%d",hak);
				if(hak==0){
					goto son;
				}
				printf("\nBlok: \n\t[ ][1][1]\n\t[1][1][ ]");
				control=0;
				printf("90 derece dondurmek icin 1 giriniz,devam etmek icin 0 girebilirsiniz:");
				scanf("%d",&control);
				if(control!=0 && control!= 1){
					printf("0 yada 1 giriniz!");
					goto bas7;
				}
				switch(control){
					case 0:
						don4:
						printf("\nBlok: \n\t[ ][1][1]\n\t[1][1][ ]");
						printf("90 derece dondurmek icin 1 giriniz,devam etmek icin 0 girebilirsiniz:");
						scanf("%d",&control);
						if(control!=0 && control!= 1){
							printf("0 yada 1 giriniz!");
							goto don4;
						}
						if(control==1){
							
							goto don5;
							
						}
						
						printf("\n Satir ve sutunlar 0'dan baslamaktadýr.\n Koordinatlarinizi giriniz:");
						scanf("%d %d",&x,&y);
						
						if(x>n-2 || y>m-2 || y==0){
						
								printf("\n Sinirdan buyuk sayi girdiniz!:");
								goto don4;
						}
						if(  matris[x+1][y]  ){
							printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
						
							goto don4;
						}
						for(i=x;i>0;i--){
					
							if(matris[i][y]==1 || matris[i][y+1]==1 || matris[x+1][y-1]==1 ){
								printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
								goto don4; 
							}
					
						}
						while(matris[x+2][y]==0 && matris[x+2][y-1]==0 && matris[x+1][y+1]==0 && x<n-2){
							x++;
						}
						if(x<x1){
							x1=x;
						}
						matris[x][y]=1;
						matris[x][y+1]=1;
						matris[x+1][y]=1;
						matris[x+1][y-1]=1;
						puan=puan+2;
						yazdir(matris,n,m,puan);
						if(x==0){
					
							goto son;
						}
						break;
					case 1:
						don5:
						printf("\nBlok: \n\t[1][0]\n\t[1][1]\n\t[ ][1]");
						printf("90 derece dondurmek icin 1 giriniz,devam etmek icin 0 girebilirsiniz:");
						scanf("%d",&control);
						if(control!=0 && control!= 1){
							printf("0 yada 1 giriniz!");
							goto don5;
						}
						if(control==1){
							
							goto don4;
							
						}
						
						printf("\n Satir ve sutunlar 0'dan baslamaktadýr.\n Koordinatlarinizi giriniz:");
						scanf("%d %d",&x,&y);
						if(x>n-3 || y>m-2){
						
								printf("\n Sinirdan buyuk sayi girdiniz!:");
								goto don5;
						}
						if( matris[x+1][y]==1 || matris[x+2][y+1]==1 ){
							printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
							
							goto don5;
							
						}
						for(i=x;i>0;i--){
					
							if(matris[i][y]==1 || matris[i+1][y+1]==1 ){
								printf("Girilen koordinatlar blok icin uygun degil,lutfen tekrar deneyiniz:");
								goto don5; 
							}
					
						}
						while(matris[x+3][y+1]==0 && matris[x+2][y]==0 && x<n-3){
							x++;
						}
						if(x<x1){
							x1=x;
						}
						matris[x][y]=1;
						matris[x+1][y]=1;
						matris[x+1][y+1]=1;
						matris[x+2][y+1]=1;
						puan=puan+2;
						yazdir(matris,n,m,puan);
						if(x==0){
					
							goto son;
						}
						break;
					
					
					
				}
				
					
			default:
				
				break;
	 	}
	}
	son:
		printf("\n\tGAME OVER\n\tPUANINIZ:%d",puan);
	return 0;
}
