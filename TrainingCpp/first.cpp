#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    cout << "Quel age avez vous ?"<< endl;
    int ageUtilisateur(0);
    cin >> ageUtilisateur;
    cout << "Vous avez " << ageUtilisateur << " ans" << endl;

    int const nrbNiveaux(10);
    double var(25);
    double puissance(2);
    cout << "sqrt(25) = " << sqrt(var) << endl;
    cout << "pow(25, 2) = " << pow(var, puissance) << endl;
    if ( ageUtilisateur >= 18 ){
        cout << "tu es majeur" << endl;
    } else
        cout << "tu es mineur" << endl;

    return 0;
}
