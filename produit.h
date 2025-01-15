//
// Created by leopo on 06/01/2025.
//

#ifndef PRODUIT_H
#define PRODUIT_H

#include <iostream>
#include <string>  // Added this for std::string

class produit {
private:
    std::string titre;
    std::string description;
    int quantite;
    int prix;

public:
    // Constructeurs
    produit();
    produit(std::string titre, std::string description, int quantite, int prix);

    // Getters
    std::string get_titre() const { return titre; }
    std::string get_description() const { return description; }

    // Méthode d'affichage
    void AfficherInfos() const;

    void modifquantite(int newquantite);
};

#endif