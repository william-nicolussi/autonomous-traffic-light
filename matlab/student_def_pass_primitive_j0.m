%%
%           Agent Logic
%          Pass Primitive J0
%               2025
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

%% Determine the optimal final velocity to pass function of j0=0
syms v0 vf a0 sf tf;
opt_pos_eq = j_opt(0, v0, a0, sf, vf, 0, tf) == 0;
vf_j0_opt = simplify(solve(opt_pos_eq, vf));

%% Export the solution
final_opt_vel_j0_pass_fun = matlabFunction(vf_j0_opt,'Vars',[v0, a0, sf, tf],'File', fullfile(exportFolder,'final_opt_vel_j0.m'));

%% Determine the optimal time to reach to final velocity with j0=0
opt_time_eq = final_opt_time_pass(v0, a0, sf, final_opt_vel_j0(v0, a0, sf, tf)) == tf;
tf_j0_opt_all = solve(opt_time_eq, tf);
tf_j0_opt_1 = tf_j0_opt_all(1); % the one with '-'
tf_j0_opt_2 = tf_j0_opt_all(2); % the one with '+'

%% Export the solutions
final_opt_time_j0_pass_fun = matlabFunction(tf_j0_opt_all,'Vars',[v0, a0, sf],'File', fullfile(exportFolder,'final_opt_time_j0.m'));
final_opt_time_j0_pass_1_fun = matlabFunction(tf_j0_opt_1,'Vars',[v0, a0, sf],'File', fullfile(exportFolder,'final_opt_time_j0_1.m'));
final_opt_time_j0_pass_2_fun = matlabFunction(tf_j0_opt_2,'Vars',[v0, a0, sf],'File', fullfile(exportFolder,'final_opt_time_j0_2.m'));