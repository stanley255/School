import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.awt.geom.Point2D;

public class CrossButton extends ActionButton {

    static Point2D.Double o = null;

    public CrossButton(PaintCanvas paintCanvas) throws HeadlessException {
        super("Plus", paintCanvas, new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                super.mousePressed(e);
                o = new Point2D.Double(e.getX(), e.getY());
                MyCross rect = new MyCross(o.getX(), o.getY(), o.getX() + 5, o.getY() + 5);
                paintCanvas.setTemporaryDrawable(rect);
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                super.mouseReleased(e);
                paintCanvas.addDrawable(getNewCross(new Point2D.Double(e.getX(), e.getY())));
            }
        }, new MouseMotionAdapter() {
            @Override
            public void mouseDragged(MouseEvent e) {
                super.mouseDragged(e);
                paintCanvas.setTemporaryDrawable(getNewCross(new Point2D.Double(e.getX(),e.getY())));
                paintCanvas.repaint();
            }
        });
    }

    static MyCross getNewCross(Point2D.Double nw) {
        if (nw.getY() < o.getY()) {
            if (nw.getX() > o.getX()) {
                return new MyCross(o.getX(),nw.getY(),o.getY()-nw.getY(),nw.getX()-o.getX());
            } else {
                return new MyCross(nw.getX(),o.getY()-(o.getX()-nw.getX()),o.getX()-nw.getX(),nw.getX()-o.getX());
            }
        } else {
            if (nw.getX() < o.getX()) {
                return new MyCross(nw.getX(),o.getY(),o.getX()-nw.getX(),nw.getY()-o.getY());
            } else {
                return new MyCross(o.getX(),o.getY(),nw.getX()-o.getX(),nw.getY()-o.getY());
            }
        }
    }

}
