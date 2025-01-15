#include "Magasin.h"
#include "Commande.h"

int main() {
    // Création du magasin
    Magasin easystore;

    // Ajout de clients
    easystore.ajouterClient(101, "Alice", "Dupont");
    easystore.ajouterClient(102, "Bob", "Martin");

    // Affichage des clients
    std::cout << "\n--- Liste des clients ---" << std::endl;
    easystore.afficherClients();

    // Recherche d'un client par ID et par Nom
    std::cout << "\n--- Recherche d'un client par ID ---" << std::endl;
    easystore.afficherClientParNomOuID(101, "");

    std::cout << "\n--- Recherche d'un client par Nom ---" << std::endl;
    easystore.afficherClientParNomOuID(0, "Martin");

    // Ajout de produits au magasin
    produit p1("Laptop", "Ordinateur portable puissant", 10, 1200);
    produit p2("Souris", "Souris sans fil", 50, 25);
    produit p3("Clavier", "Clavier mécanique", 30, 80);

    easystore.ajouterProduit(p1);
    easystore.ajouterProduit(p2);
    easystore.ajouterProduit(p3);

    // Affichage des produits du magasin
    std::cout << "\n--- Liste des produits disponibles ---" << std::endl;
    easystore.afficherProduits();

    // Ajout de produits au panier d'un client
    std::cout << "\n--- Ajout de produits au panier du client Alice ---" << std::endl;
    easystore.ajouterProduitAuPanierClient(101, "Laptop");
    easystore.ajouterProduitAuPanierClient(101, "Souris");

    // Suppression d'un produit du panier
    std::cout << "\n--- Suppression d'un produit du panier du client Alice ---" << std::endl;
    easystore.supprimerProduitDuPanierClient(101, "Souris");

    // Modification de la quantité d'un produit dans le panier
    std::cout << "\n--- Modification de la quantité d'un produit du panier du client Alice ---" << std::endl;
    easystore.modifierQuantiteProduitPanierClient(101, "Laptop", 2);

    // Affichage du panier du client après modifications
    std::cout << "\n--- Contenu final du panier du client Alice ---" << std::endl;
    easystore.afficherClientParNomOuID(101, "");

    // Récupération du client pour passer une commande
    Client clientAlice(101, "Alice", "Dupont");
    
    // Création d'une commande pour Alice avec les produits achetés
    std::vector<produit> produitsAchat = {p1, p2};
    Commande commandeAlice(clientAlice, produitsAchat);

    // Affichage de la commande
    std::cout << "\n--- Détails de la commande pour Alice ---" << std::endl;
    std::cout << commandeAlice << std::endl;

    // Mise à jour du statut de la commande
    commandeAlice.setStatut("Expédiée");
    std::cout << "\n--- Mise à jour du statut de la commande ---" << std::endl;
    std::cout << commandeAlice << std::endl;

    return 0;
}
