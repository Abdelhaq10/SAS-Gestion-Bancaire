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
        void isExist(compte c[],int count)
        {
             int found = 1;// is not exist
             char cin[25];
	     do{
                found = 1;
                printf("Enter your CIN : \t");
            scanf("%s",cin);

            for(int x = 0; x < count; x++){

            if(strcmp(cin,c[x].cin) == 0){
                found = 0;//is existe
         printf("Already exists \n");
         break;
            }
            }
	     }while(found == 0);

	     strcpy(c[count].cin, cin);
	      printf("count %d\t %s\n",count,c[count].cin);
        }

	 //Method for add sole account bancaire
	 void createCompte(compte c[])
	 {

                isExist(c,count);

			 	printf("Enter your name : \t");
			 	scanf("%s",c[count].nom);
			 	printf("Enter your last name : \t");
			 	scanf("%s",c[count].pnom);
			 	printf("Enter montant : \t");
			 	scanf("%f",&c[count].montant);
			 	count++;
	 }
	  //Method for add many accounts bancaire
	 void multiComptes(compte c[])
	 {
	 	int i,n;
	 	printf("Enter the number of comptes that you want to create please !! \n");
	 	scanf("%d",&n);

	 	for(i=0;i<n;i++)
	 	{
                int index = i + count;
                char cin[10];
                isExist(c,index);

			 	printf("Enter your name : \t");
			 	scanf("%s",c[index].nom);
			 	printf("Enter your last name : \t");
			 	scanf("%s",c[index].pnom);
			 	printf("Enter montant : \t");
			 	scanf("%f",&c[index].montant);

		 }
		 	count+=n;
	 }
	 //Create method for operation "Retrait / Depot"
	 void operation(compte c[])
	 {
	 	float withdraw,deposit;
	 	int i,exist=0,pos;
	 	char cin[10],choice[10];
	 	printf("\t \t \t Do u want to Retrait / Depot :  \t");
	 	scanf("%s",choice);
	 	if(stricmp(choice,"retrait")==0)
	 	{
	 	printf("Enter your cin please \n");
	 	scanf("%s",cin);
	 	printf("\t \t \t How much money do you want to retire?\n");
	 	scanf("%f",&withdraw);
	 	for(i=0;i<count;i++)
	 	{

	 		if(stricmp(c[i].cin,cin)==0)
	 		{
                pos=i;
	 			exist=1;
	 			break;
			 }
		 }
            if(exist==0)
			 {
			 printf("Error account doesn't exist !!\n'");
			 }
			 else
             {
                 if(c[pos].montant>=withdraw)
                 {
                      c[pos].montant-=withdraw;
                 }
                else{
                     printf("The money you want to withdraw is bigger then the money in your account \n");
                }
             }
		 }
		 else if(stricmp(choice,"depot")==0)
	 	{
	 	printf("Enter your cin please \n");
	 	scanf("%s",cin);
	 	printf("\t \t \t How much money do you want to deposit ?\n");
	 	scanf("%f",&deposit);

	 	for(i=0;i<count;i++)
	 	{

	 		if(strcmp(c[i].cin,cin)==0)
	 		{
                pos=i;
	 			exist=1;
	 			break;
            }
        }

		 }

		  if(exist==0)
			 {
			 printf("Error account doesn't exist !!\n'");
			 }
			 else
             {
                 if(deposit>=0)
                 {
                      c[pos].montant+=deposit;
                 }
                else{
                     printf("The money you want to deposit is less then zero \n");
                }
             }
		 }

		 //Methods of Sort
		 //Sort ascendant
		 void Sort_Ascendant(compte c[])
	 {
	     int i;
	     compte tmp;
	     for(i=0;i<count;i++)
     {

         for(int j=i+1;j<count;j++)
         {
             if(c[i].montant>c[j].montant)
             {
             tmp=c[i];
             c[i]=c[j];
             c[j]=tmp;
             }

         }
	 }
	 printf("%d \n",count);
	 for(i=0;i<count;i++)
	 	{
	 		printf("CIN: %s\t Nom :  %s\t Prenom : %s\t Montant : %.2f \n",c[i].cin,c[i].nom,c[i].pnom,c[i].montant);
        }
	 }
	 //Sort descendant
	 	 void Sort_Descendant(compte c[])
	 {
	     int i;
	     compte tmp;
	     for(i=0;i<count;i++)
     {

         for(int j=i+1;j<count;j++)
         {
             if(c[i].montant<c[j].montant)
             {
             tmp=c[i];
             c[i]=c[j];
             c[j]=tmp;
             }

         }
	 }
	 for(i=0;i<count;i++)
	 	{
	 		printf("CIN: %s\t Nom :  %s\t Prenom : %s\t Montant : %.2f \n",c[i].cin,c[i].nom,c[i].pnom,c[i].montant);
        }
	 }
	 //Sort ascendant from value
	 void Sort_AscendantVal(compte c[])
{
    int i,pos;
    float chiffre;
    compte tmp;

         for(i=0;i<count;i++)
         {
        for(int j=i+1;j<count;j++)
         {
             if(c[i].montant>c[j].montant)
             {
             tmp=c[i];
             c[i]=c[j];
             c[j]=tmp;
             }
         }
         }
         printf("Enter montant introduit : \t");
         scanf("%f",&chiffre);
     for(i=0;i<count;i++)
     {
            if(c[i].montant==chiffre)
             {
                 pos=i;
             }
         }
        for(i=pos;i<count;i++)
        {
           printf("CIN: %s\t Nom :  %s\t Prenom : %s\t Montant : %.2f \n",c[i].cin,c[i].nom,c[i].pnom,c[i].montant);
        }

     }
      //Sort Descendant from value
	 void Sort_DescendantVal(compte c[])
{
    int i,pos;
    float chiffre;
    compte tmp;

         for(i=0;i<count;i++)
         {
        for(int j=i+1;j<count;j++)
         {
             if(c[i].montant>c[j].montant)
             {
             tmp=c[i];
             c[i]=c[j];
             c[j]=tmp;
             }
         }
         }
         printf("Enter montant introduit : \t");
         scanf("%f",&chiffre);
     for(i=0;i<count;i++)
     {
            if(c[i].montant==chiffre)
             {
                 pos=i;
             }
         }
        for(i=count-1;i>=pos;i--)
        {
           printf("CIN: %s\t Nom :  %s\t Prenom : %s\t Montant : %.2f \n",c[i].cin,c[i].nom,c[i].pnom,c[i].montant);
        }

     }
	 void affichage(compte c[])
	 {
//	     int i;
//	     printf("count : %d\n",count);
//	     for(i=0;i<count;i++)
//	 	{
//	 		printf("CIN: %s\t Nom :  %s\t Prenom : %s\t Montant : %.2f \n",c[i].cin,c[i].nom,c[i].pnom,c[i].montant);
//        }
	     char choice[10];
        printf("\t \t \t asce: Ascendant sort\n");
        printf("\t \t \t dsce : Descendant sort\n");
        printf("\t \t \t asceval : Ascendant sort from value\n");
        printf("\t \t \t dsceval : Descendant sort from value\n");
	 	scanf("%s",choice);
        if(stricmp(choice,"asce")==0)
        {
            for(int i=0;i<count;i++)
         {
             printf("cin : %s\n",c[i].cin);
         }
            Sort_Ascendant(c);
        }
	 	else if(stricmp(choice,"dsce")==0)
        {
            Sort_Descendant(c);
        }
        else if(stricmp(choice,"asceval")==0)
        {
            Sort_AscendantVal(c);
        }
        else if(stricmp(choice,"dsceval")==0)
        {
            Sort_DescendantVal(c);
        }
    }
    //method of search
    void recherche(compte c[])
    {
        int exist=0,pos;
        char cin[10];
        printf("\t \t \tEnter your CIN please \n");
	 	scanf("%s",cin);
	 	for(int i=0;i<count;i++)
        {
            	 	if(stricmp(c[i].cin,cin)==0)
	 		{
                pos=i;
	 			exist=1;
	 			break;
                }
        }
    if(exist==1)
       {
            printf("CIN : %s\t Name :  %s\t Lname : %s\t Montant : %.2f \n",c[pos].cin,c[pos].nom,c[pos].pnom,c[pos].montant);
       }
       else{
        printf("the account is doesn't exist !!!\n");
       }
    }
    //Method Fidelisation
    void fidelisation(compte c[])
    {
         int i;
	     compte tmp;
	     for(i=0;i<count;i++)
     {

         for(int j=i+1;j<count;j++)
         {
             if(c[i].montant<c[j].montant)
             {
             tmp=c[i];
             c[i]=c[j];
             c[j]=tmp;
             }

         }
	 }
	 for(i=0;i<3;i++)
     {
         c[i].montant+=(c[i].montant * 1.3)/100;
         printf("CIN: %s\t Nom :  %s\t Prenom : %s\t Montant : %.2f \n",c[i].cin,c[i].nom,c[i].pnom,c[i].montant);
     }
    }
    void quitter()
    {
        exit(0);
    }

	 int main()
{

	int choix;
	compte c[100];
	do
	{		printf("\t \t \t \t ***MENU*** \n");
			printf("\t \t \t 1: Create compte bancaire \n");
			printf("\t \t \t 2: Create plusieurs comptes bancaires \n");
			printf("\t \t \t 3: Operations \n");
			printf("\t \t \t 4: Affichage \n");
			printf("\t \t \t 5: Recheche \n");
			printf("\t \t \t 6: Fidelisation \n");
			printf("\t \t \t 7: Quitter l’application \n");
			printf("\t \t \t Enter your choix please : \t");
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
            case 5 :
                recherche(c);
                break;
            case 6 :
                fidelisation(c);
                break;
            case 7 :
                quitter();
		}
	}while(choix!=8);

}




