//
// Created by Federico François on 31/05/21.
//

#ifndef CPP04_ENEMY_HPP
#define CPP04_ENEMY_HPP

#include <iostream>

class Enemy {
protected:
	Enemy();
	unsigned int	hp;
	std::string		type;
public:
	Enemy(int hp, std::string const & type);
	Enemy(const Enemy& enemy);
	virtual ~Enemy();
	Enemy& operator=(const Enemy& enemy);
	std::string const&	getType() const;
	int 				getHP() const;
	void				setHP(unsigned int val);
	void				setType(std::string type);
	virtual void 		takeDamage(int);
};

#endif //CPP04_ENEMY_HPP
