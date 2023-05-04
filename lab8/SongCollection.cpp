#include "SongCollection.h"

SongCollection::SongCollection(std::ifstream& in)
{
	int ok = 0;
	if (in.is_open())
	{
		std::string los,artist,title,lyrics;
		while (in >> los && ok < 100)
		{
			if (los[0] == 'A')
			{
				artist = copyFromPos(in, los, 8);
				ok++;
			}
			else if (los[0] == 'T')
				title = copyFromPos(in, los, 7);
			else if (los[0] == 'L')
			{
				for (int i = 8; i < los.size(); i++)
					lyrics += los[i];
				lyrics += " ";
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

std::vector< std::pair<std::string, int> > SongCollection::GetArtist()
{
	std::vector< std::pair<std::string, int> > aux;
	for (int i = 0; i < Songs.size(); i++)
	{
		int j = 0;
		for (; j < aux.size() && aux[j].first != Songs[i].getArtist(); j++);

		if (j != aux.size())
			aux[j].second++;
		else
			aux.push_back(std::pair<std::string, int>{Songs[i].getArtist(), 1});
	}
	return aux;
}

std::vector < std::tuple<std::string, std::string, std::vector<std::string> > > SongCollection::GetEverything()
{
	std::vector < std::tuple<std::string, std::string, std::vector<std::string> > > aux;

	for (int i = 0; i < Songs.size(); i++)
		aux.push_back(std::tuple<std::string, std::string, std::vector<std::string> >{Songs[i].getArtist(), Songs[i].getTitle(), Songs[i].getLyrics()});
	return aux;
}

//additional functions;
std::string SongCollection::copyFromPos(std::ifstream& in, std::string other, int pos)
{
	std::string cop;

	if (other[other.size() - 1] != '\"')
		for (int i = pos; i < other.size(); i++)
			cop += other[i];
	else
		for (int i = pos; i < other.size() - 1; i++)
			cop += other[i];

	while (other[other.size() - 1] != '\"')
	{
		cop += " ";
		in >> other;
		if(other[other.size() - 1] != '\"')
			for (int i = 0; i < other.size(); i++)
				cop += other[i];
		else
			for (int i = 0; i < other.size()-1; i++)
				cop += other[i];
	}
	
	return cop;
}

//SongCollection::~SongCollection()
//{
//	if (!Songs.empty())
//	{
//		for (int i = 0; i < Songs.size(); i++)
//			delete &Songs[i];
//	}
//}

