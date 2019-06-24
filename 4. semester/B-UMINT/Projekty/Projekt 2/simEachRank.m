function [] = simEachRank(net,winedata, inputs)
    disp('*****Testovanie pre jednotlive vzorky*****');
    for rank=1:10
        rankElement = find(winedata(:,12)==rank);        
        if not(isempty(rankElement))
            rankElement = inputs(:,rankElement(1));
            testRank = sim(net,rankElement);
            guessedRank = vec2ind(testRank) + 2;       
            disp(num2str(rank)+" => "+num2str(guessedRank));
        else
            disp(num2str(rank)+" => Not in data");
        end
    end
    disp('******************************************');
end

