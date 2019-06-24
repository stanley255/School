package sk.fei.oop.projekt.petrinet.components.arcs;

import sk.fei.oop.projekt.petrinet.components.vertices.Place;
import sk.fei.oop.projekt.petrinet.components.vertices.Transition;

public final class BasicInputArc extends BasicArc implements Input {

    public BasicInputArc(Place startPoint, Transition endPoint, int weight) {
        super(startPoint, endPoint, weight);
    }

    public BasicInputArc(Place startPoint, Transition endPoint) {
        super(startPoint, endPoint);
    }

    @Override
    public void consumeTokensFromPlace() {
        Place place = (Place)this.getStartPoint();
        place.setTokenCount(place.getTokenCount() - this.getWeight());
    }

    @Override
    public int canConsume() {
        return this.weight;
    }

}
