#include "Boat.h"
#include <iostream>
#include <chrono> //sleep
#include <thread>

int Boat::getSpeed() {
	return speed;
}
void Boat::setSpeed(int pSpeed) {
	speed = pSpeed;
}

int Boat::getDist() {
	return distance;
}
void Boat::setDist(int pDist) {
	distance = pDist;
}

int Boat::getNitro() {
	return nitro;
}
void Boat::setNitro(int pNitro) {
	nitro = pNitro;
}

string Boat::getName() {
	return name;
}

void Boat::setName(string pName) {
	name = pName;
}

void Boat::getParams() {
	cout << "Speed: " << speed << "\n";
	cout << "Distance: " << distance << "\n";
	cout << "Nitro: " << nitro << "\n";
	cout << "Nombre: " << name << "\n";
}

string Boat::DistancePrint() {
	int diceBoat = distance / 100;
    string print = "";
	getParams();
	for (size_t i = 0; i < diceBoat; i++)
	{
		 print += "#";
	}
    print += "\n";
    return print;    
}

void Boat::nitroFunc() {
    char nitroUse;
    bool flag = false;
    if (nitro == 2) {
        do {
            printSlowly("Quieres utilizar el nitro? (S/N)", speed);
            cin >> nitroUse;
            cout << "\n";
            nitroUse = tolower(nitroUse);
            if (nitroUse == 's') {
                setNitro(1);
                flag = true;
                int dice = rand() % 2;
                if (dice == 1) {
                    setSpeed(getSpeed() * 2);
                    printSlowly("Tu velocidad se ha duplicado :)\n", speed);
                }
                else {
                    setSpeed(getSpeed() / 2);
                    printSlowly("Tu velocidad se ha reducido a la mitad :(\n", speed);
                }
            }
            else if (nitroUse == 'n') {
                flag = true;
            }
            else {
                cout << "Valor incorrecto. (S/N)" << endl;
            }
        } while (!flag);
    }
}

int Boat::playerQuantity() {
    int playerCount = 0;
    do
    {
        cout << "Cuantos jugadores sois? ";
        cin >> playerCount;
        cout << "\n";
    } while (playerCount < 2 || playerCount > 5);

    return playerCount;
}


void Boat::printSlowly(const string& message, unsigned int millisecondsPerCharacter) { //función para imprimir el texto lentamente
    for (char c : message) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(millisecondsPerCharacter));
    }
}

Boat::Boat(int pSpeed, int pDist, int pNitro, string pName) {
	speed = pSpeed;
	distance = pDist;
	nitro = pNitro;
	name = pName;
}

