package sk.fei.oop.projekt.petrinet.components.arcs;

import sk.fei.oop.projekt.petrinet.components.vertices.Place;
import sk.fei.oop.projekt.petrinet.components.vertices.Transition;

public final class ResetArc extends Arc<Place,Transition> implements Input {

    public ResetArc(Place startPoint, Transition endPoint) {
        super(startPoint, endPoint);
    }

    @Override
    public void consumeTokensFromPlace() {
        Place place = this.getStartPoint();
        place.setTokenCount(0);
    }

    @Override
    public int canConsume() {
        return 0;
    }
}
