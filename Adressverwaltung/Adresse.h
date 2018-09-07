#pragma once
using namespace std;
#include <string>
#include <ctime>

class Adresse
{
public:
	Adresse();
	Adresse(wstring psStra�e, wstring psOrt, wstring psPLZ);
	~Adresse();

	void	GenerateRandomValues();

	wstring GetStra�e();
	void	SetStra�e(wstring psStra�e);

	wstring GetOrt();
	void	SetOrt(wstring psOrt);

	wstring GetPLZ();
	void	SetPLZ(wstring psPLZ);

private:
	wstring m_Stra�e = L"";
	wstring m_Ort;
	wstring m_PLZ;
};

