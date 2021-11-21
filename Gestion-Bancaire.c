#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declare struct Compte
int  count=0;
typedef struct
	 {
		char cin[8];
		char nom[15];
		char pnom[15];
		float montant;
	 }compte;
	 void createCompte(compte c[])
	 {
	 	
				printf("Enter your CIN : \t");
			 	scanf("%s",c[count].cin);
			 	printf("Enter your name : \t");
			 	scanf("%s",c[count].nom);
			 	printf("Enter your last name : \t");
			 	scanf("%s",c[count].pnom);
			 	printf("Enter montant : \t");
			 	scanf("%f",&c[count].montant);
			 	count++;
	 	
	 	
	 }
	 void multiComptes(compte c[])
	 {
	 	int i,n;
	 	printf("Enter the number og comptes that you want to create please !! \n");
	 	scanf("%d",&n);
	 	for(i=count;i<=count+n;i++)
	 	{
	 			printf("Enter your CIN : \t");
			 	scanf("%s",c[i].cin);
			 	printf("Enter your name : \t");
			 	scanf("%s",c[i].nom);
			 	printf("Enter your last name : \t");
			 	scanf("%s",c[i].pnom);
			 	printf("Enter montant : \t");
			 	scanf("%f",&c[count].montant);
		 }
		 count+=n;
	 }
	 void affichage(compte c[])
	 {
	 
	 	printf("%d",count);
	 	int i;
	 	for(i=0;i<count;i++)
	 	{
	 		printf("%s\t %s\t %s\t %f \n",c[i].cin,c[i].nom,c[i].pnom,c[i].montant);
		 }
	 }
	 
	 int main()
{
	
	int choix;
	compte c[100];
	do
	{		printf("\t \t \t ***MENU*** \n");
			printf("\t \t \t 1: Create compte bancaire \n");
			printf("\t \t \t 2: Create plusieurs comptes bancaires \n");
			printf("\t \t \t 3: Operations \n");
			printf("\t \t \t 4: Affichage \n");
			printf("\t \t \t Enter your choix pls : \n");
			scanf("%d",&choix);
		switch(choix)
		{
			case 1:
			 createCompte(c);
			break;
			case 2 : 
			multiComptes(c);
			break;
			case 4 :
				affichage(c);
		}
	}while(choix!=5);

}




