#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

string merge_word(string motMystere){
    string motCache;
    int nbAleatoire;
    int size(motMystere.size());
    while (motMystere.size() != 0){
        nbAleatoire = rand() % motMystere.size();
        motCache += motMystere[nbAleatoire];
        motMystere.erase(nbAleatoire, 1);
    }
    return motCache;
}

int main() {
    srand(time(0));
    string motMystere, motCache, tentative, newgame;
    double score;
    vector<double> scores(0);
    do{
        cout << "Saississez un mot" << endl;
        cin >> motMystere;

        motCache = merge_word(motMystere);
        score = 0;
            while (tentative != motMystere){
            score++;
            cout << "Quel est ce mot ?" << motCache << endl;
            cin >> tentative;
            if ( tentative == motMystere ){
                break;
            }
            cout << "Ce n'est pas le mot !" << endl;
        }
        cout << "Bravo ! vous avez trouver en " << score << " tentative(s)" << endl;
        cout << "newgame ? [o/n]" << endl;
        cin >> newgame;
        scores.push_back(score);
    } while( newgame == "o" );
    double moyenne(0);
    for (int i(0) ; i < scores.size() ; i++){
        moyenne += scores[i];
    }
    moyenne /= scores.size();
    cout << "moyenne de coups :" << moyenne << endl;
    return 0;
}
