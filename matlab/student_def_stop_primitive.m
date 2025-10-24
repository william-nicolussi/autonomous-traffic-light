%%
%           Agent Logic
%         Stop Primitive
%              2025
%
%
%%
clear; clc; close all

%% Define the folder to put the matlabfunctions
nameExportFolder = 'functions_exported';
currentFolder = pwd;
exportFolder = fullfile(currentFolder, nameExportFolder); %...\matlab\def_functions
if ~exist(exportFolder, 'dir')
    mkdir(exportFolder);
end
addpath(exportFolder);

%% Determine the optimal time to stop %%
syms z; % We create this variable for more stable solution of the equations
syms v0 a0 sf tf;
J = total_cost_var(v0, a0, sf, 0, 0, tf); %use function declared in student_def_optimal_control.m
Jz = subs(J, tf, 1/z);
dJz = diff(Jz, z);
z_all = solve(dJz==0, z);
z_sol = z_all(1); %z_sol is the positive solution of z_all
tf_sol = 1/z_sol;
disp('Optimal stopping time t_f* = ');
pretty(tf_sol);

%% Export the solution in a matlab function
final_opt_time_stop_fun = matlabFunction(tf_sol,'Vars',[v0,a0,sf],'File', fullfile(exportFolder,'final_opt_time_stop.m'));
disp(['Final opt time to stop saved to: ' exportFolder]);