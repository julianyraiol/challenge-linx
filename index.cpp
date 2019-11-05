#include <bits/stdc++.h>

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
    this->set_finalized_word(false);
}

map<wchar_t, Node*> Node::get_children(){
    return this->children;
}

bool Node::has_key(wchar_t key){
    return (this->children.find(key) != this->children.end());
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

/* matizador
violeta 
 */
class Trie{
    private:
        Node* root;
    public:
        Trie();
        void add_element(string);
        void print_all_elements(Node*, string);
        void print_by_prefix(string);
};

Trie::Trie(){
    this->root = new Node();
}

void Trie::add_element(string word){
    for(wchar_t letter:word){
        if(!this->root->has_key(letter)){
            this->root->insert_node(letter);
        }
        this->root = this->root->get_node(letter);
    }

    this->root->set_finalized_word(true);
}

void Trie::print_all_elements(Node *root, string str){
    if(this->root->get_finalized_word()){
        cout << str << endl;
    }

    for(auto element:this->root->get_children()){
        if(element.second){
            str.push_back((element.first)); 
            print_all_elements(element.second, str);
            str.pop_back(); 
        }
    }
}

int main(){

    Trie prefix_tree = Trie();
    string word;
    prefix_tree.add_element("aaaaa");
    prefix_tree.add_element("aaaaabbbb");
    prefix_tree.add_element("ccccaaaa");

    prefix_tree.print_all_elements(word);

    return 0;
}