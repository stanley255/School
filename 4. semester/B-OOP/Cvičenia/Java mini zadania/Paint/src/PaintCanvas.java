import java.awt.*;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.LinkedHashMap;
import java.util.LinkedList;

public class PaintCanvas extends Canvas {

    LinkedList<Drawable> drawables;
    LinkedHashMap<Shape, Color> colorsForShapes;
    Drawable temporaryDrawable;
    Color currentColor;

    public PaintCanvas() {
        this.drawables = new LinkedList<>();
        this.colorsForShapes = new LinkedHashMap<>();
        this.temporaryDrawable = null;
        this.currentColor = Color.BLACK;
    }

    public LinkedList<Drawable> getDrawables() {
        return drawables;
    }

    public void setDrawables(LinkedList<Drawable> drawables) {
        this.drawables = drawables;
    }

    public void addDrawable(Drawable drawable) {
        if (drawables==null) {
            this.drawables = new LinkedList<>();
        }
        Colorable colorable = (Colorable)drawable;
        if (colorable.getColor() == null) {
            ((Colorable)drawable).setColor(currentColor);
        }
        this.drawables.add(drawable);
        this.temporaryDrawable = null;
    }

    public void setTemporaryDrawable(Drawable temporaryDrawable) {
        this.temporaryDrawable = temporaryDrawable;
    }

    public Color getCurrentColor() {
        return currentColor;
    }

    public void setCurrentColor(Color currentColor) {
        this.currentColor = currentColor;
    }

    public void paint(Graphics g) {
        if (drawables==null) { return; }
        Graphics2D g2 = (Graphics2D) g;
        for (Drawable drawable : drawables) {
            drawable.draw(g2);
        }
        if (temporaryDrawable != null) {
            ((Colorable)temporaryDrawable).setColor(currentColor);
            temporaryDrawable.draw(g2);
        }
        repaint();
    }

    @Override
    public synchronized void addMouseListener(MouseListener l) {
        super.addMouseListener(l);
    }

    @Override
    public synchronized void addMouseMotionListener(MouseMotionListener l) {
        super.addMouseMotionListener(l);
    }

    public void removeListeners() {
        for (MouseListener mouseListener : getMouseListeners()) {
            removeMouseListener(mouseListener);
        }
        for (MouseMotionListener mouseMotionListener : getMouseMotionListeners()) {
            removeMouseMotionListener(mouseMotionListener);
        }
    }

}
