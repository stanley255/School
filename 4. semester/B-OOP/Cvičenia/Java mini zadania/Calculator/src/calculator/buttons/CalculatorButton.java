package calculator.buttons;

import calculator.Calculator;

import java.awt.*;

public abstract class CalculatorButton extends Button {

    protected Calculator calculator;

    public CalculatorButton(String label, Calculator calculator) throws HeadlessException {
        super(label);
        this.calculator = calculator;
    }

    public CalculatorButton(int digit, Calculator calculator) throws HeadlessException {
        super(String.valueOf(digit));
        this.calculator = calculator;
    }

}
