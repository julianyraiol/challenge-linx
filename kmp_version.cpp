#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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
        i++; j++;
        if(j == size_pattern){
            return true;
        }
    }
    return false;
}

class Product{
    private:
        string id_product;
        string name_product;
    public:
        Product(string, string);
        void set_id_product(string);
        void set_name_product(string);
        string get_id_product();
        string get_name_product();
};

Product::Product(string id_product, string name_product){
    this->id_product = id_product;
    this->name_product = name_product;
}

void Product::set_id_product(string id_product){
    this->id_product = id_product;
}

void Product::set_name_product(string name_product){
    this->name_product = name_product;
}

string Product::get_id_product(){
    return id_product;
}

string Product::get_name_product(){
    return name_product;
}

class Processing{
    private:
        vector<Product*> list_products;
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
    string str_line, name_product, id_product;

    ifstream file_json(this->path_json);
    if(file_json.is_open()){
            while (getline(file_json, str_line)){

            reader.parse(str_line, json_line);

            id_product = json_line["id"].asString();
            name_product = json_line["name"].asString();

            this->list_products.push_back(new Product(id_product, name_product));
        }
    }
    else
        cout << "Falha ao abrir arquivo Json" << endl;
}

void Processing::list_all_products_by_prefix(string pattern){
    

    int i = 1;
    for(auto product:this->list_products){
        KMP *kmp = new KMP(product->get_name_product(), pattern);

        kmp->state_process();
        if (kmp->search_pattern())
            cout << "#" << i++ << " - " << product->get_id_product() << " - " << product->get_name_product() << endl;

        if(i == 21)
            break;
    }
}

void Processing::list_all_products(){
    int i = 1;
    for(auto product:this->list_products){
        cout << "#" << i++ << " - " << product->get_id_product() << " - " << product->get_name_product() << endl;
    }
}

int main(){

    string PATH_JSON = "catalogo_produtos.json";
    Processing process = Processing(PATH_JSON);
    
    process.read_products();
    process.list_all_products_by_prefix("LEGO");
   
    return 0;
} 