% Pr�klad na aproxim�ciu funkcie y=sin(x.^2).*exp(-x) pomocou NS typu
% perceptron s 1 vstupom a 1 v�stupom

echo on
% V�pocet bodov funkcie
%x=0:0.05:5;
%y=sin(x.^2).*exp(-x);

[x,y]=simplefit_dataset;
n=length(y);
n2=fix(n/2);
% vytvorenie �trukt�ry NS 
% 1 vstup s rozsahom (0,4)
% 1 skryt� vrstva s poctom neur�nov 8 s funkciou 'tansig'
% 1 v�stup s funkciou 'purelin'
% tr�novacia met�da - Levenberg-Marquardt 
net=fitnet(8);

% vsetky data pouzite na trenovanie
% net.divideFcn='dividerand'; % n�hodn� rozdelenie
% net.divideFcn='divideblock'; % blokove
net.divideFcn='divideint';  % kazdy n-ta vzorka
%11net.divideFcn='dividetrain';  % iba trenovacie
 net.divideParam.trainRatio=0.6;
 net.divideParam.valRatio=0.2;
 net.divideParam.testRatio=0.2;


% net.divideFcn='divideind';      % indexove
% net.divideParam.trainInd=1:2:n;
% net.divideParam.valInd=2:2:n2;
% net.divideParam.testInd=n2+1:2:n;


% Nastavenie parametrov tr�novania
net.trainParam.goal = 1e-7;     % Ukon?ovacia podmienka na chybu SSE.
net.trainParam.show = 5;        % Frekvencia zobrazovania priebehu chyby tr�novania net.trainParam.epochs = 100;  % Max. po?et tr�novac�ch cyklov.

% Tr�novanie NS
net=train(net,x,y);

% Simul�cia v�stupu NS
outnetsim = sim(net,x);

% Vykreslenie priebehov
figure
plot(x,y,'b',x,outnetsim,'-or')
echo off


