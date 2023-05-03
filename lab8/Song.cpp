#include "Song.h"

Song::Song(std::string artist, std::string title, std::string lyrics)
{
	this->artist = artist;
	this->title = title;
	this->lyrics.push_back("");
	for (int i = 0, j =0; lyrics[i] != '\0'; i++)
	{
		while ((lyrics[i] < 'a' || lyrics[i] > 'z') && (lyrics[i] < 'A' && lyrics[i] > 'Z'))
			i++;
		if (lyrics[i] >= 'A' && lyrics[i] <= 'Z')
			this->lyrics[j] += lyrics[i] - 'A' + 'a';
		else if(lyrics[i] >= 'a' && lyrics[i] <= 'z')
			this->lyrics[j] += lyrics[i];
		else
			this->lyrics.push_back(""), j++;
	}
}

std::string Song::getArtist()
{
	return artist;
}

std::string Song::getTitle()
{
	return title;
}

std::vector<std::string> Song::getLyrics()
{
	return lyrics;
}
