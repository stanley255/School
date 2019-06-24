import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.awt.geom.Point2D;

public class RectangleButton extends ActionButton {

    static Point2D.Double o = null;

    public RectangleButton(PaintCanvas paintCanvas) throws HeadlessException {
        super("Rectangle", paintCanvas, new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                super.mousePressed(e);
                o = new Point2D.Double(e.getX(), e.getY());
                MyRectangle rect = new MyRectangle(o.getX(), o.getY(), o.getX() + 5, o.getY() + 5);
                paintCanvas.setTemporaryDrawable(rect);
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                super.mouseReleased(e);
                paintCanvas.addDrawable(getNewRectangle(new Point2D.Double(e.getX(), e.getY())));
            }
        }, new MouseMotionAdapter() {
            @Override
            public void mouseDragged(MouseEvent e) {
                super.mouseDragged(e);
                paintCanvas.setTemporaryDrawable(getNewRectangle(new Point2D.Double(e.getX(),e.getY())));
            }
        });
    }

    static MyRectangle getNewRectangle(Point2D.Double nw) {
        if (nw.getY() < o.getY()) {
            if (nw.getX() > o.getX()) {
                return new MyRectangle(o.getX(),nw.getY(),nw.getX()-o.getX(),o.getY()-nw.getY());
            } else {
                return new MyRectangle(nw.getX(),nw.getY(),o.getX()-nw.getX(),o.getY()-nw.getY());
            }
        } else {
            if (nw.getX() < o.getX()) {
                return new MyRectangle(nw.getX(),o.getY(),o.getX()-nw.getX(),nw.getY()-o.getY());
            } else {
                return new MyRectangle(o.getX(),o.getY(),nw.getX()-o.getX(),nw.getY()-o.getY());
            }
        }
    }

}
