function [output] = getQualityValuesCount(source)
    calc = zeros(10,1)';
    for i=1:length(source)
        index = source(i,12)';
        calc(index) = calc(index) + 1;
    end
    output = calc;
end

