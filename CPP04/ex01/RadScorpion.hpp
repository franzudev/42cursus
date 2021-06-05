//
// Created by Federico François on 31/05/21.
//

#ifndef CPP04_RADSCORPION_HPP
#define CPP04_RADSCORPION_HPP

#include "Enemy.hpp"

class RadScorpion: public Enemy {
protected:
	unsigned int	hp;
	std::string		type;
public:
	RadScorpion();
	RadScorpion(const RadScorpion& radScorpion);
	virtual ~RadScorpion();
	RadScorpion& operator=(const RadScorpion& radScorpion);
	std::string const& 	getType() const;
	int 				getHP() const;
//	virtual void 		takeDamage(int);
};

#endif //CPP04_RADSCORPION_HPP
