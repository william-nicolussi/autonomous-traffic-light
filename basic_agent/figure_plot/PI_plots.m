%% Set file

clear; clc; close all

projPath  = fileparts(pwd);
csvPath = fullfile(projPath, "bin\log_internal");
matlabPath = fullfile(projPath, 'matlab\functions_exported');
addpath(matlabPath);

fileName = 'Longitudinal_control.csv';
filePath = fullfile(csvPath, fileName);
dataCSV = readtable(filePath, 'Delimiter', {',',';'});

%% Save data into vectors

cycle = dataCSV.cycle;
s0 = dataCSV.s0;
s_req = dataCSV.s_req;
t = dataCSV.time;
v0 = dataCSV.v0;
v_req = dataCSV.v_req;
a0 = dataCSV.a0;
a_req = dataCSV.a_req;
k_p = dataCSV.k_p(1);
k_i = dataCSV.k_i(1);

%% Plot: s(t), v(t), a(t)

figure (1);
strTitle = sprintf("s(t), v(t), a(t) with k_p=%.3f, k_i=%.3f", k_p, k_i);
sgtitle(strTitle);

% --- s(t) ---
subplot(3,1,1);
plot(t, s_req, t, s0);
xlabel("Time [s]");
ylabel("Distance [m]");
legend("s\_req","s\_real","Location","best");
grid on;

% --- v(t) ---
subplot(3,1,2);
plot(t, v_req, t, v0);
xlabel("Time [s]");
ylabel("Velocity [m/s]");
legend("v\_req","v\_real","Location","best");
grid on;

% --- a(t) ---
subplot(3,1,3);
plot(t, a_req, t, a0);
xlabel("Time [s]");
ylabel("Acceleration [m/s^2]");
legend("a\_req","a\_real","Location","best");
grid on;

%% Plot: v(s), a(s)

figure (2);
strTitle = sprintf("v(s), a(s) with k_p=%.3f, k_i=%.3f", k_p, k_i);
sgtitle(strTitle);

% --- v(s) ---
subplot(2,1,1);
plot(s0, v_req, s0, v0);
xlabel("Space [m]");
ylabel("Velocity [m/s]");
legend("v\_req","v\_real","Location","best");
grid on;

% --- Acceleration ---
subplot(2,1,2);
plot(s0, a_req, s0, a0);
xlabel("Space [m]");
ylabel("Acceleration [m/s^2]");
legend("a\_req","a\_real","Location","best");
grid on;