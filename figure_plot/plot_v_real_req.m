%% Set file
clear; clc; close all
basePath = 'C:\Users\HP\Desktop\UniTn\IVAD\autonomous_traffic_light-main\bin\log_internal';

%% Plot

fileName = 'Values_PI_prof.csv';
filePath = fullfile(basePath, fileName);
dataCSV = readtable(filePath);
sgtitle(fileName, 'Interpreter', 'None');

figure(1);
abscissa = dataCSV.time;

% --- Distance from traffic light ---
subplot(3,1,1);
plot(abscissa, dataCSV.s_req); hold on;
plot(abscissa, dataCSV.dist);
ylabel("Distance");
legend("s\_req","s\_real","Location","best");
grid on;

% --- Velocity ---
subplot(3,1,2);
plot(abscissa, dataCSV.v_req); hold on;
plot(abscissa, dataCSV.v_real);
ylabel("Velocity");
legend("v\_req","v\_real","Location","best");
grid on;

% --- Acceleration ---
subplot(3,1,3);
plot(abscissa, dataCSV.a_req); hold on;
plot(abscissa, dataCSV.a_real);
ylabel("Acceleration");
legend("a\_req","a\_real","Location","best");
grid on;

%% Draw primitives
% requested velocity and velocity of the vehicles. Then write the
% sto and pass primitives (in space and time).

% convert all the function -> use student_def_optimal_control instead of
% prototypes. coeff sono double 1x6.
% Tutte le funzioni sono nello stesso file "primitives.c" -> codegen all
% functions in one file.

%taking the coefficient you can plot the primitives.
% 