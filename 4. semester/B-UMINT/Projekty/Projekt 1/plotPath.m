function [] = plotPath(coord, varargin)
%PLOTPATH Procedure that plots coordinates connecting them with lines. 
%         This procedure also plots up to two obstacles (wider lines)
%   
%     Syntax:
%       [] = plotPath(coord, varargin)
%       
%           coord    - array of 2D vectors that will be plotted and 
%                      connected with lines                      
%           varargin - in this case takes up to two 2D vectors that will be
%                      plotted with wider lines - represtents obstacles

hold on

% Vykreslenie bodov do 2D priestoru
plot(coord(:,1),coord(:,2),'o')

% Pridá "zna?ku" každému z 20 koordinátov
label = {"1.","2.","3.","4.","5.","6.","7.","8.","9.","10.","11.","12.","13.","14.","15.","16.","17.","18.","19.","20."};
text(coord(:,1),coord(:,2),label,'VerticalAlignment','top','HorizontalAlignment','right')

% Spojenie po sebe idúcich koordinátov ?iarou
for i = 1 : length(coord) - 1
    plot([coord(i,1) coord(i+1,1)],[coord(i,2) coord(i+1,2)])
end

% Vykreslenie prekážok
if (nargin >= 3) % Dve prekážky
    % Pridelenie koordinátov ur?ujúcich jednotlivé prekážky
    obst1 = varargin{1};
    obst2 = varargin{2};
    % Spojenie prekážok "hrubšou" ?iarou
    obst1 = plot([obst1(1,1),obst1(2,1)],[obst1(1,2),obst1(2,2)],'LineWidth',3);
    obst2 = plot([obst2(1,1),obst2(2,1)],[obst2(1,2),obst2(2,2)],'LineWidth',3);
elseif (nargin >= 2) % Jedna prekážka
    % Pridelenie koordinátov ur?ujúcich danú prekážku
    obst1 = varargin{1};
    % Spojenie prekážok "hrubšou" ?iarou
    obst1 = plot([obst1(1,1),obst1(1,2)],[obst1(2,1),obst1(2,2)],'LineWidth',3);
end

end