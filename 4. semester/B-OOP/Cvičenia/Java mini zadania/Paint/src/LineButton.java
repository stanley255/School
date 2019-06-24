import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;

public class LineButton extends ActionButton {

    static Point2D.Double o = null;

    public LineButton(PaintCanvas paintCanvas) throws HeadlessException {
        super("Line", paintCanvas, new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                super.mousePressed(e);
                o = new Point2D.Double(e.getX(), e.getY());
                MyLine line = new MyLine(o.getX(), o.getY(), o.getX(), o.getY());
                paintCanvas.setTemporaryDrawable(line);
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                super.mouseReleased(e);
                paintCanvas.addDrawable(new MyLine(o.getX(), o.getY(), e.getX(), e.getY()));
            }
        }, new MouseMotionAdapter() {
            @Override
            public void mouseDragged(MouseEvent e) {
                super.mouseDragged(e);
                paintCanvas.setTemporaryDrawable(new MyLine(o.getX(), o.getY(), e.getX(), e.getY()));
            }
        });
    }
}
