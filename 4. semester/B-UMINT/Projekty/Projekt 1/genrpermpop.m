function [pop] = genrpermpop(string,popsize,truncsize)
%GENRPERMPOP Function that generates population from given string
%   
%     Syntax:
%       [pop] = genrpermpop(string,popsize,truncsize)
%           pop       - new generated population
%           string    - array of 2D vectors by which function generates 
%                       population by shuffling vectors of string 
%           popsize   - number of new string in new population
%           truncsize - number of elements from start and end of string
%                       that should be left intact

% Vytvorí pracovný re?azec bez prvých a posledných "truncsize" prvkov
workingString = string(1+truncsize:end-truncsize);

% GENERATES POPULATION A.K.A ARRAY(length(string)*2*popsize)
for i=1:popsize
    % Priradí novovytvorený re?azec do po?a re?azcov na základe náhodného preusporiadania prvkov v pôvodnom re?azci a doplní prvé a posledné prvky
    pop(i,:) =[[1:truncsize], workingString(randperm(length(workingString))),[length(string) + 1 - truncsize:length(string)]]; 
end



end