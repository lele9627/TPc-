cmake_minimum_required(VERSION 3.29)
project(ueasystore)

set(CMAKE_CXX_STANDARD 20)

add_executable(ueasystore main.cpp

        produit.h
        produit.cpp
        Magasin.h
        Magasin.cpp
        Client.h
        Client.cpp
        commande.cpp)
