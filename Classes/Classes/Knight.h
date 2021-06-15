#pragma once
#ifndef _KNIGHT_H
#define _KNIGHT_H
#include "cocos2d.h"
USING_NS_CC;

class Knight : public Sprite
{
private:
	Sprite* sprite;
	int armor;
	int Hp;
	int Mp;
	int attack;
	double attackSpeed;
public:
	static Knight* KnightCreate(const std::string& filename);
	int getArmor() { return armor; };
	int getHp() { return Hp; };
	int getMp() { return Mp; };
	int getAttack() { return attack; }
	int getAttackSpeed() { return attackSpeed; };
	Sprite* getSprite() { return sprite; }
	void setArmor(int data);
	void setHp(int data);
	void setMp(int data);
};

#endif 


