#include <bits/stdc++.h>
#include <jsoncpp/json/json.h>

class Node{
    private:
        map<wchar_t, Node*> children;
        bool finalized_word;
        string id_product;
    public:
        Node();

        bool get_finalized_word();
        void set_finalized_word(bool);

        string get_id_product();
        void set_id_product(string);
}

Node::Node(){
    this->finalized_word = false;
}

void Node::set_finalized_word(bool finalized_word){
    this->finalized_word = finalized_word;
}

bool Node::get_finalized_word(){
    return this->finalized_word;
}

void Node::set_id_product(bool id_product){
    this->finalized_word = finalized_word;
}

string Node::get_id_product(){
    return this->finalized_word;
}

int main(){
    return 0;
}