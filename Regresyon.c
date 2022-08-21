#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
	int d,k,l,n,flag=0,tablo=1;
	double Nokta[100][100],x,S,temp,h,function;
	printf("Kac nokta girisi yapacaksin:");
	scanf("%d",&d);
	for(k=0;k<d;k++){
		printf("X:");
		scanf("%lf",&Nokta[k][0]);
		printf("Y:");
		scanf("%lf",&Nokta[k][1]);
	}
	h=Nokta[1][0]-Nokta[0][0];
	n=d;
	while(flag!=n-1){
		tablo++;
		for(k=0;k<n;k++){
			Nokta[k][tablo]=Nokta[k+1][tablo-1]-Nokta[k][tablo-1];
		}
		flag=0;
		for(k=0;k<n-1;k++){
			if(Nokta[k][tablo]==Nokta[k+1][tablo]){
				flag++;
			}
		}
		n--;
	}
	printf("\nBulmak istediginiz x noktasi:");
	scanf("%lf",&x);
	S=Nokta[0][1]+(Nokta[0][2]*(x-Nokta[0][0])/h);
	for(k=3;k<=tablo;k++){
		function=1;
		for(l=1;l<k;l++){
			function=function*l;
		}
		temp=1;
		for(l=0;l<k-1;l++){
			temp=temp*(x-(h*l+Nokta[0][0]));
		}
		temp=(temp*Nokta[0][k])/(function*pow(h,(k-1)));
		S=S+temp;
	}
	printf("\nSonuc:%lf",S);
	return 0;
}
