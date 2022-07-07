#include<stdio.h>
#include<stdlib.h>

void reserver_chambre();
void liste_client();
void chercher_client();
void supprimer_client();
void Modifier_client();

struct client{
    char CIN[50];
    char nom[50];
    char prenom[50];
    char adresse[50];
    char email[50];
    char tel[50];
    char periode[10];
    char datereservation[10];
    char num_chambre[10];
};
struct client client;//initialisation de structure

// Fonction principale : main
int main(){
	int i=0;


	char customername;
	char choice;

	system("cls");// effacer tout ce qu'il y a à l'écran


 	printf("\t\t*****************\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*        WELCOME TO AL HOCEIMA HOTEL            *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                AL-HOUCEIMA ,MAROC             *\n");
	printf("\t\t*  CONTACTEZ NOUS:HOUCEIMA@GMAIL.COM,0635953128 *\n");
    printf("\t\t*                                               *\n");
	printf("\t\t*****************\n\n\n");

	printf(" \n APPUYER ENTRER POUR CONSULTER MENU :");
	getch();
system("cls");

system("cls");

	while (1)// permet de reserver successivement
	{
		system("cls");

		 for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("   **********  |MAIN MENU|  *********** \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");

		printf("\t\t *SAISIR VOTRE CHOIX *:");
		printf("\n\n");
		printf(" \n Entrer 1 .................................. Reserver chambre");
		printf("\n");
		printf(" \n Entrer 2 .................................. consulter liste des clients enregistrer");
		printf("\n");
		printf(" \n Entrer 3 ................................... rechercher client ");
		printf("\n");
		printf(" \n Entrer 4 ....................................supprimer client");
		printf("\n");
		printf(" \n Entrer 5 ....................................Modifier les informations de client");
		printf("\n");

		printf("\n");

     printf("votre  choix :");
		choice=getche();

		switch(choice)
		{
		    case '1':
				reserver_chambre();break;
               case '2':
				liste_client();break;
               case '3':
            chercher_client();
                break;
                   case '4':
                supprimer_client();
                break;
                case '5':
               Modifier_client();
                break;
			default:
				system("cls");
				printf("choix invalide");
				printf("\n cliquer pour retour");
				getch();
		}
	}

}


// Reservation
void reserver_chambre(){

    system("cls");
    FILE *f;
	char test;// sortir de boucle
	f=fopen("ress.txt","a+");//ouverture du fichier texte en lecture et écriture à la fin
	if(f==0)
	{   f=fopen("ress.txt","w+"); //ouverture du fichier texte en lecture/écriture
		system("cls");
		getch();
	}
    int i=2,N; // i=2 car on commence de client i-1


while(1){

    printf("entrer les informations de client N° %d :",i-1);
    	printf("\n Entrer numero du chambre:\n");
        scanf("\n%s",client.num_chambre);
		fflush(stdin);
		printf("Entrer le nom du client:\n");
		gets(client.nom);
		printf("Entrer le cin du client:\n");
		gets(client.CIN);
		printf("Entrer Address:\n");
		gets(client.adresse);
		printf("Entrer numero telephone:\n");
		scanf("%s",client.tel);
		printf("Entrer Email:\n");
		scanf(" %s",client.email);
		printf("Entrer Period(\'x\'jours):\n");
		scanf("%s",&client.periode);
		printf("Enter date reservation(jj\\mm\\aaaa):\n");
		scanf("%s",&client.datereservation);
		fwrite(&client,sizeof(client),1,f);
		fflush(stdin);//permet de forcer explicitement la synchronisation
		printf("\n\vous avez bien reservez votre chambre!!!");
		printf("\n cliqurz sur entrer pour reservez autre chambre , esc pour retour au menu");
		 i++;
		test=getche();//esc
		  system("cls");
		if(test==27)
			break;
}


	fclose(f);


}


//liste des clients Enregistrès
void liste_client()
{

struct    client client;
	FILE *f;
	int i;
	if((f=fopen("ress.txt","r"))==NULL)
		exit(0);

	system("cls");
	printf("chambre    ");
	printf(" \ NOM\t ");
	printf("CIN\t ");
	printf("\tADDRESS ");
	printf(" \t TELEPHONE ");
	printf("\tEMAIL ");
	printf("\t\t  PERIODE ");
	printf("\t DATERESERVATION \n");

	for(i=0;i<118;i++)
		printf("-");
	while(fread(&client,sizeof(client),1,f)==1)
	{

		printf("\n%s  \t    %s \t\%s \t\t%s \t    %s \t%s\t \t  %s  \t \t    %s  \t     "      , client.num_chambre,client.nom ,client.CIN, client.adresse , client.tel  ,client.email,client.periode,  client.datereservation);
	}
	printf("\n");
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);
	getch();
}



// chercher un client
void chercher_client()
{
    struct client client;
system("cls");
	FILE *f;
	char cin[20];
	int testDeTrouve=1;
	f=fopen("ress.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Entrer CIN du client : \n");
	scanf("%s", cin);

	while(fread(&client,sizeof(client),1,f)==1)
	{
		if(strcmp(client.CIN,cin)==0){
			testDeTrouve=0;
			printf("\n\t  client trouvee\n ");
			printf("\nNumero du chambre   :\t%s",client.CIN);
			printf("\nNOM                 :\t%s",client.nom);
			printf("\nAddress             :\t%s",client.adresse);
			printf("\nTelephone           :\t%s",client.tel);
			printf("\nEmail               :\t%s",client.email);
			printf("\nPeriode             :\t%s",client.periode);
			printf("\nDate de Reservation :\t%s",client.datereservation);
			break;

		}
	}
	if(testDeTrouve==1){
		printf("\n\tDesole! Client Introuvable!");
	}
	getch();
	fclose(f);
}



// Supprimer un client
void supprimer_client()
{
    struct client client;
	FILE *f,*t;
	int i=1;
	char cin[20];
		if((t=fopen("tmp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("ress.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("entrer le CIN du client pour le spprimer : \n");
	fflush(stdin);
	scanf("%s",cin);
	while(fread(&client,sizeof(client),1,f)==1)
	{
		if(strcmp(client.CIN,cin)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&client,sizeof(client),1,t);
	}
	if(i==1)
	{
		printf("\n\n Aucun cient a ete trouver pour ce CIN");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("ress.txt");
	rename("tmp.txt","ress.txt");
	printf("\n\n client supprimee avec succes  ....");
	fclose(f);
	fclose(t);
	getch();
}







void supprimr_mod(char cin[50])
{
    struct client client;
	FILE *f,*t;
	int i=1;

		if((t=fopen("tmp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("ress.txt","r"))==NULL)
	exit(0);

	while(fread(&client,sizeof(client),1,f)==1)
	{
		if(strcmp(client.num_chambre,cin)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&client,sizeof(client),1,t);
	}
	if(i==1)
	{

		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("ress.txt");
	rename("tmp.txt","ress.txt");
	fclose(f);
	fclose(t);

}




















// Modifier les informations d'un client
void Modifier_client()
{
	FILE *f;
	int k=1;
	char numero_chambre[20];
	long int size=sizeof(client);
	if((f=fopen("ress.txt","r+"))==NULL)
		exit(0);
	system("cls");
	printf("Entrer le numero du chambre au client situee:\n\n");
	scanf("%[^\n]",numero_chambre);
	fflush(stdin);
	while(fread(&client,sizeof(client),1,f)==1)
	{
		if(strcmp(client.num_chambre,numero_chambre)==0)
		{
			k=0;
			printf("\nModifier le CIN  de client       :");
			gets(client.CIN);
			printf("\nModifier Le nom  de client       :");
			fflush(stdin);
			//scanf("%s",&client.nom);
		    gets(&client.nom);
			printf("\nModifier   Numero de chambre     :");
			scanf("%s",&client.num_chambre);

			printf("\nModifier Numero Telephone        :");
			scanf("%s",&client.tel);
			printf("\nModifier  l'Address              :");
            gets(&client.adresse);
			printf("\nModifier L' Email  du client     :");
			scanf("%s",&client.email);
			printf("\nModifier La Periode              :");
			scanf("%s",&client.periode);
			printf("\nModifier la Date de reservation  :");
			scanf("%s",&client.datereservation);

			fseek(f,size,SEEK_CUR);


			fwrite(&client,sizeof(client),1,f);

			break;
		}
	}
	if(k==1){
		printf("\n\n client n existe pas !!");
		fclose(f);
		getch();
	}else{
	fclose(f);
	    supprimr_mod(&numero_chambre);

	printf("\n\n\t\t Modifications bien Enregistres !");
	getch();
}


}
