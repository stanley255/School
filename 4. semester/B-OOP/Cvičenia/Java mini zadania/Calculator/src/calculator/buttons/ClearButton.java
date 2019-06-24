package calculator.buttons;

import calculator.Calculator;

import java.awt.*;

public final class ClearButton extends CalculatorButton {

    public ClearButton(Calculator calculator) throws HeadlessException {
        super("C", calculator);
        addActionListener(e -> {
            calculator.reset();
        });
    }
}
