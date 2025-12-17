%% Set file
clear; clc; close all

projPath  = fileparts(pwd);
csvPath = fullfile(projPath, "rrt\");

%% Plot clothoid.csv

figure(1);
hold on; grid on;
title('Trajectory RRT*', 'Interpreter', 'None');

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
plot(cx, cy, 'g+', 'MarkerSize', 10, 'LineWidth', 2);

% Plot the rrt*
fileGraph = 'paths.csv';
filePath = fullfile(csvPath, fileGraph);
dataCSV = readtable(filePath, 'Delimiter', {',',';'});

path_ids = unique(dataCSV.path_nbr);
numPath = max(path_ids);
path_k = dataCSV(dataCSV.path_nbr==numPath, :);

p_x = path_k.x;
p_y = path_k.y;

lineRRT = plot(p_x, p_y, '-o', LineWidth=1, MarkerSize=4, LineStyle="--", Color=[0, 1, 1]);

% Plot the rrt* refined
fileRefined = 'path_refined.csv';
filePath = fullfile(csvPath, fileRefined);
dataCSV_refined = readtable(filePath, 'Delimiter', {',',';'});

p_x = dataCSV_refined.x;
p_y = dataCSV_refined.y;

lineRRT_refined = plot(p_x, p_y, '-o', LineWidth=1, MarkerSize=4, LineStyle="--", Color=[1, 0, 1]);

% Plot the clothoid
fileClothoids = 'clothoid.csv';
filePath = fullfile(csvPath, fileClothoids);
dataCSVClothoids = readtable(filePath, 'Delimiter', {',',';'});

s = dataCSVClothoids.s;
x = dataCSVClothoids.x;
y = dataCSVClothoids.y;

lineCloth = plot(x, y, LineWidth=1.5, Color=[0, 0, 1]);

xlabel('x [m]');
ylabel('y [m]');
legend([lineRRT, lineRRT_refined, lineCloth], {"rrt*", "rrt* refined","clothoid"}, Location="best");
hold off;
