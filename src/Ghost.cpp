#include"../include/Ghost.h"

Ghost::Ghost(int num, string name) : num(num), name(name) { };

// Set Extra Data
void Ghost::setInfo(string info) { this->info = info; };
void Ghost::setFeature(string feature) { this->feature = feature; };
void Ghost::setWeak(string weak) { this->weak = weak; };
void Ghost::setClue(int c1, int c2, int c3) {
	clue[c1] = true;
	clue[c2] = true;
	clue[c3] = true;
};

// return Data
string	Ghost::getName()	{ return name;	}
int		Ghost::getNum()		{ return num;	}

bool Ghost::checkClue(set<int> f_clue) {
	for (auto c = f_clue.begin(); c != f_clue.end(); ++c) {
		if (!clue[*c]) return false;
	}
	return true;
}

void Ghost::getClue(vector<bool>& lclue) {
	for (int c = 0; c <= MAX_CLUE; ++c) {
		lclue[c] = lclue[c] || clue[c];
	}
}

ostream& operator<<(ostream& o, Ghost g) {
	cout << "이름 : " << g.name << endl;
	cout << "설명 : " << g.info << endl;
	cout << "특징 : " << g.feature << endl;
	cout << "약점 : " << g.weak << endl;

	return o;
}
