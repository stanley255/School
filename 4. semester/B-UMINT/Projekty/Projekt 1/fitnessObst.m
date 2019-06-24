function[Fit]=fitnessObst(Pop, coordinates, varargin)
%FITNESS Fitness function that takes population and returns rate depending
%        on distance between each vector and penalty.

% Zistenie ve?kosti popul�cie a ve?kosti jedn�ho re?azca
lpop = length(Pop);
lstring = length(Pop(1,:));

% Pridelenie hodnoty penaliz�cie
penalty_val = varargin{1};

% Pridelenie s�radn�c ur?uj�cich prek�ky do premenn�ch
obst1 = varargin{2};
obst2 = varargin{3};

% FILL ARRAY WITH SUM OF DISTANCE FOR EACH STRING
% Ka�d�mu re?azcu v popul�ci� prirad� sumu vzdialenost� po sebe nasleduj�cich bodov
for i=1:lpop
    for j=1:lstring - 1
        % Z�skanie s�radn�c aktu�lneho a nasleduj�ceho bodu v porad�
        A=coordinates(Pop(i,j),:);
        B=coordinates(Pop(i,j+1),:);
        % Ulo�enie v�po?tu vzdialenosti dan�ch dvoch bodov v 2D priestore
        stringFit(j)=pointDistance(A,B);
        % Vypo?�tanie priese?n�kov cesty medzi bodmi A a B a niektorou z prek�ok        
        tmp1 = lineSegmentIntersect([obst1(1,:) obst1(2,:)],[A(1) A(2) B(1) B(2)]);
        tmp2 = lineSegmentIntersect([obst2(1,:) obst2(2,:)],[A(1) A(2) B(1) B(2)]);
        % Overenie, ?i cesta medzi bodmi A a B neprech�dza niektorou z prek�ok
        if ((tmp1.intMatrixX > 0) || (tmp1.intMatrixY>0))
            % Aplikovanie pokuty do hodnotenia dan�ho re?azca pre prv� prek�ku             
            stringFit(j)=stringFit(j)+penalty_val;
        end
        if ((tmp2.intMatrixX > 0) || (tmp2.intMatrixY>0))
            % Aplikovanie pokuty do hodnotenia dan�ho re?azca pre druh� prek�ku 
            stringFit(j)=stringFit(j)+penalty_val;
        end
    end
    % Priradenie sumy vzdialenost� dan�ho re?azca do premennej
    stringFit = sum(stringFit(:));
    % Priradenie sumy vzdialenost� dan�ho re?azca k v�sledkom predo�l�ch
    popFit(i)=stringFit;
end

% Vr�tenie s�m vzdialenost� celej popul�cie
Fit = popFit;
