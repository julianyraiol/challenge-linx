#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm> 
#include "json.hpp"

using namespace std;
using json::JSON;


class KMP{
    private:
        vector<int> state;
        string text;
        string pattern;
    public:
        KMP(string, string);
        void state_process();
        int search_pattern();
};

KMP::KMP(string text, string pattern){
    this->text = text;
    this->pattern = pattern;
    this->state.assign(this->text.size(), 0);
}

void KMP::state_process(){
    int i = 0, j = -1, size_text, size_pattern;
    size_text = this->text.size();
    size_pattern = this->pattern.size();

    this->state[0] = -1;
    while (i < size_pattern){
        while(j >= 0 && this->pattern[i] != this->pattern[j])j = this->state[j];
        i++; j++;
        this->state[i] = j;
    }
}

int KMP::search_pattern(){
    int i = 0, j = 0;
    int size_text = this->text.size();
    int size_pattern = this->pattern.size();
   
    while (i < size_text){
        while(j >= 0 && this->text[i] != this->pattern[j]){
            j = this->state[j];
        } 
        i++; 
        j++;
        if(j == size_pattern){
            return i - j;
        }
    }
    return -1;
}

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

int main(){

    string PATH_JSON = "catalogo_produtos.json";
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