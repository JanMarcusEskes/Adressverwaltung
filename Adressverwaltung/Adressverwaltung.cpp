
// Adressverwaltung.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Verwaltung.h"
#include "Oberflaeche.h"



int main()
{
	InitStdKlaes();

	Oberflaeche lOberflaeche = Oberflaeche();
	Verwaltung lVerwaltung = Verwaltung();

	lOberflaeche.SetConsole();

	bool lbFail = false;
	bool lbChanges = false;
	lVerwaltung.m_PersonenVector = lVerwaltung.PersonenEinlesen(L"D:\\Contacts.txt", lbFail);

	wstring lsLoop;
	int liAuswahl = -1;

	do
	{
		if (liAuswahl == -1 && lbFail)
			liAuswahl = lOberflaeche.GetMenue(L"Die Datendatei konnte nicht gelesen werden!", L"Adressverwaltung", true, false);
		else if (liAuswahl != -1 && lsLoop == L"")
			liAuswahl = lOberflaeche.GetMenue(L"", L"Adressverwaltung", true);
		else
			liAuswahl = lOberflaeche.GetMenue(lsLoop);
		lsLoop = lVerwaltung.Menue(liAuswahl, lbChanges);

	} while (lsLoop != L"false");
    

	CleanupStdKlaes();
	return 0;
}

