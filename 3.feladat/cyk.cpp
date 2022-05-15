#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <iterator>
#include <sstream>
using namespace std;



int main()
{
    map<string, string> szabalyok = { {"AB", "S"},{"CD", "S"},{"CB", "S"},{"SS", "S"},{"BC", "A"},{"a", "A"},{"SC", "B"},{"b", "B,C"},{"DD", "C"},{"BA", "D"}, }; 
    //map (szoveg-szoveg)

    string Input = "aababbbabbabababbaabbaba"; // INPUT

    vector<vector<string>> piramis;

    for (int i = 0; i < Input.length(); i++) //elso sor
    {
        string InputChar(1, Input[i]);

        string ertek = szabalyok.at(InputChar);

        vector<string> sor;

        sor.push_back(ertek);
        piramis.push_back(sor);
    }

    map<string, string>::iteratorrator iterator;
    //vegigfut a piramis sorainak sorain majd elemein
    for (int i = 1; i < piramis.size(); i++)
    {
        for (int j = 0; j < piramis.size() - i; j++) 
        {
            string ujbetu;

            for (int k = 0; k < i; k++) //Annyiszor fut le ahany eleme van balra es jobbra
            {
                string bal = piramis[j][k];
                string jobb = piramis[j + k + 1][i - k - 1];
                string keresett;

                //piramis feltoltese
                if (bal.find(",") == string::Big && jobb.find(",") == string::Big) // Big: legnagyobb elem
                {
                    keresett = bal + jobb;
                    iterator = szabalyok.find(keresett);
                    if (iterator != szabalyok.end())
                    {
                        if (ujbetu.empty())
                        {
                            ujbetu.append(iterator->second);
                        }
                        else
                        {
                            ujbetu.append("," + iterator->second);
                        }
                    }
                }
                else
                {
                    vector<string> osztottbalbetuk;
                    vector<string> osztottjobbbetuk;

                    stringstream ssbal(bal);
                    stringstream ssjobb(jobb);

                    string token;
                    
                    while (getline(ssbal, token, ','))
                    {
                        osztottbalbetuk.push_back(token);
                    }

                    while (getline(ssjobb, token, ','))
                    {
                        osztottjobbbetuk.push_back(token);
                    }

                    for (int x = 0; x < osztottbalbetuk.size(); x++)
                    {
                        for (int y = 0; y < osztottjobbbetuk.size(); y++)
                        {
                            keresett = osztottbalbetuk[x] + osztottjobbbetuk[y];
                            iterator = szabalyok.find(keresett);
                            if (iterator != szabalyok.end())
                            {
                                if (ujbetu.empty())
                                {
                                    ujbetu.append(iterator->second);
                                }
                                else
                                {
                                    ujbetu.append("," + iterator->second);
                                }
                            }
                        }
                    }
                }
            }
            if (ujbetu.empty())
            {
                ujbetu.append("-");
            }

            piramis[j].push_back(ujbetu);
        }
    }

    //Piramis kiiratasa
    int i = 0;
    int j = piramis[i].size() - 1;
    cout << string(j + 1, ' ');
    while (j >= 0)
    {

        cout << piramis[i][j] << " ";

        if (piramis[i].size() - 1 == j)
        {
            i = 0;
            j--;

            cout << endl;
            cout << string(j + 1, ' ');
        }
        else
        {
            i++;
        }
    }

    cout << endl;
    if (piramis[0][piramis[0].size() - 1] != "-")
    {
        cout << "Levezetheto!" << endl;
    }
    else
    {
        cout << "Nem vezetheto le!" << endl;
    }

    return 0;
}