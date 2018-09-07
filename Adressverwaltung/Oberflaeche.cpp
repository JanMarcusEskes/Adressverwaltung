#include "stdafx.h"
#include "Oberflaeche.h"


Oberflaeche::Oberflaeche()
{
}


Oberflaeche::~Oberflaeche()
{
}

void Oberflaeche::SetConsole(int piHight, int piWidth, wstring psTitle)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT size;
	COORD b_size;

	size.Left = 0;
	size.Top = 0;
	size.Right = piWidth;
	size.Bottom = piHight;
	b_size.X = piWidth + 1; //breite+1
	b_size.Y = piHight + 1; //höhe+1

	SetConsoleWindowInfo(hCon, true, &size);
	SetConsoleScreenBufferSize(hCon, b_size);


	SetConsoleTitle(psTitle.c_str());

	m_hight = piHight;
	m_width = piWidth + 1;


}

int Oberflaeche::GetMenue(wstring psMessage, wstring psTitle, bool pbRetry, bool pbReset, int piHight, int piWidth)
{
	system("cls");
	if (pbRetry && pbReset) {
		cin.clear();
		cin.ignore();
	}

	piWidth++;
	for (int i = 0; i < piHight; i++)
	{
		for (int j = 0; j < piWidth; j++)
		{
			if (i == 0 || i == piHight - 1)
				cout << "#";
			else if (j == 0 || j == piWidth - 1)
				cout << "#";
			else if (piHight / 2 == i && j == (piWidth / 2) - (psTitle.length() / 2)) {
				wcout << psTitle;
				j += psTitle.length() - 1;
			}
			else
				cout << " ";
		}
		cout << "\n";
	}
	if (!pbRetry && psMessage != L"")
		wcout << psMessage + L"\n";
	else if (pbRetry && psMessage != L""){
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, 12);
		wcout << psMessage + L"\n";
		//cout << "Sie haben keine gueltige Zahl eingegeben! Bitte wiederholen Sie die Eingabe.\n";
		SetConsoleTextAttribute(handle, 15);
	}
	else if (pbRetry && psMessage == L"")
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, 12);
		cout << "Sie haben keine gueltige Zahl eingegeben! Bitte wiederholen Sie die Eingabe.\n";
		SetConsoleTextAttribute(handle, 15);
	}
	else if (!pbRetry && psMessage == L"")
		cout << "Was moechten Sie tun ?\n";

	cout << "1. Eintrag anlegen\n2. Eintrag generieren\n3. Einträge auflisten (Details)\n4. Einträge auflisten (Liste)\n5. Einträge durchsuchen\n6. Einträge sortieren\n7. Eintrag löschen\n8. Einträge löschen\n0. Programm beenden\n\nEingabe: ";

	int liEingabe = 0;
	if (cin >> liEingabe)
		return liEingabe;
	else
		return -1;
}

void Oberflaeche::ShowPerson(vector<Personen> psPerson)
{
	system("cls");
	SetConsole(psPerson.size() * 9 + 15);
	for each (Personen person in psPerson)
	{
		wcout << L"\n" + person.toString() + L"\n";
	}
	system("pause");
	SetConsole();
}

void Oberflaeche::ShowPersonTable(vector<Personen> pvPersonen)
{
	system("cls");

	vector<int> lWidth = { 3, 6, 11, 7, 9, 9, 7, 7 };
	vector<vector<wstring>> lAusgabe;
	for each (Personen Person in pvPersonen)
	{
		vector<wstring> lPersonwstringVector = Person.toStringVector();

		for (int i = 0; i < 8; i++) {
			if (lPersonwstringVector[i].length() + 2 > lWidth[i]) {
				lWidth[i] = lPersonwstringVector[i].length() + 2;
			}
		}

		lAusgabe.push_back(Person.toStringVector());
	}


	SetConsole(lAusgabe.size() + 20, lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + lWidth[5] + lWidth[6] + lWidth[7] + 15);

	//Erste Zeile
	for (int i = 0; i < lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + lWidth[5] + lWidth[6] + lWidth[7] +1; i++)
		cout << "#";
	cout << "\n";

	//Zweite Zeile
	for (int i = 0; i < lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + lWidth[5] + lWidth[6] + lWidth[7] + 9; i++)
	{
		if (i == 0 || i == lWidth[0] + 1 || i == lWidth[0] + lWidth[1] + 2 || i == lWidth[0] + lWidth[1] + lWidth[2] + 3 || i == lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + 4 || i == lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + 5 || i == lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + lWidth[5] + 6 || i == lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + lWidth[5] + lWidth[6] + 7 || i == lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + lWidth[5] + lWidth[6] + lWidth[7] + 8)
			cout << "#";
		else if (i == 1)
		{
			string ausgabe = "ID";
			cout << ausgabe;
			i += ausgabe.length();
		}
		else if (i == lWidth[0] + 2)
		{
			string ausgabe = "Name";
			cout << ausgabe;
			i += ausgabe.length();
		}
		else if (i == lWidth[0] + lWidth[1] + 3)
		{
			string ausgabe = "Nachname";
			cout << ausgabe;
			i += ausgabe.length();
		}
		else if (i == lWidth[0] + lWidth[1] + lWidth[2] + 4)
		{
			string ausgabe = "Alter";
			cout << ausgabe;
			i += ausgabe.length();
		}
		else if (i == lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + 5)
		{
			string ausgabe = "Adresse";
			cout << ausgabe;
			i += ausgabe.length();
		}
		else if (i == lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + 6)
		{
			string ausgabe = "Telefon";
			cout << ausgabe;
			i += ausgabe.length();
		}
		else if (i == lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + lWidth[5] + 7)
		{
			string ausgabe = "Handy";
			cout << ausgabe;
			i += ausgabe.length();
		}
		else if (i == lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + lWidth[5] + lWidth[6] + 8)
		{
			string ausgabe = "E-Mail";
			cout << ausgabe;
			i += ausgabe.length();
		}
		else
			cout << " ";
	}

	cout << "\n";
	//Dritte Zeile
	for (int i = 0; i < lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + lWidth[5] + lWidth[6] + lWidth[7]+ 1; i++)
		cout << "#";

	cout << "\n";

	for each (vector<wstring> Person in lAusgabe)
	{
		for (int i = 0; i < lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + lWidth[5] + lWidth[6] + lWidth[7] + 9; i++)
		{
			if (i == 0 || i == lWidth[0] + 1 || i == lWidth[0] + lWidth[1] + 2 || i == lWidth[0] + lWidth[1] + lWidth[2] + 3 || i == lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + 4 || i == lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + 5 || i == lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + lWidth[5] + 6 || i == lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + lWidth[5] + lWidth[6] + 7 || i == lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + lWidth[5] + lWidth[6] + lWidth[7] + 8)
				cout << "#";
			else if (i == 1)
			{
				wstring ausgabe = Person[0];
				wcout << ausgabe;
				i += ausgabe.length();
			}
			else if (i == lWidth[0] + 2)
			{
				wstring ausgabe = Person[1];
				wcout << ausgabe;
				i += ausgabe.length();
			}
			else if (i == lWidth[0] + lWidth[1] + 3)
			{
				wstring ausgabe = Person[2];
				wcout << ausgabe;
				i += ausgabe.length();
			}
			else if (i == lWidth[0] + lWidth[1] + lWidth[2] + 4)
			{
				wstring ausgabe = Person[3];
				wcout << ausgabe;
				i += ausgabe.length();
			}
			else if (i == lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + 5)
			{
				wstring ausgabe = Person[4];
				wcout << ausgabe;
				i += ausgabe.length();
			}
			else if (i == lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + 6)
			{
				wstring ausgabe = Person[5];
				wcout << ausgabe;
				i += ausgabe.length();
			}
			else if (i == lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + lWidth[5] + 7)
			{
				wstring ausgabe = Person[6];
				wcout << ausgabe;
				i += ausgabe.length();
			}
			else if (i == lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + lWidth[5] + lWidth[6] + 8)
			{
				wstring ausgabe = Person[7];
				wcout << ausgabe;
				i += ausgabe.length();
			}
			else
				cout << " ";
		}
		cout << "\n";
	}
	//Letze Zeile
	for (int i = 0; i < lWidth[0] + lWidth[1] + lWidth[2] + lWidth[3] + lWidth[4] + lWidth[5] + lWidth[6] + lWidth[7] + 1; i++)
		cout << "#";
	cout << "\n\n";
	system("pause");
	SetConsole();
}
