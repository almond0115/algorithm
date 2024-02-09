#include <bits/stdc++.h>

using namespace std;

int N, M;
map<string, int> pokemonToIndex;    // {포켓몬 이름, 번호}
map<int, string> indexToPokemon;    // {번호, 포켓몬 이름}
string name, question;

int main() {
    cin >> N >> M;
    for(int i=1 ; i<= N ; i++){
        cin >> name;

        pokemonToIndex[name] = i;
        indexToPokemon[i] = name;
    }

    // 시간 복잡도? M x logN
    for(int i=1 ; i<= M; i++){
        cin >> question;

        if(isdigit(question[0])){
            int index = stoi(question);
            // int index = atoi(question.c_str());
        
            if(indexToPokemon.find(index) != indexToPokemon.end()){
                cout << indexToPokemon[index] << '\n';
            }
        } else {
            if(pokemonToIndex.find(question) != pokemonToIndex.end()){
                cout << pokemonToIndex[question] << '\n';
            }
        }
    } 

    return 0;
}