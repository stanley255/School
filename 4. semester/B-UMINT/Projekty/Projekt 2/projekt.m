% Príklad na klasifikáciu vín
clear
load winequalityred

net=patternnet([40 40]);
% net=patternnet([80]);
% net=patternnet([20 20 20 20]);

% získanie vstupných a výstupných dát rozparsovaním winequalityred
inputs = winedata(:,1:11)';
labels = winedata(:,12)';
% orezanie nepotrebných výstupov a normalizácia vstupných dát pre zefektívnenie u?enia siete
outputs = getTrimmedOutputs(labels);
inputs = normalizeInputs(inputs);

% výber rozdelenia dát NS
net.divideFcn='dividerand'; % Náhodné rozdelenie

% parametre trénovania
net.divideParam.trainRatio = 0.6;   % Trénovacie dáta
net.divideParam.valRatio   = 0.0;   % Valida?né dáta
net.divideParam.testRatio  = 0.4;   % Testovacie dáta

% nastavenie parametrov trénovania NS
net.trainParam.epochs   = 1200;     % Maximálny po?et epoch
net.trainParam.goal     = 1e-8;     % Minimálna chybovos?
net.trainParam.min_grad = 1e-9;     % Minimálny gradient
net.trainParam.show     = 5;

% trénovanie NS
net=train(net,inputs,outputs); 

% simulácia výstupu NS
outnetsim = sim(net,inputs);

% confusion
confusion = confusion(outputs,outnetsim);
plotconfusion(outputs,outnetsim);
disp("Percentualna uspesnost: "+num2str(100-confusion*100)+"%");
% view(net)

% po?ítanie jednotlivých chýb NS
% err = (outnetsim - outputs);
% SSE = sum(err.^2,'all');
% MSE = SSE/length(outputs)
% MAE = max((err).^2,[],'all')
% MIN = min((err).^2,[],'all')

% Testovanie pre jednotlive vzorky
simEachRank(net,winedata,inputs);
