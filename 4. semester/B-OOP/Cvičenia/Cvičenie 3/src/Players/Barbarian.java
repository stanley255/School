package Players;

import Weapons.Axe;

public final class Barbarian extends Player<Axe> {

    public Barbarian(String name, int health, Axe weapon) {
        super(name, health, weapon);
    }

    @Override
    public double getDamage() {
        return getWeapon().getDamage();
    }

    @Override
    public double getBlock() {
        return Math.round(((Math.random()*0.1)+0.1)*100.0)/100.0;
    }

    @Override
    public void useSpell() {

    }
}
