function a_next = fc_c(w, a)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% implement forward computation from layer l to layer l+1
% in component form
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % define the activation function
    f = @(s) s >= 0;
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Your code BELOW
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % 1. add external inputs with value 1

    % for each neuron located in layer l+1
    for i=1:size(w,1)
        % 2. calculate net input

        % 3. calculate activation

    end

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Your code ABOVE
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
end
