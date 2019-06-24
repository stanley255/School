function [newPop] = extendPop(oldPop,truncsize)
% EXTENDPOP Function that adds elements to the beggining and end of the given population
                % truncsize = po?et prvkov od za?iatku a konca re?azcu, ktoré majú zosta? neporušené

% Zistenie ve?kosti danej populácie a re?azca
[lpop,lstring] = size(oldPop);
% Potrebné zvä?šenie d?žky re?azca o dvojnásobok hodnoty truncsize
lstring = lstring + 2*truncsize;
for i=1:lpop
    % Do každého re?azca pridáme prvých a posledných "truncsize" prvkov    
    newPop(i,:) = [[1:truncsize] oldPop(i,:) [lstring + 1 - truncsize:lstring]];
end

end

