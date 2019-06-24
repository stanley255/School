package Players;

import Weapons.Bow;
import Weapons.Sword;

public final class Knight extends Player<Sword> {

    public Knight(String name, int health, Sword weapon) {
        super(name, health, weapon);
    }

    @Override
    public double getDamage() {
        return getWeapon().getDamage();
    }

    @Override
    public double getBlock() {
        return 0.2;
    }

    @Override
    public void useSpell() {

    }
}
