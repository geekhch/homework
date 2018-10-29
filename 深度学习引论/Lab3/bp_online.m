%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Course:  Understanding Deep Neural Networks
% Teacher: Zhang Yi
% Student:
% ID:
%
% Lab 3 - BP algorithms
%
% Task 1: implement online BP algorithm
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% clear the workspace
clear

% define the activation function
f = @(s) 1 ./ (1 + exp(-s));
% define the derivative of activation function
df = @(s) f(s) .* (1 - f(s));

% prepare the training data set
data   = [1 0 0 1
          0 1 0 1]; % samples
labels = [1 1 0 0]; % labels
m = size(data, 2);

% choose parameters, initialize the weights
alpha = 0.1;
epochs = 50000;
w1 = randn(2,3);
w2 = randn(1,3);
J = zeros(1,epochs);

% loop until weights converge
for t = 1:epochs

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Your code BELOW
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% for each samples
    for i = 1:m

% forward calculation (invoke fc)
        a1 = [];
        a2 = []; z2 = [];
        a3 = []; z3 = [];

% calculate cost function
        J(t) = [];

% backwork calculation (invoke bc)
        delta3 = [];
        delta2 = [];

% calculate the gradients
        dw1 = [];
        dw2 = [];

% update weights
        w1 = [];
        w2 = [];

% end for each sample
    end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Your code ABOVE
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% end loop
    if mod(t,100) == 0
        fprintf('%i/%i epochs: J=%.4f\n', t, epochs, J(t));
    end
end

% display the result
for i = 1:4
    a1 = data(:,i);
    [a2, z2] = fc(w1, [a1;1]);
    [a3, z3] = fc(w2, [a2;1]);
    fprintf('Sample [%i %i] (%i) is classified as %i.\n', data(1,i), data(2,i), labels(i), a3>0.5);
end
