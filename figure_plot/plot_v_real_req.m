%%
clear; clc; close all

%% Plot of real velocity and requested velocity
Example = readtable('C:\Users\HP\Desktop\UniTn\IVAD\autonomous_traffic_light-main\bin\log_internal\Example.csv');
plot(Example.time, Example.v_req);
hold on
plot(Example.time,Example.v_real);

%% Draw primitives
% requested velocity and velocity of the vehicles. Then write the
% sto and pass primitives (in space and time).

% convert all the function -> use student_def_optimal_control instead of
% prototypes. coeff sono double 1x6.
% Tutte le funzioni sono nello stesso file "primitives.c" -> codegen all
% functions in one file.

%taking the coefficient you can plot the primitives.
% 