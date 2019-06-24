import java.awt.*;


public class Main {

    public static void main(String[] args) {

        Frame frame = new Frame("Cvicenie 7");
        frame.setSize(500,500);

        MojePlatno platno = new MojePlatno();
        platno.setBackground(new Color(255, 255, 255));

        frame.add(platno, BorderLayout.CENTER);

        frame.setVisible(true);

    }

}
