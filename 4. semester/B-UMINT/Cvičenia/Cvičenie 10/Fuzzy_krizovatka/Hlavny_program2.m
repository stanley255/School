
% Cielom je nastavit Fuzzy system tak, aby bola dostatocna priepustnost
% krizovatky a maximalny pocet aut v jednom pruhu bol 15.

% indexy jazdnych pruhov
% Pole = [A11 A12 A21 A22 A31 A32] (semafor, pocet aut na ceste, spustenie pruhov)
% napr: int_pri_aut = [5 4 13 12 12 11]; (doba, za ktoru pride jedno auto)



clear
%close all

dlzka_cesty = 250;  % nastavenie dlzky jednej strany cesty
sirka_pruhu = 20;   % nastavenie sirky jedneho pruhu
pauza = 0.1;    % gIntervalval na vykreslovanie


%%     inicializ�cia po�iato�n�ch hodnot

doba_prechodu = 2.5; % doba za ktoru lubovolne auto prejde cez krizovatku
pocet_aut_na_kriz = round(rand(1,6)*3); % inicializovanie po�tu aut na zaciatku simulacie
spusti_pruhy= [0 0 0 0 0 0]; % nastavenie pruhov (vsetky maju cervenu)

semafory = spusti_pruhy; % nastavenie semaforov A11 - A32 (0 - �erven�, 1 - zelen�)
int_pri_aut = [0 0 0 0 0 0]; % gIntervalval prichodu aut (meni sa podla cyklu)
zvysok = [0 0 0 0 0 0]; % na vypocet
pocitadlo = 0; % zaznamenavanie poctu cyklov

%% Nastavenie pevnej dlzky intervalu zelenej pre vsetky cykly
Interval = 8;


%% Nacitanie fuzzy systemu

f = readfis('fuzzy_logic');

%% Scen�r - z�kladn�
% cyklus A1 - A2 - A3

for cyk = 1:20 % hlavny cyklusl
    
    %%     Zmena rezimov prichodu aut (pocas dna)
    if cyk < 7
        cas = 1;
    elseif cyk < 14
        cas = 2;
    else
        cas = 3;
    end
    
    % rezimy (mody)
    switch cas
        
        case 1 %  Rezim 1
            s1 = round(rand());
            if s1 == 0
                int_pri_aut = [5 4 13 12 12 11];
            else
                int_pri_aut = [4 5 12 13 11 12];
            end
            
        case 2 %  Rezim 2
            s1 = round(rand());
            if s1 == 0
                int_pri_aut = [7 6 10 9 8 9];
            else
                int_pri_aut = [6 7 9 10 9 8];
            end
            
        case 3 %  Rezim 3
            s1 = round(rand());
            if s1 == 0
                int_pri_aut = [10 11 15 14 12 11];
            else
                int_pri_aut = [11 10 14 15 11 12];
            end
    end
    
    %%  Krizovatka
    %% zelena na ceste A1
    
    % spocitanie aut z pruhov do cyklov
    
  [A1,A2,A3] = Ziskaj_poc_aut(pocet_aut_na_kriz);
  
  output = evalfis([A1, A2+A3],f);
    
    
    %% vypocet intervalu zelenej z fuzzy systemu
    
    % Doprogramovat
    Interval = output;
    
    
    %% ziskanie poctu cyklov zelenej
    poc_cyklov = round((Interval/doba_prechodu));
    
    % spustenie pruhov A11 a A12
    spusti_pruhy = [1 1 0 0 0 0];
    semafory = spusti_pruhy;
    
    for int = 1:poc_cyklov
        [pocet_aut_na_kriz,zvysok] = Gen_auta(pocet_aut_na_kriz, int_pri_aut,doba_prechodu,zvysok,spusti_pruhy);
        
        Vykreslenie_krizovatky();
        Kresli_auta();
        
        pause(pauza);
        
        %%  zapis udajov do grafov
        pocitadlo = pocitadlo +1;
        
        for gr = 1:6
            gPoc_aut(gr,pocitadlo)= pocet_aut_na_kriz(gr); % pocet aut
            gStav_Semafor(gr,pocitadlo)= semafory(gr); % stav semaforu
            if spusti_pruhy(gr) == 1
                gInterval(gr, pocitadlo) = Interval; % interval zelenej
            end
        end
        
    end
    
    %% zelena na ceste A2
    
  [A1,A2,A3] = Ziskaj_poc_aut(pocet_aut_na_kriz);
  output = evalfis([A2, A1+A3],f);
    
    
    %% vypocet intervalu zelenej z fuzzy systemu
    
    Interval = output;
    
    
    %%
    poc_cyklov = round((Interval/doba_prechodu));
    
    spusti_pruhy = [0 0 1 1 0 0];
    semafory = spusti_pruhy;
    
    for int = 1:poc_cyklov
        [pocet_aut_na_kriz,zvysok] = Gen_auta(pocet_aut_na_kriz, int_pri_aut,doba_prechodu,zvysok,spusti_pruhy);
        
        Vykreslenie_krizovatky();
        Kresli_auta();
        
        pause(pauza);
        
        %% Zapis udajov do grafov
        pocitadlo = pocitadlo +1;
        for gr = 1:6
            gPoc_aut(gr,pocitadlo)= pocet_aut_na_kriz(gr);
            gStav_Semafor(gr,pocitadlo)= semafory(gr);
            if spusti_pruhy(gr) == 1
                gInterval(gr, pocitadlo) = Interval;
            end
        end
        
    end
    
    %% zelena na ceste A3
    
%   [A1,A2,A3] = Ziskaj_poc_aut(pocet_aut_na_kriz);
    output = evalfis([A3, A1+A2],f);
    
    
    %% vypocet intervalu zelenej z fuzzy systemu
    
    % Doprogramovat
    Interval = output;
    
    
    %%
    poc_cyklov = round((Interval/doba_prechodu));
    
    spusti_pruhy = [0 0 0 0 1 1];
    semafory = spusti_pruhy;
    
    for int = 1:poc_cyklov
        [pocet_aut_na_kriz,zvysok] = Gen_auta(pocet_aut_na_kriz, int_pri_aut,doba_prechodu,zvysok,spusti_pruhy);
        
        Vykreslenie_krizovatky();
        Kresli_auta();
        
        pause(pauza);
        
        %% Zapis udajov do grafov
        pocitadlo = pocitadlo +1;
        for gr = 1:6
            gPoc_aut(gr,pocitadlo)= pocet_aut_na_kriz(gr);
            gStav_Semafor(gr,pocitadlo)= semafory(gr);
            if spusti_pruhy(gr) == 1
                gInterval(gr, pocitadlo) = Interval;
            end
        end
        
        
    end
end

%% Vykreslenie grafov poctu aut a stav semaforov

Vykreslenie_Poc_aut(gPoc_aut);
Vykreslenie_Stavu_semaforov(gStav_Semafor);
Vykreslenie_Intervalov(gInterval);


%% Bonusov� �loha - vytvori� in� scen�r

% Vylepsit hlavny cyklus tak, aby sa zvysila priepustnost krizovatky

% Vytvorenie inych kombinacii spustania pruhov 
%  - prisposobenie cyklov zelenej, 
%  - vstupov do fuzzy systemu, 
%  - vykreslenie grafov

