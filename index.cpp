#include <iostream>
#include <string>
#include "include/processing.h"

using namespace std;

int main(){

    string PATH_JSON = "data/catalogo_produtos.json";
    Processing process = Processing(PATH_JSON);
    
    process.main();
    
    return 0;
} 