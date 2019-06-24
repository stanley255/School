package Weapons;

public final class Sword extends Weapon {

    private double sharpness;

    private double slashSpeed;

    public Sword(String name, double criticalHitChance, double criticalHitBonus, double sharpness, double slashSpeed) {
        super(name, criticalHitChance, criticalHitBonus);
        this.setSharpness(sharpness);
        this.setSlashSpeed(slashSpeed);
    }

    @Override
    public double getDamage() {
        if (super.isHitCritical()) {
            return Math.round((1+super.getCriticalHitBonus())*(sharpness*slashSpeed)*100.0)/100.0;
        }
        return Math.round(sharpness*slashSpeed*100.0)/100.0;
    }

    public double getSharpness() {
        return sharpness;
    }

    public void setSharpness(double sharpness) throws IllegalArgumentException {
        if (sharpness <= 0.0) {
            throw new IllegalArgumentException("Sword's sharpness cannot be lesser then 0.0!");
        }
        this.sharpness = sharpness;
    }

    public double getSlashSpeed() {
        return slashSpeed;
    }

    public void setSlashSpeed(double slashSpeed) throws IllegalArgumentException {
        if (slashSpeed <= 0.0) {
            throw new IllegalArgumentException("Sword's slash speed cannot be lesser then 0.0!");
        }
        this.slashSpeed = slashSpeed;
    }
}
