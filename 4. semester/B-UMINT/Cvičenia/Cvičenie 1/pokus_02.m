% Nahodne hladanie minima Rastrigin funkcie
%==================================================

numcykle=1000;                                      % pocet cyklov hladania
lpop=30;                                            % velkost  populacie - kolko retazcov naraz testujem
%topCount = 3;                                       % pocet najlepsich prvkov
%top = [2,1];                                        % rozlozenie vyberu najlepsich prvkov
Space=[ones(1,10)*(-5);ones(1,10)*5];               % rozsah prvkov v retazci

% MAIN CYCLE
Pop=genrpop(lpop,Space) ;                           % generovanie n-nahodnych retazcov
grafFit=zeros(1,numcykle); 

for i=1:numcykle
    Fit=testfn2s(Pop);                              % vypocet Rastrigin funkcie
    [minFit,indx]=min(Fit);                         % najlepsi retazec
    grafFit(i)=minFit;                              % zaznacenie do grafu
  
    % A skupina
    grpA = selbest(Pop,Fit,[1,1]);
    
    % B skupina
    grpB = selbest(Pop,Fit,[2,1,1]);
    
    % C skupina
    grpC = seltourn(Pop,Fit,12);
    
    % D skupina
    grpD = selsus(Pop,Fit,12);
    
    % E skupina
    grpE = [grpB;grpC];
    
    % KRIZENIE E skupiny
    grpE = crossov(grpE,2,0);
    
    % MUTACIA E skupiny
    grpE = mutn(grpE,0.1,ones(10)*0.15,Space);             % lokalna aditivna mutacia s normalovym rozdelenim
    
    % KRIZENIE D skupiny
    grpD = crosgrp(grpD,12);
    
    % MUTACIA D skupiny
    grpD = mutx(grpD,0.8,Space);
    grpD = mutn(grpD,0.1,ones(10)*0.15,Space);
    % SPOJENIE A ELIMINACIA DUPLIKATOV
    Pop = [grpA;grpE;grpD];
    Pop = change(Pop,0,Space);
end
% Zaver BEGIN
Fit=testfn2s(Pop);
[minFit,indx]=min(Fit);
% Zaver END
%figure
plot(grafFit,'m');                                  % vykreslenie priebehu hladania
hold on;
xlabel('Cykly');
ylabel('F(x)')

disp('Riesenie: ')
minFit
Pop(indx,:)
