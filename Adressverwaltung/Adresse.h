#pragma once
using namespace std;
#include <string>
#include <ctime>

class Adresse
{
public:
	Adresse();
	Adresse(wstring psStraﬂe, wstring psOrt, wstring psPLZ);
	~Adresse();

	void	GenerateRandomValues();

	wstring GetStraﬂe();
	void	SetStraﬂe(wstring psStraﬂe);

	wstring GetOrt();
	void	SetOrt(wstring psOrt);

	wstring GetPLZ();
	void	SetPLZ(wstring psPLZ);

private:
	wstring m_Straﬂe = L"";
	wstring m_Ort;
	wstring m_PLZ;
};

