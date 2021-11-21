#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declare un countour global to increase the size of comptes table 
int  count=0;
//Declare struct Compte
typedef struct
	 {
		char cin[8];
		char nom[15];
		char pnom[15];
		float montant;
	 }compte;
	 //Methode for add sole compte bancaire
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
	  //Methode for add many compte bancaire
	 void multiComptes(compte c[])
	 {
	 	int i,n;
	 	printf("Enter the number of comptes that you want to create please !! \n");
	 	scanf("%d",&n);
	 	for(i=count;i<n+count;i++)
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
	 //Create methode for operation "Retrait / Depot"
	 void operation(compte c[])
	 {
	 	float withdraw,deposit;
	 	int i,choice,exist=0;
	 	char cin[10];
	 	printf("\t \t \t Click 1 to Retrait / 2 to Depot \n");
	 	scanf("%d",&choice);
	 	if(choice==1)
	 	{ 
	 	printf("Enter your cin please \n");
	 	scanf("%s",cin);
	 	printf("\t \t \t How much money do you want to retire?\n");
	 	scanf("%f",&withdraw);
	 	for(i=0;i<count;i++)
	 	{
	 		if(strcmp(c[i].cin,cin)==0)
	 		{
	 			exist=1;
			 }
			 
		 }
		 if(exist==1)
		 {
		 		c[i].montant-=withdraw;
		 }
		 else 
			 { 
			 printf("Error account doesn't exist !!\n'");
			 
			 }
		 }
		 else if(choice==2)
	 	{ 
	 	printf("Enter your cin please \n");
	 	scanf("%s",cin);
	 	printf("\t \t \t How much money do you want to deposit ?\n");
	 	scanf("%f",&deposit);
	 	for(i=0;i<count;i++)
	 	{
	 		if(strcmp(c[i].cin,cin)==0)
	 		{
	 			exist=1;
			 }
			
		 }
		 if(exist==1)
		 {
		 		c[i].montant+=deposit;
		 }
		  { 
			 printf("Error account doesn't exist !!\n'");
		
			 }
		 }
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
			case 3:
				operation(c);
				break;
			case 4 :
				affichage(c);
				break;
		}
	}while(choix!=5);

}




