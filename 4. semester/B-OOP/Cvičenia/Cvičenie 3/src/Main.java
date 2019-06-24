import Players.*;
import Game.InputLoad;
import Weapons.*;

import java.lang.reflect.Constructor;
import java.lang.reflect.Type;

public class Main {

    public static void main(String[] args) {
        // Inicializacia repozitaru zbrani
        Armory armory = new Armory();

        // Nacitanie mien hracov
        String firstPlayerName = InputLoad.loadStringInput("Enter name of first player: ","Name cannot be empty, enter valid name: ");
        String secondPlayerName = InputLoad.loadStringInput("Enter name of second player: ","Name cannot be empty, enter valid name: ");

        // Nacitanie class hracov
        String firstPlayerClassString = InputLoad.loadPlayerClass("Player 1, choose your hero class: ","Enter valid class: ");
        String secondPlayerClassString = InputLoad.loadPlayerClass("Player 2, choose your hero class: ","Enter valid class: ");

        Class firstPlayerClass = InputLoad.getClassFromString(firstPlayerClassString);
        Class secondPlayerClass = InputLoad.getClassFromString(secondPlayerClassString);

        // Nacitanie zbrani hracov
        Weapon firstPlayerWeapon = InputLoad.loadPlayerClassWeapons(firstPlayerClass,armory,"Player 1, choose your weapon: ","Bad weapon number, choose correct one: ");
        Weapon secondPlayerWeapon = InputLoad.loadPlayerClassWeapons(secondPlayerClass,armory,"Player 2, choose your weapon: ","Bad weapon number, choose correct one: ");

        // Vytvor hracov
        Player p1 = InputLoad.createPlayer(firstPlayerClass,firstPlayerWeapon,firstPlayerName);
        Player p2 = InputLoad.createPlayer(secondPlayerClass,secondPlayerWeapon,secondPlayerName);

        // Kontrola
        System.out.println("Meno 1. hraca: " + p1.getName());
        System.out.println("Meno 2. hraca: " + p2.getName());

        System.out.println("Classa 1. hraca: " + p1.getClass());
        System.out.println("Classa 2. hraca: " + p2.getClass());

        System.out.println("Typ zbrane 1. hraca: " + p1.getWeapon().getClass());
        System.out.println("Typ zbrane 2. hraca: " + p2.getWeapon().getClass());
    }

}
