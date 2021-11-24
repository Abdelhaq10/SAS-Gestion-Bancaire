#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declare un countour global to increase the size of comptes table
int  count=0;
//Declare struct Compte
typedef struct
	 {
		char cin[8];
		char name[15];
		char lname[15];
		float montant;
	 }compte;
        void isExist(compte c[],int count)
        {
             int found = 1;// is not exist
             char cin[25];
	     do{
                found = 1;
                printf("\t \t \t Enter Your CIN : \t");
                scanf("%s",cin);

            for(int x = 0; x < count; x++)
                {
                    if(strcmp(cin,c[x].cin) == 0)
                    {
                        found = 0;//is exist
                         printf("\t \t \t \t [ERROR] Already Exists \n");
                         break;
                    }
                }
	       }while(found == 0);
	     strcpy(c[count].cin, cin);
        }
	 //Method for add sole account bancaire
	 void createCompte(compte c[])
	 {
                 printf("\n");
                printf("\t \t \t **************** ACCOUNT N%d : ***************\n",count+1);
                printf("\t \t \t_______________________________________________\n");
                isExist(c,count);
			 	printf("\t \t \t Enter Your Name : \t");
			 	scanf("%s",c[count].name);
			 	printf("\t \t \t Enter Your Last Name : \t");
			 	scanf("%s",c[count].lname);
			 	printf("\t \t \t Enter Montant : \t");
			 	scanf("%f",&c[count].montant);
			 	count++;
			 	system("cls");
	 }
	  //Method for add many accounts bancaire
	 void multiComptes(compte c[])
	 {
	 	int i,n;
	 	printf("\t \t \t How Many Accounts Do You Want To Create ? \t");
	 	scanf("%d",&n);
	 	system("cls");
	 	for(i=0;i<n;i++)
	 	{
                 int index = i + count;
                printf("\n");
                printf("\t \t \t **************** ACCOUNT N%d : ***************\n",index+1);
                printf("\t \t \t_______________________________________________\n");
                char cin[10];
                isExist(c,index);
			 	printf("\t \t \t Enter Your Name : \t");
			 	scanf("%s",c[index].name);
			 	printf("\t \t \t Enter Your Last Name : \t");
			 	scanf("%s",c[index].lname);
			 	printf("\t \t \t Enter Montant : \t");
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
	 	printf("\t \t \t Do You Want To Withdraw / Depot :  \t");
	 	scanf("%s",choice);
	 	if(stricmp(choice,"withdraw")==0)
	 	{
	 	printf("\t \t \t Enter Your CIN Please \t");
	 	scanf("%s",cin);
	 	printf("\t \t \t How Much Money Do You Want To Retire?\t");
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
                printf("\t \t \t Error Account Doesn't Exist !!\n'");
			 }
			 else
             {
                 if(c[pos].montant>=withdraw)
                 {
                      c[pos].montant-=withdraw;
                 }
                else{
                     printf("\t \t \t The Money That You Want To Withdraw Is More Than Your Account Balance \n");
                }
             }
		 }
		 else if(stricmp(choice,"depot")==0)
	 	{
	 	printf("\t \t \t Enter Your CIN Please \t");
	 	scanf("%s",cin);
	 	printf("\t \t \t How Much Money Do You Want To Deposit ?\t");
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
        if(exist==0)
			 {

			 printf("\t \t \t Error Account Doesn't Exist !!\n'");
			 }
			 else
             {
                 if(deposit>=0)
                 {
                      c[pos].montant+=deposit;
                 }
                else{
                     printf("\t \t \t The Money You Want To Deposit Is Less Then Zero \n");
                }
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
        int index=i;
         for(int j=i+1;j<count;j++)
         {
             if(c[i].montant>c[j].montant)
             {
             tmp=c[i];
             c[i]=c[j];
             c[j]=tmp;
             }
             if(index != i)
             {

             }
         }
	 }
	 for(i=0;i<count;i++)
	 	{
	 		printf("\t \t \t CIN: %s\t Name :  %s\t Lname : %s\t Montant : %.2f DH \n",c[i].cin,c[i].name,c[i].lname,c[i].montant);
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
	 		printf("\t \t \t CIN: %s\t Name :  %s\t Lname : %s\t Montant : %.2f DH \n",c[i].cin,c[i].name,c[i].lname,c[i].montant);
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
         printf("\t \t \t Enter Amount Introduced : \t");
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
           printf("\t \t \t CIN: %s\t Name :  %s\t Lname : %s\t Montant : %.2f DH \n",c[i].cin,c[i].name,c[i].lname,c[i].montant);
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
         printf("\t \t \t Enter Amount Introduced : \t");
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
           printf("\t \t \t CIN: %s\t Name :  %s\t Lname : %s\t Montant : %.2f DH \n",c[i].cin,c[i].name,c[i].lname,c[i].montant);
        }
     }
	 void affichage(compte c[])
	 {
	     char choice[10];
        printf("\t \t \t up: Ascendant sort\n");
        printf("\t \t \t down : Descendant sort\n");
        printf("\t \t \t asce: Ascendant sort from value\n");
        printf("\t \t \t dsce : Descendant sort from value\n");
	 	printf("\t \t \t Sort By : ");
	 	scanf("%s",choice);
	 	printf("\n");
        if(stricmp(choice,"up")==0)
        {
            Sort_Ascendant(c);
        }
	 	else if(stricmp(choice,"down")==0)
        {
            Sort_Descendant(c);
        }
        else if(stricmp(choice,"asce")==0)
        {
            Sort_AscendantVal(c);
        }
        else if(stricmp(choice,"dsce")==0)
        {
            Sort_DescendantVal(c);
        }
    }
    //method of search
    void recherche(compte c[])
    {
        int exist=0,pos;
        char cin[10];
        printf("\t \t \t Enter Your CIN please : \t");
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
            printf("\t \t \t CIN : %s\t Name :  %s\t Lname : %s\t Montant : %.2f DH \n",c[pos].cin,c[pos].name,c[pos].lname,c[pos].montant);
       }
       else{
        printf("\t \t \t The Account Is Doesn't Exist !!!\n");
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
         printf("\t \t \t CIN: %s\t Name :  %s\t Lname : %s\t Montant : %.2f DH \n",c[i].cin,c[i].name,c[i].lname,c[i].montant);
     }
    }
    void quitter()
    {
        char choice[3];
        printf("\t \t \t The System Well Shut Down Do You Want To Quit ?   (yes/no) \t");
        scanf("%s",choice);

	 	printf("\n");
	 	if(stricmp(choice,"yes")==0)
        exit(0);
    }

	 int main()
{

	int option;
	compte c[100];
	do
	{
            printf("\n");
            printf("\t \t \t **********************MENU******************** \n");
            printf("\t \t \t ______________________________________________\n");
            printf("\n");
			printf("\t \t \t 1: Create Bank Account \n");
			printf("\t \t \t 2: Create Multiple Bank Accounts \n");
			printf("\t \t \t 3: Operations \n");
			printf("\t \t \t 4: Display \n");
			printf("\t \t \t 5: Research \n");
			printf("\t \t \t 6: Fidelisation \n");
			printf("\t \t \t 7: Clean  \n");
			printf("\t \t \t 8: Quit  \n");
			printf("\t \t \t ______________________________________________\n");
            printf("\n");
			printf("\t \t \t Enter Your Option Please : \t");
			scanf("%d",&option);
			//system("cls");
		switch(option)
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
                system("cls");
                break;
            case 8 :
                quitter();
                break;
		}
	}while(option!=9);
}
