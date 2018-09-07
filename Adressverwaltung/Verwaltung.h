#pragma once
#include <string>
#include <vector>
#include "Personen.h"
#include <fstream>
#include <iterator>
#include <thread>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Oberflaeche.h"

using namespace std;

class Verwaltung
{
public:
	Verwaltung();
	~Verwaltung();

	void				StringsToPersonen	(vector<wstring> psLine, vector<Personen> &pvPersonen);
	vector<Personen>    PersonenEinlesen	(wstring psPfad, bool &pbpFail);
	bool				PersonenSpeichern	(wstring psPfad, vector<Personen> pvPersonen);

	void				newID				(vector<Personen> &pcokPersonen);

	wstring				AddEntry			(vector<Personen> &pcokPersonen, bool &pbChanges, Oberflaeche &poOberflaeche);
	wstring				GenerateEntrys		(vector<Personen> &pcokPersonen, bool &pbChanges);
	wstring				SearchEntrys		(vector<Personen> &pcokPersonen, Oberflaeche &poOberflaeche);
	wstring				SortEntrys			(vector<Personen> &pcokPersonen, bool &pbChanges);
	wstring				DeleteEntry			(vector<Personen> &pcokPersonen, bool &pbChanges);

	void				quicksort			(int piBegin, int piEnd, std::vector<Personen> &pcokData);
	int					getPivot			(int piBegin, int piEnd, std::vector<Personen> &pcokData);

	wstring				Menue				(int piMenuepunkt, bool &pbpChanges);

	vector<Personen>	m_PersonenVector;
};

