% program na hladanie kociek robotom v bludisku s prekazkami,
% robot ma 3 snimace prekazok (vpredu, vlavo, vpravo), otaca sa o 90stupnov
% vlavo alebo vpravo, ide iba dopredu
% cielom je najst vsetky kocky v bludisku, po najdeni kocky ju priniest do
% ciela do pozicie (40,40) 1. typ objektu, do pozicie (1,40) 2. typ objektu 

% toto riesenie obsahuje aj radar na hladanie kocky v def. okruhu, po
% najdeni kocky ju zoberie do ciela

%robot=[poziciaX poziciaY snimacLavo snimacPravo snimacVpred pohyb otocenie smer kocka prekazka cielx ciely offset_rand gain_rand]

% poziciaX - stlpec 1 az 40, poziciaY - riadok 1 az 40

% snimacLavo snimacPravo snimacVpred , 0-volne, 1-prekazka, 2-kocka,
% 3-iny robot

% pohyb , 0-stoji, 1-ide

% otocenie, 0-rovno, 1-doprava, 2-dolava

% smer, 1-hore, 2-dole, 3-doprava, 4-dolava

% kocka, 0-nema kocku,hlada ju, 1-nesie kocku na ciel (40,40), 2 - ide na
% definovany ciel

% prekazka, kde je prekazka 0-nie je, 1-hore, 2-dole, 3-doprava, 4-dolava,
% ak su zaporne hodnoty, prekazka je v cieli

% typ kocka , 1 - objekt 1. typu (napr. jablko, hruska), 2  - objekt 2. typu (napr. banan, pomaranc, citron)

% cielX - stlpec 1 az 40, cielY - riadok 1 az 40

% param1, param2 - parametre pre random hladanie

% hlavna funkcia
function [caszberu]=mainrobot(pocetkociek,pocetprekazok)

h1=figure;

% definovanie color mapy 1-pozadie, 2-prekazka, 3-robot, 4-robot s kockou,
% 5- kocka 1 typ ,  6- kocka 2 typ,  7 - neodkryta mapa 
colormaprobot=[1 1 1;0 0 0;0 1 0;1 0 0;0 0 1;1 0 1;1 1 0];
mapa=ones(42);
mapa(1,:)=2;
mapa(42,:)=2;
mapa(:,1)=2;
mapa(:,42)=2;

% budovana mapa 1-pozadie, 2-prekazka, 3-robot, 4-robot s kockou,
% 5- kocka 1 typ ,  6- kocka 2 typ,  7 - neodkryta mapa 
mapazobraz=7*ones(42);
mapazobraz(1,:)=2;
mapazobraz(42,:)=2;
mapazobraz(:,1)=2;
mapazobraz(:,42)=2;

odkrytiemapy=zeros(42);

% definovanie prekazok
if pocetprekazok>0
mapa(2:5,8)=2;
mapa(6,8:10)=2;

mapa(2:7,23)=2;
mapa(8,19:23)=2;

mapa(34:41,28)=2;
mapa(34,25:28)=2;

mapa(34,10:12)=2;
mapa(35:41,10)=2;

mapa(20,32:41)=2;
mapa(18:22,32)=2;

mapa(22,12:20)=2;
mapa(19:25,16)=2;

end

stanicaX=40;
stanicaY=40;

pocetrobot=3;

% maximalny cas trvania simulacie
maxcashladania=120*pocetkociek;

% zoznam kociek
% 1-pozicia X, 2-pozicia Y, 3 - stav kocky, 4 - typ, 5 - parameter 1, 6 - parameter 2, 7 - parameter 3   
zoznamkociek=[];

% definovanie parametrov robota
roboti(1)=struct('poziciaX',1,'poziciaY',1,'snimacLavo',1,'snimacPravo',0,'snimacVpred',1,'pohyb',0,'otocenie',0, ...
        'smer',1,'kocka',0,'prekazka',0,'typkocka',1,'cielX',40,'cielY',40,'param1',10,'param2',40,'pocitadlo',0,'maxkrok',0,'bludenie',0);

% zakreslenie robota
mapa(2,2)=3;

if pocetrobot>1
    %roboti(2,:)=[1 40 1 0 0 0 0 1 0 0 40 40 3 20];
roboti(2)=struct('poziciaX',1,'poziciaY',40,'snimacLavo',1,'snimacPravo',0,'snimacVpred',0,'pohyb',0,'otocenie',0, ...
        'smer',1,'kocka',0,'prekazka',0,'typkocka',1,'cielX',40,'cielY',40,'param1',3,'param2',20,'pocitadlo',0,'maxkrok',0,'bludenie',0);
    
    mapa(41,2)=3;
    if pocetrobot>2
%        roboti(3,:)=[40 1 1 0 0 0 0 2 0 0 40 40 8 30];
roboti(3)=struct('poziciaX',40,'poziciaY',1,'snimacLavo',1,'snimacPravo',0,'snimacVpred',0,'pohyb',0,'otocenie',0, ...
        'smer',2,'kocka',0,'prekazka',0,'typkocka',1,'cielX',40,'cielY',40,'param1',8,'param2',30,'pocitadlo',0,'maxkrok',0,'bludenie',0);

        mapa(2,41)=3;
        pocetrobot=3;
    end
end

% parametre na nahodne hladanie
for ii=1:pocetrobot,
    roboti(ii).maxkrok=fix(40*rand);
end

khladaj=zeros(1,pocetrobot);
nahodahladaj=fix(40*rand(1,pocetrobot));
timeout=[0 0 0];

% parametre na nahodne hladanie
% khladaj=0; 
% nahodahladaj=fix(40*rand(1,1));

% definovanie pozicii kociek
kockypos=[4 11;15 22;23 18;25 35;37 16;37 5;10 6;22 8;35 32;8 32;15 35;12 15;30 20;12 28;20 25;33 3;28 9; ...
                14 9;4 21;4 28;38 24;12 38;28 14;3 16;17 13;26 4;26 26;5 6;16 5;29 31;38 12;32 36;38 20;3 35;10 11];
            
if pocetkociek>35
    pocetkociek=35;
end
indx=randperm(35);
for i=1:pocetkociek,
    if rand(1)>0.5
        mapa(kockypos(indx(i),1),kockypos(indx(i),2))=5;
    else
        mapa(kockypos(indx(i),1),kockypos(indx(i),2))=6;
    end
end

% pociatocne vykreslenie mapy
colormap(colormaprobot);
hmapa=image(mapa);
k=0;
pocetuloh=0;
title(['ulozene kocky = ' num2str(pocetuloh)])

% % zobrazenie budovanej mapy
% h2=figure;
% colormap(colormaprobot);
% hmapa2=image(mapazobraz);


% hlavny cyklus
while k<maxcashladania && pocetuloh~=pocetkociek;
    k=k+1;
    for rrob=1:pocetrobot,
        
        % vyber pixelov z mapy
        hp=mapa(roboti(rrob).poziciaY,roboti(rrob).poziciaX+1);
        dp=mapa(roboti(rrob).poziciaY+2,roboti(rrob).poziciaX+1);
        pp=mapa(roboti(rrob).poziciaY+1,roboti(rrob).poziciaX+2);
        vp=mapa(roboti(rrob).poziciaY+1,roboti(rrob).poziciaX);
        
        % nastavenie snimacov robota
        [vs,ps,hs]=nastavsnimace(roboti(rrob),hp,dp,pp,vp);
             
        roboti(rrob).snimacLavo=vs;
        roboti(rrob).snimacPravo=ps;
        roboti(rrob).snimacVpred=hs;
        
        % chod do stanice
        if roboti(rrob).kocka==1
            %novysmer=choddostanice(roboti(rrob));
            if roboti(rrob).typkocka==2
                roboti(rrob).cielX=40;
                roboti(rrob).cielY=1;
            else
                roboti(rrob).cielX=40;
                roboti(rrob).cielY=40;
            end
            [novysmer,novaprekazka]=chodnaciel(roboti(rrob));
            roboti(rrob).prekazka=novaprekazka;
            if novysmer>-1
                roboti(rrob).otocenie=novysmer;
                roboti(rrob).pohyb=1;
                timeout(rrob)=0;
            else
                if novaprekazka<0
                    roboti(rrob).otocenie=0;
                    roboti(rrob).prekazka=0;
                    roboti(rrob).smer=abs(novaprekazka);
                else
                
                    roboti(rrob).pohyb=0;
                    timeout(rrob)=timeout(rrob)+1;
                    if timeout(rrob)>3
                        if rem(roboti(rrob).smer,2)==1
                            roboti(rrob).smer=roboti(rrob).smer+1;
                        else
                            roboti(rrob).smer=roboti(rrob).smer-1;                   
                        end
                        timeout(rrob)=0;
                    end
                end
            end
            
        % chod na ciel    
        elseif roboti(rrob).kocka==2
            [novysmer,novaprekazka]=chodnaciel(roboti(rrob));
            roboti(rrob).prekazka=novaprekazka;
            if novysmer>-1
                roboti(rrob).otocenie=novysmer;
                roboti(rrob).pohyb=1;
                timeout(rrob)=0;
            else
                % ak je prekazka v cieli kocka, zober ju
                if novaprekazka<0
                    roboti(rrob).otocenie=0;
                    roboti(rrob).prekazka=0;
                    roboti(rrob).smer=abs(novaprekazka);
                else

                    roboti(rrob).pohyb=0;
                    if roboti(rrob).poziciaX==roboti(rrob).cielX && roboti(rrob).poziciaY==roboti(rrob).cielY
                        roboti(rrob).kocka=0;

                    end
%                     timeout(rrob)=timeout(rrob)+1;
%                     if timeout(rrob)>5
%                         if rem(roboti(rrob).smer,2)==1
%                             roboti(rrob).smer=roboti(rrob).smer+1;
%                         else
%                             roboti(rrob).smer=roboti(rrob).smer-1;                   
%                         end
%                         timeout(rrob)=0;
%                     end
                    
                end
            end    
            
            % nahodne hladanie
        else
            [novysmer,kk,nahoda]=nahodnehladanie(roboti(rrob),khladaj(rrob),nahodahladaj(rrob));
            % nastavenie smeru
            if novysmer>-1
                roboti(rrob).otocenie=novysmer;
                roboti(rrob).pohyb=1;
            else
                roboti(rrob).pohyb=0;
                if rem(roboti(rrob).smer,2)==1
                    roboti(rrob).smer=roboti(rrob).smer+1;
                else
                    roboti(rrob).smer=roboti(rrob).smer-1;                   
                end
                
            end
            khladaj(rrob)=kk;
            nahodahladaj(rrob)=nahoda;
        end
        
        % nastav novu poziciu robota
        stareX=roboti(rrob).poziciaX;
        stareY=roboti(rrob).poziciaY;
        mapa(stareY+1,stareX+1)=1;

        noveX=stareX;
        noveY=stareY;
        
        % ak je robot v pohybe nastav smer cesty
        if roboti(rrob).pohyb==1
            [posX,posY,otoc]=nastavsmercesty(roboti(rrob));
            noveX=posX;
            noveY=posY;
            if otoc>0
                roboti(rrob).smer=otoc;
            end

        end
            
        roboti(rrob).poziciaX=noveX;
        roboti(rrob).poziciaY=noveY;
        
        % co vykona robot v jednotlivych stavoch
        [robotstav,nasielkocku,polozilkocku,zoznamkociek]=akciarobot(roboti(rrob),mapa,zoznamkociek,odkrytiemapy);
        roboti(rrob)=robotstav;
        
        % kontrola ci nahodou neprejde prekazku
        if mapa(roboti(rrob).poziciaY+1,roboti(rrob).poziciaX+1)==2
             noveX=stareX;
             noveY=stareY;
            roboti(rrob).poziciaX=noveX;
            roboti(rrob).poziciaY=noveY;
        end
        
        % zakreslenie novej pozicie robota
        if roboti(rrob).kocka==1 
            mapa(noveY+1,noveX+1)=4;
        else
            mapa(noveY+1,noveX+1)=3;
        end
        
%         % budovanie mapy
%         odkrytiemapy=budujmapu(odkrytiemapy,roboti(rrob));
        
        % prekreslenie mapy 
        figure(h1)
        set(hmapa,'CData',mapa)
 
        % vypisy do okna
        if nasielkocku==1
            title(['ulozene kocky = ' num2str(pocetuloh) ' cas [s] = ' num2str(k)])
        end
        if polozilkocku==1
               pocetuloh=pocetuloh+1;
               title(['ulozene kocky = ' num2str(pocetuloh) ' cas [s] = ' num2str(k)])
        end
        
        % na spomalenie priebehu simulacie
        pause(0.001)

    end
    
%     if rem(k,5)==0
%         figure(h2)
%         set(hmapa2,'CData',mapazobraz)        
%     end
        
end
caszberu=k;
end


% fukcia, ktora riesi akcie, co sa robot robit v urcitych stavoch
% robot - struktura robota
% mapab - aktualna mapa bludiska
% zkvstup - zoznam najdenych kociek
% odkrytiemapy1 - kde uz bol
function [robotupdate,nasielkocku,polozilkocku,zkvystup]=akciarobot(robot,mapab,zkvstup,odkrytiemapy1)

        dosahradaru=3;
        nasielkocku=0;
        polozilkocku=0;
        zkvystup=zkvstup;
        
        % ak nasiel kocku, nastav stav zober kocku
        if mapab(robot.poziciaY+1,robot.poziciaX+1)==5 || mapab(robot.poziciaY+1,robot.poziciaX+1)==6
            robot.kocka=1;
            robot.smer=2;
            robot.otocenie=0;
            nasielkocku=1;
            robot.typkocka=1;
            
            % doplnit rozpoznavanie pomocou NS
            % [typkocky,paramkocky]=citajparamkocky(mapab,robot.poziciaX,robot.poziciaY);
            
        end

        % ak nesie kocku
        if robot.kocka==1
            % ak priniesol kocku do ciela
            if robot.typkocka==1
                if robot.poziciaX==40 && robot.poziciaY==40
                    robot.kocka=0;
                    polozilkocku=1;
                end
            elseif robot.typkocka==2
                if robot.poziciaX==40 && robot.poziciaY==1
                    robot.kocka=0;
                    polozilkocku=1;
                end                
            end
        end

        % ak nema kocku prehlada priestor ultrazvukom
        if robot.kocka==0
            [najdenepozkocky]=najdikocku(robot,mapab,dosahradaru);
            % ak najde kocku nastavi ciel na jej poziciu
            if isempty(najdenepozkocky)==0
                robot.cielX=najdenepozkocky(1,2);
                robot.cielY=najdenepozkocky(1,1);
                robot.kocka=2;
            end
        end
        robotupdate=robot;
end


% funkcia na budovanie mapy
function odkrytiemapy2=budujmapu(odkrytiemapy1,robot)
    odkrytiemapy2=odkrytiemapy1;
    
    % doprogramovavat


end


% funkcia, ktora vrati parametre objektu a jeho typ 
function [typkocky,paramkocky]=citajparamkocky(mapab,posX,posY)

pd=[0.91 0.07 0.91 0.03 0.5 0.4;0.75 0.15 0.77 0.06 0.57 0.27; ...
0.33 0.23 0.3 0.2 0.75 0.15;0.73 0.08 0.92 0.03 0.47 0.18;0.5 0.15 0.83 0.08 0.7 0.13];

paramkocky=zeros(1,3);

            % doplnit rozpoznavanie pomocou NS
            if mapab(posY+1,posX+1)==6
               typkocky=2;
               druh=fix(3*rand(1))+3;
            else
               typkocky=1;
               druh=fix(3*rand(1))+1;

            end
            
            for i=1:3
                  paramkocky(i)=pd(druh,2*(i-1)+1)+2*pd(druh,2*(i-1)+2)*rand(1)-pd(druh,2*(i-1)+2); 
            end
end



% funkcia pre riadenie robota do ciela
% novysmer , 0-rovno, 1-vpravo, 2-vlavo, -1 - bez zmeny
% prekazka - 0-nie je, 1-hore, 2-dole, 3-doprava, 4-dolava,
% ak su zaporne hodnoty, prekazka je v cieli
function [novysmer,prekazka]=chodnaciel(robot)
    
    % suradnice ciela robota
    xciel=robot.cielX;
    yciel=robot.cielY;
    
    % kde sa nachadza ciel od aktualnej pozicie robota, vlavo, vpravo, hore
    % dole
    if (xciel-robot.poziciaX)>0
        idevpravo=1;
    else
        idevpravo=0;
    end
    if (xciel-robot.poziciaX)<0
        idevlavo=1;
    else
        idevlavo=0;
    end
    if (yciel-robot.poziciaY)>0
        idedole=1;
    else
        idedole=0;
    end
    if (yciel-robot.poziciaY)<0
        idehore=1;
    else
        idehore=0;
    end

    novysmer=-1;
    prekazka=robot.prekazka;
    % ak nenarazil na prekazku
    if prekazka==0
        
        % ma ist smerom dole
        if idedole==1
           if robot.smer==2 && robot.snimacVpred==0
                novysmer=0;
           elseif robot.smer==3 && robot.snimacPravo==0    %ide vpravo, vpravo volno, otoc dole 
                novysmer=1;
           elseif robot.smer==4 && robot.snimacLavo==0
                novysmer=2;
           elseif robot.smer==1 
                if idevpravo==1 && robot.snimacPravo==0
                    novysmer=1;
                elseif idevlavo==1 && robot.snimacLavo==0
                    novysmer=2;
                end
           end
        end
    
    if novysmer==-1
        % ma ist smerom hore
        if idehore==1
           if robot.smer==1 && robot.snimacVpred==0
                novysmer=0;
           elseif robot.smer==3 && robot.snimacLavo==0    %ide vpravo, vpravo volno, otoc dole 
                novysmer=2;
           elseif robot.smer==4 && robot.snimacPravo==0
                novysmer=1;
           elseif robot.smer==2 
                if idevpravo==1 && robot.snimacLavo==0
                    novysmer=2;
                elseif idevlavo==1 && robot.snimacPravo==0
                    novysmer=1;
                end
           end            
        end
    end
                    
    if novysmer==-1
        % ma ist smerom vpravo
        if idevpravo==1
           if robot.smer==1 && robot.snimacPravo==0
                novysmer=1;
           elseif robot.smer==3 && robot.snimacVpred==0    %ide vpravo, vpravo volno, otoc dole 
                novysmer=0;
           elseif robot.smer==2 && robot.snimacLavo==0
                novysmer=2;
           elseif robot.smer==4 
                if idehore==1 && robot.snimacPravo==0
                    novysmer=1;
                elseif idedole==1 && robot.snimacLavo==0
                    novysmer=2;
                end
           end            
        end
    end
                
    if novysmer==-1
        % ma ist smerom vlavo
        if idevlavo==1
           if robot.smer==1 && robot.snimacLavo==0
                novysmer=2;
           elseif robot.smer==4 && robot.snimacVpred==0    %ide vpravo, vpravo volno, otoc dole 
                novysmer=0;
           elseif robot.smer==2 && robot.snimacPravo==0
                novysmer=1;
           elseif robot.smer==3 
                if idehore==1 && robot.snimacLavo==0
                    novysmer=2;
                elseif idedole==1 && robot.snimacPravo==0
                    novysmer=1;
                end
           end            
        end
    end
    
    % nie je mozny ziadny smer
    if novysmer==-1
        % ak nie je v cieli, tak nastav prekazku
        if xciel~=robot.poziciaX
            if idevpravo==1 && (xciel-robot.poziciaX)==1
                prekazka=-3;
            elseif idevpravo==1
                prekazka=3;
            elseif idevlavo==1 && (robot.poziciaX-xciel)==1
                prekazka=-4;                
            elseif idevlavo==1
                prekazka=4;
            end  
        elseif yciel~=robot.poziciaY
            if idehore==1 && (robot.poziciaY-yciel)==1
                prekazka=-1; 
            elseif idehore==1
                prekazka=1; 
            elseif idedole==1 && (yciel-robot.poziciaY)==1
                prekazka=-2;
            elseif idedole==1
                prekazka=2;
            end                       
        end        
    end
    
    % ak je prekazka, potom jej obchadzanie
    else
        
        % prekazka vpravo
        if prekazka==3 && yciel<21
           if robot.smer==3 && robot.snimacVpred~=0 && robot.snimacPravo~=0 && robot.snimacLavo==0 % ak ide doprava,prekazka vpredu a vpravo, vlavo volno otoc dolava hore
                novysmer=2;
           elseif robot.smer==3 && robot.snimacVpred~=0 && robot.snimacPravo==0 % ak ide doprava,prekazka vpredu , vpravo volno otoc doprava hole
                novysmer=1;                
           elseif robot.smer==2 && robot.snimacLavo~=0 && robot.snimacVpred==0 % ak ide dole,prekazka vlavo, vpred volno pokracuj rovno
                novysmer=0; 
           elseif robot.smer==2 && robot.snimacLavo~=0 && robot.snimacVpred~=0 % ak ide dole,prekazka vlavo a rovno, otoc vpravo
                novysmer=1;                 
           elseif robot.smer==2 && robot.snimacLavo==0 && robot.snimacVpred==0  % ak ide dole,prekazka vlavo a rovno nieje, otoc dolava
                novysmer=2;
           elseif robot.smer==2 && robot.snimacLavo==0 && robot.snimacVpred~=0 && robot.snimacPravo==0 % ak ide dole,prekazka rovno, vlavo a vpravo je volno, otoc doprava
                novysmer=1;               
           elseif robot.smer==4 && robot.snimacLavo~=0 && robot.snimacVpred==0 % ak ide dolava,prekazka vlavo, vpred je volno, chod rovno
                novysmer=0;
           elseif robot.smer==4 && robot.snimacLavo==0 % ak ide dolava, vlavo je volno, chod dolava
                novysmer=2;         
           elseif robot.smer==1 % ak ide dole, toc dolava
                novysmer=2;
           elseif robot.smer==3 && robot.snimacVpred==0 && robot.poziciaX<xciel % ak ide doprava, rovno je volno, este nie je v cieli, chod rovno a vypni obchadzanie prekazky  
                novysmer=0;
                prekazka=0;
           end               
           
        elseif prekazka==3 && yciel>20
           if robot.smer==3 && robot.snimacVpred~=0 && robot.snimacLavo~=0 && robot.snimacPravo==0 % ak ide doprava,prekazka vpredu a vlavo, vpravo volno otoc doprava dole
                novysmer=1;
           elseif robot.smer==3 && robot.snimacVpred~=0 && robot.snimacLavo==0 % ak ide doprava,prekazka vpredu , vlavo volno otoc dolava hole
                novysmer=2;                
           elseif robot.smer==1 && robot.snimacPravo~=0 && robot.snimacVpred==0 % ak ide hore,prekazka vpravo, vpred volno pokracuj rovno
                novysmer=0; 
           elseif robot.smer==1 && robot.snimacPravo~=0 && robot.snimacVpred~=0 % ak ide hore,prekazka vpravo a rovno, otoc vlavo
                novysmer=2;                 
           elseif robot.smer==1 && robot.snimacPravo==0 && robot.snimacVpred==0  % ak ide hore,prekazka vpravo a rovno nieje, otoc doprava
                novysmer=1;
           elseif robot.smer==1 && robot.snimacPravo==0 && robot.snimacVpred~=0 && robot.snimacLavo==0 % ak ide hore,prekazka rovno, vlavo a vpravo je volno, otoc dolava
                novysmer=2;               
           elseif robot.smer==4 && robot.snimacPravo~=0 && robot.snimacVpred==0 % ak ide dolava,prekazka vpravo, vpred je volno, chod rovno
                novysmer=0;
           elseif robot.smer==4 && robot.snimacPravo==0 % ak ide dolava, vpravo je volno, chod doprava
                novysmer=1;         
           elseif robot.smer==2 % ak ide dole, toc dolava
                novysmer=1;
           elseif robot.smer==3 && robot.snimacVpred==0 && robot.poziciaX<xciel % ak ide doprava, rovno je volno, este nie je v cieli, chod rovno a vypni obchadzanie prekazky  
                novysmer=0;
                prekazka=0;
           end               
        end
        
        % prekazka vlavo
        if prekazka==4 && yciel>20
           if robot.smer==4 && robot.snimacVpred~=0 && robot.snimacPravo~=0 && robot.snimacLavo==0 % ak ide doprava,prekazka vpredu a vpravo, vlavo volno otoc dolava hore
                novysmer=2;
           elseif robot.smer==4 && robot.snimacVpred~=0 && robot.snimacPravo==0 % ak ide doprava,prekazka vpredu , vpravo volno otoc doprava hole
                novysmer=1;                
           elseif robot.smer==1 && robot.snimacLavo~=0 && robot.snimacVpred==0 % ak ide dole,prekazka vlavo, vpred volno pokracuj rovno
                novysmer=0; 
           elseif robot.smer==1 && robot.snimacLavo~=0 && robot.snimacVpred~=0 % ak ide dole,prekazka vlavo a rovno, otoc vpravo
                novysmer=1;                 
           elseif robot.smer==1 && robot.snimacLavo==0 && robot.snimacVpred==0  % ak ide dole,prekazka vlavo a rovno nieje, otoc dolava
                novysmer=2;
           elseif robot.smer==1 && robot.snimacLavo==0 && robot.snimacVpred~=0 && robot.snimacPravo==0 % ak ide dole,prekazka rovno, vlavo a vpravo je volno, otoc doprava
                novysmer=1;               
           elseif robot.smer==3 && robot.snimacLavo~=0 && robot.snimacVpred==0 % ak ide dolava,prekazka vlavo, vpred je volno, chod rovno
                novysmer=0;
           elseif robot.smer==3 && robot.snimacLavo==0 % ak ide dolava, vlavo je volno, chod dolava
                novysmer=2;         
           elseif robot.smer==2 % ak ide dole, toc dolava
                novysmer=2;
           elseif robot.smer==4 && robot.snimacVpred==0 && robot.poziciaX>xciel % ak ide doprava, rovno je volno, este nie je v cieli, chod rovno a vypni obchadzanie prekazky  
                novysmer=0;
                prekazka=0;
           end               
           
        elseif prekazka==4 && yciel<21
           if robot.smer==4 && robot.snimacVpred~=0 && robot.snimacLavo~=0 && robot.snimacPravo==0 % ak ide doprava,prekazka vpredu a vlavo, vpravo volno otoc doprava dole
                novysmer=1;
           elseif robot.smer==4 && robot.snimacVpred~=0 && robot.snimacLavo==0 % ak ide doprava,prekazka vpredu , vlavo volno otoc dolava hole
                novysmer=2;                
           elseif robot.smer==2 && robot.snimacPravo~=0 && robot.snimacVpred==0 % ak ide hore,prekazka vpravo, vpred volno pokracuj rovno
                novysmer=0; 
           elseif robot.smer==2 && robot.snimacPravo~=0 && robot.snimacVpred~=0 % ak ide hore,prekazka vpravo a rovno, otoc vlavo
                novysmer=2;                 
           elseif robot.smer==2 && robot.snimacPravo==0 && robot.snimacVpred==0  % ak ide hore,prekazka vpravo a rovno nieje, otoc doprava
                novysmer=1;
           elseif robot.smer==2 && robot.snimacPravo==0 && robot.snimacVpred~=0 && robot.snimacLavo==0 % ak ide hore,prekazka rovno, vlavo a vpravo je volno, otoc dolava
                novysmer=2;               
           elseif robot.smer==3 && robot.snimacPravo~=0 && robot.snimacVpred==0 % ak ide dolava,prekazka vpravo, vpred je volno, chod rovno
                novysmer=0;
           elseif robot.smer==3 && robot.snimacPravo==0 % ak ide dolava, vpravo je volno, chod doprava
                novysmer=1;         
           elseif robot.smer==1 % ak ide dole, toc dolava
                novysmer=1;
           elseif robot.smer==4 && robot.snimacVpred==0 && robot.poziciaX>xciel % ak ide doprava, rovno je volno, este nie je v cieli, chod rovno a vypni obchadzanie prekazky  
                novysmer=0;
                prekazka=0;
           end               
           
        end

        % prekazka hore
        if prekazka==1      %&& xciel>20
           if robot.smer==1 && robot.snimacVpred~=0 && robot.snimacLavo~=0 && robot.snimacPravo==0 % ak ide doprava,prekazka vpredu a vpravo, vlavo volno otoc dolava hore
                novysmer=1;
           elseif robot.smer==1 && robot.snimacVpred~=0 && robot.snimacLavo==0 % ak ide doprava,prekazka vpredu , vpravo volno otoc doprava hole
                novysmer=2;                
           elseif robot.smer==4 && robot.snimacPravo~=0 && robot.snimacVpred==0 % ak ide dole,prekazka vlavo, vpred volno pokracuj rovno
                novysmer=0; 
           elseif robot.smer==4 && robot.snimacPravo~=0 && robot.snimacVpred~=0 % ak ide dole,prekazka vlavo a rovno, otoc vpravo
                novysmer=2;                 
           elseif robot.smer==4 && robot.snimacPravo==0 && robot.snimacVpred==0  % ak ide dole,prekazka vlavo a rovno nieje, otoc dolava
                novysmer=1;
           elseif robot.smer==4 && robot.snimacLavo==0 && robot.snimacVpred~=0 && robot.snimacPravo==0 % ak ide dole,prekazka rovno, vlavo a vpravo je volno, otoc doprava
                novysmer=2;               
           elseif robot.smer==2 && robot.snimacPravo~=0 && robot.snimacVpred==0 % ak ide dolava,prekazka vlavo, vpred je volno, chod rovno
                novysmer=0;
           elseif robot.smer==2 && robot.snimacPravo==0 % ak ide dolava, vlavo je volno, chod dolava
                novysmer=1;         
           elseif robot.smer==3 % ak ide dole, toc dolava
                novysmer=1;
           elseif robot.smer==1 && robot.snimacVpred==0 && robot.poziciaY>yciel % ak ide doprava, rovno je volno, este nie je v cieli, chod rovno a vypni obchadzanie prekazky  
                novysmer=0;
                prekazka=0;
           end               
                     
        end

        % prekazka dole
        if prekazka==2  %&& xciel>20
           if robot.smer==2 && robot.snimacVpred~=0 && robot.snimacPravo~=0 && robot.snimacLavo==0 % ak ide doprava,prekazka vpredu a vpravo, vlavo volno otoc dolava hore
                novysmer=2;
           elseif robot.smer==2 && robot.snimacVpred~=0 && robot.snimacPravo==0 % ak ide doprava,prekazka vpredu , vpravo volno otoc doprava hole
                novysmer=1;                
           elseif robot.smer==4 && robot.snimacLavo~=0 && robot.snimacVpred==0 % ak ide dole,prekazka vlavo, vpred volno pokracuj rovno
                novysmer=0; 
           elseif robot.smer==4 && robot.snimacLavo~=0 && robot.snimacVpred~=0 % ak ide dole,prekazka vlavo a rovno, otoc vpravo
                novysmer=1;                 
           elseif robot.smer==4 && robot.snimacLavo==0 && robot.snimacVpred==0  % ak ide dole,prekazka vlavo a rovno nieje, otoc dolava
                novysmer=2;
           elseif robot.smer==4 && robot.snimacLavo==0 && robot.snimacVpred~=0 && robot.snimacPravo==0 % ak ide dole,prekazka rovno, vlavo a vpravo je volno, otoc doprava
                novysmer=1;               
           elseif robot.smer==1 && robot.snimacLavo~=0 && robot.snimacVpred==0 % ak ide dolava,prekazka vlavo, vpred je volno, chod rovno
                novysmer=0;
           elseif robot.smer==1 && robot.snimacLavo==0 % ak ide dolava, vlavo je volno, chod dolava
                novysmer=2;         
           elseif robot.smer==3 % ak ide dole, toc dolava
                novysmer=2;
           elseif robot.smer==2 && robot.snimacVpred==0 && robot.poziciaY<yciel % ak ide doprava, rovno je volno, este nie je v cieli, chod rovno a vypni obchadzanie prekazky  
                novysmer=0;
                prekazka=0;
           end               
                     
        end        
        
        
    end
               
end

% funkcia na nahodne prehladavanie
% novysmer , 0-rovno, 1-vpravo, 2-vlavo, -1 - bez zmeny
% kki, kko - pocitadlo
% nahodai, nahodao - kedy ma byt vykonana zmena smeru 
function [novysmer,kko,nahodao]=nahodnehladanie(robot,kki,nahodai)
        if robot.snimacPravo==2  % ak je vpravo kocka, chod doprava
           novysmer=1;
        elseif robot.snimacLavo==2  % ak je vlavo kocka, chod dolava
           novysmer=2; 
        elseif robot.snimacVpred==0 || robot.snimacVpred==2 % ak je rovno kocka alebo volno chod rovno
           novysmer=0;
        elseif robot.snimacVpred~=0 && robot.snimacPravo==0 && robot.snimacLavo==0 % ak je rovno prekazka, vpravo aj vlavo volno, vyber si vlavo alebo vpravo
           if rand<0.4
               novysmer=2;
           else
               novysmer=1;
           end
        elseif robot.snimacVpred~=0 && robot.snimacPravo==0   % ak je rovno prekazka, vpravo  volno, chod vpravo
           novysmer=1;
        elseif robot.snimacVpred~=0 && robot.snimacLavo==0
           novysmer=2;
        else
            novysmer=-1;
        end
        
        % nahodna zmena smeru
        if kki==nahodai 
           % ak ide rovno, zmen smer 
           if novysmer==0 && robot.snimacVpred~=2
               % ak je vlavo volno, chod vlavo
               if robot.snimacLavo==0
                  novysmer=2;
               elseif robot.snimacPravo==0  % ak je vpravo volno, chod vpravo
                  novysmer=1;
               end
           end
           % nahodne generovanie casu na zmenu smeru
           nahodai=fix(robot.param2*rand+robot.param1);
           kko=0;
        else
            kko=kki+1;
        end
        nahodao=nahodai;     
end

% funkcia na nastavenie smeru cesty, podla toho ktorym smerom je otoceny
% vypocita poziciu robota a ktorym smerom sa ma otocit
function [posX,posY,otoc]=nastavsmercesty(robot)
    stareX=robot.poziciaX;
    stareY=robot.poziciaY;
    posX=robot.poziciaX;
    posY=robot.poziciaY;
    otoc=0;
    % nastavenie smeru cesty
    if robot.pohyb==1
        if robot.otocenie==0 && robot.smer==1 % hore
            posX=stareX;
            posY=stareY-1;
        elseif robot.otocenie==0 && robot.smer==2 % dole
            posX=stareX;
            posY=stareY+1;
        elseif robot.otocenie==0 && robot.smer==3 % vpravo
            posX=stareX+1;
            posY=stareY;
        elseif robot.otocenie==0 && robot.smer==4 % vlavo
            posX=stareX-1;
            posY=stareY;
            
        elseif robot.otocenie==1 && robot.smer==1 % otocenie vpravo
            posX=stareX+1;
            posY=stareY;
            otoc=3;
         elseif robot.otocenie==1 && robot.smer==3 % otocenie dole
            posX=stareX;
            posY=stareY+1;
            otoc=2;
         elseif robot.otocenie==1 && robot.smer==2 % otocenie vlavo
            posX=stareX-1;
            posY=stareY;
            otoc=4;
         elseif robot.otocenie==1 && robot.smer==4 % otocenie hore
            posX=stareX;
            posY=stareY-1;
            otoc=1;
            
        elseif robot.otocenie==2 && robot.smer==1 % otocenie vlavo
            posX=stareX-1;
            posY=stareY;
            otoc=4;
         elseif robot.otocenie==2 && robot.smer==3 % otocenie hore
            posX=stareX;
            posY=stareY-1;
            otoc=1;
         elseif robot.otocenie==2 && robot.smer==2 % otocenie vpravo
            posX=stareX+1;
            posY=stareY;
            otoc=3;
         elseif robot.otocenie==2 && robot.smer==4 % otocenie dole
            posX=stareX;
            posY=stareY+1;
            otoc=2;
        end
    end
    if posY<1
        posY=1;
    end
    if posX<1
        posX=1;
    end    
    if posX>40
        posX=40;
    end    
    if posY>40
        posY=40;
    end 

end

% nastavenie stavu snimacov, podla pixelov v mape
function [vs,ps,hs]=nastavsnimace(robot,horepole,dolepole,vpravopole,vlavopole)
    
    % smer hore
    if robot.smer==1 
        if horepole==2
            hs=1;
        elseif horepole==5 || horepole==6
            hs=2;  
        elseif horepole==3 || horepole==4
            hs=3;               
        else
            hs=0;            
        end
        if vlavopole==2
            vs=1;
        elseif vlavopole==5 || vlavopole==6
            vs=2;
        elseif vlavopole==3 || vlavopole==4
            vs=3;                                                           
        else
            vs=0;                      
        end
        if vpravopole==2
            ps=1;
        elseif vpravopole==5 || vpravopole==6
            ps=2;                                                 
        elseif vpravopole==3 || vpravopole==4
            ps=3;                                                           
        else
            ps=0;                      
        end
        
    end
    % smer dole
    if robot.smer==2
        if dolepole==2
            hs=1;
        elseif dolepole==5 || dolepole==6
            hs=2;
        elseif dolepole==3 || dolepole==4
            hs=3;                                                           
        else
            hs=0;            
        end
        if vpravopole==2
            vs=1;
        elseif vpravopole==5 || vpravopole==6
            vs=2;    
        elseif vpravopole==3 || vpravopole==4
            vs=3;                                               
        else
            vs=0;                      
        end
        if vlavopole==2
            ps=1;
        elseif vlavopole==5 || vlavopole==6
            ps=2;
        elseif vlavopole==3 || vlavopole==4
            ps=3;                                               
        else
            ps=0;                      
        end
        
    end
     % smer vpravo
    if robot.smer==3
        if vpravopole==2
            hs=1;
        elseif vpravopole==5 || vpravopole==6
            hs=2;
        elseif vpravopole==3 || vpravopole==4
            hs=3;                                   
        else
            hs=0;            
        end
        if horepole==2
            vs=1;
        elseif horepole==5 || horepole==6
            vs=2;
        elseif horepole==3 || horepole==4
            vs=3;                                                           
        else
            vs=0;                      
        end
        if dolepole==2
            ps=1;
        elseif dolepole==5 || dolepole==6
            ps=2;
        elseif dolepole==3 || dolepole==4
            ps=3;                                               
        else
            ps=0;                      
        end
        
    end
     % smer vlavo
    if robot.smer==4
        if vlavopole==2
            hs=1;
        elseif vlavopole==5 || vlavopole==6
            hs=2;
        elseif vlavopole==3 || vlavopole==4
            hs=3;                       
        else
            hs=0;            
        end
        if dolepole==2
            vs=1;
        elseif dolepole==5 || dolepole==6
            vs=2;  
        elseif dolepole==3 || dolepole==4
            vs=3;                                   
        else
            vs=0;                      
        end
        if horepole==2
            ps=1;
        elseif horepole==5 || horepole==6
            ps=2;
        elseif horepole==3 || horepole==4
            ps=3;                                               
        else
            ps=0;                      
        end
        
    end
 
end

% funkcia na prehladanie okolia robota radarom
% vrati pozicie kociek [Y X] - [riadok stlpec] v mape
function [novapozkocky]=najdikocku(robot,celamapa,dosahsenzora)
    % def. rozsahu senzora
    rmin=robot.poziciaY-dosahsenzora+1;
    rmax=robot.poziciaY+dosahsenzora+1;
    smin=robot.poziciaX-dosahsenzora+1;
    smax=robot.poziciaX+dosahsenzora+1;
    
    % ohranicenie mapy
    if rmin<2
        rmin=2;
    end
    if smin<1
        smin=1;
    end
    if rmax>41
        rmax=41;
    end
    if smax>41
        smax=41;
    end
    
    % ohranicenie prekazkov, radar cez prekaz nevidi
    ss=robot.poziciaX+1;
    for rr=rmin:robot.poziciaY+1,
        if celamapa(rr,ss)==2
            rmin=rr;
            break;
        end
    end
    rr=robot.poziciaY+1;
    for ss=smin:robot.poziciaX+1,
        if celamapa(rr,ss)==2
            smin=ss;
            break;
        end
    end
    ss=robot.poziciaX+1;
    for rr=robot.poziciaY+1:rmax,
        if celamapa(rr,ss)==2
            rmax=rr;
            break;
        end
    end
    rr=robot.poziciaY+1;
    for ss=robot.poziciaX+1:smax,
        if celamapa(rr,ss)==2
            smax=ss;
            break;
        end
    end    
    novapozkocky=[];
    
    % hladanie kocky v ohranicenom priestore
    for rr=rmin:rmax,
        for ss=smin:smax,
            if celamapa(rr,ss)==5
                novapozkocky=[novapozkocky;rr-1 ss-1 1];
            elseif celamapa(rr,ss)==6
                novapozkocky=[novapozkocky;rr-1 ss-1 2];
            end
        end
    end
            
end
