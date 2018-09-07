#include "stdafx.h"
#include "Adresse.h"
#include <vector>

Adresse::Adresse()
{
	GenerateRandomValues();
}

Adresse::Adresse(wstring psStraße, wstring psOrt, wstring psPLZ)
{
	m_Straße = psStraße;
	m_Ort = psOrt;
	m_PLZ = psPLZ;
}

Adresse::~Adresse()
{
}

void Adresse::GenerateRandomValues()
{

	std::vector<wstring> lsvStraßen = { L"Badstraße",L"Turmstraße",L"Südbahnhof",L"Chausseestraße",L"Elisenstraße",L"Poststraße",L"Seestraße",L"Elektrizitätswerk",L"Hafenstraße",L"Neue Straße",L"Westbahnhof",L"Münchner Straße",L"Wiener Straße",L"Berliner Straße",L"Theaterstraße",L"Museumsstraße",L"Opernplatz",L"Nordbahnhof",L"Lessingstraße",L"Schillerstraße",L"Wasserwerk",L"Goethestraße",L"Rathausplatz",L"Hauptstraße",L"Bahnhofstraße",L"Hauptbahnhof",L"Parkstraße",L"Schloßallee" };
	m_Straße = wstring(lsvStraßen[rand() % lsvStraßen.size()]) + wstring(L" ") + wstring(to_wstring((rand() % 50) + 1 ).c_str());

	std::vector<wstring> lsvOrte = { L"Berlin",L"Hamburg",L"München",L"Köln",L"Frankfurt",L"Stuttgart",L"Düsseldorf",L"Dortmund",L"Essen",L"Leipzig",L"Bremen",L"Dresden",L"Hannover",L"Nürnberg",L"Duisburg",L"Bochum",L"Wuppertal",L"Bielefeld",L"Bonn",L"Münster" };
	m_Ort = lsvOrte[rand() % lsvOrte.size()];

	m_PLZ = to_wstring(rand() % 89999 + 10001).c_str();
}

wstring Adresse::GetStraße()
{
	return m_Straße;
}

void Adresse::SetStraße(wstring psStraße)
{
	m_Straße = psStraße;
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
