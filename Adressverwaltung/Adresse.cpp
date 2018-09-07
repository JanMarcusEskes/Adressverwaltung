#include "stdafx.h"
#include "Adresse.h"
#include <vector>

Adresse::Adresse()
{
	GenerateRandomValues();
}

Adresse::Adresse(wstring psStra�e, wstring psOrt, wstring psPLZ)
{
	m_Stra�e = psStra�e;
	m_Ort = psOrt;
	m_PLZ = psPLZ;
}

Adresse::~Adresse()
{
}

void Adresse::GenerateRandomValues()
{

	std::vector<wstring> lsvStra�en = { L"Badstra�e",L"Turmstra�e",L"S�dbahnhof",L"Chausseestra�e",L"Elisenstra�e",L"Poststra�e",L"Seestra�e",L"Elektrizit�tswerk",L"Hafenstra�e",L"Neue Stra�e",L"Westbahnhof",L"M�nchner Stra�e",L"Wiener Stra�e",L"Berliner Stra�e",L"Theaterstra�e",L"Museumsstra�e",L"Opernplatz",L"Nordbahnhof",L"Lessingstra�e",L"Schillerstra�e",L"Wasserwerk",L"Goethestra�e",L"Rathausplatz",L"Hauptstra�e",L"Bahnhofstra�e",L"Hauptbahnhof",L"Parkstra�e",L"Schlo�allee" };
	m_Stra�e = wstring(lsvStra�en[rand() % lsvStra�en.size()]) + wstring(L" ") + wstring(to_wstring((rand() % 50) + 1 ).c_str());

	std::vector<wstring> lsvOrte = { L"Berlin",L"Hamburg",L"M�nchen",L"K�ln",L"Frankfurt",L"Stuttgart",L"D�sseldorf",L"Dortmund",L"Essen",L"Leipzig",L"Bremen",L"Dresden",L"Hannover",L"N�rnberg",L"Duisburg",L"Bochum",L"Wuppertal",L"Bielefeld",L"Bonn",L"M�nster" };
	m_Ort = lsvOrte[rand() % lsvOrte.size()];

	m_PLZ = to_wstring(rand() % 89999 + 10001).c_str();
}

wstring Adresse::GetStra�e()
{
	return m_Stra�e;
}

void Adresse::SetStra�e(wstring psStra�e)
{
	m_Stra�e = psStra�e;
}

wstring Adresse::GetOrt()
{
	return m_Ort;
}

void Adresse::SetOrt(wstring psOrt)
{
	m_Ort = psOrt;
}

wstring Adresse::GetPLZ()
{
	return m_PLZ;
}

void Adresse::SetPLZ(wstring psPLZ)
{
	m_PLZ = psPLZ;
}
