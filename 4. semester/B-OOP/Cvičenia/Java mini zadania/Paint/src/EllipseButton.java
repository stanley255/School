import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.awt.geom.Point2D;

public class EllipseButton extends ActionButton {

    static Point2D.Double o = null;

    public EllipseButton(PaintCanvas paintCanvas) throws HeadlessException {
        super("Ellipse", paintCanvas, new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                super.mousePressed(e);
                o = new Point2D.Double(e.getX(), e.getY());
                MyEllipse ellipse = new MyEllipse(o.getX(), o.getY(), o.getX() + 5, o.getY() + 5);
                paintCanvas.setTemporaryDrawable(ellipse);
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                super.mouseReleased(e);
                paintCanvas.addDrawable(getNewEllipse(new Point2D.Double(e.getX(), e.getY())));
            }
        }, new MouseMotionAdapter() {
            @Override
            public void mouseDragged(MouseEvent e) {
                super.mouseDragged(e);
                paintCanvas.setTemporaryDrawable(getNewEllipse(new Point2D.Double(e.getX(),e.getY())));
            }
        });
    }

    static MyEllipse getNewEllipse(Point2D.Double nw) {
        if (nw.getY() < o.getY()) {
            if (nw.getX() > o.getX()) {
                return new MyEllipse(o.getX(),nw.getY(),nw.getX()-o.getX(),o.getY()-nw.getY());
            } else {
                return new MyEllipse(nw.getX(),nw.getY(),o.getX()-nw.getX(),o.getY()-nw.getY());
            }
        } else {
            if (nw.getX() < o.getX()) {
                return new MyEllipse(nw.getX(),o.getY(),o.getX()-nw.getX(),nw.getY()-o.getY());
            } else {
                return new MyEllipse(o.getX(),o.getY(),nw.getX()-o.getX(),nw.getY()-o.getY());
            }
        }
    }

}
