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

% v�ber rozdelenia d�t NS
net.divideFcn='dividerand'; % N�hodn� rozdelenie

% parametre tr�novania
net.divideParam.trainRatio = 0.6;   % Tr�novacie d�ta
net.divideParam.valRatio   = 0.0;   % Valida?n� d�ta
net.divideParam.testRatio  = 0.4;   % Testovacie d�ta

% nastavenie parametrov tr�novania NS
net.trainParam.epochs   = 1200;     % Maxim�lny po?et epoch
net.trainParam.goal     = 1e-8;     % Minim�lna chybovos?
net.trainParam.min_grad = 1e-9;     % Minim�lny gradient
net.trainParam.show     = 5;

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
% SSE = sum(err.^2,'all');
% MSE = SSE/length(outputs)
% MAE = max((err).^2,[],'all')
% MIN = min((err).^2,[],'all')

% Testovanie pre jednotlive vzorky
simEachRank(net,winedata,inputs);
