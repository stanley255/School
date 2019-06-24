import java.awt.*;

public class Main {
    public static void main(String[] args) {
        Frame frame = new Frame("Cvicenie6 - uloha1");
        frame.setSize(400,300);
        frame.setBackground(new Color(0,255,0));
        frame.setLayout(new BorderLayout());

        Button button1 = new Button("Tlacidlo1");
        Button button2 = new Button("Tlacidlo2");
        Button button3 = new Button("Tlacidlo3");
        Button button4 = new Button("Tlacidlo4");
        Button buttonOK = new Button("OK");
        Button buttonCancel = new Button("CANCEL");
        Label label = new Label("Ahoj ako sa mas");

        Panel panelUp = new Panel();
        panelUp.setBackground(new Color(255,0,0));
        panelUp.setLayout(new FlowLayout(FlowLayout.CENTER,0,5));

        Panel panelDown = new Panel();
        panelDown.setBackground(new Color(255,120,200));
        panelDown.setLayout(new GridLayout(2,1 ));

        Panel panelDownLabel = new Panel();
        panelDownLabel.setLayout(new GridLayout(1,1));
        panelDownLabel.add(label);

        Panel panelDownBottons = new Panel();
        panelDownBottons.setLayout(new GridLayout(1,2));
        panelDownBottons.add(buttonOK);
        panelDownBottons.add(buttonCancel);

        panelDown.add(panelDownLabel);
        panelDown.add(panelDownBottons);

        panelUp.add(button1);
        panelUp.add(button2);
        panelUp.add(button3);
        panelUp.add(button4);

        MojePlatno platno = new MojePlatno();
        platno.setBackground(new Color(255, 255, 255));

        frame.add(panelUp,BorderLayout.NORTH);
        frame.add(platno, BorderLayout.CENTER);
        frame.add(panelDown,BorderLayout.SOUTH);

        frame.setVisible(true);
    }
}
