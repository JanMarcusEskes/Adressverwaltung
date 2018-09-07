#include "stdafx.h"
#include "Kontakt.h"


Kontakt::Kontakt(wstring psName, wstring psNachname)
{
	m_EMail = psName + _T(".") + psNachname + _T("@klaes.com");
	GenerateRandomvalues();
}

Kontakt::Kontakt(wstring psName, wstring psNachname, wstring psTelefon, wstring psHandy)
{
	m_Telefon = psTelefon;
	m_Handy = psHandy;
	m_EMail = psName + _T(".") + psNachname + _T("@klaes.com");
}


Kontakt::~Kontakt()
{
}

void Kontakt::GenerateRandomvalues()
{
	m_Telefon = wstring(to_wstring((rand() % 99999999) + 10000).c_str());
	m_Handy = wstring(to_wstring((rand() % 99999999) + 10000).c_str());

}

wstring Kontakt::GetEMail()
{
	return m_EMail;
}

void Kontakt::SetEMail(wstring psEMail)
{
	m_EMail = psEMail;
}

wstring Kontakt::GetTelefon()
{
	return m_Telefon;
}

void Kontakt::SetTelefon(wstring psTelefon)
{
	m_Telefon = psTelefon;
}

wstring Kontakt::GetHandy()
{
	return m_Handy;
}

void Kontakt::SetHandy(wstring psHandy)
{
	m_Handy = psHandy;
}
