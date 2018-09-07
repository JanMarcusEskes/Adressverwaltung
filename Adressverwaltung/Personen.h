#pragma once

using namespace std;

#include <string>
#include "Adresse.h"
#include "Kontakt.h"
#include <vector>


class Personen
{
public:
	Personen();
	Personen(wstring psName , wstring psNachname, wstring psAlter, wstring psTelefon, wstring psHandy, wstring psStarﬂe, wstring psOrt, wstring psPLZ, int piID);
	~Personen();

	void	GenerateRandomValues(int piID);

	wstring GetID();
	int		GetIntID();
	void	SetID(int piID);
	
	wstring GetName();
	void	SetName(wstring psName);

	wstring GetNachname();
	void	SetNachname(wstring psNachname);

	wstring	GetAlter();
	void	SetAlter(int piAlter);
	
	Adresse GetAdresse();
	void	SetAdresse(Adresse paAdresse);

	Kontakt GetKontakt();
	void	SetKontakt(Kontakt pkKontakt);

	wstring toString();
	vector<wstring> toStringVector();
	wstring toSaveString();

private:

	int m_ID;
	wstring m_Name = L"";
	wstring m_Nachname = L"";
	wstring	m_Alter = L"";
	Adresse m_Adresse;
	Kontakt m_Kontakt;
};

