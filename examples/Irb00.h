#pragma once
#include"MJCards.h"
#include"Player.h"
#include <utility>
#include <functional>
#include<vector>




class Irb00 : public Player {
private:
	struct Tiles_
	{
		int tiles[4];
		Tiles_ operator-=(const Tiles_ & t);
		Tiles_ operator-=(const MJCard & t);
		Tiles_ operator+=(const MJCard & t);
	};

	struct CandidateThrow {
		int stepToHu;
		int numOfImprove;
		//int t2;
		int color;
		int value;
	};

	typedef struct
	{
		vector<int> code;
		vector<int> Hu_Tiles;
		int steps;
	}Groups;

	int pickToEat; //�sPick2Eat���^�ǭ�

public:
	Irb00();
	MJCard Throw(const MJCard & card = MJCard(-100, -100));
	std::pair<CommandType, MJCard> WannaHuGon(bool canHu, bool canGon, const MJCard & card, const MJCard & gonCard);
	CommandType WannaHGPE(bool canHu, bool canGon, bool canPon, bool canEat, const MJCard & card, int idx);
	int Pick2Eat(const MJCard & card);

private:
	int StepToHu1617(const Tiles_ & Hand);
	vector<int> GetComponent(Tiles_ T);
	Tiles_ HandToTiles(const MJCards & cards);
	Tiles_ HandToTiles(const MJCards & cards, const MJCard & card);
	void T1(Tiles_ & Hand, int stepToHu, vector<CandidateThrow> & Candidates);
	void T2(Tiles_ & Hand, const Tiles_ & remaindTiles, int stepToHu, vector<CandidateThrow> & Candidates, vector<CandidateThrow> & Candidates2);
	MJCard TileToCard(int color, int value);
	int NumOfImprove(Tiles_ & Hand, const Tiles_ & remainTiles, int stepToHu);
	void FindGroups(Tiles_ T, const vector<int>& Componet, vector<Groups>& result, vector<int> tmp, int start);
	vector<Groups> CountSteps(vector<Groups>& G);
	bool Have(int t, int m);

	long long CardTo34(const MJCard & card);

	//�Y�Ҧ��i�઺�b���|���i�U�ƼW�[�A�^��false�MMJCard(-10,-10)�A�Ϥ��^��true�M�n�b���P�Azimo�Y��false�N��O�O�H�᪺�P
	std::pair<bool, MJCard> GonOrNot(const MJCard & card, bool zimo);

	//�u�A�Ω�ۤv�N�P���b�A�]�����Ҽ{����b�����p
	vector<MJCard> AllYouCanGon(const MJCard & card);

	bool PonOrNot(const MJCard & card);
	std::pair<bool, int> EatOrNot(const MJCard & card);

};