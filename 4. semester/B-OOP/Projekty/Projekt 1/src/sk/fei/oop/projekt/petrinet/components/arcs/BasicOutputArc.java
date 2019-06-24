package sk.fei.oop.projekt.petrinet.components.arcs;

import sk.fei.oop.projekt.petrinet.components.vertices.Place;
import sk.fei.oop.projekt.petrinet.components.vertices.Transition;

public final class BasicOutputArc extends BasicArc implements Output {

    public BasicOutputArc(Transition startPoint, Place endPoint, int weight) {
        super(startPoint, endPoint, weight);
    }

    public BasicOutputArc(Transition startPoint, Place endPoint) {
        super(startPoint, endPoint);
    }

    @Override
    public void produceTokensToPlace() {
        Place place = (Place)this.getEndPoint();
        place.setTokenCount(place.getTokenCount() + this.getWeight());
    }

}
