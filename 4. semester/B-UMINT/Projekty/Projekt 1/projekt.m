% Mobiln� robot prech�dzaj�ci medzi bodmi v rovine najkrat�ou mo�nou dr�hou
%==========================================================================

% Hodnota ktor� sa pripo?�ta ako "trest" pri prechode cez prek�ku
penalty_val = 200;

% Zadan� koordin�ty bodov, ktor�mi ma robot prech�dza?
coordinates = [1,1;31,27;9,48;40,33;45,28;11,19;25,37;21,17;35,20;13,15;18,33;28,17;36,12;17,20;7,17;20,45;49,2;22,4;10,25;50,50];
% Vytvorenie po?a indexov bodov
coord_indx = 1:20;

% Zadan� prek�ky, ur?en� spojnicou zadan�ch bodov
obst1 = [25,25;50,25];
obst2 = [15,35;15,50];

% Generovanie popul�cie
lpop = 30;   % Ve?kos? popul�cie
Pop = genrpermpop(coord_indx,lpop,1);

% Ur?enie po?tu gener�ci� algoritmu
numcykle = 10000;

% Pole na ukladanie najlep��ch v�sledkov fitness funkcii ka�dej gener�cie
grafFit=zeros(1,numcykle);

for i=1:numcykle
    
    % Verzia fitness funkcie pre po��tanie bez prek�ok
        Fit=fitness(Pop,coordinates);        
    % Verzia fitness funkcie pre po��tanie s prek�kami    
        % Fit=fitnessObst(Pop,coordinates,penalty_val,obst1,obst2);
        
    % Z�skanie najmen�ej hodnoty fitness funkcie z celej popul�cie
    minFit=min(Fit);
    % Ulo�enie z�skanej hodnoty medzi najlep�ie hodnoty v�etk�ch gener�ci�     
    grafFit(i)=minFit;
    
    % V�BER     
        % V�ber najlep��ch jedincov z popul�cie pomocou ELIT�RSKEHO V�BERU
        grpA = selbest(Pop,Fit,[1,1]);
        % V�ber jedincov z popul�cie pomocou TURNAJOV�HO V�BERU
        grpB = seltourn(Pop,Fit,14);
        % V�ber jedincov z popul�cie pomocou V�HOVAN�HO KOLESOV�HO V�BERU
        grpC = selsus(Pop,Fit,14);
        
    % KR͎ENIE     
        % Kr�enie permuta�n�ho typu skupiny B
        grpB = extendPop(crosord(trimPop(grpB,1),0),1);
        % Kr�enie permuta�n�ho typu skupiny C
        grpC = extendPop(crosord(trimPop(grpC,1),0),1);
    
    % MUT�CIA         
        % Mut�cia na z�klade v�meny poradia dvoch ?ast� re?azcov
        grpB = extendPop(swappart(trimPop(grpB,1),0.05),1);
        % Mutacia poradia g�nov v re?azci
        grpC = extendPop(swapgen(trimPop(grpC,1),0.15),1);
    
    % SP�JANIE    
        % Spojenie dvoch skr�en�ch a zmutovan�ch skup�n    
        grpB = [grpB;grpC];
        % Spojenie v�beru najlep��ch jedincov so zvy�kom jedincov    
        Pop = [grpA;grpB];
end

% Z�vere?n� prepo?�tanie fitness funkcie pre cel� popul�ciu
    % Verzia �lohy s prek�kami
        % Fit=fitnessObst(Pop,coordinates,penalty_val,obst1,obst2);
    % Verzia �lohy bez prek�ok
        Fit=fitness(Pop,coordinates);
        
% Z�skanie re?azca s najmen��m fitness ohodnoten�m a jeho poz�cie
[minFit,indx]=min(Fit);

% Vykreslenie TREND funckie do grafu
    % figure
    plot(grafFit,'m');
    hold on;
    xlabel('Cykly');
    ylabel('F(x)')


% figure
    % Vykreslenie verzie �lohy bez prek�ok
        % plotPath(orderCoordinates(coordinates,Pop(indx,:)));

    % Vykreslenie verzie �lohy s prek�kami
        % plotPath(orderCoordinates(coordinates,Pop(indx,:)),obst1,obst2);
minFit
