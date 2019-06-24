package Weapons;

import java.util.ArrayList;
import java.util.List;

public final class Armory {
    private List<Sword> swords;

    private List<Axe> axes;

    private List<Bow> bows;

    public Armory() {

        // Swords
        List<Sword> newSwords = new ArrayList<Sword>();
        newSwords.add(new Sword("Excalibur",0.3,0.1,2.5,1.4));
        newSwords.add(new Sword("Short sword",0.5,0.4,1.75,2.4));
        newSwords.add(new Sword("Long sword",0.1,0.4,2.75,1.1));
        this.swords = newSwords;

        // Axes
        List<Axe> newAxes = new ArrayList<Axe>();
        newAxes.add(new Axe("Pandalonium",0.4,0.17,3.5,0.6));
        newAxes.add(new Axe("Golden axe",0.32,0.2,0.75,3.0));
        newAxes.add(new Axe("Qwendork",0.13,0.1,2.5,1.61));
        this.axes = newAxes;

        // Bows
        List<Bow> newBows = new ArrayList<Bow>();
        newBows.add(new Bow("Legolas' bow",0.5,0.1,1.3,1.3));
        newBows.add(new Bow("Mighty bow",0.29,0.2,2,0.98));
        newBows.add(new Bow("Letorucent",0.17,0.32,1.1,1.5));
        this.bows = newBows;

    }

    public Armory(List<Sword> swords, List<Axe> axes, List<Bow> bows) {
        this.setSwords(swords);
        this.setAxes(axes);
        this.setBows(bows);
    }

    public List<Sword> getSwords() {
        return swords;
    }

    private void setSwords(List<Sword> swords) throws IllegalArgumentException {
        if (swords.size() < 2) {
            throw new IllegalArgumentException("There should be at least two swords!");
        }
        this.swords = swords;
    }

    public List<Axe> getAxes() {
        return axes;
    }

    private void setAxes(List<Axe> axes) throws IllegalArgumentException {
        if (axes.size() < 2) {
            throw new IllegalArgumentException("There should be at least two axes!");
        }
        this.axes = axes;
    }

    public List<Bow> getBows() {
        return bows;
    }

    private void setBows(List<Bow> bows) throws IllegalArgumentException {
        if (bows.size() < 2) {
            throw new IllegalArgumentException("There should be at least two bows!");
        }
        this.bows = bows;
    }

    public List<Weapon> getWeapons() {
        List<Weapon> allWeapons = new ArrayList<>();
        allWeapons.addAll(this.swords);
        allWeapons.addAll(this.bows);
        allWeapons.addAll(this.axes);
        return allWeapons;
    }

}
