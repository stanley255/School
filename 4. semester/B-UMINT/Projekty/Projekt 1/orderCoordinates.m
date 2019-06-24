function [ordCoordinates] = orderCoordinates(coordinates,indexes)
%ORDERCOORDINATES Function that puts coordinates into right order


for i=1:length(indexes)
    ordCoordinates(i,:) = coordinates(indexes(i),:);
end

end
