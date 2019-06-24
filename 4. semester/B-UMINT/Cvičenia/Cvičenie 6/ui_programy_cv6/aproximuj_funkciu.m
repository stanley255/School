% Pr�klad na aproxim�ciu nelin. funkcie pomocou NS typu
% MLP siet s 1 vstupom a 1 v�stupom
clear
load datafun2

% vytvorenie �trukt�ry NS 
% 1 vstup - x suradnica
% 1 skryt� vrstva s poctom neur�nov 25 s funkciou 'tansig'
% 1 v�stup s funkciou 'purelin' - y suradnica
% tr�novacia met�da - Levenberg-Marquardt
pocet_neuronov=12;
net=fitnet(pocet_neuronov);

% net.layers{1}.transferFcn = 'tansig';

% trainFcn = 'trainlm';  % Levenberg-Marquardt

% vyber rozdelenia
net.divideFcn='dividerand'; % n�hodn� rozdelenie

% net.divideFcn='divideint';  % kazdy n-ta vzorka

% net.divideFcn='dividetrain';  % iba trenovacie

net.divideParam.trainRatio=0.6;
net.divideParam.valRatio=0;
net.divideParam.testRatio=0.4;

% net.divideFcn = 'divideblock'; % Divide targets into three sets using blocks of indices
% net.divideParam.trainRatio = 0.6; % Ratio of targets for training. Default = 0.7.
% net.divideParam.valRatio = 0.2; % Ratio of targets for validation. Default = 0.15.
% net.divideParam.testRatio = 0.2; % Ratio of targets for testing. Default = 0.15.
% net.divideMode = 'sample'; % 'time' for dynamic networks or 'sample' for static networks


% net.divideFcn='divideind';      % indexove
% net.divideParam.trainInd=indx_train;
% net.divideParam.valInd=[];
% net.divideParam.testInd=indx_test;


% Nastavenie parametrov tr�novania
net.trainParam.goal = 1e-6;     % Ukoncovacia podmienka na chybu
net.trainParam.show = 5;        % Frekvencia zobrazovania priebehu chyby tr�novania net.trainParam.epochs = 100;  % Max. po?et tr�novac�ch cyklov.
net.trainParam.epochs =1000;     % maximalny pocet trenovacich epoch.

% Tr�novanie NS
net=train(net,x,y);

% Simul�cia v�stupu NS
outnetsim = sim(net,x);

% vypocet chyby siete
SSE=sum((y-outnetsim).^2)
MSE=SSE/length(y)           
MAE=mae(y-outnetsim)      % Priemern� v�konov� funkcia absol�tnej chyby

% Vykreslenie priebehov
figure
plot(x,y,'b',x,outnetsim,'-or')




