#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

struct Song {
    int id;
    int plays;
};

struct Genre {
    int totalPlays;
    vector<Song> songs;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, Genre> genreMap;
    
    for (int i = 0; i < genres.size(); i++) {
        genreMap[genres[i]].totalPlays += plays[i];
        genreMap[genres[i]].songs.push_back({i, plays[i]});
    }
    
    vector<pair<string, Genre>> genreList(genreMap.begin(), genreMap.end());
    sort(genreList.begin(), genreList.end(), [](const auto& a, const auto& b) {
        return a.second.totalPlays > b.second.totalPlays;
    });
    
    vector<int> result;
    
    for (auto& genre : genreList) {
        vector<Song>& songs = genre.second.songs;
        sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {
           if (a.plays == b.plays) {
               return a.id < b.id;
           }
            return a.plays > b.plays;
        });
        
        for (size_t i = 0; i < min(songs.size(), static_cast<size_t>(2)); i++) {
            result.push_back(songs[i].id);
        }
    }
    
    return result;
}