%% Define the folder to get matlabfunction
% before typing "coder", execute these lines to add the folder to the
% project path

% nameExportFolder = 'functions_exported';
% currentFolder = pwd;
% exportFolder = fullfile(currentFolder, nameExportFolder); %...\matlab\def_functions
% if ~exist(exportFolder, 'dir')
%     mkdir(exportFolder);
% end
% addpath(exportFolder);

%%
clear; clc; close all

%% prototypes
pass_primitive(5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0);
stop_primitive(5.0,6.0,7.0);
coef_list(5.0, 6.0, 7.0, 8.0, 9.0, 10.0);

s_opt(2.0, 3.0, 4.0, 5.0, 7.0, 8.0, 9.0);
v_opt(2.0, 3.0, 4.0, 5.0, 7.0, 8.0, 9.0);
a_opt(2.0, 3.0, 4.0, 5.0, 7.0, 8.0, 9.0);
j_opt(2.0, 3.0, 4.0, 5.0, 7.0, 8.0, 9.0);

s_from_coeffs(1.0, [1.0, 2.0, 3.0, 4.0, 5.0, 6.0]);
v_from_coeffs(1.0, [1.0, 2.0, 3.0, 4.0, 5.0, 6.0]);
a_from_coeffs(1.0, [1.0, 2.0, 3.0, 4.0, 5.0, 6.0]);
j_from_coeffs(1.0, [1.0, 2.0, 3.0, 4.0, 5.0, 6.0]);

total_cost(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
time_min_vel_pass(1.0, -2.0);
min_vel(1.0, -2.0, 3.0);

final_opt_time_pass(1.0, 2.0, 3.0, 4.0);
final_opt_time_stop(1.0, 2.0, 3.0);
final_opt_vel_pass(1.0, -2.0, 3.0, 4.0);

final_opt_pos_j0(1.0, 2.0, 3.0);
final_opt_time_j0(1.0, 2.0, 3.0);
final_opt_time_j0_1(1.0, 2.0, 3.0);
final_opt_time_j0_2(1.0, 2.0, 3.0);
final_opt_time_stop_j0(1.0, 2.0);
final_opt_vel_j0(1.0, 2.0, 3.0, 4.0);

pass_primitive_j0(1.0, 2.0, 3.0, 4.0, 5.0);
stop_primitive_j0(1.0, 2.0);