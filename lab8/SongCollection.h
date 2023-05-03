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

	std::string copyFromPos(std::string other, int pos, int endSlash = 0);

public:
	SongCollection(std::ifstream& in);
	std::set<std::string> UniArtits();
	std::unordered_map< std::string, std::string> GetArtist();
};