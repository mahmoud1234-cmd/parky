#include<gtk/gtk.h>

typedef struct
{ 
char identifiant[30];
int capacite;
char  ville[30];
char options[30];
char affectation[50];
}parking;


void ajouter_parking(parking b,char *park);
void afficher_parking(GtkWidget *liste);
void modifier_parking(char identifiant[],parking b,char *park);
void supprimer_parking(char identifiant[],char *park);
int rechercher_parking(char identifiant[]);
void afficher_rechercher_parking(GtkWidget *liste);
int remplirtabRech (parking tab[],int nb) ;
int affecter_agent(const char *parking_id, const char *agent_id, const char *filename);
