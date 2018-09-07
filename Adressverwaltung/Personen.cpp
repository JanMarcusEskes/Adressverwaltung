#include "stdafx.h"
#include "Personen.h"

Personen::Personen()
{
}

Personen::Personen(wstring psName, wstring psNachname, wstring psAlter, wstring psTelefon, wstring psHandy, wstring psStarße, wstring psOrt, wstring psPLZ, int piID)
{
	m_Name = psName;
	m_Nachname = psNachname;
	m_Alter = psAlter;
	m_Adresse = Adresse(psStarße, psOrt, psPLZ);
	m_Kontakt = Kontakt(m_Name, m_Nachname, psTelefon, psHandy);
	m_ID = piID;
}

Personen::~Personen()
{
}

void Personen::GenerateRandomValues(int piID)
{
	vector<wstring> lsvNamen = { L"Adrian",L"Aimée",L"Albert",L"Alexander",L"Alexandra",L"Alexis",L"Alina",L"Amadeus",L"Amelie",L"Amy",L"Anabella",L"Andrea",L"Anja",L"Ann",L"Anna",L"Annemaria",L"Annette",L"Anouk",L"Anton",L"Arthur",L"Asia",L"Aurelia",L"Ava",L"Avan",L"Babette",L"Barbara",L"Baris",L"Basil",L"Bastian",L"Bea",L"Beatrix",L"Bekir",L"Belina",L"Bella",L"Ben",L"Benedikt",L"Benita",L"Benjamin",L"Bennet",L"Benno",L"Bent",L"Bente",L"Berenike",L"Berit",L"Bernd",L"Betta",L"Bettina",L"Bianca",L"Bilal",L"Birgit",L"Birk",L"Birte",L"Bjarne",L"Björn",L"Blanka",L"Bodo",L"Bonnie",L"Boris",L"Bosse",L"Breanna",L"Brigitte",L"Bruno",L"Bryan",L"Béla",L"Caesar",L"Caitlyn",L"Carina",L"Carla",L"Carline",L"Carlo",L"Carolin",L"Caspar",L"Catalina",L"Cecilia",L"Cedric",L"Celia",L"Celina",L"Chantal",L"Charlene",L"Charlotte",L"Chiara",L"Chris",L"Christian",L"Christin",L"Christina",L"Christoph",L"Ciara",L"Claas",L"Clara",L"Clarissa",L"Claudio",L"Claudius",L"Clemens",L"Cleo",L"Colin",L"Coralie",L"Corinna",L"Cornelius",L"Cosima",L"Cressida",L"Cristiano",L"Curly",L"Dajana",L"Dalika",L"Damian",L"Dana",L"Danial",L"Daniel",L"Daniela",L"Danika",L"Dante",L"Daphne",L"Daria",L"Darius",L"David",L"Daya",L"Denis",L"Diana",L"Dilara",L"Dirk",L"Dominik",L"Dorothea",L"Douglas",L"Dunja",L"Edith",L"Eduard",L"Eike",L"Ela",L"Elana",L"Elena",L"Elenor",L"Elias",L"Eliot",L"Elisabeth",L"Elisann",L"Elise",L"Ellen",L"Emanuel",L"Emanuela",L"Emelie",L"Emil",L"Emilia",L"Emma",L"Enja",L"Enzo",L"Erik",L"Esther",L"Eva",L"Fabian",L"Fabienne",L"Fabio",L"Fabiola",L"Falk",L"Fang",L"Fanny",L"Farid",L"Fatima",L"Fee",L"Felia",L"Felicitas",L"Felipa",L"Felix",L"Fenja",L"Ferdinand",L"Fida",L"Fidelia",L"Findus",L"Finja",L"Finjas",L"Finley",L"Finn",L"Fiona",L"Firat",L"Florens",L"Florentine",L"Florian",L"Florin",L"Florine",L"Floyd",L"Frank",L"Franka",L"Franziska",L"Frauke",L"Frederike",L"Freya",L"Fridolin",L"Frieda",L"Fritz",L"Frédéric",L"Fudo",L"Fujita",L"Gabriel",L"Gabriela",L"Geert",L"Geertje",L"Geneviève",L"Gent",L"Geoffrey",L"Georg",L"George",L"Gerald",L"Gerd",L"Gerda",L"Gerhard",L"Gerit",L"Gesa",L"Ghazi",L"Gia",L"Gideon",L"Gido",L"Gina",L"Giorgio",L"Gisbert",L"Gisela",L"Giulia",L"Giuseppa",L"Gizem",L"Glenn",L"Gloria",L"Gonzales",L"Gordon",L"Grace",L"Gracia",L"Greetje",L"Gregor",L"Greta",L"Grigori",L"Grischa",L"Grit",L"Gudrun",L"Guido",L"Guillaume",L"Gunnar",L"Gustav",L"Gwen",L"Gérard",L"Gérôme",L"Götz",L"Gülçin",L"Hagen",L"Hailey",L"Hanna",L"Hannes",L"Hanno",L"Hans",L"Harry",L"Haru",L"Hayo",L"Hedda",L"Hedy",L"Heidi",L"Heike",L"Heiko",L"Heja",L"Hektor",L"Helen",L"Helena",L"Helene",L"Helga",L"Hendrik",L"Henna",L"Henri",L"Henrietta",L"Henrike",L"Heta",L"Hilke",L"Holger",L"Horst",L"Hugo",L"Ian",L"Ida",L"Idris",L"Ike",L"Ilay",L"Ilias",L"Ilona",L"Ilse",L"Ilvy",L"Immanuel",L"Ina",L"Inas",L"India",L"Indira",L"Ines",L"Inga",L"Ingmar",L"Ingo",L"Inka",L"Ira",L"Irene",L"Iris",L"Irmina",L"Isaak",L"Isabell",L"Isaiah",L"Isalie",L"Isis",L"Ismael",L"Isolde",L"Ivan",L"Ivana",L"Ivonne",L"Jakob",L"Jan",L"Jana",L"Janina",L"Jasmin",L"Jennica",L"Johanna",L"Johannes",L"Jonas",L"Jonathan",L"Josef",L"Josephine",L"Julia",L"Julian",L"Julius",L"Karin",L"Karl",L"Karla",L"Karoline",L"Katharina",L"Kathrin",L"Katja",L"Kilian",L"Klaus",L"Konstantin",L"Korbinian",L"Lara",L"Larissa",L"Lars",L"Laura",L"Laurin",L"Lea",L"Leandro",L"Leif",L"Lena",L"Leni",L"Lennard",L"Lennox",L"Lenny",L"Lenya",L"Leo",L"Leon",L"Leonardo",L"Leonie",L"Lewin",L"Leyla",L"Liam",L"Lias",L"Liem",L"Lien",L"Lilli",L"Lilliana",L"Lina",L"Linus",L"Lisa",L"Loreen",L"Louis",L"Louisa",L"Luca",L"Lucia",L"Luciano",L"Lucien",L"Lucy",L"Ludger",L"Luise",L"Lukas",L"Magdalena",L"Magnus",L"Maik",L"Maja",L"Malala",L"Malia",L"Malin",L"Malou",L"Malte",L"Mandy",L"Manila",L"Manuel",L"Manuela",L"Mara",L"Marcel",L"Marco",L"Marek",L"Maren",L"Margit",L"Maria",L"Marian",L"Mariana",L"Marie",L"Mariella",L"Marina",L"Mario",L"Marion",L"Marissa",L"Marit",L"Mark",L"Markus",L"Marlene",L"Marlon",L"Marten",L"Martin",L"Marvin",L"Mary-Lou",L"Mathilda",L"Mathilde",L"Mats",L"Matteo",L"Mattheo",L"Matthias",L"Maurice",L"Mauro",L"Max",L"Maxi",L"Maximilian",L"Melanie",L"Melchior",L"Melina",L"Melissa",L"Melody",L"Melvin",L"Merlin",L"Mette",L"Mia",L"Michael",L"Michaela",L"Michel",L"Michelle",L"Mieke",L"Mika",L"Milan",L"Milena",L"Milos",L"Mira",L"Miriam",L"Mona",L"Monika",L"Moritz",L"Muriel",L"Nadine",L"Naomi",L"Natalie",L"Natascha",L"Nathan",L"Nemo",L"Nikolaus",L"Nilay",L"Nina",L"Noah",L"Noel",L"Oana",L"Oda",L"Odelia",L"Odette",L"Odin",L"Oke",L"Oksana",L"Oktavian",L"Ola",L"Olaf",L"Olavi",L"Ole",L"Oleg",L"Olek",L"Olga",L"Oli",L"Olia",L"Oliver",L"Olivia",L"Olympia",L"Omar",L"Omid",L"Ona",L"Onni",L"Onur",L"Ophelia",L"Oriana",L"Orietta",L"Orin",L"Orla",L"Orlando",L"Ornella",L"Osia",L"Oskar",L"Otila",L"Otis",L"Ottelo",L"Ottilie",L"Otto",L"Owen",L"Pablo",L"Paddy",L"Paige",L"Palina",L"Pamela",L"Paola",L"Paolo",L"Pari",L"Pascal",L"Patricia",L"Patrick",L"Paul",L"Paula",L"Pauline",L"Paulo",L"Pearl",L"Pedro",L"Peggy",L"Penelope",L"Penny",L"Pepe",L"Per",L"Percival",L"Peter",L"Petra",L"Phil",L"Philipp",L"Pia",L"Pietro",L"Pius",L"Polan",L"Preston",L"Primus",L"Queenie",L"Quentin",L"Quiana",L"Quirin",L"Ramona",L"Raphael",L"Rebekka",L"Ricarda",L"Ricardo",L"Robert",L"Robin",L"Roman",L"Rosa",L"Rosalia",L"Sabine",L"Samuel",L"Sandra",L"Sarah",L"Sebastian",L"Silja",L"Simon",L"Sophia",L"Sophie",L"Stefan",L"Suri",L"Sven",L"Tabea",L"Tamara",L"Tanja",L"Theodora",L"Theresa/e",L"Thomas",L"Thorsten",L"Till",L"Tim",L"Tobias",L"Udo",L"Uli",L"Ulla",L"Ulrich",L"Ulrika",L"Uriel",L"Ursula",L"Uta",L"Ute",L"Uwe",L"Valentin",L"Valentina",L"Vanessa",L"Vera",L"Veronika",L"Viktor",L"Viktoria",L"Vilmar",L"Vinzent",L"Vinzenz",L"Viola",L"Walter",L"Wanda",L"Wendy",L"Werner",L"Wibke",L"Wilhelm",L"Wilhelma",L"Willi",L"Wilma",L"Wolfram",L"Xana",L"Xander",L"Xandra",L"Xaver",L"Xaviera",L"Xena",L"Xenia",L"Yafa",L"Yamina",L"Yannick",L"Yasemin",L"Yelena",L"Yorick",L"Yuma",L"Yvonne",L"Zacharias",L"Zahra",L"Zander",L"Zarah",L"Zarif",L"Zeno",L"Zoe",L"Zohra",L"Zora",L"Zyprian" };
	m_Name = lsvNamen[rand() % lsvNamen.size()];

	vector<wstring> lsvNachname = { L"Müller",L"Schmidt",L"Schneider",L"Fischer",L"Weber",L"Meyer",L"Wagner",L"Becker",L"Schulz",L"Hoffmann",L"Schäfer",L"Koch",L"Bauer",L"Richter",L"Klein",L"Wolf",L"Schneider",L"Neumann",L"Schwarz",L"Zimmermann",L"Braun",L"Krüger",L"Hofmann",L"Hartmann",L"Lange",L"Schmitt",L"Werner",L"Schmitz",L"Krause",L"Meier",L"Lehmann",L"Schmid",L"Schulze",L"Maier",L"Köhler",L"Herrmann",L"König",L"Walter",L"Mayer",L"Huber",L"Kaiser",L"Fuchs",L"Peters",L"Lang",L"Scholz",L"Möller",L"Weiß",L"Jung",L"Hahn",L"Schubert",L"Vogel",L"Friedrich",L"Keller",L"Günther",L"Frank",L"Berger",L"Winkler",L"Roth",L"Beck",L"Lorenz",L"Baumann",L"Franke",L"Albrecht",L"Schuster",L"Simon",L"Ludwig",L"Böhm",L"Winter",L"Kraus",L"Martin",L"Schumacher",L"Krämer",L"Vogt",L"Stein",L"Jäger",L"Otto",L"Sommer",L"Groß",L"Seidel",L"Heinrich",L"Brandt",L"Haas",L"Schreiber",L"Graf",L"Schulte",L"Dietrich",L"Ziegler",L"Kuhn",L"Kühn",L"Pohl",L"Engel",L"Horn",L"Busch",L"Bergmann",L"Thomas",L"Voigt",L"Sauer",L"Arnold",L"Wolff",L"Pfeiffer" };
	m_Nachname = lsvNachname[rand() % lsvNachname.size()];

	m_Alter = to_wstring((rand() % 55) + 16).c_str();

	m_Kontakt = Kontakt(m_Name, m_Nachname);
	m_ID = piID;
}

wstring Personen::GetID()
{
	return to_wstring(m_ID);
}

int Personen::GetIntID()
{
	return m_ID;
}

void Personen::SetID(int piID)
{
	m_ID = piID;
}

wstring Personen::GetName()
{
	return m_Name;
}

void Personen::SetName(wstring psName)
{
	m_Name = psName;
}

wstring Personen::GetNachname()
{
	return m_Nachname;
}

void Personen::SetNachname(wstring psNachname)
{
	m_Nachname = psNachname;
}

wstring Personen::GetAlter()
{
	return m_Alter;
}

void Personen::SetAlter(int piAlter)
{
	m_Alter = piAlter;
}

Adresse Personen::GetAdresse()
{
	return m_Adresse;
}

void Personen::SetAdresse(Adresse paAdresse)
{
	m_Adresse = paAdresse;
}


Kontakt Personen::GetKontakt()
{
	return m_Kontakt;
}

void Personen::SetKontakt(Kontakt pkKontakt)
{
	m_Kontakt = pkKontakt;
}


wstring Personen::toString()
{
	wstring lsAusgabe;

	lsAusgabe = L"ID: " + GetID() + L"\nName: " + m_Name + L"\nNachname: " + m_Nachname + L"\nAlter: " + m_Alter + L"\nAdresse: " + m_Adresse.GetStraße() + L", " + m_Adresse.GetPLZ() + L" " + m_Adresse.GetOrt() + L"\nTelefon: " + m_Kontakt.GetTelefon() + L"\nHandy: " + m_Kontakt.GetHandy() + L"\nE-Mail: " + m_Kontakt.GetEMail();

	return lsAusgabe;
}

vector<wstring> Personen::toStringVector()
{
	vector<wstring> lvAusgabe = vector<wstring>();

	lvAusgabe.push_back(GetID());
	lvAusgabe.push_back(m_Name);
	lvAusgabe.push_back(m_Nachname);
	lvAusgabe.push_back(m_Alter);

	lvAusgabe.push_back(m_Adresse.GetStraße() + L", " + m_Adresse.GetPLZ() + L" " + m_Adresse.GetOrt());

	lvAusgabe.push_back(m_Kontakt.GetTelefon());
	lvAusgabe.push_back(m_Kontakt.GetHandy());
	lvAusgabe.push_back(m_Kontakt.GetEMail());

	return lvAusgabe;
}

wstring Personen::toSaveString()
{
	wstring lAusgabe;
	lAusgabe = m_Name + L"|" + m_Nachname + L"|" + m_Alter + L"|" + m_Kontakt.GetTelefon() + L"|" + m_Kontakt.GetHandy() + L"|" + m_Adresse.GetStraße() + L"|" + m_Adresse.GetOrt() + L"|" + m_Adresse.GetPLZ() + L"|";
	return lAusgabe;
}

