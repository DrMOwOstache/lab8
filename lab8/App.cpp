#include "SortedSet.h"
#include "SortedSetIterator.h"
#include "SongCollection.h"
#include <iostream>
#include <crtdbg.h>
#include <unordered_map>

#include <fstream>

using namespace std;

int main() {

	ifstream in("songs.txt");
	unordered_map<std::string, std::string> topTen;
	SongCollection songs{in};

	for(int i=0;i<songs)

	_CrtDumpMemoryLeaks();

	system("pause");
}