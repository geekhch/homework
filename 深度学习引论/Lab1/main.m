%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Course: Introduction to Deep Learning
% Teacher: Zhang Yi
% Student:
% ID:
%
% Lab 1 - XOR Problem
%
% Task 1: Implement the function f(s) and F(x1, x2) in F.m
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% prepare the samples
data = [1 0 0 1
    0 1 0 1]; % samples

m = size(data, 2); % number of samples

% for each sample
for i = 1:m
    x = data(:, i); % retrieve the i-th column of data

    if F(x(1), x(2)) == 0
        % display the result
        fprintf('Sample [%i %i] is classified as smooth worm.\n', x(1), x(2));
    elseif F(x(1), x(2)) == 1
        % display the result
        fprintf('Sample [%i %i] is classified as doted worm.\n', x(1), x(2));
    else
        % display the result
        fprintf('Sample [%i %i] is unknown worm.\n', x(1), x(2));
    end
end
