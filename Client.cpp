//
// Created by leopo on 06/01/2025.
//

#include "Client.h"
#include <algorithm>

// Constructeur par défaut
Client::Client() : clientID(0), prenom(""), nom("") {}

// Constructeur avec paramètres
Client::Client(int clientID, std::string prenom, std::string nom)
    : clientID(clientID), prenom(prenom), nom(nom) {}

// Ajouter un produit au panier
void Client::ajouterAuPanier(const produit& p) {
    panierAchat.push_back(p);
    std::cout << "Produit ajouté au panier : " << p.get_titre() << std::endl;
}

// Afficher le contenu du panier
void Client::afficherPanier() const {
    if (panierAchat.empty()) {
        std::cout << prenom << " " << nom << ", votre panier est vide." << std::endl;
        return;
    }

    std::cout << "Panier de " << prenom << " " << nom << " : " << std::endl;
    for (const auto& p : panierAchat) {
        p.AfficherInfos();
        std::cout << "--------------------\n";
    }
}

// Valider la commande et vider le panier
void Client::validerCommande() {
    if (panierAchat.empty()) {
        std::cout << "Votre panier est déjà vide, aucune commande à valider." << std::endl;
        return;
    }

    std::cout << "Commande validée pour " << prenom << " " << nom << " !" << std::endl;
    panierAchat.clear();
}

// Getters
int Client::getClientID() const {
    return clientID;
}
std::string Client::getPrenom() const {
    return prenom;
}
std::string Client::getNom() const {
    return nom;
}

// Supprimer un produit du panier
void Client::supprimerProduitDuPanier(const std::string& produitNom) {
    auto it = std::remove_if(panierAchat.begin(), panierAchat.end(),
                             [&](const produit& p) { return p.get_titre() == produitNom; });
    if (it != panierAchat.end()) {
        panierAchat.erase(it, panierAchat.end());
        std::cout << "Produit supprimé du panier : " << produitNom << std::endl;
    } else {
        std::cout << "Produit non trouvé dans le panier." << std::endl;
    }
}

// Modifier la quantité d'un produit dans le panier
void Client::modifierQuantiteProduitPanier(const std::string& produitNom, int nouvelleQuantite) {
    for (auto& p : panierAchat) {
        if (p.get_titre() == produitNom) {
            p.modifquantite(nouvelleQuantite);
            std::cout << "Quantité mise à jour pour " << produitNom << " : " << nouvelleQuantite << std::endl;
            return;
        }
    }
    std::cout << "Produit non trouvé dans le panier." << std::endl;
}

