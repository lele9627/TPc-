//
// Created by leopo on 06/01/2025.
//

#include "Magasin.h"

// Ajouter un produit au magasin
void Magasin::ajouterProduit(const produit& p) {
    produits.push_back(p);
    std::cout << "Produit ajouté : " << p.get_titre() << std::endl;
}

// Afficher tous les produits
void Magasin::afficherProduits() const {
    if (produits.empty()) {
        std::cout << "Aucun produit dans le magasin." << std::endl;
        return;
    }
    std::cout << "Liste des produits disponibles :" << std::endl;
    for (const auto& p : produits) {
        p.AfficherInfos();
        std::cout << "--------------------\n";
    }
}

// Afficher un produit par son nom
void Magasin::afficherProduitParNom(const std::string& nom) const {
    for (const auto& p : produits) {
        if (p.get_titre() == nom) {
            p.AfficherInfos();
            return;
        }
    }
    std::cout << "Produit non trouvé : " << nom << std::endl;
}

// Mettre à jour la quantité d'un produit par son nom
void Magasin::mettreAJourQuantite(const std::string& nom, int nouvelleQuantite) {
    for (auto& p : produits) {
        if (p.get_titre() == nom) {
            p.modifquantite(nouvelleQuantite);
            std::cout << "Quantité mise à jour pour " << nom << " : " << nouvelleQuantite << std::endl;
            return;
        }
    }
    std::cout << "Produit non trouvé : " << nom << std::endl;
}

// Ajouter un client
void Magasin::ajouterClient(int id, const std::string& prenom, const std::string& nom) {
    clients.emplace_back(id, prenom, nom);
    std::cout << "Client ajouté : " << prenom << " " << nom << " (ID: " << id << ")" << std::endl;
}

// Afficher tous les clients
void Magasin::afficherClients() const {
    if (clients.empty()) {
        std::cout << "Aucun client enregistré." << std::endl;
        return;
    }
    std::cout << "Liste des clients :" << std::endl;
    for (const auto& c : clients) {
        std::cout << "ID: " << c.getClientID() << " | Nom: " << c.getPrenom() << " " << c.getNom() << std::endl;
    }
}

// Afficher un client par son nom ou ID
void Magasin::afficherClientParNomOuID(int id, const std::string& nom) const {
    for (const auto& c : clients) {
        if (c.getClientID() == id || c.getNom() == nom) {
            std::cout << "Client trouvé : " << c.getPrenom() << " " << c.getNom() << " (ID: " << c.getClientID() << ")" << std::endl;
            return;
        }
    }
    std::cout << "Client non trouvé." << std::endl;
}

// Ajouter un produit au panier d'un client
void Magasin::ajouterProduitAuPanierClient(int clientID, const std::string& produitNom) {
    for (auto& c : clients) {
        if (c.getClientID() == clientID) {
            for (const auto& p : produits) {
                if (p.get_titre() == produitNom) {
                    c.ajouterAuPanier(p);
                    return;
                }
            }
            std::cout << "Produit non trouvé dans le magasin." << std::endl;
            return;
        }
    }
    std::cout << "Client non trouvé." << std::endl;
}

// Supprimer un produit du panier d'un client
void Magasin::supprimerProduitDuPanierClient(int clientID, const std::string& produitNom) {
    for (auto& c : clients) {
        if (c.getClientID() == clientID) {
            c.supprimerProduitDuPanier(produitNom);
            return;
        }
    }
    std::cout << "Client non trouvé." << std::endl;
}

// Modifier la quantité d'un produit dans le panier d'un client
void Magasin::modifierQuantiteProduitPanierClient(int clientID, const std::string& produitNom, int nouvelleQuantite) {
    for (auto& c : clients) {
        if (c.getClientID() == clientID) {
            c.modifierQuantiteProduitPanier(produitNom, nouvelleQuantite);
            return;
        }
    }
    std::cout << "Client non trouvé." << std::endl;
}

// Ajouter un client
void Magasin::ajouterClient(int id, const std::string& prenom, const std::string& nom) {
    clients.emplace_back(id, prenom, nom);
    std::cout << "Client ajouté : " << prenom << " " << nom << " (ID: " << id << ")" << std::endl;
}

// Afficher tous les clients
void Magasin::afficherClients() const {
    if (clients.empty()) {
        std::cout << "Aucun client enregistré." << std::endl;
        return;
    }
    std::cout << "Liste des clients :" << std::endl;
    for (const auto& c : clients) {
        std::cout << "ID: " << c.getClientID() << " | Nom: " << c.getPrenom() << " " << c.getNom() << std::endl;
    }
}

// Afficher un client par nom ou ID
void Magasin::afficherClientParNomOuID(int id, const std::string& nom) const {
    for (const auto& c : clients) {
        if (c.getClientID() == id || c.getNom() == nom) {
            std::cout << "Client trouvé : " << c.getPrenom() << " " << c.getNom() << " (ID: " << c.getClientID() << ")" << std::endl;
            return;
        }
    }
    std::cout << "Client non trouvé." << std::endl;
}

// Ajouter un produit au panier d'un client
void Magasin::ajouterProduitAuPanierClient(int clientID, const std::string& produitNom) {
    for (auto& c : clients) {
        if (c.getClientID() == clientID) {
            for (const auto& p : produits) {
                if (p.get_titre() == produitNom) {
                    c.ajouterAuPanier(p);
                    return;
                }
            }
            std::cout << "Produit non trouvé dans le magasin." << std::endl;
            return;
        }
    }
    std::cout << "Client non trouvé." << std::endl;
}

// Supprimer un produit du panier d'un client
void Magasin::supprimerProduitDuPanierClient(int clientID, const std::string& produitNom) {
    for (auto& c : clients) {
        if (c.getClientID() == clientID) {
            c.supprimerProduitDuPanier(produitNom);
            return;
        }
    }
    std::cout << "Client non trouvé." << std::endl;
}

// Modifier la quantité d'un produit dans le panier d'un client
void Magasin::modifierQuantiteProduitPanierClient(int clientID, const std::string& produitNom, int nouvelleQuantite) {
    for (auto& c : clients) {
        if (c.getClientID() == clientID) {
            c.modifierQuantiteProduitPanier(produitNom, nouvelleQuantite);
            return;
        }
    }
    std::cout << "Client non trouvé." << std::endl;
}
#include "Magasin.h"

// Valider une commande et l'ajouter à la liste des commandes
void Magasin::validerCommande(const Client& client, const std::vector<produit>& produits) {
    Commande nouvelleCommande(client, produits);
    commandes.push_back(nouvelleCommande);
    std::cout << "Commande validée pour " << client.getPrenom() << " " << client.getNom() << std::endl;
}

// Mettre à jour le statut d'une commande par ID client
void Magasin::mettreAJourStatutCommande(int clientID, const std::string& nouveauStatut) {
    for (auto& commande : commandes) {
        if (commande.client.getClientID() == clientID) {
            commande.setStatut(nouveauStatut);
            std::cout << "Statut de la commande mis à jour pour le client " << clientID << " : " << nouveauStatut << std::endl;
            return;
        }
    }
    std::cout << "Aucune commande trouvée pour le client ID " << clientID << std::endl;
}

// Afficher toutes les commandes passées
void Magasin::afficherToutesLesCommandes() const {
    if (commandes.empty()) {
        std::cout << "Aucune commande enregistrée." << std::endl;
        return;
    }
    std::cout << "\n--- Liste des commandes ---" << std::endl;
    for (const auto& commande : commandes) {
        std::cout << commande << std::endl;
    }
}

// Afficher toutes les commandes d'un client donné
void Magasin::afficherCommandesClient(int clientID) const {
    bool found = false;
    std::cout << "\n--- Commandes pour le client ID " << clientID << " ---" << std::endl;
    for (const auto& commande : commandes) {
        if (commande.client.getClientID() == clientID) {
            std::cout << commande << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Aucune commande trouvée pour ce client." << std::endl;
    }
}
// Modifier le statut d'une commande par ID client
void Magasin::mettreAJourStatutCommande(int clientID, const std::string& nouveauStatut) {
    for (auto& commande : commandes) {
        if (commande.getClient().getClientID() == clientID) {
            commande.setStatut(nouveauStatut);
            std::cout << "Statut de la commande mis à jour pour le client " << clientID << " : " << nouveauStatut << std::endl;
            return;
        }
    }
    std::cout << "Aucune commande trouvée pour le client ID " << clientID << std::endl;
}

// Afficher toutes les commandes d'un client donné
void Magasin::afficherCommandesClient(int clientID) const {
    bool found = false;
    std::cout << "\n--- Commandes pour le client ID " << clientID << " ---" << std::endl;
    for (const auto& commande : commandes) {
        if (commande.getClient().getClientID() == clientID) {
            std::cout << commande << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Aucune commande trouvée pour ce client." << std::endl;
    }
}
