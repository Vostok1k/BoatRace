#include <iostream>
#include "Boat.h"
#include <cctype> // Para tolower
#include <cstdlib> // Añadido para rand()
#include <ctime>
#include <vector> // Para utilizar vectores

using namespace std;



int main() {
    srand(time(NULL));

    int playerCount = Boat::playerQuantity(); //cantidad de barcas que van a jugar

    vector<Boat> boats; 

    for (size_t i = 0; i < playerCount; i++)
    {
        string name;
        cout << "Nombre del jugador " << i + 1 << ": ";
        cin >> name;
        boats.push_back(Boat(0, 0, 2, name));
    }

    for (size_t i = 0; i < 5; i++) {
        cout << "\t\t\t\t\t\tTurno " << i + 1 << endl;

        for (size_t j = 0; j < playerCount; j++) {
            int dice = rand() % 6 + 1;
            boats[j].setSpeed(boats[j].getSpeed() + dice);
            boats[j].setDist(boats[j].getDist() + boats[j].getSpeed() * 100);
            cout << boats[j].DistancePrint();
            boats[j].nitroFunc();
        }
        cout << "\n";
    }

    if (boats[0].getDist() > boats[1].getDist()) {
        cout << "Ha ganado " << boats[0].getName();
    }
    else if (boats[0].getDist() < boats[1].getDist()) {
        cout << "Ha ganado " << boats[1].getName();
    }
    else {
        cout << "Habeis empatado!";
    }
}
