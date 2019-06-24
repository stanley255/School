function[Fit]=fitness(Pop, coordinates, varargin)
%FITNESS Fitness function that takes population and returns rate depending
%        on distance between each vector.

% Zistenie ve?kosti populácie a ve?kosti jedného re?azca
lpop = length(Pop);
lstring = length(Pop(1,:));

% FILL ARRAY WITH SUM OF DISTANCE FOR EACH STRING
% Každému re?azcu v populácií priradí sumu vzdialeností po sebe nasledujúcich bodov
for i=1:lpop
    for j=1:lstring - 1
        % Získanie súradníc aktuálneho a nasledujúceho bodu v poradí
        A=coordinates(Pop(i,j),:);
        B=coordinates(Pop(i,j+1),:);
        % Uloženie výpo?tu vzdialenosti daných dvoch bodov v 2D priestore
        stringFit(j)=pointDistance(A,B);
    end
    % Priradenie sumy vzdialeností daného re?azca do premennej
    stringFit = sum(stringFit(:));
    % Priradenie sumy vzdialeností daného re?azca k výsledkom predošlých
    popFit(i)=stringFit;
end

% Vrátenie súm vzdialeností celej populácie
Fit = popFit;


