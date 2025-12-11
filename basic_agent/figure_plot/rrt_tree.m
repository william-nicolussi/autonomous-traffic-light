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
    if p ~= -1 % index in matlab starts with 1 instead of 0 in c++
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

    % draw poly of the obstacle
    plot(vx, vy, 'k-'); % black bordes
    fill(vx, vy, [0.8 0.2 0.2]); % red inside
end

% Plot Obstacles
fileNameObs = 'obstacles.csv';
filePathObs = fullfile(csvPath, fileNameObs);

obs = readtable(filePathObs, 'Delimiter', {',',';'});

for i = 1:height(obs)
    obx = [obs.ob1_x(i) obs.ob2_x(i) obs.ob4_x(i) obs.ob3_x(i) obs.ob1_x(i)];
    oby = [obs.ob1_y(i) obs.ob2_y(i) obs.ob4_y(i) obs.ob3_y(i) obs.ob1_y(i)];
    plot(obx, oby, 'k-', 'LineWidth', 1.5);
    fill(obx, oby, [0.6 0.6 0.6], 'FaceAlpha', 0.4);

    vx = [obs.v1_x(i) obs.v2_x(i) obs.v4_x(i) obs.v3_x(i) obs.v1_x(i)]; 
    vy = [obs.v1_y(i) obs.v2_y(i) obs.v4_y(i) obs.v3_y(i) obs.v1_y(i)];

    plot(vx, vy, 'r-', 'LineWidth', 1.5);
    fill(vx, vy, [0.8 0.2 0.2], 'FaceAlpha', 0.3);
end

% Plot goal circle
fileNameEnd = 'endNode.csv';
filePathEnd = fullfile(csvPath, fileNameEnd);
endNode = readtable(filePathEnd, 'Delimiter', {',',';'});

cx = endNode.x(1);
cy = endNode.y(1);
R  = endNode.GOAL_THRESHOLD(1);

theta = linspace(0, 2*pi, 200);
xc = cx + R * cos(theta);
yc = cy + R * sin(theta);

fill(xc, yc, [0.4 1.0 0.4], 'FaceAlpha', 0.35, 'EdgeColor', [0 0.7 0], 'LineWidth', 0.5);
plot(cx, cy, 'g+', 'MarkerSize', 10, 'LineWidth', 2);   % center goal

xlabel('x');
ylabel('y');
hold off;

%% Plot Path(s) found
fileName = 'paths.csv';
filePath = fullfile(csvPath, fileName);
dataCSV = readtable(filePath, 'Delimiter', {',',';'});

figure(2);
hold on; grid on;
title('Path(s) found with RRT*', 'Interpreter', 'None');

path_ids = unique(dataCSV.path_nbr);
numPaths = numel(path_ids);
colors = lines(numPaths); 

legendHandles = gobjects(numPaths,1);
legendNames = strings(numPaths,1);

for k = 1:numPaths
    pid = path_ids(k);
    
    mask   = (dataCSV.path_nbr == pid);
    path_k = dataCSV(mask, :); % only one path
    
    x = path_k.x;
    y = path_k.y;
    parent = path_k.parent_index;
    
    idx_col = path_k.index;
    [~, parent_row] = ismember(parent, idx_col);

    for i = 1:height(path_k)
        plot(x(i), y(i), 'o', 'MarkerSize', 5, 'MarkerFaceColor', colors(k,:), 'MarkerEdgeColor', colors(k,:));
        
        pRow = parent_row(i);
        if parent(i) ~= -1 && pRow > 0
            h = plot([x(i) x(pRow)], [y(i) y(pRow)], '-', 'Color', colors(k,:), 'LineWidth', 1.5);
        end
    end

    % Plot legend
    thisCost = path_k.cost(end);
    legendHandles(k) = h;
    legendNames(k) = sprintf("Path %d – cost %.2f", pid, thisCost);
end
lgd = legend(legendHandles, legendNames, 'Location','best');
lgd.AutoUpdate = 'off';

% Plot Obstacles
fileNameObs = 'obstacles.csv';
filePathObs = fullfile(csvPath, fileNameObs);

obs = readtable(filePathObs, 'Delimiter', {',',';'});

for i = 1:height(obs)
    obx = [obs.ob1_x(i) obs.ob2_x(i) obs.ob4_x(i) obs.ob3_x(i) obs.ob1_x(i)];
    oby = [obs.ob1_y(i) obs.ob2_y(i) obs.ob4_y(i) obs.ob3_y(i) obs.ob1_y(i)];
    plot(obx, oby, 'k-', 'LineWidth', 1.5);
    fill(obx, oby, [0.6 0.6 0.6], 'FaceAlpha', 0.4);

    vx = [obs.v1_x(i) obs.v2_x(i) obs.v4_x(i) obs.v3_x(i) obs.v1_x(i)]; 
    vy = [obs.v1_y(i) obs.v2_y(i) obs.v4_y(i) obs.v3_y(i) obs.v1_y(i)];
    plot(vx, vy, 'r-', 'LineWidth', 1.5);
    fill(vx, vy, [0.8 0.2 0.2], 'FaceAlpha', 0.3);
end

% Plot goal circle
fileNameEnd = 'endNode.csv';
filePathEnd = fullfile(csvPath, fileNameEnd);
endNode = readtable(filePathEnd, 'Delimiter', {',',';'});

cx = endNode.x(1);
cy = endNode.y(1);
R  = endNode.GOAL_THRESHOLD(1);

theta = linspace(0, 2*pi, 200);
xc = cx + R * cos(theta);
yc = cy + R * sin(theta);

fill(xc, yc, [0.4 1.0 0.4], 'FaceAlpha', 0.35, 'EdgeColor', [0 0.7 0], 'LineWidth', 0.5);
plot(cx, cy, 'g+', 'MarkerSize', 10, 'LineWidth', 2);   % centro goal

xlabel('x');
ylabel('y');
hold off;