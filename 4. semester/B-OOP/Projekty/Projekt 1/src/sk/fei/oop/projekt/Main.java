package sk.fei.oop.projekt;

import sk.fei.oop.projekt.petrinet.PetriNet;
import sk.fei.oop.projekt.petrinet.components.arcs.*;
import sk.fei.oop.projekt.petrinet.components.vertices.*;

/*
* Vypracoval: Stanislav Pekarovič
* AIS_ID: 92323
* Predmet: B-OOP
*
* Poznámka: Nevedel som, ako by ste preferovali mať spravené exceptions a ich handling, čo sa týka main-u a preto
*           som sa rozhodol pre nasledujúci prístup:
*               - ak je chybne inicializovaný objekt => propagácia príslušnej exception do mainu => koniec programu
*               - ak je pridaný chybný objekt do PN  => propagácia príslušnej exception do mainu => koniec programu
*               - fire:
*                   * chyba v zmysle poskytnutie zlého ID => exception propagovana do mainu => koniec programu
*                   * nespustiteľný prechod => nie je generovaná exception iba návratová hodnota fire je false
*           Tento prístup som zvolil z toho dôvodu, že si myslím, že ak sa nepodarí programátorovi inicializovať objekt,
*           s ktorým chcel pracovať resp. sa mu ho nepodarí pridať do PetriNet prípadne zadal zlé ID prechodu do fire
*           tak by sa nemalo pokračovať ďalej kdežto keď sa mu nepodarí spustiť prechod, tak je to iba dôsledok
*           nedostatku tokenov, čo má signalizované návratovou hodnotou metódy fire. To je iba môj názor a nemyslím si,
*           že je najlepší, ale nakoľko nebolo špecifikované, že ako to máme robiť, tak som Vás len chcel informovať
*           o tom, ako som nad tým uvažoval.
*
* Poznámka: V metóde fire som ponechal dva riadky, ktoré do console lognú, či sa prechod podarilo spusiť alebo nie,
*           aby ste to nemuseli kontrolovať na návratovej hodnote. Taktiež som pre Vás spravil do PetriNet
*           metódu printPlaces(), ktorá vypíše všetky miesta a ich aktuálny stav tokenov.
*
*/

public class Main {

    public static void main(String[] args) {

        PetriNet petriNet = new PetriNet();

        Transition t1 = new Transition("t1");
        Transition t2 = new Transition("t2");
        Transition t3 = new Transition("t3");
        Transition t4 = new Transition("t4");
        Transition t5 = new Transition("t5");

        Place p1 = new Place("p1");
        Place p2 = new Place("p2");
        Place p3 = new Place("p3",1);
        Place p4 = new Place("p4",1);
        Place p5 = new Place("p5",5);
        Place p6 = new Place("p6");
        Place p7 = new Place("p7");

        BasicArc ba1 = new BasicOutputArc(t2,p1,5);
        BasicArc ba2 = new BasicInputArc(p2,t3);
        BasicArc ba3 = new BasicInputArc(p3,t4);
        BasicArc ba4 = new BasicOutputArc(t4,p3,2);
        BasicArc ba5 = new BasicInputArc(p4,t5);
        BasicArc ba6 = new BasicOutputArc(t5,p6);
        BasicArc ba7 = new BasicOutputArc(t5,p7);

        ResetArc ra1 = new ResetArc(p5,t5);

        petriNet.add(t1);
        petriNet.add(t2);
        petriNet.add(t3);
        petriNet.add(t4);
        petriNet.add(t5);
        petriNet.add(p1);
        petriNet.add(p2);
        petriNet.add(p3);
        petriNet.add(p4);
        petriNet.add(p5);
        petriNet.add(p6);
        petriNet.add(p7);
        petriNet.add(ba1);
        petriNet.add(ba2);
        petriNet.add(ba3);
        petriNet.add(ba4);
        petriNet.add(ba5);
        petriNet.add(ba6);
        petriNet.add(ba7);
        petriNet.add(ra1);

        // petriNet.fire(t1.getId());
        // petriNet.fire(t2.getId());
        // petriNet.fire(t3.getId());
        // petriNet.fire(t4.getId());
        // petriNet.fire(t5.getId());

        // petriNet.printPlaces();

    }

}
