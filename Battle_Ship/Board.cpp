#include "Board.h"



Board::Board(int wspx = 0, int wspy = 0, int m2s = 4, int m3s = 3, int m4s = 2, int m5s = 1)
{
	x = wspx;
	y = wspy;
	m2 = m2s;
	m3 = m3s;
	m4 = m4s;
	m5 = m5s;
}

void Board::set_x(int x)
{
	this->x = x;
}

void Board::set_y(int y)
{
	this->y = y;
}


void Board::createboard()
{

	
	for (int i = 1; i < 32; ++i) // tu ma byc 31
	{
		for (int j = 0; j < 32; ++j)
		{	

				plansza[i][j] = '.';
		}
	}

}

void Board::createenemyboard()
{
	int literka = 97;
	for (int i = 0; i < 31; ++i)
	{
		for (int j = 0; j < 31; ++j)
		{	
			
			eplansza[i][j] = '*';

		}
	}

}

void Board::createscreen()
{
	for (int i = 1; i < R; ++i)
	{
		for (int j = 1; j < 2 * R + 10; ++j)
		{
			screen[i][j] = ' ';
		}
	}
}

void Board::showboard()
{
	for (int i = 0; i < 31; ++i)
	{
		for (int j = 1; j < 31; ++j)
		{
			cout << plansza[i][j] << " ";
		}
		cout << endl;
	}
}

void Board::showscreen()
{
	for (int i = 1; i < 31; ++i)
	{
		for (int j = 1; j < 31; ++j)
		{
			screen[i][j] = plansza[i][j];
			screen[i][j + R + 5] = eplansza[i][j];
		}
	}

	for (int i = 1; i < 31; ++i)
	{
		for (int j = 1; j < 2 * R + 10; ++j) //  2 * R + 10
		{
			cout << screen[i][j] << " ";
		}
		cout << endl;
	}

}

void Board::random_board()
{
	srand(time(nullptr));
	int cordX = 0;
	int cordY = 0;
	int kierunek = 0;
	int maszty;

	cout << "Wybierz ilosc statkow:" << endl;
	cout << "Statek dwumasztowy ilosc: ";
	cin >> m2;
	cout << "Statek trojmasztowy ilosc: ";
	cin >> m3;
	cout << "Statek czteromasztowy ilosc: ";
	cin >> m4;
	cout << "Statek pieciomastrztowy ilosc: ";
	cin >> m5;

	while (m2 != 0 || m3 != 0 || m4 != 0 || m5 != 0)
	{
		bool error = 1;
		char statek = ' ';
		maszty = rand() % 4 + 2;
		switch (maszty)
		{
		case 2:
		{
			if (m2 != 0)
			{
				statek = '2';
				--m2;
				break;
			}
		}
		case 3:
		{
			if (m3 != 0)
			{
				statek = '3';
				--m3;
				break;
			}
		}
		case 4:
		{
			if (m4 != 0)
			{
				statek = '4';
				--m4;
				break;
			}

		}
		case 5:
		{
			if (m5 != 0)
			{
				statek = '5';
				--m5;
				break;
			}
			else
			{

			}

		}
		}
		if (statek != ' ')
		{
			while (error)
			{
				cordX = rand() % 30 + 1;
				cordY = rand() % 30 + 1;
				kierunek = rand() % 4 + 1;

				switch (kierunek)
				{
				case 1:
				{
					error = 0;
					for (int i = 0; i < maszty; ++i)
					{
						if ((cordY - i) < 1)
						{
							error = 1;
						}
						else if (plansza[cordX][cordY - i - 1] != '.' || plansza[cordX][cordY - i + 1] != '.'
							|| plansza[cordX - 1][cordY - i - 1] != '.' || plansza[cordX - 1][cordY - i + 1] != '.'
							|| plansza[cordX + 1][cordY - i - 1] != '.' || plansza[cordX + 1][cordY - i + 1] != '.')
						{
							error = 1;
						}
					}
					break;
				}
				case 2:
				{
					error = 0;
					for (int i = 0; i < maszty; ++i)
					{
						if ((cordY + i) > 30)
						{
							error = 1;
						}
						else if (plansza[cordX][cordY + i - 1] != '.' || plansza[cordX][cordY + i + 1] != '.'
							|| plansza[cordX - 1][cordY + i - 1] != '.' || plansza[cordX - 1][cordY + i + 1] != '.'
							|| plansza[cordX + 1][cordY + i - 1] != '.' || plansza[cordX + 1][cordY + i + 1] != '.')
						{
							error = 1;
						}
					}
					break;
				}
				case 3:
				{
					error = 0;
					for (int i = 0; i < maszty; ++i)
					{
						if ((cordX - i) < 1)
						{
							error = 1;
						}
						else if (plansza[cordX - i - 1][cordY] != '.' || plansza[cordX - i + 1][cordY] != '.'
							|| plansza[cordX - i - 1][cordY - 1] != '.' || plansza[cordX - i + 1][cordY - 1] != '.'
							|| plansza[cordX - i - 1][cordY + 1] != '.' || plansza[cordX - i + 1][cordY + 1] != '.')
						{
							error = 1;
						}
					}
					break;

				}
				case 4:
				{
					error = 0;
					for (int i = 0; i < maszty; ++i)
					{
						if ((cordX + i) > 30)
						{
							error = 1;
						}
						else if (plansza[cordX + i - 1][cordY] != '.' || plansza[cordX + i + 1][cordY] != '.'
							|| plansza[cordX + i - 1][cordY - 1] != '.' || plansza[cordX + i + 1][cordY - 1] != '.'
							|| plansza[cordX + i - 1][cordY + 1] != '.' || plansza[cordX + i + 1][cordY + 1] != '.')
						{
							error = 1;
						}
					}
					break;

				}
				}
			}

			switch (kierunek)
			{
			case 1:
			{
				for (int i = 0; i < maszty; ++i)
				{
					plansza[cordX][cordY - i] = statek;

				}
				break;
			}
			case 2:
			{

				for (int i = 0; i < maszty; ++i)
				{
					plansza[cordX][cordY + i] = statek;

				}
				break;
			}
			case 3:
			{

				for (int i = 0; i < maszty; ++i)
				{
					plansza[cordX - i][cordY] = statek;

				}
				break;

			}
			case 4:
			{

				for (int i = 0; i < maszty; ++i)
				{
					plansza[cordX + i][cordY] = statek;

				}
				break;

			}
			}
		}
	}
}



bool Board::attack(int x, int y)
{



	if (plansza[x][y] == '2' || plansza[x][y] == '3' || plansza[x][y] == '4' || plansza[x][y] == '5')
	{
		plansza[x][y] = 'o'; // zbito jedno pole
		showboard();
		cout << endl;
		return true;
		//break;
	}
	else
	{
		return false;
	}

}


void Board::nanies(int xc, int yc)
{
	eplansza[xc][yc] = 'X';
}


void Board::naniesB(int xc, int yc)
{
	eplansza[xc][yc] = '0';
}

void Board::load_ships()
{
	int cordX = 0;
	int cordY = 0;
	int kierunek = 0;
	int maszty;
	// kod do wybierania ilosci statkow
	cout << "Wybierz ilosc statkow:" << endl;
	cout << "Statek dwumasztowy ilosc: ";
	cin >> m2;
	cout << "Statek trojmasztowy ilosc: ";
	cin >> m3;
	cout << "Statek czteromasztowy ilosc: ";
	cin >> m4;
	cout << "Statek pieciomastrztowy ilosc: ";
	cin >> m5;

	while (m2 != 0 || m3 != 0 || m4 != 0 || m5 != 0)
	{
		bool error = 1;

		cout << "Statek 2 masztowy, pozostalo: " << m2 << endl
			<< "Statek 3 masztowy, pozostalo: " << m3 << endl
			<< "Statek 4 masztowy, pozostalo: " << m4 << endl
			<< "Statek 5 masztowy, pozostalo: " << m5 << endl;


		cout << "Wybierz model statku:" << endl;
		char statek = ' ';
		cin >> maszty;
		switch (maszty)
		{
		case 2:
		{
			if (m2 != 0)
			{
				statek = '2';
				--m2;
				break;
			}
		}
		case 3:
		{
			if (m3 != 0)
			{
				statek = '3';
				--m3;
				break;
			}
		}
		case 4:
		{
			if (m4 != 0)
			{
				statek = '4';
				--m4;
				break;
			}

		}
		case 5:
		{
			if (m5 != 0)
			{
				statek = '5';
				--m5;
				break;
			}
			else
			{

			}

		}
		}
		if (statek != ' ')
		{

			while (error) {
				showboard();
				cout << "Wybor wspolrzednych poczatkowych(1 - 30, w formie: x y): ";
				cin >> cordX >> cordY;
				while (cordX < 1 || cordX > 30 || cordY < 1 || cordY > 30) {
					cout << "Podales bledne wspolrzedne, sprobuj jeszcze raz" << endl;
					cin >> cordX >> cordY;
				}

				cout << "Podaj kierunek statku(1_Lewo, 2_Prawo, 3_Gora, 4_Dol): ";
				cin >> kierunek;
				while (kierunek < 1 || kierunek > 4)
				{
					cout << "Bledny kierunek, podaj jeszcze raz" << endl;
					cin >> kierunek;

				}

				switch (kierunek)
				{
				case 1:
				{
					error = 0;
					for (int i = 0; i < maszty; ++i)
					{
						if ((cordY - i) < 1)
						{
							error = 1;
						}
						else if (plansza[cordX][cordY - i - 1] != '.' || plansza[cordX][cordY - i + 1] != '.'
							|| plansza[cordX - 1][cordY - i - 1] != '.' || plansza[cordX - 1][cordY - i + 1] != '.'
							|| plansza[cordX + 1][cordY - i - 1] != '.' || plansza[cordX + 1][cordY - i + 1] != '.')
						{
							error = 1;
						}
					}
					break;
				}
				case 2:
				{
					error = 0;
					for (int i = 0; i < maszty; ++i)
					{
						if ((cordY + i) > 30)
						{
							error = 1;
						}
						else if (plansza[cordX][cordY + i - 1] != '.' || plansza[cordX][cordY + i + 1] != '.'
							|| plansza[cordX - 1][cordY + i - 1] != '.' || plansza[cordX - 1][cordY + i + 1] != '.'
							|| plansza[cordX + 1][cordY + i - 1] != '.' || plansza[cordX + 1][cordY + i + 1] != '.')
						{
							error = 1;
						}
					}
					break;
				}
				case 3:
				{
					error = 0;
					for (int i = 0; i < maszty; ++i)
					{
						if ((cordX - i) < 1)
						{
							error = 1;
						}
						else if (plansza[cordX - i - 1][cordY] != '.' || plansza[cordX - i + 1][cordY] != '.'
							|| plansza[cordX - i - 1][cordY - 1] != '.' || plansza[cordX - i + 1][cordY - 1] != '.'
							|| plansza[cordX - i - 1][cordY + 1] != '.' || plansza[cordX - i + 1][cordY + 1] != '.')
						{
							error = 1;
						}
					}
					break;

				}
				case 4:
				{
					error = 0;
					for (int i = 0; i < maszty; ++i)
					{
						if ((cordX + i) > 30)
						{
							error = 1;
						}
						else if (plansza[cordX + i - 1][cordY] != '.' || plansza[cordX + i + 1][cordY] != '.'
							|| plansza[cordX + i - 1][cordY - 1] != '.' || plansza[cordX + i + 1][cordY - 1] != '.'
							|| plansza[cordX + i - 1][cordY + 1] != '.' || plansza[cordX + i + 1][cordY + 1] != '.')
						{
							error = 1;
						}
					}
					break;

				}
				default:
				{
					cout << "Bledny kierunek" << endl;
				}
				}
				if (error) {
					system("cls");
					cout << "Nie mozna ustawic statku w ta strone" << endl;
				}
			}

			switch (kierunek)
			{
			case 1:
			{
				for (int i = 0; i < maszty; ++i)
				{
					plansza[cordX][cordY - i] = statek;

				}
				break;
			}
			case 2:
			{

				for (int i = 0; i < maszty; ++i)
				{
					plansza[cordX][cordY + i] = statek;

				}
				break;
			}
			case 3:
			{

				for (int i = 0; i < maszty; ++i)
				{
					plansza[cordX - i][cordY] = statek;

				}
				break;

			}
			case 4:
			{

				for (int i = 0; i < maszty; ++i)
				{
					plansza[cordX + i][cordY] = statek;

				}
				break;

			}
			default:
			{
				cout << "Bledny kierunek";
			}
			}

			system("cls");
			//showboard();
		}
		else
		{
			system("cls");
			cout << "Brak dostepnych statkow" << endl;
		}

	}



}






