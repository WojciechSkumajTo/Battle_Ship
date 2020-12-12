// Battle_Ship.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Board.h"


using namespace std;




int main()
{
	Board b1(0, 0, 4, 3, 2, 1);
	Board b2(0, 0, 4, 3, 2, 1);
	b1.createboard();
	b1.createenemyboard();
	b1.createscreen();
	b2.createboard();
	b2.createenemyboard();
	b2.createscreen();
	int x;
	int y;
	int menu1, menu2;
	bool trafiony=0;
	
	//gracz1
	cout << "rozstawianie statkow gracz 1:\n 1 - Automatyczne\n 2 - Reczne\n";
	cin >> menu1;
	if (menu1 == 1)
	{
		b1.random_board();
		system("cls");
	}
	else if (menu1 == 2)
	{
		system("cls");
		b1.load_ships();
	}
	else
	{
		cout << "bledna opcja, wychodze";
		return 0;
	}
	system("cls");
	//gracz2
	cout << "rozstawianie statkow gracz 2:\n 1 - Automatyczne\n 2 - Reczne\n";
	cin >> menu2;
	if (menu2 == 1) {
		b2.random_board();
		system("cls");
	}
	else if (menu2 == 2) 
	{
		system("cls");
		b2.load_ships();
	}
	else
	{
		cout << "bledna opcja, wychodze";
		return 0;
	}

	
	while (true)
	{
		system("cls");
		cout << "*GRACZ 1*\n";
		b1.showscreen();

		cout << "Podaj wspolrzedne ataku(x y)" << endl;
		cin >> x >> y;
		while (x < 1 || y < 1 || x>30 || y>30)
		{
			cout << "Bledne wspolrzedne, podaj jeszcze raz" << endl;
			cin >> x >> y;
		}
		trafiony = b2.attack(x, y);
		while (trafiony)
		{
			system("cls");
			cout << "*GRACZ 1*\n";
			b1.nanies(x, y);
			b1.showscreen();
			cout << "Trafiony" << endl;
			cout << "Podaj nastepne wspolrzedne: ";
			cin >> x >> y;
			trafiony = b2.attack(x, y);

		}
		system("cls");
		cout << "Pudlo, teraz nastepny gracz" << endl;
		b1.naniesB(x, y);
		system("pause");
		

		system("cls");
		cout << "*GRACZ 2*\n";
		b2.showscreen();

		cout << "Podaj wspolrzedne ataku(x y)" << endl;
		cin >> x >> y;
		while (x < 1 || y < 1 || x>30 || y>30)
		{
			cout << "Bledne wspolrzedne, podaj jeszcze raz" << endl;
			cin >> x >> y;
		}
		trafiony = b1.attack(x, y);
		while (trafiony)
		{
			system("cls");
			cout << "*GRACZ 2*\n";
			b2.nanies(x, y);
			b2.showscreen();
			cout << "Trafiony" << endl;
			cout << "Podaj nastepne wspolrzedne: ";
			cin >> x >> y;
			trafiony = b1.attack(x, y);

		}
		system("cls");
		cout << "Pudlo, teraz nastepny gracz" << endl;
		b2.naniesB(x, y);
		system("pause");
		
	}

	return 0;
}


