#ifndef _GHOST_H_
#define _GHOST_H_

#include<set>
#include<vector>
#include<cstring>
#include<iostream>

#include<commonValue.h>

using namespace std;

class Ghost {
	private:
		int num;
		string name;
		string info;
		string feature;
		string weak;
		bool clue[MAX_CLUE] = { false };

	public:
		Ghost(int num, string name);

		void setInfo(string info);
		void setFeature(string feature);
		void setWeak(string weak);
		void setClue(int c1, int c2, int c3);

		string getName();
		int getNum();
		void getClue(vector<bool>& v_clue);

		bool checkClue(set<int> s_clue);

		friend ostream& operator<<(ostream& o, Ghost g);
};

#endif
