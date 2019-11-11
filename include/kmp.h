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
    int i, j, size_pattern;
    i = 1;
    j = 0;		    
    size_pattern = this->pattern.size();

    while(i < size_pattern){
        if(this->pattern[i] == this->pattern[j]){
            j++;
            this->state[i] = j;
            i++;
        }
        else{
            if(j>0)
                j = this->state[j-1];
            else{
                this->state[i] = 0;
                i++;
            }
        }
    }
}

int KMP::search_pattern(){
    int i = 0, j = 0;
    int size_text = this->text.size();
    int size_pattern = this->pattern.size();
    
    while(i < size_text){
        while (j > 0 && this->text[i] != this->pattern[j]){
            j = this->state[j - 1];
        } 

        if (this->text[i] == this->pattern[j]) {
            j++;
        }

        if(j == size_pattern){
            return i - (j - 1);
        }

        i++;
    }
    return -1;
}