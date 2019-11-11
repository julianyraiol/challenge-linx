#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "kmp.h"
#include "json.hpp"

using namespace std;
using json::JSON;

class Processing{
    private:
        map<string, string> list_products;
        string path_json;

        void print_product(int, string, string);
    public:
        Processing(string);
        
        void read_products();
        void list_all_products();
        void list_all_products_by_prefix(string);
};

Processing::Processing(string path_json){
    this->path_json = path_json;
}

void Processing::print_product(int occurences, string id_product, string name_product){
    cout << "#" << occurences << " - " << id_product << " - " << name_product << endl;
}

void Processing::read_products(){

    string str_line, name_product, id_product;

    ifstream file_json(this->path_json);
    if(file_json.is_open()){
            while (getline(file_json, str_line)){

            JSON Obj = JSON::Load(str_line);

            id_product = Obj["id"].ToString();
            name_product = Obj["name"].ToString();

            this->list_products[id_product] = name_product;
        }
    }
    else
        cout << "Falha ao abrir arquivo Json" << endl;
}

void Processing::list_all_products_by_prefix(string pattern){
    
    int occurences = 1, search_result;
    bool is_finish = false;
    map<string, string> others_occurences;

    for(auto product:this->list_products){
        KMP *kmp = new KMP(product.second, pattern);
        kmp->state_process();

        search_result = kmp->search_pattern();

        if(search_result == 0)
            print_product(occurences++, product.first, product.second);
        else if(search_result != -1)
            others_occurences[product.first] = product.second;

        if(occurences > 20) return;
    }

    for(auto product:others_occurences){
        print_product(occurences++, product.first, product.second);
        if(occurences > 20) return;
    }
}

void Processing::list_all_products(){
    int i = 1;
    for(auto product:this->list_products){
        print_product(i++, product.first, product.second);
    }
}

