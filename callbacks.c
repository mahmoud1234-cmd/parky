#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include"hasnawi.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"

int x,y,z,s;
int m,n,l,p;
void
on_radiobutton_acmot_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}


void
on_radiobutton_oui_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=1;}
}


void
on_radiobutton_nn_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=2;}
}


void
on_radiobutton_actruk_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}
}


void
on_checkbutton_confadd_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=1;}
}

//button add
void
on_button_add_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
parking b;
GdkColor color;
GtkWidget *windowajout,*idd,*capp,*vil,*opt,*aff,*combobox1,*output,*output1;
windowajout=create_window_gest();
idd= lookup_widget(button,"entry_hasnawi");

capp = lookup_widget(button,"spinbutton_cap");

combobox1=lookup_widget(button,"comboboxentry_vil");

strcpy(b.identifiant,gtk_entry_get_text(GTK_ENTRY(idd)));

b.capacite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (capp));


if(x==1)
{strcpy(b.options,"motors");}
else if(x==2)
{strcpy(b.options,"truks");}

if(y==1)
{strcpy(b.affectation,"oui");}
else if(y==2)
{strcpy(b.affectation,"non");}


if ((strcmp(b.identifiant,"")==0)  ) {
output1=lookup_widget(button,"label2");
gtk_label_set_text(GTK_LABEL(output1), "Données manquantes. \n Veuillez remplir tout les champs!");
output=lookup_widget(button,"label3");
gtk_label_set_text(GTK_LABEL(output), "");
}
if (combobox1 != NULL) {
        gchar *selected_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1));

        if (selected_text != NULL) {
            // Affiche le genre sélectionné dans la console (debug)
            g_print("Genre sélectionné : %s\n", selected_text);
            // Copie le genre sélectionné dans la structure c
            strcpy(b.ville, selected_text);
           g_free(selected_text);
        } else {
            // Aucune option sélectionnée dans la combobox
            // Faites quelque chose en conséquence
           s=0;
        }
}
if(z==1){
ajouter_parking(b,"parking.txt");
output1=lookup_widget(button,"label2");
gtk_label_set_text(GTK_LABEL(output1), "");
output=lookup_widget(button,"label3");
gtk_label_set_text(GTK_LABEL(output), "Ajouter avec Succes");

}
x=0;
y=0;
z=0;
}


void
on_radiobutton_trukmod_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{m=2;}
}


void
on_radiobutton_motmod_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{m=1;}
}


void
on_radiobutton_ouimod_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{n=1;}
}


void
on_radiobutton_nonmod_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{n=2;}
}


void
on_checkbutton_confmod_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{l=1;}
}

//button modif
void
on_button_mod_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
parking b1;
GtkWidget *windowmodifier,*idd1,*capp1,*vil1,*opt1,*aff1,*combobox2,*output2;
windowmodifier=create_window_gest();
idd1= lookup_widget(button,"entry_idmod");

capp1 = lookup_widget(button,"spinbutton_capmod");


combobox2=lookup_widget(button,"comboboxentry_vilmod");

strcpy(b1.identifiant,gtk_entry_get_text(GTK_ENTRY(idd1)));


b1.capacite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (capp1));


if (combobox2 != NULL) {
        gchar *selected_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2));

        if (selected_text != NULL) {
            // Affiche le genre sélectionné dans la console (debug)
            g_print("Genre sélectionné : %s\n", selected_text);

            // Copie le genre sélectionné dans la structure c
            strcpy(b1.ville, selected_text);

            g_free(selected_text);
        } else {
            // Aucune option sélectionnée dans la combobox
            // Faites quelque chose en conséquence
           p=0;
        }


if(m==1)
{strcpy(b1.options,"motors");}
else if(m==2)
{strcpy(b1.options,"truks");}

if(n==1)
{strcpy(b1.affectation,"oui");}
else if(n==2)
{strcpy(b1.affectation,"non");}


if(l==1){
modifier_parking(b1.identifiant,b1,"parking.txt");
output2=lookup_widget(button,"label15");
gtk_label_set_text(GTK_LABEL(output2), "Modifier avec Succes");

}
m=0;
n=0;
l=0;
}
}

void
on_button_supp_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
parking b;
char identif[20];
GtkWidget *windowaff,*tree, *idd,*output;

idd = lookup_widget(button,"entry_supp");
strcpy(identif,gtk_entry_get_text(GTK_ENTRY(idd)));
if ((strcmp(b.identifiant,"")==0)){
output=lookup_widget(button,"label20");
gtk_label_set_text(GTK_LABEL(output), "donnes manquantes");
}
else{
supprimer_parking(identif,"parking.txt");
windowaff=lookup_widget(button,"window_gest");
tree=lookup_widget(windowaff,"treeview1");
afficher_parking(tree);



output=lookup_widget(button,"entry_supp");
gtk_label_set_text(GTK_LABEL(output), "Supprimer avec Succes");
gtk_widget_hide(windowaff);
gtk_widget_show(windowaff);
}
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
gchar* cap;
gchar* vil;
gchar* opt;
gchar* aff;

parking b;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);

}

//boutton refresh
void
on_button_aff_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tree,*window_aff;
window_aff=lookup_widget(button,"window_gest");
gtk_widget_destroy(window_aff);
window_aff=create_window_gest();
tree=lookup_widget(window_aff,"treeview1");

afficher_parking(tree);

gtk_widget_hide(window_aff);
gtk_widget_show(window_aff);
}


void
on_rechercher_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
char identifiant[20];
int c; 
GtkWidget *idd,*tree,*windowrech,*output;
windowrech=lookup_widget(button,"window_gest");
idd = lookup_widget(button,"entry_rech");
strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(idd)));
c=rechercher_parking(identifiant);
if (c==0)
{
	output=lookup_widget(button,"label8");
	gtk_label_set_text(GTK_LABEL(output), "fiche INTROUVABLE");
}
if (c==1)
{	
tree=lookup_widget(windowrech,"treeview2");
afficher_rechercher_parking(tree);
}
}


void
on_ok_clicked                          (GtkButton       *button,
                                        gpointer         user_data)
{

    
}



void
on_homme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_femme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


 

void
on_login_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *window_gest, *log;  // Fenêtres
    window_gest = lookup_widget(GTK_WIDGET(button), "window_gest"); // Fenêtre actuelle (parking)
    
    gtk_widget_destroy(window_gest); // Fermer la fenêtre parking

    log = create_Login_WINDOW(); // Charger la fenêtre de connexion (login)
    gtk_widget_show(log); // Afficher la fenêtre de connexion
}

