//
// Created by Federico Francois on 5/28/21.
//

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	FragTrap fragTrap1;
	FragTrap fragTrap("Egidio");
	FragTrap fragTrap3;
	ScavTrap scavTrap;
	ScavTrap scavTrap1("Boris");
	ScavTrap scavTrap3;

	fragTrap3 = FragTrap(fragTrap);
	scavTrap3 = ScavTrap(scavTrap);

	fragTrap1.meleeAttack("Egidio");
	fragTrap.takeDamage(30);
	fragTrap.rangedAttack("Egidio.clone");
	fragTrap3.takeDamage(20);
	fragTrap3.meleeAttack("NullFrag");
	fragTrap1.takeDamage(30);
	fragTrap1.beRepaired(7);
	fragTrap.beRepaired(23);
	fragTrap3.beRepaired(15);
	fragTrap3.vaulthunter_dot_exe("Egidio");
	fragTrap3.vaulthunter_dot_exe("Egidio");
	fragTrap3.vaulthunter_dot_exe("Egidio");
	fragTrap3.vaulthunter_dot_exe("Egidio");
	fragTrap3.vaulthunter_dot_exe("Egidio");


	scavTrap1.meleeAttack("Boris");
	scavTrap.takeDamage(30);
	scavTrap.rangedAttack("Boris.clone");
	scavTrap3.takeDamage(20);
	scavTrap3.meleeAttack("NullFrag");
	scavTrap1.takeDamage(30);
	scavTrap1.beRepaired(7);
	scavTrap.beRepaired(23);
	scavTrap3.beRepaired(15);
	scavTrap.challengeNewcomer();
	scavTrap3.challengeNewcomer();
	scavTrap1.challengeNewcomer();
	scavTrap3.challengeNewcomer();
	scavTrap1.challengeNewcomer();
	scavTrap.challengeNewcomer();



	return 0;
}
