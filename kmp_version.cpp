#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm> 
#include <jsoncpp/json/json.h>

using namespace std;

class KMP{
    private:
        vector<int> state;
        string text;
        string pattern;
    public:
        KMP(string, string);
        void state_process();
        bool search_pattern();
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

bool KMP::search_pattern(){
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
            return true;
        }
    }
    return false;
}

class Processing{
    private:
        map<int64_t, string> list_products;
        string path_json;

    public:
        Processing(string);
        void read_products();
        void list_all_products();
        void list_all_products_by_prefix(string);
};

Processing::Processing(string path_json){
    this->path_json = path_json;
}

void Processing::read_products(){
    
    Json::Reader reader;
    Json::Value json_line;
    string str_line, name_product; id_product;

    ifstream file_json(this->path_json);
    if(file_json.is_open()){
            while (getline(file_json, str_line)){

            reader.parse(str_line, json_line);

            id_product = json_line["id"].asInt64();
            name_product = json_line["name"].asString();
            this->list_products[id_product] = name_product;
        }
    }
    else
        cout << "Falha ao abrir arquivo Json" << endl;
}

void Processing::list_all_products_by_prefix(string pattern){
    
    int i = 1;
    for(auto product:this->list_products){
        KMP *kmp = new KMP(product.second, pattern);

        kmp->state_process();
        if (kmp->search_pattern())
            cout << "#" << i++ << " - " << product.first << " - " << product.second << endl;

        if(i == 21)
            break;
    }
}

void Processing::list_all_products(){
    int i = 1;
    for(auto product:this->list_products){
        cout << "#" << i++ << " - " << product.first  << " - " << product.second << endl;
    }
}

int main(){

    string PATH_JSON = "catalogo_produtos.json";
    Processing process = Processing(PATH_JSON);
    string product_name;

    process.read_products();

    cout << "Digite aqui sua consulta: ";
    getline(cin, product_name);

    process.list_all_products_by_prefix(product_name);
   
    return 0;
} 