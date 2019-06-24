load winequalityred

inputs = winedata(:,1:11)';

for i=1:11
   inputs(i,:) = normalize(inputs(i,:), 'range', [-2 2]);
end
