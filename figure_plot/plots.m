%% Set file
clear; clc; close all

projPath  = fileparts(pwd);
csvPath = fullfile(projPath, "bin\log_internal");
matlabPath = fullfile(projPath, 'matlab\functions_exported');
addpath(matlabPath);

%% Plot: s(t), v(t), a(t)
fileName = 'Test.csv';
filePath = fullfile(csvPath, fileName);
dataCSV = readtable(filePath, 'Delimiter', {',',';'});
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
plot(abscissa, dataCSV.v0);
ylabel("Velocity");
legend("v\_req","v\_real","Location","best");
grid on;

% --- Acceleration ---
subplot(3,1,3);
plot(abscissa, dataCSV.a_req); hold on;
plot(abscissa, dataCSV.a0);
ylabel("Acceleration");
legend("a\_req","a\_real","Location","best");
grid on;

%% Plot: v(s), a(s)
fileName = 'Test.csv';
filePath = fullfile(csvPath, fileName);
dataCSV = readtable(filePath, 'Delimiter', {',',';'});
sgtitle(fileName, 'Interpreter', 'None');

figure(1);
abscissa = dataCSV.dist;

% --- Velocity ---
subplot(2,1,1);
plot(abscissa, dataCSV.v_req); hold on;
plot(abscissa, dataCSV.v0);
ylabel("Velocity");
legend("v\_req","v\_real","Location","best");
grid on;

% --- Acceleration ---
subplot(2,1,2);
plot(abscissa, dataCSV.a_req); hold on;
plot(abscissa, dataCSV.a0);
ylabel("Acceleration");
legend("a\_req","a\_real","Location","best");
grid on;
%% Plot: v(t) with primitives

fileName = 'Test.csv';
filePath = fullfile(csvPath, fileName);
dataCSV = readtable(filePath, 'Delimiter', {',',';'});

cycle_first = 1; % start to plot from this cycle
cycle_step = 10; % plot every cycle
cycle_last =  max(dataCSV.cycle); % plot until this cycle

figure; hold on;

% plot v_req; v_real
abscissa = dataCSV.time;
title(fileName, 'Interpreter', 'None');
plot(abscissa, dataCSV.v_req);
plot(abscissa, dataCSV.v0);

for cycle = cycle_first : cycle_step : cycle_last
    t_init = dataCSV.time(cycle);
    t_fin = dataCSV.final_time(cycle);
    
    % select only the time in [t_init, t_fin]
    idx = (dataCSV.time >= t_init) & (dataCSV.time <= (t_fin+t_init));
    t_vec = dataCSV.time(idx);
    
    coef_all = [ dataCSV.c0(cycle), dataCSV.c1(cycle), dataCSV.c2(cycle), dataCSV.c3(cycle), dataCSV.c4(cycle), dataCSV.c5(cycle)];
    v_primitive = v_from_coeffs(t_vec-t_init, coef_all);
    plot(t_vec, v_primitive, Color="green");
    fprintf("cycle=%d   t_init=%.6f   t_fin=%.6f\n   c1=%.6f\n", cycle, t_init, t_fin, dataCSV.c1(cycle));
end
ylim([-1,50]);

xlabel("Time"); ylabel("Velocity");
legend("v\_req","v0","v\_primitive","Location","best");
grid on; hold off;

%% Plot: a(t) with primitives

fileName = 'Test_4_Coeff.csv';
filePath = fullfile(csvPath, fileName);
dataCSV = readtable(filePath, 'Delimiter', {',',';'});

cycle_first = 1; % start to plot from this cycle
cycle_step = 10; % plot every cycle
cycle_last =  max(dataCSV.cycle); % plot until this cycle

figure; hold on;

% plot v_req; v_real
abscissa = dataCSV.time;
title(fileName, 'Interpreter', 'None');
plot(abscissa, dataCSV.a_req);
plot(abscissa, dataCSV.a_real);

for cycle = cycle_first : cycle_step : cycle_last
    t_init = dataCSV.time(cycle);
    t_fin = dataCSV.final_time(cycle);
    
    % select only the time in [t_init, t_fin]
    idx = (dataCSV.time >= t_init) & (dataCSV.time <= t_fin);
    t_vec = dataCSV.time(idx);
    
    coef_all = [ dataCSV.c0(cycle), dataCSV.c1(cycle), dataCSV.c2(cycle), dataCSV.c3(cycle), dataCSV.c4(cycle), dataCSV.c5(cycle)];
    a_primitive = a_from_coeffs(t_vec,coef_all);
    plot(t_vec, a_primitive, Color="green");
    fprintf("cycle=%d   t_init=%.6f   t_fin=%.6f\n   c1=%.6f\n", cycle, t_init, t_fin, dataCSV.c1(cycle));
end

xlabel("Time"); ylabel("Acceleration");
legend("a\_req","a\_real","a\_primitive","Location","best");
grid on; hold off;

%% Draw primitives velocity
% requested velocity and velocity of the vehicles. Then write the
% sto and pass primitives (in space and time).

% convert all the function -> use student_def_optimal_control instead of
% prototypes. coeff sono double 1x6.
% Tutte le funzioni sono nello stesso file "primitives.c" -> codegen all
% functions in one file.

%taking the coefficient you can plot the primitives.
% 



%% Draw primitives acceleration
% "It is important that you remove the initial time"
for ind = 1:10:length(dataCSV.time);
    tt = dataCSV.time(ind);
    Tfinal = dataCSV.final_time(ind);
    time_primitive_idx = find(dataCSV.time >= tt & dataCSV.time <= Tfinal + tt);
    times_primitive_vect = dataCSV.time(time_primitive_idx);
    vel_primitive_vect = v_from_coeffs(times_primitive_vect-tt, [dataCSV.c0(ind),dataCSV.c1(ind),dataCSV.c2(ind),dataCSV.c3(ind),dataCSV.c4(ind),dataCSV.c5(ind)]);
    plot(times_primitive_vect, vel_primitive_vect, '-g', 'LineWidth', 0.5, 'HandleVisibility','off');
end
ylim([-1,50]);