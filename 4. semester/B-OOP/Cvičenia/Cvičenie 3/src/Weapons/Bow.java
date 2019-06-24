package Weapons;

public final class Bow extends Weapon {

    private double arrowPiercing;

    private double arrowSpeed;

    public Bow(String name, double criticalHitChance, double criticalHitBonus, double arrowPiercing, double arrowSpeed) {
        super(name, criticalHitChance, criticalHitBonus);
        this.setArrowPiercing(arrowPiercing);
        this.setArrowSpeed(arrowSpeed);
    }

    @Override
    public double getDamage() {
        if (super.isHitCritical()) {
            return Math.round((1+super.getCriticalHitBonus())*(arrowPiercing*arrowSpeed)*100.0)/100.0;
        }
        return Math.round(arrowPiercing*arrowSpeed*100.0)/100.0;
    }

    public double getArrowPiercing() {
        return arrowPiercing;
    }

    public void setArrowPiercing(double arrowPiercing) throws IllegalArgumentException {
        if (arrowPiercing <= 0.0) {
            throw new IllegalArgumentException("Arrow's piercing cannot be lesser then 0.0!");
        }
        this.arrowPiercing = arrowPiercing;
    }

    public double getArrowSpeed() {
        return arrowSpeed;
    }

    public void setArrowSpeed(double arrowSpeed) throws IllegalArgumentException {
        if (arrowSpeed <= 0.0) {
            throw new IllegalArgumentException("Arrow's speed cannot be lesser then 0.0!");
        }
        this.arrowSpeed = arrowSpeed;
    }
}
