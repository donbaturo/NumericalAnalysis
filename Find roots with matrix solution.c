#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
	int k,l,i,d,ensatir,turn=0,flag=0;
	float A[100][100],control,en,B[2][100],j;
	double hata;
	printf("kac degisken var:");
	scanf("%d",&d);
	for(k=1;k<=d;k++){
		for(l=1;l<=d+1;l++){
			if(l<=d){
				printf("\nx%d'in katsayisi:",l);
				scanf("%f",&A[k][l]);
			}
			else{
				printf("\nesitligin sag tarafindaki sabit sayi:");
				scanf("%f",&A[k][l]);
			}
		}
	}
	printf("\nHata Payini giriniz:");
	scanf("%lf",&hata);
	for(k=1;k<=d;k++){
		en=A[1][k];
		ensatir=1;
		for(l=2;l<=d;l++){
			if(A[l][k]>en){
				en=A[l][k];
				ensatir=l;
			}
		}
		for(l=1;l<=d+1;l++){
			A[ensatir][l]=A[ensatir][l]/en;
		}
	}
	for(k=1;k<=d;k++){
		B[1][k]=1;
		B[2][k]=1;
	}
	while(flag==0){
		control=0;
		for(k=1;k<=d;k++){
			j=(B[1][k]-B[2][k]);
			if(j<0){
				j=j*(-1);
			}
			if(j<=hata&&turn>0){
				control++;
			}
		}
		if(control==d){
			flag=1;
		}
		else{
			for(i=1;i<=d;i++){
				for(k=1;k<=d;k++){
					if(A[k][i]==1){
						B[2][i]=B[1][i];
						B[1][i]=A[k][d+1];
						for(l=1;l<=d;l++){
							if(l!=i){
								B[1][i]=B[1][i]-(A[k][l]*B[1][l]);
							}
						}
						k=4;
					}
				}
			}
		}
		turn++;
	}
	for(k=1;k<=d;k++){
		printf("\nx%d=%f",k,B[1][k]);
	}
	return 0;
}
