function [normalizedInputs] = normalizeInputs(inputs)
% Normaliz�cia d�t
for i=1:11
  normalizedInputs(i,:) = normalize(inputs(i,:), 'range', [-2 2]);
end
end

