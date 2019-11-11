#include <iostream>
#include <string>
#include "include/processing.h"

using namespace std;

int main(){

    string PATH_JSON = "data/catalogo_produtos.json";
    Processing process = Processing(PATH_JSON);
    string product_name;

    process.read_products();

    while(true){
        cout << "Digite aqui sua consulta: ";
        getline(cin, product_name);
         
        process.list_all_products_by_prefix(product_name);
       
        cout << endl;
    }
    
    return 0;
} 