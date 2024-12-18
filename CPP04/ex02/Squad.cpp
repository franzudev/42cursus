//
// Created by Federico François on 02/06/21.
//

#include "Squad.hpp"

Squad::Squad(): count(0), units(nullptr) {}

Squad::Squad(const Squad &squad): count(0), units(nullptr) {
	*this = squad;
}

Squad::~Squad() {
	for (int i = 0; i < count; i++)
		delete units[i];
	delete units;
}

Squad& Squad::operator=(const Squad &squad) {
	if (count)
		delete[] units;
	count = 0;
	units = nullptr;
	for (int i = 0; i < squad.count; i++)
		push(squad.getUnit(i)->clone());
	return *this;
}

ISpaceMarine * Squad::getUnit(int idx) const {
	if (!count || !units || !(idx < count && idx > -1))
		return nullptr;
	return units[idx];
}

int Squad::getCount() const {
	return count;
}

int Squad::push(ISpaceMarine *spaceMarine) {
	if (!spaceMarine)
		return count;
	for (int i = 0; i < count; i++)
	{
		if (spaceMarine == getUnit(i))
			return count;
	}
	ISpaceMarine **newUnits = new ISpaceMarine*[count + 1];
	for (int i = 0; i < count; i++)
		newUnits[i] = getUnit(i);
	count++;
	newUnits[!count ? 0 : count - 1] = spaceMarine;
	if (units)
		delete units;
	units = newUnits;
	return count;
}