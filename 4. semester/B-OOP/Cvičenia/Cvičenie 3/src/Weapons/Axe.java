package Weapons;

public final class Axe extends Weapon {

    private double size;

    private double slashSpeed;

    public Axe(String name, double criticalHitChance, double criticalHitBonus, double size, double slashSpeed) {
        super(name, criticalHitChance, criticalHitBonus);
        this.setSize(size);
        this.setSlashSpeed(slashSpeed);
    }

    @Override
    public double getDamage() {
        if (super.isHitCritical()) {
            return Math.round((1+super.getCriticalHitBonus())*(size*slashSpeed)*100.0)/100.0;
        }
        return Math.round(size*slashSpeed*100.0)/100.0;
    }

    public double getSize() {
        return size;
    }

    public void setSize(double size) throws IllegalArgumentException {
        if (size <= 0.0) {
            throw new IllegalArgumentException("Axe's size cannot be lesser then 0.0!");
        }
        this.size = size;
    }

    public double getSlashSpeed() {
        return slashSpeed;
    }

    public void setSlashSpeed(double slashSpeed) throws IllegalArgumentException {
        if (slashSpeed <= 0.0) {
            throw new IllegalArgumentException("Axe's slash speed cannot be lesser then 0.0!");
        }
        this.slashSpeed = slashSpeed;
    }
}
