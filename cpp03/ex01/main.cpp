#include "ClapTrap.hpp"

int main() {
    // Création de deux objets ClapTrap
    ClapTrap clapTrap1("ClapTrap1");
    ClapTrap clapTrap2("ClapTrap2");

    // ClapTrap1 attaque ClapTrap2
    clapTrap1.attack("ClapTrap2");

    // ClapTrap2 prend des dégâts
    // Cas où le montant des dégâts est inférieur aux points de vie
    clapTrap2.takeDamage(5);

    // Cas où le montant des dégâts est égal aux points de vie
    clapTrap2.takeDamage(5);

    // Cas où le montant des dégâts est supérieur aux points de vie
    clapTrap2.takeDamage(10);

    // ClapTrap2 se répare
    // Cas où la réparation est positive
    clapTrap2.beRepaired(5);

    // Cas où la réparation est nulle
    clapTrap2.beRepaired(0);

    // Utilisation du constructeur par copie
    ClapTrap clapTrap3(clapTrap1);

    return 0;
}
