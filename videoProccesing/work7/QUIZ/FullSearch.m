function [MVy MVx] = FullSearch(Block, img_ref, xc, yc, SearchLimit)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Full Search algorithm
%
% [MVy MVx] = FullSearch(Block, img_ref, xc, yc, SearchLimit)
% finds the motion vector of the (yc, xc)-th Block in the reference image
% img_ref.
%
% Input:
% Block         - the current block being searched
% img_ref       - the reference image
% xc, yc        - (xc, yc) is the center coordinate of Block
%
% Output:
% [MVy MVx]     - the motion vector of Block
%
% Stanley Chan
% 3 Jun, 2009
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Parameters
[M N C]       = size(img_ref);
BlockSize   = size(Block,1);
L           = floor(BlockSize/2);
BlockRange  = -L:L-1;
SearchRange = SearchLimit;
SADmin      = 1e6;


%% Rejection
if (yc<=SearchRange+L)||(yc>=M-(SearchRange+L))
    error('Can you set yc >%3g pixels from the boundary? \n',SearchRange+L);
end

if (xc<=SearchRange+L)||(xc>=N-(SearchRange+L))
    error('Can you set xc >%3g pixels from the boundary? \n',SearchRange+L);
end


%% Full Search Loop
for i = -SearchRange:SearchRange
    for j = -SearchRange:SearchRange
        xt = xc + j;
        yt = yc + i;
        
        Block_ref  = img_ref(yt+BlockRange, xt+BlockRange, :);
        SAD        = sum(abs(Block(:) - Block_ref(:)))/(BlockSize^2);
        
        if SAD < SADmin
            SADmin  = SAD;
            x_min   = xt;
            y_min   = yt;
        end
        
        % Motion Vector (integer part)
        MVx_int = xc - x_min;
        MVy_int = yc - y_min;
    end
end

MVx = MVx_int;
MVy = MVy_int;


end

