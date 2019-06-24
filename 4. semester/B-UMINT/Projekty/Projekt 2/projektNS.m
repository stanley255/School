% Príklad na klasifikaciu vin
% MLP siet s 12 vstupmi a 1 výstupom
clear
load winequalityred

net=patternnet([50],'traingdx');
% net.layers{1}.transferFcn = 'logsig';
% net.layers{2}.transferFcn = 'logsig';
% net.performFcn = 'sse';
% net.trainParam.mem_reduc=2;
%net.layers{1}.transferFcn = 'tansig';
%net.layers{2}.transferFcn = 'logsig';
%net.layers{3}.transferFcn = 'softmax';

inputs = winedata(:,1:11)';
labels = winedata(:,12)';
outputs = zeros(10,length(labels));
for i=1:length(labels)
    outputs(labels(i),i)=1;
end
% vyber rozdelenia
net.divideFcn='dividerand'; % náhodné rozdelenie

net.divideParam.trainRatio=0.6;
net.divideParam.valRatio=0.2;
net.divideParam.testRatio=0.2;

% Nastavenie parametrov trénovania
net.trainParam.goal     = 1e-6;     % Ukoncovacia podmienka na chybu
net.trainParam.min_grad = 1e-6;     % Ukoncovacia podmienka na gradient
net.trainParam.show     = 5;        % Frekvencia zobrazovania priebehu chyby trénovania net.trainParam.epochs = 100;  % Max. po?et trénovacích cyklov.
net.trainParam.epochs   = 5000;     % maximalny pocet trenovacich epoch.
net.trainParam.max_fail = 6;

% Trénovanie NS
net=train(net,inputs,outputs); 

% Simulácia výstupu NS
outnetsim = sim(net,inputs);
confusion(outputs,outnetsim)
plotconfusion(outputs,outnetsim);
