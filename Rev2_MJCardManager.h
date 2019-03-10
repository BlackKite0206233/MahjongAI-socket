#ifndef REV2_MJCARDMANAGER_H
#define REV2_MJCARDMANAGER_H

#include <iostream>
#include <vector>

using namespace std;

#define T1_WEIGHT 20 
#define T2_WEIGHT 5
#define VALUE_WEIGHT 1
#define VALUE_FIRST_X 3
//�קK����ȭp�⬰0
#define VALUE_BASE 0.5  
//�����Wť, ���J
//���J, �V�@��, �M�@��, �T�t��, �|�t��, ���t��, ���o��, �j�|��, �p�|��, �j�T��, �p�T��, �魷�x, �����x, �r�@��
#define FAN_WEIGHT {4, 4, 8, 2, 5, 8, 1, 16, 8, 8, 4, 1, 1, 16}

typedef struct element
{
	int type; //0:��l, 1:���l, 2:�@��, 3:�p��, 4:���}, 5:��i
	vector<int> card;
}group;

typedef struct trans
{
	int leftCard;
	int type;
	//21 �@��->�@��
	//22 �@��->��l
	//31 �p��->���l
	//32 �p��->���l
	//41 ���}->���l
	//51 ��i->���l
	//52 ��i->���l
	//53 ��i->���l
	//54 ��i->��l
	//55 ��i->�@��
	int len;
}changeNode;

vector< group > getElement(vector<int> hand);
vector<double> throwOneCard_v2(vector<int> hand, vector<int> deck, vector<int> door, int totalDeck, int handCount, vector<int> sea, int canPonPon, int position, int round);
vector<double> calcScore(vector<int>* record, vector<int> hand, vector<int> deck, vector<int> door, int handCount, int minStep, int countTi, int totalDeck);
double calcTi(vector<int> hand, vector<int> door);

void countTing(int remain, int nowPos, vector< group > combine, vector<int> usedHand, const vector<int>& hand, int *  min);

void estimute_v2(vector< group > combine, vector<int> deck, int totalDeck, vector<double> * totalValue, vector<int> door);
void returnAllCombineProp_v2(int nowPos, vector< vector<changeNode> > changePattern, int once, vector<int> nowHand, vector<double> * totalValue, vector<int> deck, int totalDeck, vector<int> door);

#endif // REV2_MJCARDMANAGER_H