%%
%           Agent Logic
%         Stop Primitive J0
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

%% Determine the optimal final position imposing j0=0
syms v0 a0 sf tf;
opt_pos_eq = j_opt(0, v0, a0, sf, 0, 0, tf) == 0;
sf_j0_opt = simplify(solve(opt_pos_eq, sf)); %s_f^(j0)

%% Export the solution
final_opt_pos_j0_fun = matlabFunction(sf_j0_opt,'Vars',[v0, a0, tf],'File', fullfile(exportFolder,'final_opt_pos_j0.m'));

%% Determine the optimal time to stop with j0=0
opt_time_eq = final_opt_time_stop(v0, a0, final_opt_pos_j0(v0, a0, tf)) == tf;
sf_j0_opt_all = simplify(solve(opt_time_eq, tf));
sf_j0_opt = sf_j0_opt_all(2);

%% Export the solution
final_opt_time_stop_j0_fun = matlabFunction(sf_j0_opt,'Vars',[v0, a0],'File', fullfile(exportFolder,'final_opt_time_stop_j0.m'));
