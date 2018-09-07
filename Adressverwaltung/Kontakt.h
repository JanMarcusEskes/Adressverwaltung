#pragma once

using namespace std;

#include <string>
#include <ctime>

class Kontakt
{
public:
	Kontakt(wstring psName = L"", wstring psNachname = L"");
	Kontakt(wstring psName, wstring psNachname, wstring psTelefon, wstring psHandy);
	~Kontakt();

	void	GenerateRandomvalues();

	wstring GetEMail();
	void	SetEMail(wstring psEMail);

	wstring GetTelefon();
	void	SetTelefon(wstring psTelefon);

	wstring GetHandy();
	void	SetHandy(wstring psHandy);

private:
	wstring m_EMail;
	wstring m_Telefon;
	wstring m_Handy;
};

