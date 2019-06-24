function [indices_train, indices_val, indices_test] = getCrossValidationIndices()


% 5 dielov => 1 diel == 320prvkov
%     grpA = 1:320;
%     grpB = 321:640;
%     grpC = 641:960;
%     grpD = 961:1280;
%     grpE = 1281:1599;
% 
%     indices_train = [grpA, grpD, grpE];
%     indices_val = [];
%     indices_test = [grpB, grpC];


% 10 dielov => 1 diel == 160prvkov

    grp1 = 1:160;
    grp2 = 161:320;
    grp3 = 321:480;
    grp4 = 481:640;
    grp5 = 641:800;
    grp6 = 801:960;
    grp7 = 961:1120;
    grp8 = 1121:1280;
    grp9 = 1281:1440;
    grp10 = 1440:1599;
    indices_train = [grp3, grp4, grp5, grp6, grp9, grp10];
%     indices_train = [grp1, grp7, grp3, grp9, grp5, grp10];
    indices_val = [];
%     indices_test = [grp2, grp4, grp6, grp8];
    indices_test = [grp1, grp2, grp7, grp8];    
end

