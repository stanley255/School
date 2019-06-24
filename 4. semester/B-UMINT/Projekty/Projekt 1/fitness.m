function[Fit]=fitness(Pop, coordinates, varargin)
%FITNESS Fitness function that takes population and returns rate depending
%        on distance between each vector.

% Zistenie ve?kosti popul�cie a ve?kosti jedn�ho re?azca
lpop = length(Pop);
lstring = length(Pop(1,:));

% FILL ARRAY WITH SUM OF DISTANCE FOR EACH STRING
% Ka�d�mu re?azcu v popul�ci� prirad� sumu vzdialenost� po sebe nasleduj�cich bodov
for i=1:lpop
    for j=1:lstring - 1
        % Z�skanie s�radn�c aktu�lneho a nasleduj�ceho bodu v porad�
        A=coordinates(Pop(i,j),:);
        B=coordinates(Pop(i,j+1),:);
        % Ulo�enie v�po?tu vzdialenosti dan�ch dvoch bodov v 2D priestore
        stringFit(j)=pointDistance(A,B);
    end
    % Priradenie sumy vzdialenost� dan�ho re?azca do premennej
    stringFit = sum(stringFit(:));
    % Priradenie sumy vzdialenost� dan�ho re?azca k v�sledkom predo�l�ch
    popFit(i)=stringFit;
end

% Vr�tenie s�m vzdialenost� celej popul�cie
Fit = popFit;


