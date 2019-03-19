#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) {
  unordered_map<string, int> hashMag, hashNote;

  for (int i = 0; i < magazine.size(); ++i) {
        if(hashMag.find(magazine[i]) == hashMag.end())
            hashMag.insert(make_pair(magazine[i], 1));
        else
            ++hashMag[magazine[i]];
    }

    for (int i = 0; i < note.size(); ++i) {
      if (hashNote.find(note[i]) == hashNote.end()) 
            hashNote.insert(make_pair(note[i], 1));
        
        else
            ++hashNote[note[i]];
    }

    for(int i = 0; i < note.size(); ++i)
    {
        if(hashMag.find(note[i]) == hashMag.end() || hashMag[note[i]] < hashNote[note[i]])
        {
            std::cout << "No";
            return;
        }
    }
    std::cout << "Yes";
}