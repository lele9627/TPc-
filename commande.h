#ifndef COMMANDE_H
#define COMMANDE_H

#include <iostream>
#include <vector>
#include "Client.h"
#include "produit.h"

class Commande {
private:
    Client client;
    std::vector<produit> produitsAchetes;
    std::string statut;

public:
    // Constructeur
    Commande(const Client& client, const std::vector<produit>& produits);

    // Modifier le statut de la commande
    void setStatut(const std::string& nouveauStatut);

    // Getter pour accéder au client
    const Client& getClient() const;

    // Surcharge de l'opérateur <<
    friend std::ostream& operator<<(std::ostream& os, const Commande& commande);
};

#endif // COMMANDE_H
