package Game;

import Players.*;
import Utils.*;
import Weapons.Armory;
import Weapons.Weapon;

import java.lang.reflect.Constructor;
import java.lang.reflect.ParameterizedType;
import java.util.*;

public class InputLoad {

    private static Map<Integer, String> classChoices  = new HashMap<Integer, String>() {{
        put(1, "Knight");
        put(2, "Barbarian");
        put(3, "Ranger");
    }};

    private static void printClassOptions() {
        for (Map.Entry<Integer, String> entry : classChoices.entrySet()) {
            System.out.println(Character.toLowerCase(entry.getKey()) + ") " + entry.getValue());
        }
    }

    public static String loadStringInput(String inputText, String falseInputText) {
        String toReturn = "";
        System.out.println(inputText);
        toReturn = KeyboardInput.readString();
        while (StringUtils.isEmpty(toReturn)) {
            System.out.println(falseInputText);
            toReturn = KeyboardInput.readString();
        }
        return toReturn;
    }

    public static Integer loadPlayerInputFromMap(String inputText, String falseInputText, Map<?,?> inputList) {
        System.out.println(inputText);
        Integer inputOption = KeyboardInput.readInt();
        while (!inputList.containsKey(inputOption)) {
            System.out.println(falseInputText);
            inputOption = KeyboardInput.readInt();
        }
        return inputOption;
    }

    public static String loadPlayerClass(String inputText, String falseInputText) {
        printClassOptions();
        return classChoices.get(loadPlayerInputFromMap(inputText, falseInputText,classChoices));
    }

    public static Class getClassFromString(String classString) {
        final String fullClassString = "Players."+classString;
        try {
            return Class.forName(fullClassString);
        }
        catch (ClassNotFoundException e) { }
        return null;
    }

    private static Class getWeaponTypeFromClass(Class playerClass) {
        ParameterizedType parameterizedType = (ParameterizedType) playerClass.getGenericSuperclass();
        return (Class<?>)parameterizedType.getActualTypeArguments()[0];
    }

    private static boolean isWeaponAvailableForClass(Class playerWeaponType, Weapon armoryWeapon) {
        return playerWeaponType == armoryWeapon.getClass();
    }

    private static Map<Integer, Weapon> getAvailableWeaponsMap(Class playerClass, Armory armory) {
        Map<Integer, Weapon> availableWeapons = new HashMap<Integer,Weapon>();
        Class availableWeaponType = getWeaponTypeFromClass(playerClass);
        int i = 1;
        for(Weapon weapon: armory.getWeapons()) {
            if (isWeaponAvailableForClass(availableWeaponType,weapon)) {
                availableWeapons.put(i,weapon);
                i++;
            }
        }
        return availableWeapons;
    }

    private static void listAvailableWeapons(Map<Integer, Weapon> weapons) {
        for (Map.Entry<Integer, Weapon> entry: weapons.entrySet()) {
            System.out.println(entry.getKey()+") "+entry.getValue().getName());
        }
    }

    public static Weapon loadPlayerClassWeapons(Class playerClass, Armory armory, String inputText, String falseInputText) {
        Map<Integer, Weapon> weapons = getAvailableWeaponsMap(playerClass, armory);
        listAvailableWeapons(weapons);
        Integer playerWeaponIndex = loadPlayerInputFromMap(inputText,falseInputText, weapons);
        return weapons.get(playerWeaponIndex);
    }

    public static Player createPlayer(Class playerClass, Weapon playerWeapon , String playerName) {
        try {
            Constructor<?> ctor = playerClass.getConstructor(String.class, int.class, playerWeapon.getClass());
            Object object = ctor.newInstance(new Object[] { playerName, 100, playerWeapon });
            Player player = (Player) object;
            return player;
        } catch (final Exception e) {
            e.printStackTrace();
        }
        return null;
    }

}
