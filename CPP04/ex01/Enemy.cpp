//
// Created by Federico François on 31/05/21.
//

#include "Enemy.hpp"

Enemy::Enemy(int hp, const std::string &type) {
	setHP(hp);
	setType(type);
}

Enemy::Enemy(const Enemy &enemy) {
	setHP(enemy.hp);
	setType(enemy.type);
}

Enemy::~Enemy() {}

Enemy& Enemy::operator=(const Enemy &enemy) {
	setHP(enemy.hp);
	setType(enemy.type);

	return *this;
}

void Enemy::setType(std::string _type) {
	type = _type;
}

void Enemy::setHP(unsigned int val) {
	hp = val;
}

void Enemy::takeDamage(int damage) {
	if (damage < 1)
		return;
	if (hp - damage < 0)
	{
		hp = 0;
		return ;
	}
	hp -= damage;
}

const std::string & Enemy::getType() const {
	return type;
}

int Enemy::getHP() const {
	return hp;
}

