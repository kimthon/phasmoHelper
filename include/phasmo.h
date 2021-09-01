#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<sstream>
#include<cstring>

using namespace std;

static const int spirit = 0;
static const int wraith = 1;
static const int phantom = 2;
static const int poltergeist = 3;
static const int banshee = 4;
static const int jinn = 5;
static const int mare = 6;
static const int revenant = 7;
static const int shade = 8;
static const int demon = 9;
static const int yurei = 10;
static const int oni = 11;

static const int emf = 0;
static const int box = 1;
static const int cold = 2;
static const int hand = 3;
static const int writing = 4;
static const int orb = 5;


class ghost {
	private:
		int num;
		string name;
		string info;
		string feature;
		string weak;
		bool clue[6] = { false };

	public:
		ghost(int num, string name) : num(num), name(name) { };

		void setInfo(string info) { this->info = info; };
		void setFeature(string feature) { this->feature = feature; };
		void setWeak(string weak) { this->weak = weak; };
		void setClue(int c1, int c2, int c3) {
			clue[c1] = true;
			clue[c2] = true;
			clue[c3] = true;
		};

		string getName() { return name; }
		int getNum() { return num; }

		bool checkClue(set<int> f_clue) {
			for (auto c = f_clue.begin(); c != f_clue.end(); ++c) {
				if (!clue[*c]) return false;
			}
			return true;
		}

		void getClue(vector<bool>& lclue) {
			for (int c = 0; c < 6; ++c) {
				lclue[c] = lclue[c] || clue[c];
			}
		}

		friend ostream& operator<<(ostream& o, ghost g) {
			cout << "이름 : " << g.name << endl;
			cout << "설명 : " << g.info << endl;
			cout << "특징 : " << g.feature << endl;
			cout << "약점 : " << g.weak << endl;

			return o;
		}
};

class phasmo {
	private:
		vector<ghost> gs;
		set<int> f_clue;
		vector<string> clue_s = { "EMF 5단계", "주파수 측정기", "서늘함",
			"손자국", "고스트 라이팅", "고스트 오브" };

		void setGhostClue(vector<bool>& clue, int c1, int c2, int c3) {
			clue[c1] = true;
			clue[c2] = true;
			clue[c3] = true;
		}

		void setGhost() {
			gs.push_back(ghost(1, "스피릿"));
			gs[spirit].setInfo("스피릿은 가장 흔하지만 위험한 유령입니다");
			gs[spirit].setFeature("없음");
			gs[spirit].setWeak("정화 양초를 사용하면 오랜 시간 동안 공격을 막을 수 있습니다");
			gs[spirit].setClue(box, hand, writing);

			gs.push_back(ghost(2, "레이스"));
			gs[wraith].setInfo("공중을 떠다니며 벽을 통과할 수 있습니다");
			gs[wraith].setFeature("공중을 떠다니기 때문에 발자국을 남기지 않습니다.");
			gs[wraith].setWeak("소금을 뿌려 공격을 막을 수 있습니다.");
			gs[wraith].setClue(box, cold, hand);

			gs.push_back(ghost(3, "팬텀"));
			gs[phantom].setInfo("보통 위저보드로 소환됩니다.");
			gs[phantom].setFeature("팬텀을 바라보면 정신력이 급격히 떨어집니다.");
			gs[phantom].setWeak("사진을 찍으면 일시적으로 모습을 감춥니다.");
			gs[phantom].setClue(emf, cold, orb);

			gs.push_back(ghost(4, "폴터가이스트"));
			gs[poltergeist].setInfo("폴터가이스트는 주변 사물들을 조종하여 사람들을 공포에 떨게하는 유령입니다.");
			gs[poltergeist].setFeature("많은 양의 물체를 한번에 던질 수 있습니다.");
			gs[poltergeist].setWeak("주변에 사물이 없으면 공격성이 저하됩니다.");
			gs[poltergeist].setClue(box, hand, orb);

			gs.push_back(ghost(5, "밴시"));
			gs[banshee].setInfo("밴시는 사냥감을 가리지 않으며, 한번 노린 사냥감을 죽일 때까지 스토킹합니다.");
			gs[banshee].setFeature("한번에 오직 한 사람만 노립니다.");
			gs[banshee].setWeak("십자가 근처에서 공격성이 저하됩니다.");
			gs[banshee].setClue(emf, cold, hand);

			gs.push_back(ghost(6, "진"));
			gs[jinn].setInfo("진은 자신의 영역을 침범하는 사람들에게 빠른 속도로 접근하여 공격합니다.");
			gs[jinn].setFeature("희생자가 멀어질수록 더 빠르게 접근합니다.");
			gs[jinn].setWeak("전원을 내려 능력 사용을 제한 할 수 있습니다.");
			gs[jinn].setClue(emf, box, orb);

			gs.push_back(ghost(7, "메어"));
			gs[mare].setInfo("메어는 악몽의 근원이며, 어둠속에서 강한 힘을 발휘합니다.");
			gs[mare].setFeature("어두운 곳에서 더 자주 공격합니다.");
			gs[mare].setWeak("불을 켜면 공격 주기를 늦출 수 있습니다.");
			gs[mare].setClue(box, cold, orb);

			gs.push_back(ghost(8, "레버넌트"));
			gs[revenant].setInfo("평소에는 느리지만, 사냥을 시작하면 매우 빠른 속도로 움직이며 주위 사람들을 무차별적으로 공격합니다.");
			gs[revenant].setFeature("희생자를 사냥할 때 매우 빨라집니다.");
			gs[revenant].setWeak("몸을 숨기면 느린 속도로 이동합니다.");
			gs[revenant].setClue(emf, hand, writing);

			gs.push_back(ghost(9, "셰이드"));
			gs[shade].setInfo("모습을 잘 들어내지 않으며 주변에 사람이 많으면 증거를 남기지 않습니다.");
			gs[shade].setFeature("증거를 남기지 않아 존재 발견이 어렵습니다.");
			gs[shade].setWeak("여럿이 같이 있을 때 공격하지 않습니다.");
			gs[shade].setClue(emf, writing, orb);

			gs.push_back(ghost(10, "데몬"));
			gs[demon].setInfo("데몬은 당신이 만날 수 있는 유령 중 가장 사악합니다. 이들은 아무 이유없이 공격합니다.");
			gs[demon].setFeature("다른 유령보다 더 자주 공격합니다.");
			gs[demon].setWeak("위자보드를 통해 질문을 성공하면 정신력 감소를 늦출 수 있습니다.");
			gs[demon].setClue(box, cold, writing);

			gs.push_back(ghost(11, "유레이"));
			gs[yurei].setInfo("유레이는 복수심과 증오심만을 가지고 물리적 세계에 나타납니다.");
			gs[yurei].setFeature("정신력을 더 많이 감소시킵니다.");
			gs[yurei].setWeak("유레이가 있는 방을 정화하면 오랜 시간 동안 다시 나타나지 않습니다.");
			gs[yurei].setClue(cold, writing, orb);

			gs.push_back(ghost(12, "오니"));
			gs[oni].setInfo("데몬의 사촌이며 극도로 강한 힘을 가지고 있습니다. 이들은 사냥감 근처에서 훨씬 활동적입니다.");
			gs[oni].setFeature("사람이 근처에 있을 때 활동적으로 변하고 움직이는 목표를 향해 빠른 속도로 움직입니다.");
			gs[oni].setWeak("활동적으로 움직일수록 오니를 발견하기 쉬워집니다.");
			gs[oni].setClue(emf, box, writing);
		}


		void addClue(int n) {
			//범위 외 값은 제거
			if (n >= 6 || n < 0) return;
			f_clue.insert(n);
		}
		void delClue(int n) { f_clue.erase(n); }
		void cleanClue() { f_clue.clear(); }

		list<ghost*> LeftGhostList() {
			list<ghost*> glist;
			for (int i = 0; i < 12; ++i) glist.push_back(&gs[i]);

			for (auto i = glist.begin(); i != glist.end();) {
				ghost& g = **i;
				if (!g.checkClue(f_clue)) i = glist.erase(i);
				else ++i;
			}

			return glist;
		}

		vector<bool> LeftClue(list<ghost*> glist) {
			vector<bool> lclue(6, false);
			for (auto i = glist.begin(); i != glist.end(); ++i) {
				ghost& g = **i;
				g.getClue(lclue);
			}

			// 이미 찾은 증거 제거
			for (int c : f_clue) lclue[c] = false;

			return lclue;
		}

		void ShowInfo(int n) {
			if (n < 0 || n >= 12) return;
			system("clear");
			cout << "=========================================" << endl;
			cout << gs[n];
			cout << "=========================================" << endl;
			cout << "계속 진행하시려면 아무 키나 눌러주세요";
			getc(stdin);
			system("clear");
		}

		void ShowStatus() {
			if (!f_clue.empty()) {


				cout << "=========================================" << endl;
				cout << "결과물" << endl;
				cout << "=========================================" << endl;
				cout << "현재 찾은 증거 : ";
				for (int c : f_clue) {
					cout << clue_s[c] << '(' << c + 1 << ')' << ',';
				}
				cout << endl;

				list<ghost*> glist = LeftGhostList();
				cout << "남은 귀신 들 : ";
				for (auto i = glist.begin(); i != glist.end(); ++i) {
					ghost& g = **i;
					cout << g.getName() << '(' << g.getNum() << ')' << ',';
				}
				cout << endl;

				vector<bool> lclue = LeftClue(glist);
				cout << "찾아야 하는 증거 : ";
				for (int i = 0; i < 6; ++i) {
					if (lclue[i]) cout << clue_s[i] << '(' << i + 1 << ')' << ',';
				}

				cout << endl;
				cout << "=========================================" << endl << endl;
			}
		}

		void ReadMe() {
			cout << "=========================================" << endl;
			cout << "증거 번호" << endl;
			cout << "=========================================" << endl;
			for (int i = 0; i < 6; ++i) {
				cout << i + 1 << '.' << clue_s[i] << endl;
			}
			cout << "=========================================" << endl << endl;

			cout << "=========================================" << endl;
			cout << "명령어 사용법" << endl;
			cout << "=========================================" << endl;
			cout << "증거 추가		: add 숫자" << endl;
			cout << "증거 삭제		: del 숫자" << endl;
			cout << "유령 정보		: info 숫자" << endl;
			cout << "초기화			: clear" << endl;
			cout << "프로그램 종료		: quit, exit" << endl;
			cout << "=========================================" << endl << endl;
		}

		vector<string> SplitCMD(string cmd) {
			vector<string> cmds;
			string buffer;
			istringstream ss(cmd);
			while (getline(ss, buffer, ' ')) {
				cmds.push_back(buffer);
			}
			return cmds;
		}

	public:
		phasmo() {
			setGhost();
		}

		void run() {
			system("clear");
			while (true) {

				ReadMe();
				ShowStatus();

				string cmd;
				cout << "명령 입력 : ";
				getline(cin, cmd);

				//입력 오류 시 처리
				if (cin.fail()) {
					cin.clear();
					continue;
				}

				vector<string> cmds = SplitCMD(cmd);
				system("clear");

				int num = -1;
				if (cmds.size() > 1) {
					try {
						num = stoi(cmds.at(1));
					}
					catch (...) {
						cout << "=========================================" << endl;
						cout << "Error : 잘못된 값 입력" << endl;
						cout << "=========================================" << endl << endl;
					}
				}

				if (cmds.at(0) == "add") addClue(num - 1);
				else if (cmds.at(0) == "del") delClue(num - 1);
				else if (cmds.at(0) == "info") ShowInfo(num - 1);
				else if (cmds.at(0) == "clear") cleanClue();
				else if (cmds.at(0) == "quit" || cmds.at(0) == "exit") break;
			}
		}
};

int main() {
	phasmo p;

	p.run();

	return 0;
}
