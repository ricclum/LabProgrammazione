#include <iostream>
#include "User.h"


int main(){
    Item item1("pizza", 1, false);

    std::shared_ptr<List> lista1 = std::make_shared<List>("lista1");
    std::shared_ptr<List> lista2 = std::make_shared<List>("lista2");


    lista1->add_item(item1);
    lista2->add_item(item1);


    User utente1("Riccardo");
    User utente2("Alberto");


    utente1.add_list(lista1);
    utente1.add_list(lista2);
    utente2.add_list(lista1);
    utente2.add_list(lista2);

}

