#include "sport.h"
#include "ui_sport.h"
#include <qmessagebox.h>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QFileDialog>

    using namespace std;



    sport::sport(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::sport)
    {
        ui->setupUi(this);

    }

    sport::~sport()
    {
        delete ui;
    }



    void sport::on_boutoncalculer_clicked()
    {

    //déclaration des variables
        int NombreCalorie;
        int poids;
        int taille;
        int age;
    //on converti les valeurs saisies en int;
        poids=ui->poids->text().toInt();
        taille=ui->taille->text().toInt();
        age=ui->age->text().toInt();
        //on créer des condition, on peut utiliser aussi le try an catch
    if (ui->sexe->text()=="femme" ){

       NombreCalorie=(447.593) + (9.247 * poids) + (3.098 * taille) - (4.33 * age);
        NombreCalorie=NombreCalorie*1.55;
        }else{
        if(ui->sexe->text()=="homme")
        NombreCalorie=(88.362) + (13.397 * poids) + (4.799 * taille) - (5.677 * age);
        NombreCalorie=NombreCalorie*1.55;


    }

        int nombredeCalorieParRepas;
        nombredeCalorieParRepas=NombreCalorie/3;
        QString caloriefinal;
        //on converti notre resultat en un Qstring pour pouvoir l'insérer et donc l'afficher.
        caloriefinal=QString::number(NombreCalorie);
        ui->resultat->setText(caloriefinal);//on l'insère dans la zone "resultat".

    //on crée des conditions pour que les cases soient remplis correctement.
    if( poids!=0 && age!=0 && taille!=0 && ui->typefichier->text()!="" ){
    QString typeFICHIER;
    typeFICHIER= ui->typefichier->text();//on récupère le type du fichier que l'on enregistre.

    string typefinal;
    typefinal=typeFICHIER.toStdString();//on converti en string car le chemin du fichier est un string.
    string const nomFichier("test."+typefinal);//le chemin du fichier et celui du programme.
        ofstream  fichier(nomFichier.c_str());
        //si le fichier est ouvert ou créer.
        if(fichier){
        fichier<<"Voici un tableau qui qui montre votre besoin calorique par jour et par repas\n\n";
        fichier<<"\n\ncalorie total : " <<NombreCalorie<<"\n";
        fichier<<"\n\ncalorie aux petit déjeuner: "<<nombredeCalorieParRepas;
        fichier<<"\n\ncalorie aux déjeuner: "<<nombredeCalorieParRepas;
        fichier<<"\n\ncalorie aux dîner: "<<nombredeCalorieParRepas;


        //message
        QMessageBox msgBox; QString x;
        msgBox.setIcon(QMessageBox::Information);
        x="Votre fichier à été créer";
        msgBox.setText(x);
        msgBox.exec();
        //on bloque les zones de saisie .

        ui->sexe->setEnabled(false);
        ui->age->setEnabled(false);
        ui->poids->setEnabled(false);
        ui->taille->setEnabled(false);

        //si il y à un problème avec le fichier.
        }else {
        QMessageBox msgBox; QString x;
        msgBox.setIcon(QMessageBox::Information);
        x="impossible d'ouvrir le fichier  ";
        msgBox.setText(x);
        msgBox.exec();}
    }else {//si une case est mal rentrée.
        QMessageBox msgBox; QString x;
        msgBox.setIcon(QMessageBox::Information);
        x="resultat vide ";
        msgBox.setText(x);
        msgBox.exec();

    }

    }



//fonction du bouton chosir fichier.
    void sport::on_pushButton_clicked()
    {
        QFileDialog dialog(this);
        dialog.setFileMode(QFileDialog::ExistingFile);
        dialog.setNameFilter(tr("Text files (*.txt);"));

        nomFICHIER = dialog.getOpenFileName();//chemin du fichier sélectionner
        string chemin=nomFICHIER.toStdString();//on le convertis en string
        ifstream fichier(chemin);//on ouvre le fichier avec en paramètre le chemin
        string ligne((istreambuf_iterator<char>(fichier)), (istreambuf_iterator<char>()));//pour lire toutes les lignes du document.



            ui->contenu->setText(QString::fromStdString(ligne)); //on affiche le contenu du document.


    }

//procedure du bouton "nettoyer"
    void sport::on_nettoyer_clicked()
    {
        ui->contenu->clear();
    }

    //procedure du bouton "quitter"

    void sport::on_QUITTER_clicked()
    {
        this->close();
    }

    //procedure du bouton "recommencer"

    void sport::on_RECOMMENCER_clicked()
    {
        ui->sexe->setEnabled(true);
        ui->poids->setEnabled(true);
        ui->age->setEnabled(true);
        ui->taille->setEnabled(true);

        ui->sexe->clear();
        ui->poids->clear();
        ui->age->clear();
        ui->taille->clear();
    }

