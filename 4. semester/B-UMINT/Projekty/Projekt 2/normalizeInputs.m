function [normalizedInputs] = normalizeInputs(inputs)
% Normalizácia dát
for i=1:11
  normalizedInputs(i,:) = normalize(inputs(i,:), 'range', [-2 2]);
end
end

