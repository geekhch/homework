%-------------------------------------
function weights = compute_weights_NG(imPatch, TargetModel, ColorModel, Nbins)
w = zeros(size(imPatch));
b = floor(256/Nbins);
matrix_bin = floor(imPatch/b) + 1;

% This kind of method below is slower (but not much), because we do loop for each pixel
% [row, col] = size(imPatch);
% for i=1:row
%     for j=1:col
%         value = matrix_bin(i,j);
%         w(i,j) = sqrt(TargetModel(value)/ColorModel(value));
%     end
% end

% let's make weight matrix
for u=1:Nbins
    %this if to avoid empty element in bins that can lead into division by zero
    if (sum(sum(matrix_bin==u))~=0)
        w = w + (matrix_bin==u) * sqrt(TargetModel(u)/ColorModel(u));
    end
end

weights = w;

end