%% Set file
clear; clc; close all

projPath  = fileparts(pwd);
csvPath = fullfile(projPath, "rrt\");

%% Plot tree.csv
fileName = 'tree.csv';
filePath = fullfile(csvPath, fileName);
dataCSV = readtable(filePath, 'Delimiter', {',',';'});

figure(1);
hold on; grid on;
title('RRT* tree', 'Interpreter', 'None');

x  = dataCSV.x;
y  = dataCSV.y;
parent = dataCSV.parent_index;

plot(x, y, '.', 'MarkerSize', 8);

N = height(dataCSV);
for i = 1:N
    p = parent(i);
    if p ~= -1 % gli indici nel file partono da 0, le righe MATLAB da 1
        parent_row = p + 1;
        plot([x(i) x(parent_row)], [y(i) y(parent_row)], '-');
    end
end

% Plot Obstacles
fileNameObs = 'obstacles.csv';
filePathObs = fullfile(csvPath, fileNameObs);

obs = readtable(filePathObs, 'Delimiter', {',',';'});

for i = 1:height(obs)
    vx = [obs.v1_x(i) obs.v2_x(i) obs.v4_x(i) obs.v3_x(i) obs.v1_x(i)]; 
    vy = [obs.v1_y(i) obs.v2_y(i) obs.v4_y(i) obs.v3_y(i) obs.v1_y(i)];

    % disegno il poligono dell'ostacolo
    plot(vx, vy, 'k-'); % bordo nero
    fill(vx, vy, [0.8 0.2 0.2]); % rosso
end

xlabel('x');
ylabel('y');
hold off;