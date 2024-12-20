#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"hasnawi.h"
#include <gtk/gtk.h>

enum
{ 
	EID,
	ECAP,
	EVIL,
	EOPT,
	EAFF,
	COLUMNS,
};
////ajouter
void ajouter_parking(parking b,char *park){
FILE * f;
f=fopen(park,"a");

  fprintf(f,"%s %d %s %s %s \n ",b.identifiant,b.capacite,b.ville,b.options,b.affectation);
  fclose(f);
}
///afficher
void afficher_parking(GtkWidget *liste){
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char identifiant[30];
	char capacite[30];
	char  ville[30];
	char options[30];
	char affectation[50];
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("identifiant", renderer, "text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("capacite", renderer, "text",ECAP,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ville", renderer, "text",EVIL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("options", renderer, "text",EOPT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("affectation", renderer, "text",EAFF,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	

	

	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING);
	f=fopen("parking.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("parking.txt","a+");
		while(fscanf(f,"%s %s %s %s %s    \n",identifiant,capacite,ville,options,affectation)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EID, identifiant, ECAP,capacite, EVIL, ville, EOPT, options, EAFF, affectation ,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}

////modifier
void modifier_parking(char identifiant[],parking b1,char *park)
{
parking b;
  FILE* f=fopen(park, "r");
  FILE* f2=fopen("parkmod.txt", "w");
  
  if((f!=NULL) ||( f2!=NULL))
 {
while(fscanf(f,"%s %d %s %s %s \n ",b.identifiant,&b.capacite,b.ville,b.options,b.affectation)!=EOF)
{
if(strcmp(b.identifiant,b1.identifiant)==0)
  fprintf(f2,"%s %d %s %s %s \n ",b1.identifiant,b1.capacite,b1.ville,b1.options,b1.affectation);
else
 fprintf(f2,"%s %d %s %s %s \n ",b.identifiant,b.capacite,b.ville,b.options,b.affectation);
}
   fclose(f);
   fclose(f2);
remove(park);
rename("parkmod.txt",park);
 }
}
///////////////////////////////Supprimerr
void supprimer_parking(char identifiant[],char *park)
{
parking b;     
FILE * f=fopen(park,"r");
FILE * f2=fopen("parksupp.txt","w");

while (fscanf(f,"%s %d %s %s %s \n  ",b.identifiant,&b.capacite,b.ville,b.options,b.affectation)!=EOF)
{

if(strcmp(b.identifiant,identifiant)!=0)

  fprintf(f2,"%s %d %s %s %s \n  ",b.identifiant,b.capacite,b.ville,b.options,b.affectation);
}
  fclose(f);

  fclose(f2);

remove(park);
rename("parksupp.txt",park);

 
}
//fonction remplir tab
int remplirtabRech (parking tab[],int nb)
{
    char identifiant[20];
    char ville[30];	
    int capacite;
    char options[20];
    char affectation[20];
   
  
    FILE* fichier ;
    int i;

    fichier = fopen("parking.txt", "a+");

        while (fscanf(fichier,"%s %d %s %s %s \n ",identifiant,&capacite,ville,options,affectation)!=EOF)
        {
            
            strcpy(tab[i].identifiant,identifiant);
	    tab[i].capacite=capacite;
            strcpy(tab[i].ville,ville);
	    
            strcpy(tab[i].options,options);
	    strcpy(tab[i].affectation,affectation);
	    
	    	
            nb++;
	    i++;    
        }
        fclose(fichier);
	return(nb);
}
//rechercher 

int rechercher_parking(char identifiant[])
{
parking tab[100];
int nb;
int ce,i;
FILE*f;
ce=0;
nb=remplirtabRech (tab,nb);
for (i=0;i<nb;i++)
	{if ((strcmp(identifiant,tab[i].identifiant)==0) )
		{
		ce=1;
		f=fopen("rechpark.txt", "w+");
		if("f!=NULL")			
	{fprintf(f,"%s %d %s %s %s \n ",tab[i].identifiant,tab[i].capacite,tab[i].ville,tab[i].options,tab[i].affectation);}
		fclose(f);		
		}
	
	}
return(ce);		
}
//AFF RECH
void afficher_rechercher_parking(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char identifiant[30];
	char capacite[30];
	char  ville[30];
	char options[30];
	char affectation[50];
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("identifiant", renderer, "text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("capacite", renderer, "text",ECAP,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ville", renderer, "text",EVIL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("options", renderer, "text",EOPT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("affectation", renderer, "text",EAFF,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	

	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING);
	f=fopen("rechpark.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("rechpark.txt","a+");
		while(fscanf(f,"%s %s %s %s %s   \n",identifiant,capacite,ville,options,affectation)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter,  EID, identifiant, ECAP,capacite, EVIL, ville, EOPT, options, EAFF, affectation ,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
	
}
/*int affecter_agent(const char* parking_id, const char* agent_id, const char* filename) {
    FILE *file, *temp;
    parking p;
    int found = 0;

    file = fopen(filename, "r");
    temp = fopen("temp.txt", "w");

    if (!file || !temp) {
        return -1; // Erreur d'ouverture des fichiers
    }

    while (fscanf(file, "%s %d %s %s %s %s\n", p.identifiant, &p.capacite, p.ville, p.options, p.affectation, p.agent_id) != EOF) {
        if (strcmp(p.identifiant, parking_id) == 0) {
            found = 1;
            strcpy(p.agent_id, agent_id); // Affectation de l'agent
        }
        fprintf(temp, "%s %d %s %s %s %s\n", p.identifiant, p.capacite, p.ville, p.options, p.affectation, p.agent_id);
    }

    fclose(file);
    fclose(temp);

    remove(filename);
    rename("temp.txt", filename);

    return found;
}*/

// Nom du fichier contenant les informations des parkings
#define PARKING_FILE "parking.txt"

int verifier_login(const char *user_entry, const char *password_entry) {
    FILE *f = fopen(PARKING_FILE, "r");
    parking b;

    if (!f) {
        perror("Erreur : Impossible d'ouvrir le fichier parking.txt");
        return 0; // Échec : Fichier introuvable
    }

    while (fscanf(f, "%19s %d %49s %49s %19s",
                  b.identifiant, &b.capacite, b.ville, b.options, b.affectation) == 5) {
        // Remplacez `password_entry` par un champ existant dans votre structure
        // si nécessaire pour correspondre à la logique métier.
        if (strcmp(b.identifiant, user_entry) == 0 && strcmp(b.affectation, password_entry) == 0) {
            fclose(f);
            return 1; // Succès : Identifiant et mot de passe valides
        }
    }

    fclose(f);
    return 0; // Échec : Identifiants incorrects
}


