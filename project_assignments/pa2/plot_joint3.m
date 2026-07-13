% plot_joint3.m
% Reads the logged CSV (expected in the same folder as this script) and
% plots reference vs measured joint 3 position, saving the figure as
% screenshots/matlab_plot.png alongside this script.

script_dir = fileparts(mfilename('fullpath'));
data = readmatrix(fullfile(script_dir, 'joint3_log.csv'));
t   = data(:,1);
ref = data(:,2);
cur = data(:,3);

figure;
plot(t, ref, 'r--', 'LineWidth', 1.5); hold on;
plot(t, cur, 'b-', 'LineWidth', 1.5);
grid on;
xlabel('Time (s)');
ylabel('Joint 3 Position (m)');
title('Joint 3 Position Tracking: Reference vs. Measured');
legend('Reference', 'Measured', 'Location', 'best');

out_dir = fullfile(script_dir, 'screenshots');
if ~exist(out_dir, 'dir')
    mkdir(out_dir);
end
exportgraphics(gcf, fullfile(out_dir, 'matlab_plot.png'), 'Resolution', 150);
