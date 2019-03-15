#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

class Song
{
    char *name;
    char *artist;
    char *genre;
    double time;

    void copy(const Song &toCopy)
    {
        if(this == &toCopy)
        {
            return;
        }
        delete[] name;
        delete[] artist;
        delete[] genre;
        int len = strlen(toCopy.name);
        name = new char[len+1];
        strcpy(name, toCopy.name);

        len = strlen(toCopy.artist);
        artist = new char[len+1];
        strcpy(artist, toCopy.artist);

        len = strlen(toCopy.genre);
        genre = new char[len+1];
        strcpy(genre, toCopy.genre);

        time = toCopy.time;
    }

public:
    Song()
    {
        name = new char[0];
        artist = new char[0];
        genre = new char[0];
        time = 0;
    }

    Song (char *_name, char *_artist, char *_genre, double _time)
    {
        setName(_name);
        setArtist(_artist);
        setGenre(_genre);
        setTime(_time);
    }

    Song(const Song &toCopy)
    {
        setName(toCopy.getName());
        setArtist(toCopy.getArtist());
        setGenre(toCopy.getGenre());
        setTime(toCopy.getTime());
    }

    ~Song()
    {
        delete[] name;
        delete[] artist;
        delete[] genre;
    }

    char *getName() const
    {
        char *ret = new char[strlen(name)+1];
        strcpy(ret, name);
        return ret;
    }

    char *getArtist() const
    {
        char *ret = new char[strlen(artist)+1];
        strcpy(ret, artist);
        return ret;
    }

    char *getGenre() const
    {
        char *ret = new char[strlen(genre)+1];
        strcpy(ret, genre);
        return ret;
    }

    double getTime() const
    {
        return time;
    }

    void setName(char *_name)
    {
        delete[] name;
        name = new char[strlen(_name)+1];
        strcpy(name, _name);
    }

    void setArtist(char *_artist)
    {
        delete[] artist;
        artist = new char[strlen(_artist)+1];
        strcpy(artist, _artist);
    }

    void setGenre(char *_genre)
    {
        delete[] genre;
        genre = new char[strlen(_genre)+1];
        strcpy(genre, _genre);
    }

    void setTime(int _time)
    {
        time = _time;
    }

    Song& operator = (const Song &toCopy)
    {
        copy(toCopy);
        return *this;
    }

    bool operator < (const Song &cmp) const
    {
        return time < cmp.getTime();
    }

    bool operator <= (const Song &cmp) const
    {
        return time <= cmp.getTime();
    }

    bool operator == (const Song &cmp) const
    {
        return time == cmp.getTime();
    }

    bool operator != (const Song &cmp) const
    {
        return time != cmp.getTime();
    }

    bool operator > (const Song &cmp) const
    {
        return time > cmp.getTime();
    }

    bool operator >= (const Song &cmp) const
    {
        return time >- cmp.getTime();
    }

    void print()
    {
        cout << name << endl;
        cout << artist << endl;
        cout << genre << endl;
        cout << time << endl;
    }

};

class MusicAlbum
{
    Song *songs;
    int numSongs;
    int capacity;

    void resize()
    {
        capacity *= 2;
        Song *cur = new Song[capacity];
        for(int i = 0; i < numSongs; i++)
        {
            cur[i] = songs[i];
        }
        delete[] songs;
        songs = cur;
    }

public:
    MusicAlbum()
    {
        songs = new Song[1];
        numSongs = 0;
        capacity = 1;
    }

    MusicAlbum(const MusicAlbum &toCopy)
    {
        numSongs = toCopy.numSongs;
        capacity = toCopy.capacity;
        songs = new Song[numSongs];
        for(int i = 0; i < numSongs; i++)
        {
            songs[i] = toCopy.songs[i];
        }
    }

    ~MusicAlbum()
    {
        delete[] songs;
    }

    MusicAlbum& operator = (const MusicAlbum &toCopy)
    {
        if(this == &toCopy)
            return *this;
        delete[] songs;
        numSongs = toCopy.numSongs;
        capacity = toCopy.capacity;
        songs = new Song[numSongs];
        for(int i = 0; i < numSongs; i++)
        {
            songs[i] = toCopy.songs[i];
        }
        return *this;
    }

    int size()
    {
        return numSongs;
    }

    int getCapacity()
    {
        return capacity;
    }

    void addSong(const Song &song)
    {
        if(numSongs == capacity)
        {
            resize();
        }
        songs[numSongs] = song;
        numSongs++;
    }

    void removeSongAtIndex(size_t index)
    {
        assert(index < numSongs);
        for(int i = index; i < numSongs - 1; i++)
        {
            songs[i] = songs[i + 1];
        }
        numSongs--;
    }

    double totalLength() const
    {
        double sum = 0;
        for(int i = 0; i < numSongs; i++)
        {
            sum += songs[i].getTime();
        }
        return sum;
    }

    size_t countOfSongsOfGenre(char *genre)
    {
        size_t cnt = 0;
        for(int i = 0; i < numSongs; i++)
        {
            if(!strcmp(songs[i].getGenre(),genre))
                cnt++;
        }
        return cnt;
    }

    size_t countOfSongsOfArtist(char *artist)
    {
        size_t cnt = 0;
        for(int i = 0; i < numSongs; i++)
        {
            if(!strcmp(songs[i].getArtist(),artist))
                cnt++;
        }
        return cnt;
    }

    size_t indexOfShortestSong()
    {
        size_t minIndex = 0;
        for(int i = 1; i < numSongs; i++)
        {
            if(songs[i] < songs[minIndex])
                minIndex = i;
        }
        return minIndex;
    }
};

int main()
{
	Song s("name", "artist", "genre", 2);
	Song s2("Name", "Artist", "Genre", 1);
	Song s3("NAME", "ARTIS", "genre", 3);
    MusicAlbum m;
    m.addSong(s);
    m.addSong(s2);
    m.addSong(s3);
    m.addSong(s);
    m.addSong(s2);
    cout << m.getCapacity() << endl;
    cout << m.totalLength() << endl;
	return 0;
}
