#pragma once
#ifndef _BATTLESCENE_H_
#define _BATTLESCENE_H_

//#include "Actor\Knight.h"
//#include "Enemy\Enemy.h"
#include "BattleRoom.h"
#include "Const.h"
#include "Knight.h"
#include "cocos2d.h"
#include <queue>

USING_NS_CC;
using std::queue;

class BattleScene : public Scene {
	friend class BattleRoom;
	static constexpr INT32 SIZEMTX = 5;
	static constexpr INT32 MAXROOM = 5; // temporarily make it 5

public:
	static Scene* createScene();
	virtual bool init();
	virtual void update(float delta);
	CREATE_FUNC(BattleScene);

private:
	void initRoom(); //generate room randomly

	void getNextRoomDir(INT32, INT32, BattleRoom*&, queue<BattleRoom*>&);
	void randomGenerate(INT32, INT32);

private:
	INT32 cntRoom = 0;
private:
	Knight* knight = nullptr;

	// temporarily just one kind of map floor and wall
private:
	Sprite* floorSprite = nullptr;
	Sprite* wallSprite = nullptr;

	Vector<Sprite*> vecFloor;
	Vector<Sprite*> vecWall;

	//Vector<Enemy*> vecEnemy;

	BattleRoom* battleRoom[SIZEMTX][SIZEMTX] = { nullptr };  // room
};

#endif

