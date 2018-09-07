#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include <vector>
#include "Personen.h"

using namespace std;

class Oberflaeche
	
{
public:
	Oberflaeche();
	~Oberflaeche();
	void SetConsole(int hight = 20, int width = 100, wstring title = wstring(L"Adressverwaltung"));
	int  GetMenue(wstring psMessage = wstring(L""), wstring psTitle = wstring(L"Adressverwaltung"), bool pbRetry = false, bool pbReset = true, int piHight = 5, int piWidth = 100);
	void ShowPerson(vector<Personen> psPerson);
	void ShowPersonTable(vector<Personen> pvPersonen);


	int m_width;
	int m_hight;
};

