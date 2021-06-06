#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<gtk/gtk.h>

/*****variable global*****/

static  GtkBuilder *b;
static GtkWidget *windowM;
static GtkWidget *window1;
static GtkWidget *window3;
static GtkWidget *window5;
static GtkWidget *window4;

/************************/

void Menu_principal();
void Gestion_location();
void Gestion_voiture();
void Gestion_client();
void Retourvoiture();
void Retourlocation();
void Retourclient();
void close1();
void close();

/****Gestion voiture****/
int recherche_voiture(int);
void list_voiture();
void ajoute_voiture();
void modifier_voiture();
void suprimer_voiture();
/**********************/

/****Gestion client****/
int recherche_Client(int);
void list_Clients();
void ajoute_Client();
void modifier_Client();
void suprimer_client();
/**********************/

void visualiser_contrat();
int louer_voiture();
void Return_voiture();
void Modifier_contrat();
void supprimer_contrat();

typedef struct
{
      GtkWidget *button1;
      GtkWidget *button2;
      GtkWidget *button3;
      GtkWidget *button4;
      GtkWidget *button5;
      GtkWidget *button6;

}menu;
menu M;
typedef struct
{
      int jj_debut;
      int mm_debut;
      int aa_debut;

}date_debut;
typedef struct
{
      int jj_fin;
      int mm_fin;
      int aa_fin;

}date_fin;
typedef struct
{

      int id_voiture;
      char marque[15];
      char nom_voiture[15];
      char couleur[7];
      int nbplace;
      int prix_jour;
      char enlocation[4];
}voiture;
voiture V;
typedef struct
{
      float num_contrat ;
      int id_Voiture;
      int id_client;
      date_debut debut;
      date_fin fin;
      int count;

}contrat;
contrat cl;
typedef struct client
{
      int id_client;
      char nom[20];
      char prenom[20];
      int cin;
      char adresse[15];
      int telephone;
}client;
client Client;

/************************************ main *********************************/
int main(int argc , char **argv)
{

      gtk_init(&argc,&argv);
      GtkWidget *buttonA;
      b=gtk_builder_new_from_file("c.glade");
      windowM=GTK_WIDGET(gtk_builder_get_object(b,"wM"));
      buttonA=GTK_WIDGET(gtk_builder_get_object(b,"button2"));
      g_signal_connect(buttonA , "clicked" ,G_CALLBACK(Menu_principal), NULL);
      g_signal_connect(buttonA , "clicked" ,G_CALLBACK(close), NULL);
      gtk_widget_show_all(windowM);
      gtk_main();
      return 0;
}

/*********************************surface_graphique**********************************/

void Retourlocation()
{
      Menu_principal();
      gtk_widget_destroy(window5);

}

void Retourvoiture()
{
      Menu_principal();
      gtk_widget_destroy(window3);

}
void Retourclient()
{
      Menu_principal();
      gtk_widget_destroy(window4);

}
void close()//destroy premier window
{
   gtk_widget_destroy(windowM);
}

void close1() //destroy Menu principal
{
   gtk_widget_destroy(window1);
}
void Gestion_location()
{
      b=gtk_builder_new_from_file("c.glade");
      window5=GTK_WIDGET(gtk_builder_get_object(b,"w2"));
      M.button1=GTK_WIDGET(gtk_builder_get_object(b,"Vc"));
      M.button2=GTK_WIDGET(gtk_builder_get_object(b,"Lc"));
      M.button3=GTK_WIDGET(gtk_builder_get_object(b,"Rc"));
      M.button4=GTK_WIDGET(gtk_builder_get_object(b,"Mc"));
      M.button5=GTK_WIDGET(gtk_builder_get_object(b,"Sc"));
      M.button6=GTK_WIDGET(gtk_builder_get_object(b,"Rw"));
      g_signal_connect(M.button1 , "clicked" ,G_CALLBACK(visualiser_contrat), NULL);
      g_signal_connect(M.button2 , "clicked" ,G_CALLBACK(louer_voiture), NULL);
      g_signal_connect(M.button3 , "clicked" ,G_CALLBACK(Return_voiture), NULL);
      g_signal_connect(M.button4 , "clicked" ,G_CALLBACK(Modifier_contrat), NULL);
      g_signal_connect(M.button5 , "clicked" ,G_CALLBACK(supprimer_contrat), NULL);
      g_signal_connect(M.button6 , "clicked" ,G_CALLBACK(Retourlocation), NULL);
       gtk_widget_show_all(window5);
}
void Gestion_client()
{

      b=gtk_builder_new_from_file("c.glade");
      window4=GTK_WIDGET(gtk_builder_get_object(b,"w4"));
      M.button1=GTK_WIDGET(gtk_builder_get_object(b,"Lcl"));
      M.button2=GTK_WIDGET(gtk_builder_get_object(b,"Acl"));
      M.button3=GTK_WIDGET(gtk_builder_get_object(b,"Mcl"));
      M.button4=GTK_WIDGET(gtk_builder_get_object(b,"Scl"));
      M.button5=GTK_WIDGET(gtk_builder_get_object(b,"Rcl"));
      g_signal_connect(M.button1 , "clicked" ,G_CALLBACK(list_Clients), NULL);
      g_signal_connect(M.button2 , "clicked" ,G_CALLBACK(ajoute_Client), NULL);
      g_signal_connect(M.button3 , "clicked" ,G_CALLBACK(modifier_Client), NULL);
      g_signal_connect(M.button4 , "clicked" ,G_CALLBACK(suprimer_client), NULL);
      g_signal_connect(M.button5 , "clicked" ,G_CALLBACK(Retourclient), NULL);
     gtk_widget_show_all(window4);
}
void Gestion_voiture()
{
      b=gtk_builder_new_from_file("c.glade");
      window3=GTK_WIDGET(gtk_builder_get_object(b,"w3"));
      M.button1=GTK_WIDGET(gtk_builder_get_object(b,"Lv"));
      M.button2=GTK_WIDGET(gtk_builder_get_object(b,"Av"));
      M.button3=GTK_WIDGET(gtk_builder_get_object(b,"Mv"));
      M.button4=GTK_WIDGET(gtk_builder_get_object(b,"Sv"));
      M.button5=GTK_WIDGET(gtk_builder_get_object(b,"Rv"));
      g_signal_connect(M.button1 , "clicked" ,G_CALLBACK(list_voiture), NULL);
      g_signal_connect(M.button2 , "clicked" ,G_CALLBACK(ajoute_voiture), NULL);
      g_signal_connect(M.button3 , "clicked" ,G_CALLBACK(modifier_voiture), NULL);
      g_signal_connect(M.button4 , "clicked" ,G_CALLBACK(suprimer_voiture), NULL);
      g_signal_connect(M.button5 , "clicked" ,G_CALLBACK(Retourvoiture), NULL);
     gtk_widget_show_all(window3);
}

void Menu_principal()
{
      menu M;
      b=gtk_builder_new_from_file("c.glade");
      window1=GTK_WIDGET(gtk_builder_get_object(b,"w1"));
      M.button1=GTK_WIDGET(gtk_builder_get_object(b,"button1_w2"));
      M.button3=GTK_WIDGET(gtk_builder_get_object(b,"button3_w2"));
      M.button2=GTK_WIDGET(gtk_builder_get_object(b,"button2_w2"));
      M.button4=GTK_WIDGET(gtk_builder_get_object(b,"button4_w2"));

      //connect chaque button par leur fonction

      g_signal_connect(M.button1 , "clicked" ,G_CALLBACK(Gestion_location), NULL);
      g_signal_connect(M.button2, "clicked" ,G_CALLBACK(Gestion_voiture), NULL);
      g_signal_connect(M.button3, "clicked" ,G_CALLBACK(Gestion_client), NULL);
      g_signal_connect(M.button4 , "clicked" ,G_CALLBACK(gtk_main_quit), NULL);

      //destroy la windows pour chaque click de buttom

      g_signal_connect(M.button1 , "clicked" ,G_CALLBACK(close1), NULL);
       g_signal_connect(M.button2 , "clicked" ,G_CALLBACK(close1), NULL);
      g_signal_connect(M.button3 , "clicked" ,G_CALLBACK(close1), NULL);
      g_signal_connect(M.button3 , "clicked" ,G_CALLBACK(close1), NULL);

      gtk_widget_show_all(window1);
}
/**************************************************************************/

                /************gestion voiture**************/
int recherche_voiture(int Vrech)
{
      FILE *F;
      F=fopen("voiture.txt","r");
      fflush(stdin);
      do
      {
        fscanf(F,"%d,%s,%s,%s,%d,%d,%s\n" ,&V.id_voiture,&V.marque,&V.nom_voiture,&V.couleur,&V.nbplace,&V.prix_jour,&V.enlocation);
        if(V.id_voiture == Vrech)
        {
              fclose(F);
              return 1;

        }
      }while(!feof(F));
        fclose(F);
        return -1;
}
void list_voiture()
{
      gtk_widget_destroy(window3);
      system("cls");
	FILE *F;
	F=fopen("voiture.txt","r");
	do
	{
		fscanf(F,"%d,%s,%s,%s,%d,%d,%s \n" ,&V.id_voiture,&V.marque,&V.nom_voiture,&V.couleur,&V.nbplace,&V.prix_jour,&V.enlocation);
		fflush(stdin);
		printf("%d\t", V.id_voiture);
		printf("%s\t",V.marque);
		printf("%s\t",V.nom_voiture);
		printf("%s\t",V.couleur);
		printf("%d\t", V.nbplace);
		printf("%d\t", V.prix_jour);
		printf("%s\n",V.enlocation);

	}while(feof(F));
      fclose(F);

	Gestion_voiture();

}
void ajoute_voiture()
{
      gtk_widget_destroy(window3);
      system("cls");
	FILE *F;
	int id;
	F=fopen("voiture.txt","a");
	printf("\t\t\tid de nouveau voiture :");
	scanf("%d",&id);
	fflush(stdin);
	while (recherche_voiture(id)==1)
	{
	    printf("l id de voiture est dejat existe ");
	    printf("id de nouveau voiture :");
	    scanf("%d",&id);
	}
	V.id_voiture=id;
	printf("\t\t\tentrez la marque de voiture ");
	fgets(V.marque , sizeof(V.marque),stdin);
      fflush(stdin);
	printf("\t\t\tentrez la nom de voiture ");
	fgets(V.nom_voiture , sizeof(V.nom_voiture ),stdin);;
	fflush(stdin);
	printf("\t\t\tentrez la couleur de voiture ");
	fgets(V.couleur , sizeof(V.couleur),stdin);
	fflush(stdin);
	printf("\t\t\tentrez la nbplace de voiture ");
	scanf("%d",&V.nbplace);
	fflush(stdin);
	printf("\t\t\tentrez la prixjour de voiture ");
	scanf("%d",&V.prix_jour);
	fflush(stdin);
	printf("\t\t\tentrez l enlocation de voiture ");
      fgets(V.enlocation , sizeof(V.enlocation),stdin);
      fflush(stdin);
	fprintf(F,"%d, %s, %s, %s, %d, %d, %s \n" , V.id_voiture,V.marque,V.nom_voiture,V.couleur,V.nbplace,V.prix_jour,V.enlocation);
	fclose(F);
	Gestion_voiture();
}
void modifier_voiture()
{
      system("cls");
      gtk_widget_destroy(window3);
	FILE *F,*f;
	int id_mdf;
	char cf_mdf;


	printf("entrez l'id_voiture pour modifier : \n");
	scanf("%d",&id_mdf);
	if(recherche_voiture(id_mdf) == 1)
	{
		printf("\n confermer par 'o' c'est oui ou pour annuller par 'n' c'est non : ");
		scanf("%c",&cf_mdf);
		if (cf_mdf=='o'||cf_mdf=='O')
		{
			F=fopen("voiture.txt","r");
			f=fopen("voiture1.txt","a");
			do
			{
		   		fscanf(F,"%d, %s, %s, %s, %d, %d, %s \n" ,&V.id_voiture,&V.marque,&V.nom_voiture,&V.couleur,&V.nbplace,&V.prix_jour,&V.enlocation);
		   	    if(id_mdf==V.id_voiture)
		   	    {
		   	      	      V.id_voiture=id_mdf;
                                    printf("\t\t\tentrez la marque de voiture ");
                                    fgets(V.marque ,sizeof(V.marque),stdin);
                                    printf("\n\t\t\tentrez la nom de voiture ");
                                    fgets(V.nom_voiture , sizeof(V.nom_voiture ),stdin);;
                                    fflush(stdin);
                                    printf("\n\t\t\tentrez la couleur de voiture ");
                                    fgets(V.couleur , sizeof(V.couleur),stdin);
                                    fflush(stdin);
                                    printf("\n\t\t\tentrez la nbplace de voiture ");
                                    scanf("%d",&V.nbplace);
                                    fflush(stdin);
                                    printf("\n\t\t\tentrez la prixjour de voiture ");
                                    scanf("%d",&V.prix_jour);
                                    fflush(stdin);
                                    printf("\n\t\t\tentrez l enlocation de voiture ");
                                    fgets(V.enlocation , sizeof(V.enlocation),stdin);
                                    fflush(stdin);
				}
				fprintf(f,"%d,%s,%s,%s,%d,%d,%s/n" ,V.id_voiture,V.marque,V.nom_voiture,V.couleur,V.nbplace,V.prix_jour,V.enlocation);
			}while(feof(F));
			fclose(f);
			fclose(F);
			remove("voiture.txt");
			rename("voiture1.txt","voiture.txt");
			printf("\n la modification de voiture a reussi");
		}
		else printf("modification annuler ");
	}
    else printf("id de voiture n'exist pas");
    Gestion_voiture();
}
void suprimer_voiture()
{
      system("cls");
      gtk_widget_destroy(window3);
	int id_sup;
	char cf_sup;
	printf("entrez le id de voiture pour le suprimer :");
	scanf("%d",&id_sup);
	if(recherche_voiture(id_sup) == 1)
	{
		printf("confermer par 'o' c'est oui ou pour annuller par 'n' c'est non : ");
		scanf("%c",&cf_sup);
		if (cf_sup=='o'||cf_sup=='O')
		{
			FILE *F, *f;
			F=fopen("voiture.txt","r");
			f=fopen("voiture1.txt","a");
		    do
			{
				fscanf(F,"%d,%s,%s,%s,%d,%d,%s/n" ,&V.id_voiture,&V.marque,&V.nom_voiture,&V.couleur,&V.nbplace,&V.prix_jour,&V.enlocation);
				if(id_sup != V.id_voiture)
				{
			  		fprintf(f,"%d,%s,%s,%s,%d,%d,%s\n" ,V.id_voiture,V.marque,V.nom_voiture,V.couleur,V.nbplace,V.prix_jour,V.enlocation);
				}
			}while(feof(F));
			fclose(f);
			fclose(F);
			remove("voiture.txt");
			rename("voiture1.txt","voiture.txt");
			printf("suppresion effectuee avec succes");
		}
	}
	else printf("l'id_voiture n'exist pas");
	Gestion_voiture();
}

             /***********Gestion client***************/

int recherche_Client(int Crech)
{
      FILE *F;
      F=fopen("Client.txt","r");
      fflush(stdin);
      do
      {
        fscanf(F,"%d, %s, %s, %d, %s, %d \n" ,&Client.id_client,&Client.nom,&Client.prenom,&Client.cin,&Client.adresse,&Client.telephone);
        if(Client.id_client == Crech)
        {
              fclose(F);
              return 1;

        }
      }while(feof(F));
        fclose(F);
        return -1;
}
void list_Clients()
{
      system("cls");
      gtk_widget_destroy(window4);
	FILE *F;
	F=fopen("Client.txt","r");

	do
	{
		fscanf(F,"%d, %s, %s, %d, %s, %d \n" ,&Client.id_client,&Client.nom,&Client.prenom,&Client.cin,&Client.adresse,&Client.telephone);
		fflush(stdin);
		printf("%d\t",Client.id_client);
		printf("%s\t",Client.nom);
		printf("%s\t",Client.prenom);
		printf("%d\t",Client.cin);
		printf("%s\t",Client.adresse);
		printf("%d\t",Client.telephone);
	}while(feof(F));
	fclose(F);
	Gestion_client();

}
void ajoute_Client()
{
      system("cls");
      gtk_widget_destroy(window4);
	FILE *F;
	int id;
	F=fopen("Client.txt","a");
	printf("id de nouveau Client :");
	scanf("%d",&id);
	fflush(stdin);
	while (recherche_Client(id)==1)
	{
	    printf("l'id de Client est dejat existe ");
	    printf("l'id de nouveau Client :");
	    scanf("%d",&id);
	}
	Client.id_client=id;
	printf("\t\t\tentrez le Nom de Client : ");
      fgets(Client.nom , sizeof(Client.nom),stdin);
	fflush(stdin);
	printf("\t\t\tentrez le Prenom de Client : ");
	fgets(Client.prenom,sizeof(Client.prenom),stdin);
	fflush(stdin);
	printf("\t\t\tentrez le CIN de Client : ");
	scanf("%d",&Client.cin);
	fflush(stdin);
	printf("\t\t\tentrez l'adresse de Client : ");
	fgets(Client.adresse,sizeof(Client.adresse),stdin);
	fflush(stdin);
	printf("\t\t\tentrez N° de telephone de Client : ");
	scanf("%d",&Client.telephone);
	fflush(stdin);
    fprintf(F,"%d, %s, %s, %d, %s, %d /n" , Client.id_client,Client.nom,Client.prenom,Client.cin,Client.adresse,Client.telephone);
	fclose(F);
	Gestion_client();
}
void modifier_Client()
{
      system("cls");
      gtk_widget_destroy(window4);
	int id_mdf;
	char cf_mdf;

	printf("entrez l'id de client pour modifier :");
	scanf("%d",&id_mdf);
	if(recherche_Client(id_mdf) == 1)
	{
		printf("\n confermer par  'o' c'est oui ou pour annuller par  'n' c'est non : ");
		scanf("%c",&cf_mdf);
		if (cf_mdf=='o'||cf_mdf=='O')
		{
			FILE *F,*f;
			F=fopen("Client.txt","r");
			f=fopen("client1.txt","a");
			do
			{
                        fscanf(F,"%d, %s, %s, %d, %s, %d \n" ,&Client.id_client,&Client.nom,&Client.prenom,&Client.cin,&Client.adresse,&Client.telephone);
                        if(id_mdf==Client.id_client)
                        {
		   	      	      Client.id_client=id_mdf;
                                    	printf("\t\t\tentrez le Nom de Client : ");
                                          fgets(Client.nom , sizeof(Client.nom),stdin);
                                          fflush(stdin);
                                          printf("\t\t\tentrez le Prenom de Client : ");
                                          fgets(Client.prenom,sizeof(Client.prenom),stdin);
                                          fflush(stdin);
                                          printf("\t\t\tentrez le CIN de Client : ");
                                          scanf("%d",&Client.cin);
                                          fflush(stdin);
                                          printf("\t\t\tentrez l'adresse de Client : ");
                                          fgets(Client.adresse,sizeof(Client.adresse),stdin);
                                          fflush(stdin);
                                          printf("\t\t\tentrez N° de telephone de Client : ");
                                          scanf("%d",&Client.telephone);
                                          fflush(stdin);
				}
				fprintf(f,"%d, %s, %s, %d, %s, %d \n" , Client.id_client,Client.nom,Client.prenom,Client.cin,Client.adresse,Client.telephone);
			}while(feof(F));
			fclose(f);
			fclose(F);
			remove("Client.txt");
			rename("Client1.txt","Client.txt");
			printf("\n la modification de client a reussi");
		}
		else printf("modification annuler ");
	}
    else printf("l'id n'exist pas");
    Gestion_client();
}
void suprimer_client()
{
      system("cls");
      gtk_widget_destroy(window4);
      system("cls");
	int id_sup;
	char cf_sup;
	printf("entrez le id de Client pour le suprimer :");
	scanf("%d",&id_sup);
	if(recherche_Client(id_sup) == 1)
	{
		printf("confermer par 'o' c'est oui ou pour annuller par 'n' c'est non : ");
		scanf("%c",&cf_sup);
		if (cf_sup=='o'||cf_sup=='O')
		{
			FILE *F, *f;
			F=fopen("Client.txt","r");
			f=fopen("Client1.txt","a");
		    do
			{
                        fscanf(F,"%d, %s, %s, %d, %s, %d \n" ,&Client.id_client,&Client.nom,&Client.prenom,&Client.cin,&Client.adresse,&Client.telephone);
				if(id_sup != Client.id_client)
				{
                              fprintf(f,"%d, %s, %s, %d, %s, %d \n" , Client.id_client,Client.nom,Client.prenom,Client.cin,Client.adresse,Client.telephone);
				}
			}while(!feof(F));
			fclose(f);
			fclose(F);
			remove("Client.txt");
			rename("Client1.txt","voiture.txt");
            printf("suppresion de client effectuee avec succes");
		}
	}
	else printf("l' id_voiture n' exist pas");

	Gestion_client();
}
/*****************************************************************************/

/************ Gestion location  ************/


int recherche_contrat(int Vrech)
{
      FILE *F;
      F=fopen("contrat.txt","r");
      fflush(stdin);
      do
      {
        fscanf(F,"%f, %d, %d, %d, %d, %d \n" ,&cl.num_contrat,&cl.id_Voiture,&cl.id_client,&cl.debut,&cl.fin,&cl.count);
        if(cl.num_contrat == Vrech)
        {
              fclose(F);
              return 1;

        }
      }while(!feof(F));
        fclose(F);
        return -1;
}
void visualiser_contrat()
{
      gtk_widget_destroy(window5);
      system("cls");
    float num_contrat;
    contrat Contrat;
    printf("Entrez le numero de contrat que tu veux l'afficher: \n");
    scanf("%f", &num_contrat);
    FILE* fichier;
    fichier=fopen("ContratsLocations.txt", "r");
    do {
    	fscanf(fichier, "%f,%d,%d,%d,%d,%d,%d,%d,%d,%d,\n",
			&Contrat.num_contrat, &Contrat.id_Voiture, &Contrat.id_client,
			&Contrat.debut.jj_debut, &Contrat.debut.mm_debut, &Contrat.debut.aa_debut,
			&Contrat.fin.jj_fin, &Contrat.fin.mm_fin, &Contrat.fin.aa_fin, &Contrat.count);
    	if(num_contrat==Contrat.num_contrat) {
            printf("\t\tNumero de contrat : %f",Contrat.num_contrat);
            printf("\t\tid de voiture  : %d",Contrat.id_Voiture);
            printf("\t\tid de client : %d",Contrat.id_client);
            printf("\t\t Le debut de location : %d-%d-%d", Contrat.debut.jj_debut, Contrat.debut.mm_debut, Contrat.debut.aa_debut);
            printf("\t\t La fin de location : %d-%d%d", Contrat.debut.aa_debut, Contrat.fin.mm_fin, Contrat.fin.aa_fin);
            printf("\t\t Le cout: %d dh", Contrat.count);
            break;
        }
	}while(!feof(fichier));

	fclose(fichier);
}

 int louer_voiture()
{
     gtk_widget_destroy(window5);
      system("cls");
    int idc,idv;
    int trouver_client=0;
    int trouver_voiture=0;
    voiture V;
    contrat Contrat;
    printf("Donnez id de client : ");
    scanf("%d",&idc);
    trouver_client=recherche_Client(idc);
    if(trouver_client==-1) { /* if client n'est exist pas en fait l appelle de gestion_client()*/
       int i;
	    printf("\n\n\t\tERROR votre id n'est existe pas\n");
        printf("enregistrer des propres information a travers le menu de gestion client , 1|0");
        scanf("%d",&i);
        switch(i)
        {
        	case 1:
        	 Gestion_client();
        	 return 0;
        	case 0:
        	      Menu_principal();
        	     return 0;
        	default: printf("vous voulez entrer 1|0");

		}

    }

	/* if client dejat exist */

    printf("donnez id de voiture : ");
    scanf("%d",idv);
    trouver_voiture=recherche_voiture(idv);
    if(trouver_voiture==-1) {  /* if la voiture n'est exist pas*/
        printf("\n\n\t\tERROR voiture n'est existe pas\a");
        getchar();
    }

    /* if la voiture exist*/

    else {  /* en vus if la voiture en location ou no*/
    	FILE *F;
    	FILE *N;
        F=fopen("voiture.txt","r");
        N=fopen("nouveu_voiture.txt", "w"); /* ce fichier va copier le data de fichier "voiture.txt" pour changer la valeur de enlovation */
		fflush(stdin);
		/* cherche de voiture de fichier "voiture.txt" */
		do {
			fscanf(F,"%d,%s,%s,%s,%d,%d,%s/n" ,V.id_voiture,V.marque,V.nom_voiture,V.couleur,V.nbplace,V.prix_jour,V.enlocation);

			/* if a voiture exist */
			if(V.id_voiture == idv) {
			    if( strcmp(V.enlocation,"oui")==0) { /* if voiture deja louer*/
                    printf("\n\n\t\tvoiture deja louer\a");
                    getchar();
                    fclose(F);  /* fermeture les fichier */
                    fclose(N);
                    remove("nouveu_voiture.txt");  /* supprimer le fichier */
                    return 1; /* sortier car on ne peut contuner avec un voiture deja louer */
            	}

		        else {  /* if la voiture possible de louer*/

		            printf("\t\t\t\tclient,saiaie les information necessaire suivant: \n ");

					/* ecrire le contrat*/
					/* id voiture et id de client deja exist */
		            printf("numero du contrat: ");
		            scanf("%f", &Contrat.num_contrat);
		            printf("\n\t donnez la date debut de location (jj mm aa): ");
		            scanf("%d %d %d", &Contrat.debut.jj_debut, &Contrat.debut.mm_debut,&Contrat.debut.aa_debut);
		            printf("\t\t\tentrez date de fin (jj mm aa): ");
		            scanf("%d %d %d", &Contrat.fin.jj_fin, &Contrat.fin.mm_fin, &Contrat.fin.aa_fin);
		            printf("\t\t Determinez le count: ");
		            scanf("%d", &Contrat.count);

		            /*On ajout cette contrat dans le fichier "contatlocation"*/
		            FILE* fichier;
		            fichier = fopen("ContratsLocations.txt", "a");
		            	fprintf(fichier, "%f, %d, %d, %d, %d, %d, %d, %d, %d, %d, \n",
								Contrat.num_contrat, idv, idc,
								Contrat.debut.jj_debut, Contrat.debut.mm_debut, Contrat.debut.aa_debut,
								Contrat.fin.jj_fin, Contrat.fin.mm_fin, Contrat.fin.aa_fin, Contrat.count
						);
		            fclose(fichier);
		            /* change la valeur de enlocation*/
		           	strcpy(V.enlocation,"oui");
				    /* copier dans un notre fichier*/
				    fprintf(N, "%d,%s,%s,%s,%d,%d,%s/n" ,V.id_voiture,V.marque,V.nom_voiture,V.couleur,V.nbplace,V.prix_jour,V.enlocation);
				    continue; /* pour eviter repetion de fprintf */
	            }
			}
			/* copier  "voiture" dans "nouveu_voiture"*/
			fprintf(N, "%d,%s,%s,%s,%d,%d,%s/n" ,V.id_voiture,V.marque,V.nom_voiture,V.couleur,V.nbplace,V.prix_jour,V.enlocation);
		}while(!feof(F));
		fclose(F);
		fclose(N);
		remove("voiture.txt");
		rename("nouveu_voiture.txt", "voiture.txt");
		Gestion_location();

    }
}
void Return_voiture() {
      gtk_widget_destroy(window5);
      system("cls");
    int Vrech;
    contrat Contrat;
    FILE *F;
    FILE *N;

    printf("Donneez id de la voiture: ");
    scanf("%d", &Vrech);

    F=fopen("voiture.txt", "r");
    N=fopen("nouveu_voiture.txt", "w");
    do {
		fscanf(F,"%d,%s,%s,%s,%d,%d,%s/n" , &V.id_voiture, V.marque, V.nom_voiture, V.couleur, &V.nbplace, &V.prix_jour, V.enlocation);

		/* if la voiture exist */
		if(V.id_voiture == Vrech) {
			strcpy(V.enlocation,"non");
            /* copier les donner de fichier voiture dans le fichier "nouveu_voiture.txt" en chande  enlocation = "non" */
			fprintf(N, "%d,%s,%s,%s,%d,%d,%s/n" ,V.id_voiture,V.marque,V.nom_voiture,V.couleur,V.nbplace,V.prix_jour,V.enlocation);
			continue;
	    }
	    /* copier les donners de fichier voiture dans le fichier "nouveu_voiture.txt"*/
		fprintf(N, "%d,%s,%s,%s,%d,%d,%s/n" ,V.id_voiture,V.marque,V.nom_voiture,V.couleur,V.nbplace,V.prix_jour,V.enlocation);
	}while(!feof(F));

	fclose(F);
	fclose(N);
	remove("voiture.txt");
	rename("nouveu_voiture.txt", "voiture.txt");

	/* supprimer le contrat */
	/* recherche l idvoiure de contrat si elle est meme qui le client saisie */
     /* cherche dans le voiture*/
    F=fopen("ContratsLocations.txt", "r");
    N=fopen("nouveu_Contrat.txt", "w"); /* new fichier */
    do {
    	fscanf(F, "%f,%d,%d,%d,%d,%d,%d,%d,%d,%d,\n",
			&Contrat.num_contrat, &Contrat.id_Voiture, &Contrat.id_client,
			&Contrat.debut.jj_debut, &Contrat.debut.mm_debut, &Contrat.debut.aa_debut,
			&Contrat.fin.jj_fin, &Contrat.fin.mm_fin, &Contrat.fin.aa_fin, &Contrat.count);
    	if(Vrech==Contrat.id_Voiture) {
            continue;  /* pour ne pas ecrire les info de voiture dans le new  ficher comme on supprimer*/
        }
        fprintf(N, "%f,%d,%d,%d,%d,%d,%d,%d,%d,%d,\n",
			Contrat.num_contrat, Contrat.id_Voiture, Contrat.id_client,
			Contrat.debut.jj_debut, Contrat.debut.mm_debut, Contrat.debut.aa_debut,
			Contrat.fin.jj_fin, Contrat.fin.mm_fin, Contrat.fin.aa_fin, Contrat.count);
	}while(!feof(F));

	fclose(F);
	fclose(N);
	remove("ContratsLocations.txt");
	rename("nouveu_Contrat.txt", "ContratsLocations.txt");
	Gestion_location();


}
void Modifier_contrat(){
     gtk_widget_destroy(window5);
      system("cls");
    float num_contrat;
    contrat Contrat;
    int test = 0;


	printf("Entrez le num de contrat pour la modifier: ");
	scanf("%d",&num_contrat);

	FILE* F;
	FILE* N;
    F=fopen("ContratsLocations.txt", "r");
    N=fopen("nouveu_Contrat.txt", "w"); /* new fichier */
    do {
    	fscanf(F, "%f,%d,%d,%d,%d,%d,%d,%d,%d,%d,\n",
			&Contrat.num_contrat, &Contrat.id_Voiture, &Contrat.id_client,
			&Contrat.debut.jj_debut, &Contrat.debut.mm_debut, &Contrat.debut.aa_debut,
			&Contrat.fin.jj_fin, &Contrat.fin.mm_fin, &Contrat.fin.aa_fin, &Contrat.count);
    	/* if le contrat exist ---> modifier la dat de fin et le cout*/
		if(num_contrat==Contrat.num_contrat) {
			test = 1;  /*pour connaitre if le contrat exist*/

            printf("\t\t\Entrez la nouvelle date de fin : ");
            scanf("%d%d%d", &Contrat.fin.jj_fin, &Contrat.fin.mm_fin,&Contrat.fin.aa_fin);
        	fflush(stdin);
            printf("\t\t\tEntrez le nouveu cout: ");
            scanf("%d",&Contrat.count);
        }
        /* copier dans "ContratsLocations.txt" avec modification   */
        fprintf(N, "%f,%d,%d,%d,%d,%d,%d,%d,%d,%d,\n",
			Contrat.num_contrat, Contrat.id_Voiture, Contrat.id_client,
			Contrat.debut.jj_debut, Contrat.debut.mm_debut, Contrat.debut.aa_debut,
			Contrat.fin.jj_fin, Contrat.fin.mm_fin, Contrat.fin.aa_fin, Contrat.count);
	}while(!feof(F));

	fclose(F);
	fclose(N);
	remove("ContratsLocations.txt");
	rename("nouveu_Contrat.txt", "ContratsLocations.txt");

	if(test) {
		printf("\n la modification de contrat a reussi");
	}
	else {
		printf("Le contrat n'exist pas");
	}
	    Gestion_location();
}


void supprimer_contrat()
{
      gtk_widget_destroy(window5);
      system("cls");
      float nc;
      char cf_cn;
	printf("entrez le num de contrat pour le suprimer :");
	scanf("%d",&nc);
	if(recherche_contrat(nc) == 1)
	{
		printf("confermer par 'o' c'est oui ou pour annuller par 'n' c'est non : ");
		scanf("%c",&cf_cn);
		if (cf_cn=='o'||cf_cn=='O')
		{
			FILE *F, *f;
			F=fopen("contrat.txt","r");
			f=fopen("contrat1.txt","a");
		    do
			{
                        fscanf(F,"f, %d, %d, %d, %d, %d \n" ,&cl.num_contrat,&cl.id_Voiture,&cl.id_client,&cl.debut,&cl.fin,&cl.count);
				if(cf_cn != cl.num_contrat)
				{
                              fprintf(f,"%f, %d, %d, %d, %d, %d \n" , cl.num_contrat,cl.id_Voiture,cl.id_client,cl.debut,cl.fin,cl.count);
				}
			}while(feof(F));
			fclose(f);
			fclose(F);
			remove("contrat.txt");
			rename("contrat1.txt","contrat.txt");
            printf("suppresion de contrat effectuee avec succes");
		}
	}
	else printf("le num de contrat n' exist pas");
	Gestion_location();
}
