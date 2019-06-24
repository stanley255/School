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
% získanie indexov trénovacích, valida?ných a testovacích dát na základe pravidiel krížovej validácie
[indices_train, indices_val, indices_test] = getCrossValidationIndices();


                                    % [indices_train, indices_val, indices_test] = getIndices(winedata);


% výber rozdelenia dát NS
net.divideFcn='divideind'; % Indexové rozdelenie

% parametre indexového trénovania NS
net.divideParam.trainInd = indices_train;
net.divideParam.valInd   = indices_val;
net.divideParam.testInd  = indices_test;

% nastavenie parametrov trénovania NS
net.trainParam.epochs   = 3000;     % Maximálny pocet epóch
net.trainParam.goal     = 1e-16;    % Minimálna chybovost
net.trainParam.min_grad = 1e-16;    % Minimálny gradient
net.trainParam.show     = 5;        % Frekvencia zobrazovania priebehu chyby trénovania

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
% SSE = sum(err.^2,'all');        % suma kvadrátov odchýliek medzi meraným výstupom a výstupom siete
% MSE = SSE/length(outputs)       % priemer z SSE
% MAE = max((err).^2,[],'all')    % maximálna absolútna odchýlka medzi meraným výstupom a výstupom siete
% MIN = min((err).^2,[],'all')

% Testovanie pre jednotlive vzorky
simEachRank(net,winedata);
