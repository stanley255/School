package calculator.buttons;

import calculator.Calculator;
import calculator.Executable;

import java.awt.*;

public class SubstractionButton extends CalculatorButton implements Executable {

    public SubstractionButton(Calculator calculator) throws HeadlessException {
        super("-", calculator);
        addActionListener(e->{
            if (calculator.getOperator() == null){
                String firstOperand = calculator.getStringValueOfFirstOperand();
                if (firstOperand.equals("") || firstOperand.equals("0")) {
                    calculator.setFirstOperand("-");
                    calculator.getDisplay().setText("-");
                } else {
                    calculator.setOperator(this);
                }
            } else {
                String secondOperand = calculator.getStringValueOfSecondOperand();
                if (secondOperand.equals("") || secondOperand.equals("0")) {
                    calculator.setSecondOperand("-");
                    calculator.getDisplay().setText("-");
                }
            }
        });
    }

    @Override
    public double calculate(double x, double y) {
        return x-y;
    }
}
