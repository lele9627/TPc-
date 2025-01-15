//
// Created by leopo on 06/01/2025.
//

#ifndef CLIENT_H
#define CLIENT_H
#include <vector>
#include <iostream>
#include "produit.h"


class Client {
private:
  int clientID;
  std::string prenom;
  std::string nom;
  std::vector <produit> panierAchat;


//constructeur
  public:
  Client();
  Client(int clientID, std::string prenom, std::string nom);

  //Methode
  // Ajouter un produit au panier
  void ajouterAuPanier(const produit& p);

  // Afficher le panier
  void afficherPanier() const;

  // Valider la commande (vider le panier)
  void validerCommande();
    // Getters pour accéder aux attributs privés
    int getClientID() const;
    std::string getPrenom() const;
    std::string getNom() const;
    
    // Méthodes pour gérer le panier
    void supprimerProduitDuPanier(const std::string& produitNom);
    void modifierQuantiteProduitPanier(const std::string& produitNom, int nouvelleQuantite);
};



#endif //CLIENT_H
