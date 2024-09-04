//Main File
#include <iostream>
#include "User.h"

int main(){
    Item item1("pizza", "gastronomia", "Buitoni");

    List* lista1 = new List("spesa coop");
    List* lista2 = new List("spesa conad");

    lista1->add_item(item1, 2);
    lista2->add_item(item1, 3);


    User utente1("Riccardo");
    User utente2("Alberto");


    utente1.add_list(lista1);
    utente1.add_list(lista2);
    utente2.add_list(lista1);
    utente2.add_list(lista2);


    lista1->add_item(Item("Prosciutto crudo", "gastronomia", "Beretta"), 2);

}

