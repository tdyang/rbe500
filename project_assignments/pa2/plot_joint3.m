% plot_joint3.m
% Reads the logged CSV and plots reference vs measured joint 3 position

log_dir = fullfile(getenv('HOME'), 'ros2_ws', 'src', 'scara_controller', 'logs');
files = dir(fullfile(log_dir, 'joint3_log_*.csv'));

[~, idx] = max([files.datenum]);
latest_file = fullfile(files(idx).folder, files(idx).name);

data = readmatrix(latest_file);
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