/*
 Problem A: Football (aka Soccer) 

The Problem

Football the most popular sport in the world (americans insist to call it "Soccer", but we will call it "Football"). As everyone knows, Brasil is the country that have most World Cup titles (four of them: 1958, 1962, 1970 and 1994). As our national tournament have many teams (and even regional tournaments have many teams also) it's a very hard task to keep track of standings with so many teams and games played!

So, your task is quite simple: write a program that receives the tournament name, team names and games played and outputs the tournament standings so far.

A team wins a game if it scores more goals than its oponent. Obviously, a team loses a game if it scores less goals. When both teams score the same number of goals, we call it a tie. A team earns 3 points for each win, 1 point for each tie and 0 point for each loss.

Teams are ranked according to these rules (in this order):

Most points earned.
Most wins.
Most goal difference (i.e. goals scored - goals against)
Most goals scored.
Less games played.
Lexicographic order.
The Input

The first line of input will be an integer N in a line alone (0 < N < 1000). Then, will follow N tournament descriptions. Each one begins with the tournament name, on a single line. Tournament names can have any letter, digits, spaces etc. Tournament names will have length of at most 100. Then, in the next line, there will be a number T (1 < T <= 30), which stands for the number of teams participating on this tournament. Then will follow T lines, each one containing one team name. Team names may have any character that have ASCII code greater than or equal to 32 (space), except for '#' and '@' characters, which will never appear in team names. No team name will have more than 30 characters.

Following to team names, there will be a non-negative integer G on a single line which stands for the number of games already played on this tournament. G will be no greater than 1000. Then, G lines will follow with the results of games played. They will follow this format:

team_name_1#goals1@goals2#team_name_2
For instance, the following line:
Team A#3@1#Team B
Means that in a game between Team A and Team B, Team A scored 3 goals and Team B scored 1. All goals will be non-negative integers less than 20. You may assume that there will not be inexistent team names (i.e. all team names that appear on game results will have apperead on the team names section) and that no team will play against itself.
The Output

For each tournament, you must output the tournament name in a single line. In the next T lines you must output the standings, according to the rules above. Notice that should the tie-breaker be the lexographic order, it must be done case insenstive. The output format for each line is shown bellow:

[a]) Team_name [b]p, [c]g ([d]-[e]-[f]), [g]gd ([h]-[i])
Where:
[a] = team rank
[b] = total points earned
[c] = games played
[d] = wins
[e] = ties
[f] = losses
[g] = goal difference
[h] = goals scored
[i] = goals against
There must be a single blank space between fields and a single blank line between output sets. See the sample output for examples.
Sample Input

2
World Cup 1998 - Group A
4
Brazil
Norway
Morocco
Scotland
6
Brazil#2@1#Scotland
Norway#2@2#Morocco
Scotland#1@1#Norway
Brazil#3@0#Morocco
Morocco#3@0#Scotland
Brazil#1@2#Norway
Some strange tournament
5
Team A
Team B
Team C
Team D
Team E
5
Team A#1@1#Team B
Team A#2@2#Team C
Team A#0@0#Team D
Team E#2@1#Team C
Team E#1@2#Team D
Sample Output

World Cup 1998 - Group A
1) Brazil 6p, 3g (2-0-1), 3gd (6-3)
2) Norway 5p, 3g (1-2-0), 1gd (5-4) 
3) Morocco 4p, 3g (1-1-1), 0gd (5-5)
4) Scotland 1p, 3g (0-1-2), -4gd (2-6)

Some strange tournament
1) Team D 4p, 2g (1-1-0), 1gd (2-1)
2) Team E 3p, 2g (1-0-1), 0gd (3-3)
3) Team A 3p, 3g (0-3-0), 0gd (3-3)
4) Team B 1p, 1g (0-1-0), 0gd (1-1)
5) Team C 1p, 2g (0-1-1), -1gd (3-4)
*/
#define ONLINE_JUAGE
#pragma warning(disable:4786)
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Team
{
public:	

	Team(const string & name, int totalPoints=0, int gamesPlayed=0,
		int wins=0, int ties=0, int losses=0, int goalDiff=0, 
		int goalScored=0, int goalAgainst=0) : 
		name(name),
		totalPoints(totalPoints),
		gamesPlayed(gamesPlayed),
		wins(wins),
		ties(ties),
		losses(losses),
		goalDiff(goalDiff),
		goalScored(goalScored),
		goalAgainst(goalAgainst){}

		bool operator<(const Team & t) const {
			if (totalPoints>t.totalPoints) {
				return true;
			} else if (totalPoints==t.totalPoints) {
				if (wins>t.wins) {
					return true;
				} else if (wins==t.wins) {
					if (goalDiff>t.goalDiff) {
						return true;
					} else if (goalDiff==t.goalDiff) {
						if (goalScored>t.goalScored) {
							return true;
						} else if (goalScored==t.goalScored) {
							if (gamesPlayed<t.gamesPlayed) {
								return true;
							} else if (gamesPlayed==t.gamesPlayed) {
								if (name>t.name) {
									return true;
								} else {
									return false;
								}
							} else {
								return false;
							}
						} else {
							return false;
						}
					} else {
						return false;
					}					
				} else {
					return false;
				}
			} else {
				return false;
			}
		}

		bool operator==(const Team & t) const {
			return name==t.name;
		}
	string name;
	int totalPoints;
	int gamesPlayed;
	int wins;
	int ties;
	int losses;
	int goalDiff;
	int goalScored;
	int goalAgainst;
};

struct myLess : public binary_function<Team, Team, bool> {

	bool operator()(const Team & t1, const Team & t2) const {
		return t1.name < t2.name;
	}
};

int main() {
#ifndef ONLINE_JUAGE
	ifstream in("10010_i.txt");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());
	ofstream out("10010_o.txt");
	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
#endif
	
	int N;

	cin>>N;
	cin.ignore();

	while (N--) {
		string tourName;		
		getline(cin, tourName);
		int T;
		cin>>T;
		cin.ignore();
		vector<Team> teams;
		string name;
		while (T--) {
			getline(cin, name);
			teams.push_back(Team(name));
		}
		int G;
		cin>>G;
		cin.ignore();
		string gameLine;
		while (G--) {
			getline(cin, gameLine);
			stringstream ss(gameLine);
			string t1_name, t2_name;
			int t1_score, t2_score;
			getline(ss, t1_name, '#');
			ss>>t1_score;
			ss.get();
			ss>>t2_score;
			ss.get();
			getline(ss, t2_name);
		
			vector<Team>::iterator resIter1 = find(teams.begin(), teams.end(), t1_name);
			vector<Team>::iterator resIter2 = find(teams.begin(), teams.end(), t2_name);
			if (t1_score>t2_score) {
				++ resIter1->wins;
				resIter1->totalPoints += 3;
				++ resIter2->losses;
			} else if (t1_score == t2_score) {
				++ resIter1->ties;
				++ resIter2->ties;

				resIter1->totalPoints += 1;
				resIter2->totalPoints += 1;
			} else {
				++ resIter2->wins;
				resIter2->totalPoints += 3;
				++ resIter1->losses;
			}
			
			resIter1->goalScored += t1_score;
			resIter1->goalAgainst += t2_score;
			resIter2->goalScored += t2_score;
			resIter2->goalAgainst += t1_score;

			resIter1->goalDiff += t1_score-t2_score;
			resIter2->goalDiff += t2_score-t1_score;

			++ resIter1->gamesPlayed;
			++ resIter2->gamesPlayed;
		}
		
		sort(teams.begin(), teams.end());
		cout<<tourName<<endl;
		for (int i=0; i<teams.size(); ++i) {
			cout<<i+1<<") "<<teams[i].name<<" "<<teams[i].totalPoints<<"p, "<<teams[i].gamesPlayed<<"g ("
				<<teams[i].wins<<"-"<<teams[i].ties<<"-"<<teams[i].losses<<"), "<<teams[i].goalDiff<<"gd ("
				<<teams[i].goalScored<<"-"<<teams[i].goalAgainst<<")"<<endl;
		}
		cout<<endl;
	}
	
#ifndef ONLINE_JUAGE
	in.close();
	out.close();
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
#endif

	return 0;
}

