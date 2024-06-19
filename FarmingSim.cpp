#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdio.h>
#include<windows.h>
#include<thread>
using namespace std;

string sName, sFarmName, strEingabe;
//pointer auf file
FILE* Datastream;
char cKaufen;
int iMoney = 50;
int HowMuchFarm = 1;
bool back = false;
bool subback = false;

bool updateMoneyNow = false;

int FarmLand = 0;

void welcome();
void Intro();
void Game();
void machGeld();
void moveCursor(int x, int y);

int main()
{
	system("color 0B");
	welcome();
	system("cls");
	Intro();
	system("cls");
	Game();


	system("Pause");
	return 0;
}

void welcome()
{
	cout << " ,ggg,      gg      ,gg" << endl;
	cout << "dP\"\"Y8a     88     ,8P        ,dPYb," << endl;
	cout << "Yb, `88     88     d8'        IP'`Yb" << endl;
	cout << " `\"  88     88     88         I8  8I" << endl;
	cout << "     88     88     88         I8  8'" << endl;
	cout << "     88     88     88 ,ggg,   I8 dP    ,gggg,    ,ggggg,    ,ggg,,ggg,,ggg,    ,ggg," << endl;
	cout << "     88     88     88i8\" \"8i  I8dP    dP\"  \"Yb  dP\"  \"Y8ggg,8\" \"8P\" \"8P\" \"8,  i8\" \"8i" << endl;
	cout << "     88     88     8PI8, ,8I  I8P    i8'       i8'    ,8I  I8   8I   8I   8I  I8, ,8I" << endl;
	cout << "     Y8    ,88,    8PI8, ,8I  I8P    i8'       i8'    ,8I  I8   8I   8I   8I  I8, ,8I" << endl;
	cout << "      Yb,,d8\"\"8b,,dP `YbadP' ,d8b,_ ,d8,_    _,d8,   ,d8' ,dP   8I   8I   Yb, `YbadP'" << endl;
	cout << "       \"88\"    \"88\" 888P\"Y8888P'\"Y88P\"\"Y8888PPP\"Y8888P\"   8P'   8I   8I   `Y8888P\"Y888" << endl << endl << endl << endl << endl << endl;

	cout << "                              Press enter to start the game!";

	cin.get();
}

void Intro()
{
	Datastream = fopen("Spieldaten.dat", "r"); //Datei �ffnet sich
	if (Datastream == NULL) //Wenn Datei vorhanden ist dann kein intro
	{
		Datastream = fopen("Spieldaten.dat", "w+");

		cout << "???: ";
		cin.get();
		system("cls");
		cout << "???: ";
		//Text output
		char Intro1[] = " Hey! What's your Name?";
		for (int i = 0; i < strlen(Intro1); i++)
		{
			Sleep(3);
			putchar(Intro1[i]);
			fflush(stdout);
		}

		cout << "\nName: ";
		cin >> sName;
		cin.get();

		//Der Name wird in die Datei geschrieben
		fwrite(&sName, sizeof(sName), 1, Datastream);

		cout << "???: ";
		cin.get();

		char Intro2[] = "Nice to meet you ";
		char Intro3[] = ". My Name is Natalie and I'm the mayor in this City.\nWhat is your Farms Name?";
		//Text output 2
		for (int i = 0; i < strlen(Intro2); i++)
		{
			Sleep(3);
			putchar(Intro2[i]);
			fflush(stdout);
		}

		cout << sName;

		//Text output 3
		for (int i = 0; i < strlen(Intro3); i++)
		{
			Sleep(3);
			putchar(Intro3[i]);
			fflush(stdout);
		}

		cout << "\nFarms Name: ";
		cin >> sFarmName;
		//Farmname wird in die Datei geschrieben
		fwrite(&sFarmName, sizeof(sFarmName), 1, Datastream);
	}
	//Datei wird geschlossen
	fclose(Datastream);
}

void Game()
{
	/*Datastream = fopen("Spieldaten.dat", "w+");
	while (!feof(Datastream))
	{
		fread(&sFarmName, sizeof(sFarmName), 1, Datastream);
		cout << "Farmname: " << sFarmName;
	}*/

	do {
		system("cls");

		back = false;
		updateMoneyNow = true;
		cout << "Money: " << iMoney << "\tPress i for information\n" << endl << endl;
		cin >> cKaufen;

		switch (cKaufen)
		{
		case 'i':
		{
			do {
				updateMoneyNow = false;
				system("cls");
				cout << "Information:\n\n";
				cout << "type \"exit\" to get back\n\n";

				cin >> strEingabe;
				if (strEingabe == "Exit" || strEingabe == "exit")
				{
					back = true;
					subback = true;
				}
				else
				{
					cout << "No valid input.";
					subback = false;
					cin.get(); cin.get();

				}
			} while (subback == false);

		};
		break;
		case '1':
		{
			thread first(machGeld);
			first.detach();
			back = true;
		}
		break;
		default: {
			system("cls");
			cout << "Money: " << iMoney << "\tPress i for information\n" << endl << endl;
			cout << "no valid input";
			back = true;
			cin.get(); cin.get();
		}
			   break;
		}

	} while (back == true);
	cout << "programm beenden" << endl;
	Sleep(1000);
}

void updateMoney() {
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

		GetConsoleScreenBufferInfo(consoleHandle, &consoleInfo);
		COORD savedCursorPosition = consoleInfo.dwCursorPosition;

		moveCursor(0, 0);

		cout << "Money: " << iMoney << "\tPress i for information\n" << endl << endl;

		//system("pause");

		SetConsoleCursorPosition(consoleHandle, savedCursorPosition);
}

void moveCursor(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	cursorPosition.X = x;
	cursorPosition.Y = y;
	SetConsoleCursorPosition(consoleHandle, cursorPosition);
}

void machGeld()
{

	iMoney -= 30;
	HowMuchFarm =+ 1;
	while(true) {
		iMoney = iMoney + 2 * HowMuchFarm;
		if (updateMoneyNow) {
			updateMoney();
		}
		Sleep(2000);
	}

}

//Pastelgr�n farbe outputten
//Threads hinbekommen und mehr dar�ber hrausfinden