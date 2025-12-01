%#codegen
%%
%          Agent Logic
%         Stop Primitive
%              2025
%
%

%% Function
% This function must be converted in c code using coder add-on.
% Copy from this path C:\Program Files\MATLAB\R2024a\extern\include


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

%% Stopping Primitive

function [m, s_max, tf] = stop_primitive(v0, a0, sf)
    if v0<=0 || sf==0  % If negative velocity or null final position, return all 0
        s_max = 0.;
        tf = 0.;
        m = zeros(1, 6);
    else
        if 4*v0^2+5*a0*sf < 0  % --- Unfeasible case ---
            s_max = - (4*v0^2)/(5*a0);
            tf = (10*s_max)/(2*v0);
        else  % --- Feasible case ---
            s_max = sf;
            tf = final_opt_time_stop(v0, a0, s_max);
        end
        m = coef_list(v0, a0, s_max, 0, 0, tf);
end