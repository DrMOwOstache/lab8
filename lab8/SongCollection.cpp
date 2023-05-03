#include "SongCollection.h"

SongCollection::SongCollection(std::ifstream& in)
{
	if (in.is_open())
	{
		std::string los,artist,title,lyrics;
		while (in >> los)
		{
			if (los[0] == 'A')
				artist = copyFromPos(los, 8, 1);
			else if (los[0] == 'T')
				title = copyFromPos(los, 7, 1);
			else if (los[0] == 'L')
			{
				lyrics = copyFromPos(los, 8);
				bool ok = false;
				while (ok == false)
				{
					in >> los;
					if (los[los.size() - 1] == '\"')
						ok = true;
					else
						lyrics += los + " ";
				}
				this->Songs.push_back(Song(artist, title, lyrics));
			}
		}
	}
	else
		throw std::invalid_argument("file was not found");
}

std::set<std::string> SongCollection::UniArtits()
{
	std::set<std::string> aux;
	for (int i = 0; i < Songs.size(); i++)
		aux.insert(Songs[i].getArtist());
	return aux;
}

std::unordered_map< std::string, std::string> GetArtist()
{

}

//additional functions;
std::string SongCollection::copyFromPos(std::string other, int pos, int endSlash = 0)
{
	std::string cop;
	for (int i = pos, j = 0; i < other.size() - endSlash; i++, j++)
		cop[j] = other[i];
	return cop;
}