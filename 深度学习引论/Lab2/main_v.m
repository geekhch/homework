%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Course: Introduction to Deep Learning
% Teacher: Zhang Yi
% Student:
% ID:
%
% Lab 2 - Feedforward Computation
%
% Task 2: Implement the forward computation of FNN in vector form
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% prepare the samples
data = [1 0 0 1
    0 1 0 1]; % samples
labels = [1 1 0 0]; % labels

m = size(data, 2); % number of samples

% assign connection weight
w1 = [ 2  2  -1
    -1 -1 1.5]; % connection from layer 1 to layer 2
w2 = [ 1  1  -1.5 ]; % connection from layer 2 to layer 3

% for each sample
for i = 1:m
    x = data(:, i); % retrieve the i-th column of data

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Your code BELOW
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    % layer 1 - input layer
    a1 = x;

    % layer 2 - hidden layer
    a2 = [];
    % 1. calculate the activation a2, call function fc_v


    % layer 3 - output layer
    a3 = [];
    % 2. calculate the activation a3, call function fc_v


    % collect result
    y = a3;
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Your code ABOVE
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    % display the result
    fprintf('Sample [%i %i] is classified as %i.\n', x(1), x(2), y);
end
