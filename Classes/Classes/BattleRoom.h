#pragma once
#ifndef _BATTLEROOM_H
#define _BATTLEROOM_H
#include "cocos2d.h"
#include "const.h"
USING_NS_CC;

class BattleRoom : public Node
{
	static constexpr INT32 SIZEROOM = 19;
	friend class BattleScene;
public:
	CREATE_FUNC(BattleRoom);

	virtual bool init();
	//virtual void update(float delta);
	float getCenterX();
	float getCenterY();
	INT32 getX();
	INT32 getY();

	void createMap(); 

	void setCenter(float, float);

	void connect(BattleRoom*);

private:
	float centerX, centerY;
	INT32 x, y;  // row and column in 7 * 7 BattleRoom matrix
	INT32 visTime; //maybe not needed
	INT32 nextDIR;
	bool visDir[CNTDIR] = { false };

private:
	BattleRoom* nextRoom = nullptr;
	BattleRoom* prevRoom = nullptr;

	//EnemyController* enemyCtr = nullptr;

private:
	Vector<Sprite*> vecBG;
};
#endif // !_BATTLEROOM_H


