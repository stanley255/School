function [indices_train, indices_val, incidex_test] = getIndices(source)
    source = sortrows(source, 12);
    values = getQualityValuesCount(source);
    
end

