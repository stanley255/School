import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.awt.geom.Rectangle2D;

public class ColorChangeButton extends ActionButton {


    public ColorChangeButton(PaintCanvas paintCanvas) throws HeadlessException {
        super("Change", paintCanvas, new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);
                for (Drawable drawable : paintCanvas.getDrawables()) {
                    Rectangle2D.Double clickArea = new Rectangle2D.Double(e.getX()-5,e.getY()-5,10,10);
                    if (drawable.intersects(clickArea)) {
                        System.out.println("Oznacil si drawable!");
                        Colorable colorable = (Colorable) drawable;
                        colorable.setColor(paintCanvas.getCurrentColor());
                        paintCanvas.repaint();
                        break;
                    }
                }
            }
        }, new MouseMotionAdapter() {});
    }
}
