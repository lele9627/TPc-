#include "Commande.h"

// Constructeur
Commande::Commande(const Client& client, const std::vector<produit>& produits)
    : client(client), produitsAchetes(produits), statut("En cours") {}

// Modifier le statut de la commande
void Commande::setStatut(const std::string& nouveauStatut) {
    statut = nouveauStatut;
}

// Getter pour accéder au client
const Client& Commande::getClient() const {
    return client;
}

// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& os, const Commande& commande) {
    os << "Commande de " << commande.client.getPrenom() << " " << commande.client.getNom() << "\n";
    os << "Statut : " << commande.statut << "\n";
    os << "Produits achetés : \n";
    
    for (const auto& p : commande.produitsAchetes) {
        os << "- " << p.get_titre() << " | " << p.get_description() << "\n";
    }
    
    return os;
}
