//
// Created by leopo on 06/01/2025.
//

#include "produit.h"
#include <iostream>
#include <string>

// Constructeur par défaut
produit::produit() : titre(""), description(""), quantite(0), prix(0) {}  // Added `prix(0)`

// Constructeur avec paramètres
produit::produit(std::string titre, std::string description, int quantite, int prix)
    : titre(titre), description(description), quantite(quantite), prix(prix) {}

// Méthode pour afficher les détails d'un produit
void produit::AfficherInfos() const {
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Afficher infos:\n"
              << "Titre: " << titre << "\n"
              << "Description: " << description << "\n"
              << "Quantite: " << quantite << "\n"
              << "Prix: " << prix << "\n";
}

// Méthode pour modifier la quantité du produit
void produit::modifquantite(int newquantite) {
    quantite = newquantite;
}
