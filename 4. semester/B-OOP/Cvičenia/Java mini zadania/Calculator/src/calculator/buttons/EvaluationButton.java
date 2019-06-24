package calculator.buttons;

import calculator.Calculator;

import java.awt.*;

public class EvaluationButton extends CalculatorButton {

    public EvaluationButton(Calculator calculator) throws HeadlessException {
        super("=", calculator);
        addActionListener(e->{
            try {
                double result = calculator.trimNumber(calculator.getOperator().calculate(calculator.getFirstOperand(),calculator.getSecondOperand()));
                calculator.reset();
                calculator.setFirstOperand(String.valueOf(result));
                calculator.getDisplay().setText(calculator.getStringValueOfFirstOperand());
            } catch (NullPointerException | NumberFormatException exc) {
                calculator.reset();
                calculator.getDisplay().setText("ERROR");
            }
        });
    }
}
