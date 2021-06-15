#include "Knight.h"

Knight* Knight::KnightCreate(const std::string& filename) 
{
	Knight* knight = new Knight;
	knight->sprite = Sprite::create(filename);
	knight->armor = 5;
	knight->Hp = 5;
	knight->Mp = 200;
	knight->attack = 3;
	knight->attackSpeed = 1;
	return knight;
}
void Knight::setArmor(int data)
{
	armor = data;
}
void Knight::setHp(int data)
{
	Hp = data;
}
void Knight::setMp(int data)
{
	Mp = data;
}
