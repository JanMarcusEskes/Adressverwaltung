#include "stdafx.h"
#include "Verwaltung.h"


Verwaltung::Verwaltung()
{
}

Verwaltung::~Verwaltung()
{
}

#pragma region Sortieren

int Verwaltung::getPivot(int piBegin, int piEnd, std::vector<Personen> &pcokData)
{
	int i = piBegin;
	int j = piEnd - 1;
	Personen lpPivot = pcokData[piEnd];

	do
	{
		while (pcokData[i].GetName() + pcokData[i].GetNachname() < lpPivot.GetName() + lpPivot.GetNachname() && i < piEnd - 1)
		{
			i++;
		}

		while (pcokData[j].GetName() + pcokData[j].GetNachname() >= lpPivot.GetName() + lpPivot.GetNachname() && j > piBegin)
		{
			j--;
		}

		if (i < j)
		{
			Personen liTemp = pcokData[i];
			pcokData[i] = pcokData[j];
			pcokData[j] = liTemp;
		}

	} while (i < j);

	if (pcokData[i].GetName() >= lpPivot.GetName())
	{
		Personen liTemp = pcokData[i];
		pcokData[i] = pcokData[piEnd];
		pcokData[piEnd] = liTemp;
		return i;
	}
	else
	{
		return piEnd;
	}
}

void Verwaltung::quicksort(int piBegin, int piEnd, std::vector<Personen> &pcokData)
{
	if (piBegin < piEnd)
	{
		int liPivot = getPivot(piBegin, piEnd, pcokData);
		quicksort(piBegin, liPivot - 1, pcokData);
		quicksort(liPivot + 1, piEnd, pcokData);
	}
}

void Verwaltung::newID(vector<Personen> &pcokPersonen)
{
	for (int i = 0; i < pcokPersonen.size(); ++i)
		pcokPersonen[i].SetID(i);
}

#pragma endregion

#pragma region Daten speichern/lesen

void Verwaltung::StringsToPersonen(vector<wstring> psLine, vector<Personen> &pvPersonen)
{
	for each (wstring zeile in psLine)
	{
		vector<wstring> felder;
		int start = 0;
		int end = zeile.find('|', 0);
		int length = end - start;
		felder.push_back(zeile.substr(start, length));

		for (int i = 0; i < 7; i++)
		{
			start = end;
			end = zeile.find('|', end + 1);
			length = end - start;
			felder.push_back(zeile.substr(start + 1, length - 1));
		}

		Personen person = Personen(felder[0], felder[1], felder[2], felder[3], felder[4], felder[5], felder[6], felder[7], pvPersonen.size());
		pvPersonen.push_back(person);
	}
}

vector<Personen> Verwaltung::PersonenEinlesen(wstring psPfad, bool &pbpFail)
{
	system("cls");

	wcout << L"Die Daten werden eingelesen ...\n\nFortschritt:\n0%" << L"\r" << flush;

	vector<Personen> lPersonenAusgabe;
	vector<wstring> lEingelesen;
	wifstream Datei;  // Datei-Handle
	wstring ausgabe = L"";
	Datei.open(psPfad, ios::in); // Öffne Datei aus Parameter

	getline(Datei, ausgabe);

	int Max = 0;
	int i = 0;
	int liPercent = 0;
	int tmpPercent = 0;

	try
	{
		Max = stoi(ausgabe);
	}
	catch (const std::exception&)
	{
		pbpFail = true;
		return lPersonenAusgabe;
	}

	while (getline(Datei, ausgabe))          // Solange noch Daten vorliegen
	{
		lEingelesen.push_back(ausgabe);

		if (i % 1000 == 0) {
			StringsToPersonen(lEingelesen, lPersonenAusgabe);
			lEingelesen.clear();
		}

		liPercent = (i * (100.0 / Max));
		i++;
		if (tmpPercent + 2 == liPercent)
		{
			tmpPercent = liPercent;
			wcout << to_wstring(liPercent) << L"%\r" << flush;
		}
	}
	if (lEingelesen.size() > 0)
	{
		StringsToPersonen(lEingelesen, lPersonenAusgabe);
		lEingelesen.clear();
	}

	Datei.close();
	return lPersonenAusgabe;
}

bool Verwaltung::PersonenSpeichern(wstring psPfad, vector<Personen> pvPersonen)
{
	system("cls");
	wcout << L"Die Daten werden gespeichert ...\nProgramm wird automatisch beendet!\n\nFortschritt:\n0%" << L"\r" << flush;

	try {
		wfstream Datei(psPfad, ios::out);

		int liPercent = 0;
		int Max = pvPersonen.size();
		int tmpPercent = 0;

		Datei << to_wstring(Max) << endl;

		for each (Personen Person in pvPersonen)
		{
			Datei << Person.toSaveString() << endl;

			liPercent = Person.GetIntID() * (100.0 / Max);
			if (tmpPercent + 2 == liPercent)
			{
				tmpPercent = liPercent;
				//system("cls");
				wcout << to_wstring(liPercent) << L"%\r" << flush;
			}
		}
	}
	catch (...)
	{
		return false;
	}
	return true;
}

#pragma endregion

#pragma region Menüpunkte

wstring Verwaltung::AddEntry(vector<Personen> &pcokPersonen, bool &pbChanges, Oberflaeche &poOberflaeche)
{
	cin.ignore();

	string einträge[8] = { "den Vornamen", "den Nachnamen", "das Alter", "die Telefonnummer", "die Handynummer", "die Strasse und Hausnummer", "den Ort", "die Postleitzahl" };
	wstring eingaben[8];
	int i = 0;

	poOberflaeche.SetConsole(50);

	for (int i = 0; i < 8; i++)
	{
		system("cls");
		cout << "Bitte geben Sie " + einträge[i] + " ein.\nEingabe: ";
		getline(wcin, eingaben[i]);
	}

	Personen lPerson(eingaben[0], eingaben[1], eingaben[2], eingaben[3], eingaben[4], eingaben[5], eingaben[6], eingaben[7], pcokPersonen.size());
	pcokPersonen.push_back(lPerson);

	pbChanges = true;
	return L"Aktion erfolgreich durchgefuehrt.";
}

wstring Verwaltung::GenerateEntrys(vector<Personen>& pcokPersonen, bool & pbChanges)
{
	system("cls");
	cout << "Bitte geben Sie ein, wie viele Einträge Sie generieren wollen.\nEingabe: ";
	int liEingabe = 0;
	if (cin >> liEingabe)
	{
		system("cls");
		wcout << "Einträge werden generiert.\n\nFortschritt:\n0%\r" << flush;

		int liPercent = 0;
		int Max = liEingabe;
		int tmpPercent = 0;

		for (int j = 0; j < liEingabe; j++)
		{
			Personen lPerson;
			lPerson.GenerateRandomValues(pcokPersonen.size());
			pcokPersonen.push_back(lPerson);
			liPercent = j * (100.0 / Max);
			if (tmpPercent + 2 == liPercent)
			{
				tmpPercent = liPercent;
				wcout << to_wstring(liPercent) << L"%\r" << flush;
			}
		}

		pbChanges = true;
		return L"Aktion erfolgreich durchgefuehrt.";
	}
	else
		return L"";
}

wstring Verwaltung::SearchEntrys(vector<Personen>& pcokPersonen, Oberflaeche & poOberflaeche)
{
	cin.ignore();
	system("cls");
	wcout << L"Wie lautet der Suchbegriff?\n\nSuchbegriff: ";
	wstring lsEingabe;
	getline(wcin, lsEingabe);

	vector<Personen> lcokFoundedPersons;

	for (Personen person : pcokPersonen)
	{
		if (person.GetName().find(lsEingabe) != string::npos || person.GetNachname().find(lsEingabe) != string::npos || person.GetAdresse().GetStraße().find(lsEingabe) != string::npos || person.GetAdresse().GetOrt().find(lsEingabe) != string::npos)
			lcokFoundedPersons.push_back(person);
	}
	poOberflaeche.ShowPersonTable(lcokFoundedPersons);
	return L"Aktion erfolgreich durchgefuehrt.";
}

wstring Verwaltung::SortEntrys(vector<Personen>& pcokPersonen, bool & pbChanges)
{
	system("cls");
	cout << "Vorgang wird bearbeitet, bitte warten ...";

	quicksort(0, pcokPersonen.size() - 1, pcokPersonen);
	newID(pcokPersonen);

	pbChanges = true;
	return L"Aktion erfolgreich durchgefuehrt.";
}

wstring Verwaltung::DeleteEntry(vector<Personen>& pcokPersonen, bool &pbChanges)
{
	system("cls");
	cout << "Bitte geben Sie die ID ein, dessen Eintrag Sie löschen möchten.\nEingabe: ";
	int liEingabe = 0;
	if (cin >> liEingabe)
	{
		if (liEingabe >= pcokPersonen.size())
			return L"";
		else
		{
			pcokPersonen.erase(pcokPersonen.begin() + liEingabe);

			newID(pcokPersonen);

			pbChanges = true;
			return L"Aktion erfolgreich durchgefuehrt.";
		}
	}
	else
		return L"";
}

#pragma endregion

wstring Verwaltung::Menue(int piMenuepunkt, bool &pbpChanges)
{
	Oberflaeche lOberflaeche = Oberflaeche();

	switch (piMenuepunkt)
	{
	case 0:	//Programm beenden
	{
		if (pbpChanges)
			PersonenSpeichern(L"D:\\Contacts.txt", m_PersonenVector);
		return L"false";
	}
	case 1: //Eintrag anlegen
	{
		return AddEntry(m_PersonenVector, pbpChanges, lOberflaeche);
	}
	case 2:	//Einträge generieren
	{
		return GenerateEntrys(m_PersonenVector, pbpChanges);
	}
	case 3: //Anzeigen (Details)
	{
		lOberflaeche.ShowPerson(m_PersonenVector);
		return L"Aktion erfolgreich durchgefuehrt.";
	}
	case 4:	//Anzeigen (Tabelle)
	{
		lOberflaeche.ShowPersonTable(m_PersonenVector);
		return L"Aktion erfolgreich durchgefuehrt.";
	}
	case 5: //Durchsuchen
	{
		return SearchEntrys(m_PersonenVector, lOberflaeche);
	}
	case 6:	//Sortieren
	{
		SortEntrys(m_PersonenVector, pbpChanges);
	}
	case 7: //Bestimmte Löschen
	{
		return DeleteEntry(m_PersonenVector, pbpChanges);
	}
	case 8: //Alle löschen
	{
		m_PersonenVector.clear();
		pbpChanges = true;
		return L"Aktion erfolgreich durchgefuehrt.";
	}
	default: //Fehleingabe
	{
		return L"";
	}
	}
}
