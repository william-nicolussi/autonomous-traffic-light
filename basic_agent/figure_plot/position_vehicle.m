%% Set file
clear; clc; close all

fileName = 'Follow_path.csv';
projPath  = fileparts(pwd);
vector_step = 5;
clothoid_step = 10;
csvPath = fullfile(projPath, "bin\log_internal", fileName);
dataCSVPosVeh = readtable(csvPath, 'Delimiter', {',',';'});

x0 = dataCSVPosVeh.X0;
y0 = dataCSVPosVeh.Y0;
v0 = dataCSVPosVeh.v0;
psi0 = dataCSVPosVeh.Psi0;
x_ref = dataCSVPosVeh.X_closest;
y_ref = dataCSVPosVeh.Y_closest;
psi_ref = dataCSVPosVeh.Psi_closest;
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
posVeh = plot(x0, y0, LineWidth=1.5, Color=[1, 0.5, 0]);

% for i = 1 : vector_step : N
%     quiver(x0(i), y0(i), u(i), v(i));
% end

% Plot the clothoid
lineCloth = plot(x, y, LineWidth=1.5, Color=[0, 0, 1]);

% Plot C1
C1 = ClothoidCurve();
for i = 1 : clothoid_step : N
    SX = x0(i);
    SY = y0(i);
    SPsi = psi0(i);

    EX = x_ref(i);
    EY = y_ref(i);
    EPsi = psi_ref(i);

    C1.build_G1(SX, SY, SPsi, EX, EY, EPsi);
    C1.plot(20, 'Color', 'Green');
    quiver(x0(i), y0(i), u(i), v(i));
end

xlabel('s [m]');
ylabel('n [m]');
legend([lineCloth, posVeh], {"clothoid", "vehicle"}, Location="best");
hold off;
