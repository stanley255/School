package Weapons;

import Utils.StringUtils;

public abstract class Weapon {

    private String name;

    private double criticalHitChance;

    private double criticalHitBonus;

    public abstract double getDamage();

    public Weapon(String name, double criticalHitChance, double criticalHitBonus) {
        this.setName(name);
        this.setCriticalHitChance(criticalHitChance);
        this.setCriticalHitBonus(criticalHitBonus);
    }

    public String getName() {
        return name;
    }

    private void setName(String name) throws IllegalArgumentException {
        if (StringUtils.isEmpty(name)) {
            throw new IllegalArgumentException("Player name cannot by empty!");
        }
        this.name = name;
    }

    public double getCriticalHitChance() {
        return criticalHitChance;
    }

    private void setCriticalHitChance(double criticalHitChance) throws IllegalArgumentException {
        if (criticalHitChance <= 0.0){
            throw new IllegalArgumentException("Critical hit chance cannot be lesser then 0.0!");
        }
        this.criticalHitChance = criticalHitChance;
    }

    public double getCriticalHitBonus() {
        return criticalHitBonus;
    }

    private void setCriticalHitBonus(double criticalHitBonus)  throws IllegalArgumentException {
        if (criticalHitBonus <= 0.0){
            throw new IllegalArgumentException("Critical hit bonus cannot be lesser then 0.0!");
        }
        this.criticalHitBonus = criticalHitBonus;
    }

    protected boolean isHitCritical() {
        return (this.criticalHitChance + Math.random()) > 1;
    }

}
