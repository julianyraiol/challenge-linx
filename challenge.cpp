#include <bits/stdc++.h>
#include <jsoncpp/json/json.h>

using namespace std;
 
struct Node{
    map<wchar_t, Node*> children;
    string id;
    bool finalized;

    Node(){
        finalized = false;
    }
};

void insert(Node *root, string word, string id){
    
    cout<< word << " == " << id << endl;
    int index;
    for(wchar_t letter:word){
        if(root->children.find(letter) == root->children.end()){
            root->children[letter] = new Node();      
        }
        root = root->children[letter];
    }
    root->id = id;
    root->finalized = true;
}

void print(Node* root, string str, int &cont) 
{   
    if (root->finalized != false){ 
        cout << str << endl; 
    } 

    for (auto x:root->children){ 
        if (x.second)  { 
            str.push_back((x.first)); 
            print(x.second, str, cont);
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
    string str, str1;
    int cont = 0;
    
    Json::Reader reader;
    Json::Value json_line;
    ifstream file_json("catalogo_produtos.json");
  
    if(file_json){
        while (getline(file_json, str)){
            reader.parse(str, json_line);
            insert(root, json_line["name"].asString(), json_line["id"].asString());
        }
    }   
    else{
        cout << "Erro ao abrir o arquivo" << endl;
    }   
    
    cout << endl << "==============" << endl;
    print(root, str1, cont);
}