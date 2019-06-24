function [newPop] = extendPop(oldPop,truncsize)
% EXTENDPOP Function that adds elements to the beggining and end of the given population
                % truncsize = po?et prvkov od za?iatku a konca re?azcu, ktor� maj� zosta? neporu�en�

% Zistenie ve?kosti danej popul�cie a re?azca
[lpop,lstring] = size(oldPop);
% Potrebn� zv�?�enie d?�ky re?azca o dvojn�sobok hodnoty truncsize
lstring = lstring + 2*truncsize;
for i=1:lpop
    % Do ka�d�ho re?azca prid�me prv�ch a posledn�ch "truncsize" prvkov    
    newPop(i,:) = [[1:truncsize] oldPop(i,:) [lstring + 1 - truncsize:lstring]];
end

end

