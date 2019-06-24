import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseMotionAdapter;

public class ActionButton extends Button {

    public ActionButton(String label, PaintCanvas paintCanvas, MouseAdapter mouseAdapter, MouseMotionAdapter mouseMotionAdapter) throws HeadlessException {
        super(label);
        addActionListener(e -> {
            paintCanvas.removeListeners();
            paintCanvas.addMouseListener(mouseAdapter);
            paintCanvas.addMouseMotionListener(mouseMotionAdapter);
        });
    }

}
