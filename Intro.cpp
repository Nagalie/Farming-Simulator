
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdio.h>
#include<windows.h>
#include<thread>
#include<string>
using namespace std;


void Intro()
{
	Datastream = fopen("Spieldaten.dat", "r"); //Datei öffnet sich
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