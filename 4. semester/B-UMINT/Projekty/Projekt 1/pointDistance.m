function [distance] = pointDistance(startPoint,endPoint)
%DISTANCE Function that calculates and returns distance between two 2D points

distance = sqrt((startPoint(1)-endPoint(1)).^2+((startPoint(2)-endPoint(2)).^2));

end

