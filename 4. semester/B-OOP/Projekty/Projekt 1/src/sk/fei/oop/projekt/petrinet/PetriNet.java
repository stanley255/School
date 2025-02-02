package sk.fei.oop.projekt.petrinet;

import sk.fei.oop.projekt.petrinet.components.Component;
import sk.fei.oop.projekt.petrinet.components.arcs.*;
import sk.fei.oop.projekt.petrinet.components.vertices.*;
import sk.fei.oop.projekt.petrinet.exceptions.NegativeTokenCount;

import java.util.*;

public final class PetriNet {

    private Map<Long,Vertex> vertices;
    private Map<Long,Arc> arcs;

    public PetriNet() {
        this.vertices = new HashMap<>();
        this.arcs =  new HashMap<>();
    }

    public void add(Vertex vertex) {
        if (vertex == null) {
            throw new IllegalArgumentException("Null component cannot be added to Petri net!");
        }
        verifyExistingComponent(vertex,Vertex.class);
        this.vertices.put(vertex.getId(),vertex);
    }

    public void add(Arc arc) {
        if (arc == null) {
            throw new IllegalArgumentException("Null component cannot be added to Petri net!");
        }
        verifyExistingComponent(arc,Arc.class);
        verifyArcVertices(arc);
        this.arcs.put(arc.getId(),arc);
    }

    public void printPlaces() {
        for (Map.Entry<Long,Vertex> longVertexEntry:this.vertices.entrySet()) {
            Vertex vertex = longVertexEntry.getValue();
            if (vertex instanceof Place) {
                System.out.println(vertex);
            }
        }
    }

    public boolean fire(long transitionID) {
        Transition transition = this.getTransitionFromID(transitionID);
        // Get places connected with transition
        ArrayList<Arc> transitionArcs = this.getTransitionArcs(transition);
        // Get input places
        ArrayList<Arc> inputArcs = this.filterIOArcs(transitionArcs, Input.class);
        // Check if transition is fire-able
        if (!canAllArcsConsume(inputArcs)) {
            System.out.println("Transition "+transition+" cannot be fired!"); // This line is for quick control
            return false;
        }
        // Apply token consumption
        this.applyTokenConsumption(inputArcs);
        // Get output places
        ArrayList<Arc> outputArcs = this.filterIOArcs(transitionArcs, Output.class);
        // Increment token count of output places
        this.applyTokenProduction(outputArcs);
        System.out.println("Transition "+transition+" was fired!"); // This line is for quick control
        return true;
    }

    private void applyTokenProduction(ArrayList<Arc> inputArcs) {
        for (Arc arc : inputArcs) {
            BasicOutputArc outputArc = (BasicOutputArc) arc;
            outputArc.produceTokensToPlace();
        }
    }

    private void applyTokenConsumption(ArrayList<Arc> inputArcs) {
        for (Arc arc : inputArcs) {
            Input inputArc = (Input) arc;
            try {
                inputArc.consumeTokensFromPlace();
            } catch (NegativeTokenCount e) {
                Place place = (Place) arc.getStartPoint();
                place.setTokenCount(0);
            }
        }
    }

    private Boolean canAllArcsConsume(ArrayList<Arc> inputArcs) {
        Map<Place,Integer> consumeFromPlaces = new HashMap<>();
        // Creates map<Place,Integer> where int is amount of tokens in place and decrements that number based on weight
        for (Arc arc:inputArcs){
            Input input = (Input) arc;
            Place place = (Place) arc.getStartPoint();
            if (consumeFromPlaces.get(place) == null) {
                consumeFromPlaces.put(place,place.getTokenCount()-input.canConsume());
            } else {
                consumeFromPlaces.put(place,consumeFromPlaces.get(place)-input.canConsume());
            }
        }
        // Loops through map and checks for negative number occurrence
        return canAllArcsConsume(consumeFromPlaces);
    }

    private Boolean canAllArcsConsume(Map<Place,Integer> toConsumeFromPlaces) {
        for (Map.Entry<Place,Integer>placeIntegerEntry:toConsumeFromPlaces.entrySet()) {
            if (placeIntegerEntry.getValue() < 0) { return false; }
        }
        return true;
    }

    private ArrayList<Arc> getTransitionArcs(Transition transition) {
        ArrayList<Arc> filteredArcs = new ArrayList<>();
        for (Map.Entry<Long,Arc>longArcEntry:this.arcs.entrySet()) {
            Arc arc = longArcEntry.getValue();
            if (transition == arc.getStartPoint() || transition == arc.getEndPoint()) {
                filteredArcs.add(arc);
            }
        }
        return filteredArcs;
    }

    // Method filters arc based on class interface passed (input/output)
    private ArrayList<Arc> filterIOArcs(ArrayList<Arc> arcArray ,Class ioInterface) {
        ArrayList<Arc> filteredArcs = new ArrayList<>();
        for (Arc arc:arcArray) {
            if (ioInterface.isInstance(arc)) {
                filteredArcs.add(arc);
            }
        }
        return filteredArcs;
    }

    private Transition getTransitionFromID(long transitionID) {
        try{
            Transition transToReturn = (Transition)this.vertices.get(transitionID);
            if (transToReturn == null) { throw new IllegalArgumentException("Invalid transition ID!"); }
            return transToReturn;
        } catch (Exception e) {
            throw new IllegalArgumentException("Invalid transition ID!");
        }
    }

    private void verifyArcVertices(Arc arc) {
        Vertex startPoint = (Vertex) arc.getStartPoint();
        Vertex endPoint = arc.getEndPoint();
        if (this.vertices.get(startPoint.getId()) == null) {
            throw new IllegalArgumentException("Arc's start point is not added in Petri net!");
        }
        if (this.vertices.get(endPoint.getId()) == null) {
            throw new IllegalArgumentException("Arc's end point is not added in Petri net");
        }
    }

    private void verifyExistingComponent(Component component, Class componentClass) {
        Component toVerify;
        if (componentClass == Vertex.class) {
            toVerify = this.vertices.get(component.getId());
        } else {
            toVerify = this.arcs.get(component.getId());
        }
        if (toVerify != null) {
            throw new IllegalArgumentException("Same component cannot be added multiple times into same petri net!");
        }
    }

}
