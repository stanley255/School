package Players;

import Weapons.Bow;

public final class Ranger extends Player<Bow> {

    public Ranger(String name, int health, Bow weapon) {
        super(name, health, weapon);
    }

    @Override
    public double getDamage() {
        return getWeapon().getDamage();
    }

    @Override
    public double getBlock() {
        return 0;
    }

    @Override
    public void useSpell() {

    }
}
