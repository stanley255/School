function [outputs] = getTrimmedOutputs(labels)
outputs = zeros(6,length(labels));
for i=1:length(labels)
    outputs(labels(i)-2,i)=1;
end
end

