function[Fit]=fitnessObst(Pop, coordinates, varargin)
%FITNESS Fitness function that takes population and returns rate depending
%        on distance between each vector and penalty.

% Zistenie ve?kosti populácie a ve?kosti jedného re?azca
lpop = length(Pop);
lstring = length(Pop(1,:));

% Pridelenie hodnoty penalizácie
penalty_val = varargin{1};

% Pridelenie súradníc ur?ujúcich prekážky do premenných
obst1 = varargin{2};
obst2 = varargin{3};

% FILL ARRAY WITH SUM OF DISTANCE FOR EACH STRING
% Každému re?azcu v populácií priradí sumu vzdialeností po sebe nasledujúcich bodov
for i=1:lpop
    for j=1:lstring - 1
        % Získanie súradníc aktuálneho a nasledujúceho bodu v poradí
        A=coordinates(Pop(i,j),:);
        B=coordinates(Pop(i,j+1),:);
        % Uloženie výpo?tu vzdialenosti daných dvoch bodov v 2D priestore
        stringFit(j)=pointDistance(A,B);
        % Vypo?ítanie priese?níkov cesty medzi bodmi A a B a niektorou z prekážok        
        tmp1 = lineSegmentIntersect([obst1(1,:) obst1(2,:)],[A(1) A(2) B(1) B(2)]);
        tmp2 = lineSegmentIntersect([obst2(1,:) obst2(2,:)],[A(1) A(2) B(1) B(2)]);
        % Overenie, ?i cesta medzi bodmi A a B neprechádza niektorou z prekážok
        if ((tmp1.intMatrixX > 0) || (tmp1.intMatrixY>0))
            % Aplikovanie pokuty do hodnotenia daného re?azca pre prvú prekážku             
            stringFit(j)=stringFit(j)+penalty_val;
        end
        if ((tmp2.intMatrixX > 0) || (tmp2.intMatrixY>0))
            % Aplikovanie pokuty do hodnotenia daného re?azca pre druhú prekážku 
            stringFit(j)=stringFit(j)+penalty_val;
        end
    end
    % Priradenie sumy vzdialeností daného re?azca do premennej
    stringFit = sum(stringFit(:));
    % Priradenie sumy vzdialeností daného re?azca k výsledkom predošlých
    popFit(i)=stringFit;
end

% Vrátenie súm vzdialeností celej populácie
Fit = popFit;
