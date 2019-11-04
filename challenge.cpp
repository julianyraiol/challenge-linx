#include <bits/stdc++.h>
#define ALPHABET_SIZE 127

using namespace std;
 
struct Node{
    struct Node* children[ALPHABET_SIZE];
    char caracter;
    bool finalized;

    Node(){
        memset(children, false, sizeof(children));
        finalized = false;
    }
};

void insert(Node *root, string word){
    
    int index;
    for(char letter:word){
        index = letter;
        
        if(!root->children[index]){
            root->children[index] = new Node();
            root->children[index]->caracter = letter;
            
        }
        root = root->children[index];
    }
    root->finalized = true;
}


void print(Node* root, string str, int &cont) 
{   
    if (root->finalized != false){ 
        cout << str << endl; 
    } 

    for (int i = 0; i < ALPHABET_SIZE; i++){ 
        if (root->children[i])  { 
            str.push_back(root->children[i]->caracter); 
            print(root->children[i], str, cont);
            str.pop_back();    
        } 
    } 
} 

int print_by_prefix(Node* root, string word){
    int index, cont = 0;
    for(char letter:word){
        index = letter - 'a';
        if(!root->children[index]){
            return false;
        }
        root = root->children[index];
    }

    print(root, word, cont);
    
    return cont;
}

int main(){
    Node* root = new Node();
    string str;
    int cont = 0;
    Json::Reader reader;
    Json::Value json_line;
    ifstream file_json("catalogo_produtos.json");

    if(file_json){
        while (getline(file_json, str)){
            reader.parse(str, json_line);
            cout << json_line << endl;
            insert(root, json_line["name"].asString(), json_line["id"].asString());
        }
    }   
    else{
        cout << "Erro ao abrir o arquivo" << endl;
    }    
    //print(root, str, cont);
}