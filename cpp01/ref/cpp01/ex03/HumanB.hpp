#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class HumanB {
	private:
		std::string _name;
		Weapon *_weapon;

	public:
		HumanB(void);
		~HumanB(void);

		HumanB(std::string name);
		void setWeapon(Weapon &weapon);
		void attack(void) const;
};

#endif