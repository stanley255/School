% Nahodne hladanie minima Rastrigin funkcie
%==================================================

numcykle=1000;                                      % pocet cyklov hladania
lpop=30;                                            % velkost  populacie - kolko retazcov naraz testujem
topCount = 3;                                       % pocet najlepsich prvkov
top = [2,1];                                        % rozlozenie vyberu najlepsich prvkov
Space=[ones(1,10)*(-5);ones(1,10)*5];               % rozsah prvkov v retazci

% MAIN CYCLE
Pop=genrpop(lpop,Space) ;                           % generovanie n-nahodnych retazcov
grafFit=zeros(1,numcykle); 

for i=1:numcykle
    Fit=testfn2s(Pop);                              % vypocet Rastrigin funkcie
    [minFit,indx]=min(Fit);                         % najlepsi retazec
    grafFit(i)=minFit;                              % zaznacenie do grafu
    
    % VYBER
    newBest = selbest(Pop,Fit,top);                 % vyber najlepsie retazce
    popForCross = selsort(Pop,Fit,lpop-topCount);   
    
    % KRIZENIE
    Pop = crossov(popForCross,2,0);
    
    % MUTACIA
    Pop = mutn(Pop,0.1,ones(10),Space);             % aditivna mutacia s normalovym rozdelenim
    
    % SPOJENIE A ELIMINACIA DUPLIKATOV
    Pop = [Pop;newBest];
    Pop = change(Pop,0,Space);
end
% Zaver BEGIN
Fit=testfn2s(Pop);
[minFit,indx]=min(Fit);
% Zaver END
figure
plot(grafFit,'m');                                  % vykreslenie priebehu hladania
hold on;
xlabel('Cykly');
ylabel('F(x)')

disp('Riesenie: ')
minFit
Pop(indx,:)
