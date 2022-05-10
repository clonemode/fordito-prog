
#include "ctype.h"
#include "string"
#include "vector"
#include "iostream"
#include "map"

using namespace std;

/*	
	S->T+S
	S->T
	T->a
	T->b
	kesz
*/
/*
	b+a
*/
bool talaldmeg(vector<string> v, string megtalalnikivant)
{
	for (string s : v)
	{
		if (s == megtalalnikivant)
			return true;
	}

	return false;
}

int main()
{
	string szabaly = "", nemterminalis = "", terminalis = "", tarolo = "", szo = "", szo2 = "", masolat = "";
	int i = 0, tarolo_char = 0;
	multimap<string, string> szabalyok;
	multimap<string, string>::iterator pozicio;
	vector<string> megoldas, nem_megoldas, levezetes;
	bool megtalalt = false;

	cout << "Add meg a szabalyokat szokozok hasznalata nelkul!" << endl << "Ha befejezted ird be hogy 'kesz' !" << endl;

	while (cin >> szabaly)
	{
		if (szabaly == "kesz")
			break;

		nemterminalis = "";
		terminalis = "";
		i = 0;

		while (szabaly[i] != '-' && szabaly[i + 1] != '>')
		{
			nemterminalis = nemterminalis + szabaly[i];
			i++;
		}

		i = i + 2;

		while (i < szabaly.size())
		{
			terminalis = terminalis + szabaly[i];
			i++;
		}

		tarolo = tarolo + nemterminalis;
		tarolo_char = 0;

		for (char c : tarolo)
		{
			if (c == nemterminalis[0])
				tarolo_char++;
		}

		szabalyok.insert(pair<string, string>(nemterminalis + to_string(tarolo_char), terminalis));
	}

	cout << endl << "A megadott szabalyok: " << endl;

	for (pozicio = szabalyok.begin(); pozicio != szabalyok.end(); pozicio++)
	{
		cout << pozicio->first << " -> " << pozicio->second << endl;
	}

	cout << endl << "Add meg a levezetni kivant szot!" << endl;
	cin >> szo;
	cout << endl;
	szo2 = szo;

	levezetes.push_back("S");

	while (szo2.size() != 0)
	{
		while (levezetes[levezetes.size() - 1][0] == szo2[0] && szo2.size() != 0)
		{
			levezetes[levezetes.size() - 1].erase(levezetes[levezetes.size() - 1].begin());

			szo2.erase(szo2.begin());
		}

		megtalalt = false;

		for (pozicio = szabalyok.begin(); pozicio != szabalyok.end(); pozicio++)
		{
			if (pozicio->first[0] == levezetes[levezetes.size() - 1][0])
			{
				masolat = levezetes[levezetes.size() - 1];

				masolat = masolat.replace(0, 1, pozicio->second);

				if (!talaldmeg(nem_megoldas, masolat))
				{
					megtalalt = true;

					levezetes.push_back(masolat);
					megoldas.push_back(pozicio->first);
				}
			}
		}

		if (!megtalalt && szo2.size() != 0)
		{
			if (levezetes.size() == 1)
			{
				cout << endl << "A megadott '" << szo << "' nem levezetheto! " << endl;

				return 0;
			}
			nem_megoldas.push_back(levezetes[levezetes.size() - 1]);

			levezetes.pop_back();
			megoldas.pop_back();
		}
	}

	cout << endl << "A megadott '" << szo << "' levezetheto! A baloldali levezetese az alabbi: " << endl;
	for (string s : megoldas)
	{
		cout << s << " ";
	}

	cout << endl;

	return 0;
}