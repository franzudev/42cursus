#include "FragTrap.hpp"

int main() {
	FragTrap fragTrap1;
	FragTrap fragTrap("Egidio");
	FragTrap fragTrap3;

	fragTrap3 = FragTrap(fragTrap);
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

	return 0;
}
