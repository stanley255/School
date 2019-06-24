clear
load winequalityred.txt

calc = zeros(10,1)';
for i=1:length(winequalityred)
    index = winequalityred(i,12)';
    calc(index) = calc(index) + 1;
end

for i=1:length(calc(1,:))
   disp(i+" => "+calc(1,i)); 
end

for i=1:length(calc(1,:))
   disp(i+" => "+(calc(1,i)/length(winequalityred))*100+"%"); 
end