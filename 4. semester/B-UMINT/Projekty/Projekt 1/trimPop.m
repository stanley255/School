function [newPop] = trimPop(oldPop,truncsize)
%TRIMPOP Function that trims off elements from the beggining and end of the given population

% Zistenie ve?kosti danej populácie a re?azca
[lpop,lstring] = size(oldPop);

for i=1:lpop
    % Z každého re?azca odstrihneme prvých a posledných "truncsize" prvkov
   newPop(i,:) = oldPop(i,truncsize+1:lstring-truncsize);
end

end

