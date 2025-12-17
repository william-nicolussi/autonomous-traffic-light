%% Set file
clear; clc; close all

projPath  = fileparts(pwd);
csvPath = fullfile(projPath, "bin\log_internal");
matlabPath = fullfile(projPath, 'matlab\functions_exported');
addpath(matlabPath);

fileName = 'Follow_path.csv';
filePath = fullfile(csvPath, fileName);
dataCSV = readtable(filePath, 'Delimiter', {',',';'});

%% Save data into vectors
cycle = dataCSV.cycle;
s0 = dataCSV.variable_s;
t = dataCSV.time;
TL_state = dataCSV.TL_state;
a0 = dataCSV.a0;
a_req = dataCSV.a_req;
final_time = dataCSV.final_time;

c0 = dataCSV.c0;
c1 = dataCSV.c1;
c2 = dataCSV.c2;
c3 = dataCSV.c3;
c4 = dataCSV.c4;
c5 = dataCSV.c5;

y_min = min([a0; a_req]);
y_max = max([a0; a_req]);

%% Get portions of data with a certain TL_state
idx_change = find(diff(TL_state) ~= 0);
cycle_TL_changed = cycle(idx_change + 1);
time_TL_changed = t(idx_change + 1);
idx_start = [1; idx_change + 1]; % beginning of interval
N = length(t);
idx_end   = [idx_change+1; N]; % end of interval
nSeg = length(idx_start); % number of intervals

rectX = cell(nSeg,1);
rectY = cell(nSeg,1);
rectState = zeros(nSeg,1);

for k = 1:nSeg
    
    i1 = idx_start(k);
    i2 = idx_end(k);
    
    t_start = t(i1);
    t_end   = t(i2); 
    
    rectState(k) = TL_state(i1);
    
    % vertexes of the region:
    % (t_start, y_max) -- (t_end  , y_max)
    %        |                    |
    % (t_start, y_min) -- (t_end  , y_min)

    x_rect = [t_start  t_end    t_end    t_start  t_start];
    y_rect = [y_min    y_min    y_max    y_max    y_min  ];
    
    rectX{k} = x_rect;
    rectY{k} = y_rect;
end

%% To calculate v(t) Primitive
plot_step = 10; % plot every cycle


%% Plot: a(t)

figure (1); hold on;

title("Longitudinal Control in time");
xlabel('time [s]');
ylabel('acceleration [m/s^2]');
ylim([-1,20]);

% Draw Background same color as TL_state
for k = 1:nSeg
    x_rect = rectX{k};
    y_rect = rectY{k};
    
    switch rectState(k)
        case 1
            col = [0.8 1.0 0.8];   % light green
        case 2
            col = [1.0 1.0 0.6];   % yellow
        case 3
            col = [1.0 0.8 0.8];   % red
    end
    fill(x_rect, y_rect, col, 'EdgeColor','none', 'FaceAlpha', 0.4);
end

% Plot Primitives
for i = 1 : plot_step : N
    t_init = t(i);
    t_fin = final_time(i);

    % select only the time in [t_init, t_fin]
    idx = (t >= t_init) & (t <= (t_fin+t_init));
    t_vec = t(idx);

    coef_all = [ c0(i), c1(i), c2(i), c3(i), c4(i), c5(i)];
    a_primitive = a_from_coeffs(t_vec-t_init, coef_all);
    % If-else necessary to plot the legend
    if i==1
        line_prim = plot(t_vec, a_primitive, Color='Green', LineWidth = 0.4);
    else
        plot(t_vec, a_primitive, Color='Green', LineWidth = 0.4);
    end
    % fprintf("i=%d   t_init=%.6f   t_fin=%.6f\n   c1=%.6f\n", i, t_init, t_fin, c1(i));
end

% Plot a0 and a_req
line_a0 = plot(t, a0, Color='Red', LineWidth=1.5);
line_a_req = plot(t, a_req, Color='Blue', LineWidth=1.5, LineStyle="--");

legend([line_a_req, line_a0, line_prim], {"v\_req","a0","v\_primitive"}, "Location", "best");
grid on; hold off;


%% Get portions of data with a certain TL_state
idx_change = find(diff(TL_state) ~= 0);
space_TL_changed = s0(idx_change + 1);
idx_start = [1; idx_change + 1]; % beginning of interval
N = length(s0);
idx_end   = [idx_change+1; N]; % end of interval
nSeg = length(idx_start); % number of intervals

rectX = cell(nSeg,1);
rectY = cell(nSeg,1);
rectState = zeros(nSeg,1);

for k = 1:nSeg
    
    i1 = idx_start(k);
    i2 = idx_end(k);
    
    s_start = s0(i1);
    s_end   = s0(i2); 
    
    rectState(k) = TL_state(i1);
    
    % vertexes of the region:
    % (t_start, y_max) -- (t_end  , y_max)
    %        |                    |
    % (t_start, y_min) -- (t_end  , y_min)

    x_rect = [s_start  s_end    s_end    s_start  s_start];
    y_rect = [y_min    y_min    y_max    y_max    y_min  ];
    
    rectX{k} = x_rect;
    rectY{k} = y_rect;
end

%% Plot a(s)

figure(2); hold on;

title("Longitudinal Control in space");
xlabel('space [m]');
ylabel('acceleration [m/s^2]');
ylim([-1,20]);

% Draw Background same color as TL_state
for k = 1:nSeg
    x_rect = rectX{k};
    y_rect = rectY{k};
    
    switch rectState(k)
        case 1
            col = [0.8 1.0 0.8];   % light green
        case 2
            col = [1.0 1.0 0.6];   % yellow
        case 3
            col = [1.0 0.8 0.8];   % red
    end
    fill(x_rect, y_rect, col, 'EdgeColor','none', 'FaceAlpha',0.4);
end

% Plot Primitives in space
for i = 1 : plot_step : N
    t_init = t(i);
    t_fin = final_time(i);

    idx = (t >= t_init) & (t <= (t_fin+t_init));
    t_vec = t(idx);
    coef_all = [ c0(i), c1(i), c2(i), c3(i), c4(i), c5(i)];
    a_primitive = a_from_coeffs(t_vec-t_init, coef_all);
    s_primitive = s_from_coeffs(t_vec-t_init, coef_all) + s0(i);
    if i == 1
        line_prim_s = plot(s_primitive, a_primitive, Color='Green', LineWidth=0.4);
    else
        plot(s_primitive, a_primitive, Color='Green', LineWidth=0.4);
    end
    fprintf("i=%d; t_init=%.6f; t_fin=%.6f; c1=%.6f; s0(i)=%.6f\n", i, t_init, t_fin, c1(i), s0(i));
end

% Plot a0(s) and a_req(s)
line_v0_s = plot(s0, a0, Color='Red', LineWidth=1.5);
line_v_req_s = plot(s0, a_req, Color='Blue', LineWidth=1.5, LineStyle="--");

legend([line_v_req_s, line_v0_s, line_prim_s], {"v\_req(s)","a0(s)","v\_primitive(s)"}, "Location", "best");
grid on; hold off;
