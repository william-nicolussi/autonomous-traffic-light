%% Set file
clear; clc; close all

fileName = 'Follow_path.csv';
projPath  = fileparts(pwd);
vector_step = 5;
csvPath = fullfile(projPath, "bin\log_internal", fileName);
dataCSVPosVeh = readtable(csvPath, 'Delimiter', {',',';'});

x0 = dataCSVPosVeh.X0;
y0 = dataCSVPosVeh.Y0;
v0 = dataCSVPosVeh.v0;
psi0 = dataCSVPosVeh.Psi0;
N = length(v0);
K_US = dataCSVPosVeh.K_US(1);

fileClothoids = 'clothoid.csv';
projPath  = fileparts(pwd);
csvPath = fullfile(projPath, "rrt\");
filePath = fullfile(csvPath, fileClothoids);
dataCSVClothoids = readtable(filePath, 'Delimiter', {',',';'});

s = dataCSVClothoids.s;
x = dataCSVClothoids.x;
y = dataCSVClothoids.y;

%% Plot path

figure(1);
hold on; grid on;
strTitle = sprintf("Position of the vehicle with K_{US}=%.3f", K_US);
sgtitle(strTitle);

%Plot the position of the vehicle
u = v0 .* cos(psi0);
v = v0 .* sin(psi0);

posVeh = plot(x0, y0);

for i = 1 : vector_step : N
    quiver(x0(i), y0(i), u(i), v(i));
end

% Plot the clothoid
lineCloth = plot(x, y, LineWidth=1.5, Color=[0, 0, 1]);

xlabel('s [m]');
ylabel('n [m]');
legend([lineCloth, posVeh], {"clothoid", "vehicle"}, Location="best");
hold off;
