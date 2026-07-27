% plot_velocity.m
% Reads the logged CSV (expected in the same folder as this script) and
% plots reference vs measured joint velocity for all three joints during
% the constant +y end-effector velocity test (Part 4), saving the figure
% as screenshots/velocity_plot.png alongside this script.

script_dir = fileparts(mfilename('fullpath'));
data = readmatrix(fullfile(script_dir, 'velocity_log.csv'));

% The controller node starts logging as soon as it launches, which is
% normally well before the constant-velocity node (Part 4) is started by
% hand. Trim the idle lead-in so the plot isn't mostly a flat zero line,
% keeping ~0.2s of context before the reference first goes nonzero.
moving = any(abs(data(:, [2 4 6])) > 1e-6, 2);
first_idx = find(moving, 1);
if ~isempty(first_idx)
    lead_in = max(1, first_idx - 20);
    data = data(lead_in:end, :);
end

t = data(:,1) - data(1,1);

joint_labels = {'Joint 1 (rad/s)', 'Joint 2 (rad/s)', 'Joint 3 (m/s)'};

figure;
for i = 1:3
    ref = data(:, 2*i);
    cur = data(:, 2*i + 1);

    subplot(3,1,i);
    plot(t, ref, 'r--', 'LineWidth', 1.5); hold on;
    plot(t, cur, 'b-', 'LineWidth', 1.5);
    grid on;
    xlabel('Time (s)');
    ylabel(joint_labels{i});
    title(sprintf('Joint %d Velocity Tracking: Reference vs. Measured', i));
    legend('Reference', 'Measured', 'Location', 'best');
end

out_dir = fullfile(script_dir, 'screenshots');
if ~exist(out_dir, 'dir')
    mkdir(out_dir);
end
exportgraphics(gcf, fullfile(out_dir, 'velocity_plot.png'), 'Resolution', 150);
