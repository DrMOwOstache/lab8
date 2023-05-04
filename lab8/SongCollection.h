#pragma once
#include "Song.h"
#include <fstream>
#include <exception>
#include <set>
#include <unordered_map>

class SongCollection
{
	friend class Song;
private:
	std::vector<Song> Songs;

	std::string copyFromPos(std::ifstream& in, std::string other, int pos);

public:
	SongCollection(std::ifstream& in);
	std::set<std::string> UniArtits();
	std::vector< std::pair<std::string, int> > GetArtist();

	std::vector < std::tuple<std::string, std::string, std::vector<std::string> > > GetEverything();
	//~SongCollection();
};