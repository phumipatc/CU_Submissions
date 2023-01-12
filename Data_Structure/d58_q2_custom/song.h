#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song {
  public:
    std::string artist,title;
    int count;

    Song() { }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) { }
    Song(std::string artist,std::string title,int count) :  artist(artist), title(title), count(count) { }

    friend std::ostream& operator<<(std::ostream &out,const Song &s) {
      return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }

};
class cmp1{
	public:
		bool operator()(const Song &lhs,const Song &rhs) const{
			if(lhs.artist != rhs.artist)
				return lhs.artist > rhs.artist;
			else if(lhs.title != rhs.title)
				return lhs.title > rhs.title;
			else
				return lhs.count < rhs.count;
		}
};

class cmp2{
	public:
		bool operator()(const Song &lhs,const Song &rhs) const{
			if(lhs.count != rhs.count)
				return lhs.count < rhs.count;
			else if(lhs.artist != rhs.artist)
				return lhs.artist > rhs.artist;
			else
				return lhs.title > rhs.title;
		}
};

//  you have to write something below this line 
//  you *MIGHT* have to change the declaration of pq1 and pq2
CP::priority_queue<Song,cmp1> pq1;
CP::priority_queue<Song,cmp2> pq2;

#endif
