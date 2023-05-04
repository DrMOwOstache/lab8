#include "SortedSet.h"
#include "SortedSetIterator.h"
#include "SongCollection.h"
#include <iostream>
#include <crtdbg.h>
#include <unordered_map>
#include <cstdlib>
#include <algorithm>

#include <fstream>

using namespace std;

bool cmp(const pair<string, int>&a, const pair<string, int>& b)
{
	return a.second > b.second;
}

bool art(const tuple<string, string, vector<string> >& a,
	const tuple<string, string, vector<string> >& b)
{
	return get<0>(a) < get<0>(b);
}

bool tit(const tuple<string, string, vector<string> >& a,
	const tuple<string, string, vector<string> >& b)
{
	return get<1>(a) > get<1>(b);
}

bool lyr(const tuple<string, string, vector<string> >& a,
	const tuple<string, string, vector<string> >& b)
{
	return get<2>(a).size() < get<2>(b).size();
}

void showList(vector < tuple<string, string, vector<string> > > aux)
{
	for (int i = 0; i < aux.size(); i++)
		cout << get<0>(aux[i]) << " with the melody: " << get<1>(aux[i]) << '\n';
	cout<<'\n';
}

vector<string> FindWord(vector < tuple<string, string, vector<string> > > aux, string word)
{
	vector<string> lista;
	for (int i = 0; i < aux.size(); i++)
	{
		if (find(get<2>(aux[i]).begin(), get<2>(aux[i]).end(), word) != get<2>(aux[i]).end())
			lista.push_back(get<1>(aux[i]));
	}
	return lista;
}

int main() {

	ifstream in("songs.txt");

	cout << "Entering data\n";
	SongCollection songs{in};

	cout << "Data Entered\n";
	vector<pair<string, int> > aux = songs.GetArtist();
	vector < tuple<string, string, vector<string> > > test = songs.GetEverything();

	cout << "Do you want to show the test, right <yes> if you want to, if not anything else: ";
	string showtests;
	cin >> showtests;
	if (showtests == "yes")
	{
		sort(aux.begin(), aux.end(), cmp);

		for (int i = 0; i < 10; i++)
			cout << aux[i].first << " with " << aux[i].second << '\n';

		sort(test.begin(), test.end(), art);
		showList(test);

		sort(test.begin(), test.end(), tit);
		showList(test);

		sort(test.begin(), test.end(), lyr);
		showList(test);

	}

	cout << ">>>Type a word from a song: ";
	string good;
	cin >> good;
	vector<string> lista = FindWord(test, good);
	if(lista.empty())
		cout << ">>>There is no song with the word " << good << " in it.\n";
	else
	{
		cout << "The songs that have " << good << " in the lyrics are:\n";
		for (int i = 0; i < lista.size(); i++)
			cout << lista[i] << '\n';
	}

	//delete &songs;
	in.close();
	//_CrtDumpMemoryLeaks();

	system("pause");
	return 0;
}