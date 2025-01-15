/*
 * Created by leopo on 06/01/2025.
 */

#ifndef MAGASIN_H
#define MAGASIN_H

#include <iostream>
#include <vector>
#include <string>

#include "Client.h"
#include "produit.h"
#include "Commande.h"

class Magasin {
private:
    std::vector<produit> produits;  // Liste des produits du magasin
    std::vector<Client> clients;    // Liste des clients du magasin
    std::vector<Commande> commandes; // Liste des commandes du magasin

public:
    // Ajouter un produit au magasin
    void ajouterProduit(const produit& p);

    // Afficher tous les produits
    void afficherProduits() const;

    // Afficher un produit par son nom
    void afficherProduitParNom(const std::string& nom) const;

    // Mettre à jour la quantité d'un produit par son nom
    void mettreAJourQuantite(const std::string& nom, int nouvelleQuantite);

    // Ajouter un nouveau client
    void ajouterClient(int id, const std::string& prenom, const std::string& nom);

    // Afficher tous les clients
    void afficherClients() const;

    // Afficher un client par son nom ou son ID
    void afficherClientParNomOuID(int id, const std::string& nom) const;

    // Ajouter un produit au panier d'un client
    void ajouterProduitAuPanierClient(int clientID, const std::string& produitNom);

    // Supprimer un produit du panier d'un client
    void supprimerProduitDuPanierClient(int clientID, const std::string& produitNom);

    // Modifier la quantité d'un produit dans le panier d'un client
    void modifierQuantiteProduitPanierClient(int clientID, const std::string& produitNom, int nouvelleQuantite);

    // Valider une commande et l'ajouter à la liste des commandes
    void validerCommande(const Client& client, const std::vector<produit>& produits);

    // Mettre à jour le statut d'une commande par ID client
    void mettreAJourStatutCommande(int clientID, const std::string& nouveauStatut);

    // Afficher toutes les commandes passées
    void afficherToutesLesCommandes() const;

    // Afficher toutes les commandes d'un client donné
    void afficherCommandesClient(int clientID) const;
};

#endif // MAGASIN_H
