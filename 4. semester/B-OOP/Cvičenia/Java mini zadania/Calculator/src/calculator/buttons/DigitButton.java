package calculator.buttons;

import calculator.Calculator;

import java.awt.*;

public class DigitButton extends CalculatorButton {

    public DigitButton(int digit, Calculator calculator) throws HeadlessException {
        super(digit, calculator);
        addActionListener(e -> calculator.appendDigit(digit));
    }
}
