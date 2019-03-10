#ifndef REV2_PLAYER_H
#define REV2_PLAYER_H

#include "Player.h"

#include "Rev2_MJCardManager.h"

class Rev2_Player : public Player {

	// 0~8:�U, 9~17:��, 18~26:��, 27~33:�F-�n-��-�_-��-�o-��
	vector<int> hand;
	vector<int> deck;
	//��-4��ܷt�b
	vector<int> door;
	vector<int> sea; //�����ӥ]�t�O�H�����e
	int totalDeck;
	int canPonPon;
	int nowHand;
	//�L�kŪ���魷��T
	int roundWind;
	//�ثe�|�L������T
	int positionWind;
	
public:
	static int eatCommand;
	void dataSet();
	Rev2_Player();
	MJCard Throw();
	MJCard Throw(const MJCard & card);
	std::pair<CommandType, MJCard> WannaHuGon(bool canHu, bool canGon, const MJCard & card, const MJCard & gonCard);
	CommandType WannaHGPE(bool canHu, bool canGon, bool canPon, bool canEat, const MJCard & card, int idx);
	bool WannaHu(const MJCard & card) { return true; }

	int Pick2Eat(const MJCard & card);

};


#endif // !REV2_PLAYER_H


