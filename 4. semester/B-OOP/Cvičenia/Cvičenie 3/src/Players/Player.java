package Players;

import Weapons.Weapon;

import Utils.StringUtils;

public abstract class Player <T extends Weapon> {

    private String name;

    private int health;

    private T weapon;

    public abstract double getDamage();

    public abstract double getBlock();

    public abstract void useSpell();

    public Player(String name, int health, T weapon) {
        this.setName(name);
        this.setHealth(health);
        this.setWeapon(weapon);
    }

    public String getName() {
        return name;
    }

    private void setName(String name) throws IllegalArgumentException {
        if (StringUtils.isEmpty(name)) {
            throw new IllegalArgumentException("Player name cannot be empty!");
        }
        this.name = name;
    }

    public int getHealth() {
        return health;
    }

    private void setHealth(int health) throws IllegalArgumentException  {
        if (health <= 0) {
            throw new IllegalArgumentException("Player's health cannot be 0 or less!");
        }
        this.health = health;
    }

    public T getWeapon() {
        return weapon;
    }

    private void setWeapon(T weapon) throws IllegalArgumentException {
        if (weapon == null) {
            throw new IllegalArgumentException("Player needs weapon!");
        }
        this.weapon = weapon;
    }

    public void takeDamage(double opponentDamage) {
        this.health = (int) (this.health - opponentDamage*(1-this.getBlock()));
    }

}
