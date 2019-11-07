#include <bits/stdc++.h>
#include <jsoncpp/json/json.h>

using namespace std;

class Node{
    private:
        map<wchar_t, Node*> children;
        bool finalized_word;
        string id_product;
    public:
        Node();        

        map<wchar_t, Node*> get_children();
        
        bool has_key(wchar_t);
        void insert_node(wchar_t);
        Node* get_node(wchar_t);

        bool get_finalized_word();
        void set_finalized_word(bool);

        string get_id_product();
        void set_id_product(string);   
};

Node::Node(){
    this->finalized_word = false;
}

map<wchar_t, Node*> Node::get_children(){
    return this->children;
}

bool Node::has_key(wchar_t key){
    return !(this->children.find(key) == this->children.end());
}

void Node::insert_node(wchar_t key){
    this->children[key] = new Node();
}

Node* Node::get_node(wchar_t key){
    return this->children[key];
}

void Node::set_finalized_word(bool finalized_word){
    this->finalized_word = finalized_word;
}

bool Node::get_finalized_word(){
    return this->finalized_word;
}

void Node::set_id_product(string id_product){
    this->id_product = id_product;
}

string Node::get_id_product(){
    return this->id_product;
}

class Trie{
    private:
        Node* root;
        void print_all_elements(Node*, string);
    public:
        Trie();
        void add_element(string, string);
        void show_all_occurences();
        void show_occurences_by_prefix(string);
};

Trie::Trie(){
    this->root = new Node();
}

void Trie::add_element(string product, string id_product){

    Node* aux = this->root;

    for(wchar_t letter:product){
        if(!aux->has_key(letter)){
            aux->insert_node(letter);
        }
        aux = aux->get_node(letter);
    }

    aux->set_finalized_word(true);
    aux->set_id_product(id_product);
}

void Trie::print_all_elements(Node* current_node,string current_word){
    
    if(current_node->get_finalized_word()){
        cout << current_word << endl;
    }

    for(auto node:current_node->get_children()){
        if(node.second){
            current_word.push_back((node.first)); 
            print_all_elements(node.second, current_word);
            current_word.pop_back(); 
        }
    }
}

void Trie::show_all_occurences(){
    string current_word;
    print_all_elements(this->root, current_word);
}

void Trie::show_occurences_by_prefix(string prefix){
    Node* aux = this->root;
    
    for(wchar_t key:prefix){
        if(!aux->has_key(key))
            return;
        aux = aux->get_node(key);
    }

    print_all_elements(aux, prefix);
}

class Processing{
    private:
        Trie* prefix_products;
        string path_json;
    public:
        Processing(string);
        void read_products();
        void list_products();
};

Processing::Processing(string path_json){
    
    this->path_json = path_json;
    this->prefix_products = new Trie();
}

void Processing::read_products(){
    Json::Reader reader;
    Json::Value json_line;
    string str_line, name_product, id_product;

    try{
        ifstream file_json(this->path_json);
        while (getline(file_json, str_line)){

            reader.parse(str_line, json_line);

            id_product = json_line["id"].asString();
            name_product = json_line["name"].asString();
            
            this->prefix_products->add_element(name_product, id_product);
        }
    }catch(exception &e){
        cout << "[ERRO] Falha ao abrir o arquivo" << endl;  
    }
}

int main(){

    string PATH_JSON = "catalogo_produtos.json";

    Processing process = Processing(PATH_JSON);
    process.read_products();
    //process.list_products();

    /*string word;
    prefix_tree.add_element("Roupa de cachoro", "1234");
    prefix_tree.add_element("Refrigerador Azul", "12345");
    prefix_tree.add_element("Refrigerador Amarelo", "123467");
    prefix_tree.add_element("Refrigerador Cinza", "1234678");

    prefix_tree.show_all_occurences();

    cout << "=========" << endl;

    prefix_tree.show_occurences_by_prefix("Refrigerador");*/

    return 0;
}