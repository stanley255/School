% Pr�klad na klasifik�ciu v�n
clear
load winequalityred

net=patternnet([40 40]);
% net=patternnet([80]);
% net=patternnet([20 20 20 20]);

% z�skanie vstupn�ch a v�stupn�ch d�t rozparsovan�m winequalityred
inputs = winedata(:,1:11)';
labels = winedata(:,12)';
% orezanie nepotrebn�ch v�stupov a normaliz�cia vstupn�ch d�t pre zefekt�vnenie u?enia siete
outputs = getTrimmedOutputs(labels);
inputs = normalizeInputs(inputs);
% z�skanie indexov tr�novac�ch, valida?n�ch a testovac�ch d�t na z�klade pravidiel kr�ovej valid�cie
[indices_train, indices_val, indices_test] = getCrossValidationIndices();


                                    % [indices_train, indices_val, indices_test] = getIndices(winedata);


% v�ber rozdelenia d�t NS
net.divideFcn='divideind'; % Indexov� rozdelenie

% parametre indexov�ho tr�novania NS
net.divideParam.trainInd = indices_train;
net.divideParam.valInd   = indices_val;
net.divideParam.testInd  = indices_test;

% nastavenie parametrov tr�novania NS
net.trainParam.epochs   = 3000;     % Maxim�lny pocet ep�ch
net.trainParam.goal     = 1e-16;    % Minim�lna chybovost
net.trainParam.min_grad = 1e-16;    % Minim�lny gradient
net.trainParam.show     = 5;        % Frekvencia zobrazovania priebehu chyby tr�novania

% tr�novanie NS
net=train(net,inputs,outputs); 

% simul�cia v�stupu NS
outnetsim = sim(net,inputs);

% confusion
confusion = confusion(outputs,outnetsim);
plotconfusion(outputs,outnetsim);
disp("Percentualna uspesnost: "+num2str(100-confusion*100)+"%");
% view(net)

% po?�tanie jednotliv�ch ch�b NS
% err = (outnetsim - outputs);
% SSE = sum(err.^2,'all');        % suma kvadr�tov odch�liek medzi meran�m v�stupom a v�stupom siete
% MSE = SSE/length(outputs)       % priemer z SSE
% MAE = max((err).^2,[],'all')    % maxim�lna absol�tna odch�lka medzi meran�m v�stupom a v�stupom siete
% MIN = min((err).^2,[],'all')

% Testovanie pre jednotlive vzorky
simEachRank(net,winedata);
