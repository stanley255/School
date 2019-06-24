% Mobilný robot prechádzajúci medzi bodmi v rovine najkratšou možnou dráhou
%==========================================================================

% Hodnota ktorá sa pripo?íta ako "trest" pri prechode cez prekážku
penalty_val = 200;

% Zadané koordináty bodov, ktorými ma robot prechádza?
coordinates = [1,1;31,27;9,48;40,33;45,28;11,19;25,37;21,17;35,20;13,15;18,33;28,17;36,12;17,20;7,17;20,45;49,2;22,4;10,25;50,50];
% Vytvorenie po?a indexov bodov
coord_indx = 1:20;

% Zadané prekážky, ur?ené spojnicou zadaných bodov
obst1 = [25,25;50,25];
obst2 = [15,35;15,50];

% Generovanie populácie
lpop = 30;   % Ve?kos? populácie
Pop = genrpermpop(coord_indx,lpop,1);

% Ur?enie po?tu generácií algoritmu
numcykle = 10000;

% Pole na ukladanie najlepších výsledkov fitness funkcii každej generácie
grafFit=zeros(1,numcykle);

for i=1:numcykle
    
    % Verzia fitness funkcie pre poèítanie bez prekážok
        Fit=fitness(Pop,coordinates);        
    % Verzia fitness funkcie pre poèítanie s prekážkami    
        % Fit=fitnessObst(Pop,coordinates,penalty_val,obst1,obst2);
        
    % Získanie najmenšej hodnoty fitness funkcie z celej populácie
    minFit=min(Fit);
    % Uloženie získanej hodnoty medzi najlepšie hodnoty všetkých generácií     
    grafFit(i)=minFit;
    
    % VÝBER     
        % Výber najlepších jedincov z populácie pomocou ELITÁRSKEHO VÝBERU
        grpA = selbest(Pop,Fit,[1,1]);
        % Výber jedincov z populácie pomocou TURNAJOVÉHO VÝBERU
        grpB = seltourn(Pop,Fit,14);
        % Výber jedincov z populácie pomocou VÁHOVANÉHO KOLESOVÉHO VÝBERU
        grpC = selsus(Pop,Fit,14);
        
    % KRÍŽENIE     
        % Kríženie permutaèného typu skupiny B
        grpB = extendPop(crosord(trimPop(grpB,1),0),1);
        % Kríženie permutaèného typu skupiny C
        grpC = extendPop(crosord(trimPop(grpC,1),0),1);
    
    % MUTÁCIA         
        % Mutácia na základe výmeny poradia dvoch ?astí re?azcov
        grpB = extendPop(swappart(trimPop(grpB,1),0.05),1);
        % Mutacia poradia génov v re?azci
        grpC = extendPop(swapgen(trimPop(grpC,1),0.15),1);
    
    % SPÁJANIE    
        % Spojenie dvoch skrížených a zmutovaných skupín    
        grpB = [grpB;grpC];
        % Spojenie výberu najlepších jedincov so zvyškom jedincov    
        Pop = [grpA;grpB];
end

% Závere?né prepo?ítanie fitness funkcie pre celú populáciu
    % Verzia úlohy s prekážkami
        % Fit=fitnessObst(Pop,coordinates,penalty_val,obst1,obst2);
    % Verzia úlohy bez prekážok
        Fit=fitness(Pop,coordinates);
        
% Získanie re?azca s najmenším fitness ohodnotením a jeho pozície
[minFit,indx]=min(Fit);

% Vykreslenie TREND funckie do grafu
    % figure
    plot(grafFit,'m');
    hold on;
    xlabel('Cykly');
    ylabel('F(x)')


% figure
    % Vykreslenie verzie úlohy bez prekážok
        % plotPath(orderCoordinates(coordinates,Pop(indx,:)));

    % Vykreslenie verzie úlohy s prekážkami
        % plotPath(orderCoordinates(coordinates,Pop(indx,:)),obst1,obst2);
minFit
