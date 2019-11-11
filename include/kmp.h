#include <iostream>
#include <vector>
#include <string>

using namespace std;

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