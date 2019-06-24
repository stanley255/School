clear
% suradnice x,y,z piatich skupin bodov
load databody

% vykreslenie bodov podla skupin
h=figure;
plot3(data1(:,1),data1(:,2),data1(:,3),'b+')
hold on
plot3(data2(:,1),data2(:,2),data2(:,3),'co')
plot3(data3(:,1),data3(:,2),data3(:,3),'g*')
plot3(data4(:,1),data4(:,2),data4(:,3),'r*')
plot3(data5(:,1),data5(:,2),data5(:,3),'mx')

axis([0 1 0 1 0 1])
title('Data body')
xlabel('x')
ylabel('y')
zlabel('z')

% disp(' --------------- stlac klavesu --------------')
% pause

% vstupne a vystupne data na trenovanie neuronovej siete
datainnet=[data1; data2; data3; data4; data5]';
dataoutnet=[ones(1,50) zeros(1,200);zeros(1,50) ones(1,50) zeros(1,150); zeros(1,100) ones(1,50) zeros(1,100);  ...
            zeros(1,150) ones(1,50) zeros(1,50);zeros(1,200) ones(1,50)];

% vytvorenie struktury siete
pocet_neuronov=20;  % definujte pocet neuronov v skrytej vrstve
net = patternnet(pocet_neuronov);

% parametre rozdelenia dat na trenovanie, validacne a testovanie
% definujte rozdelenie dat 
net.divideFcn='dividerand';
net.divideParam.trainRatio=0.6;
net.divideParam.valRatio=0.2;
net.divideParam.testRatio=0.2;

% indx_all = 1:length(datainnet);
% indx_all = indx_all(randperm(length(indx_all)));
% indx_train = indx_all(1:150);
% indx_val = indx_all(151:200);
% indx_test = indx_all(201:250);
% 
% net.divideFcn='divideind';      % indexove
% net.divideParam.trainInd=indx_train;
% net.divideParam.valInd=indx_val;
% net.divideParam.testInd=indx_test;

% nastavenie parametrov trenovania
% definujte parametre trenovania siete
net.trainParam.goal = 1.00e-20;     % ukoncovacia podmienka na chybu.
net.trainParam.min_grad = 1e-20;    % ukoncovacia podmienka na gradient
net.trainParam.show = 10;           % frekvencia zobrazovania chyby
net.trainParam.epochs = 1000;        % maximalny pocet trenovacich epoch.
net.trainParam.max_fail = 1000;     % validity check count

% trenovanie NS
for i=1:10
   net = train(net,datainnet,dataoutnet); 
end

% zobrazenie struktury siete
% view(net)

% simulacia vystupu NS pre trenovacie data
% testovanie NS
outnetsim = sim(net,datainnet);

% chyba NS a dat
err=(outnetsim-dataoutnet);

% percento neuspesne klasifikovanych bodov
% pouzit funkciu -> confusion 
confusion(dataoutnet,outnetsim)
% kontingenèná matica
figure
% pouzit funkciu -> plotconfusion
plotconfusion(dataoutnet,outnetsim);         % porovnanie 

% klasifikacia 5 novych bodov do tried
bodynew=[0.55 0.25 0.2;0.3 0.4 0.7;0.2 0.7 0.5;0.7 0.55 0.35;0.9 0.85 0.4];
% pouzit funkcia -> sim , vec2ind 

outnetsim = sim(net,bodynew');
pointsGrouped = vec2ind(outnetsim);
figure(h)
farby='bcgrm';
for i=1:5
    plot3(bodynew(i,1),bodynew(i,2),bodynew(i,3),strcat(farby(pointsGrouped(i)),'o'),'MarkerSize',10,'LineWidth',2)   
end
                