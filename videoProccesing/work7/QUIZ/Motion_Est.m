%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Motion Estimation
% 
% [MVx MVy] = Motion_Est(img_test, img_ref, opts)
% estimates motion based on block matching. 
%
% Input: img_test         - current   image
%        img_ref          - reference image
%        opts.BlockSize   - block size {default: 10}
%        opts.SearchLimit - search limit {default: 10}
%
% Output: MVx - horizontal motion vectors
%         MVy - vertical motion vectors
%        
% 
% Stanley Chan
% 
% Copyright 2010
% University of California, San Diego
%
% Last Modified:
%  3 Jun, 2009
% 28 Apr, 2010
%  5 May, 2010 bug corrected, thanks to Ramsin Khoshabeh
% 29 Jun, 2010 modified for color images
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [MVx MVy] = Motion_Est(img_test, img_ref, opts)
% Set default values
if ~isfield(opts,'BlockSize')
    opts.BlockSize = 10;
end

if ~isfield(opts,'SearchLimit')
    opts.SearchLimit = 20;
end

% Set lower limits to BlockSize and SearchLimit
BlockSize   = max(opts.BlockSize,   6);
SearchLimit = max(opts.SearchLimit, 6);

if mod(BlockSize,2)~=0
    error('it is better to have BlockSize = even number');
end
if mod(SearchLimit,2)~=0
    error('it is better to have SearchLimit = even number');
end

% Crop the images so that image size is a multiple of BlockSize
M        = floor(size(img_ref, 1)/BlockSize)*BlockSize;
N        = floor(size(img_ref, 2)/BlockSize)*BlockSize;
img_ref  = img_ref(1:M, 1:N, :);
img_test = img_test(1:M, 1:N, :);


% Enlarge the image boundaries by BlockSize/2 pixels
img_ref  = padarray(img_ref,  [BlockSize/2 BlockSize/2], 'replicate');
img_test = padarray(img_test, [BlockSize/2 BlockSize/2], 'replicate');

% Pad zeros to images to fit SearchLimit
img_ref  = padarray(img_ref,  [SearchLimit, SearchLimit]);
img_test = padarray(img_test, [SearchLimit, SearchLimit]);


% Set parameters
[M N C]     = size(img_ref);
L           = floor(BlockSize/2); %向下取整
BlockRange  = -L:L-1;
xc_range    = SearchLimit+L+1 : BlockSize : N-(SearchLimit+L);
yc_range    = SearchLimit+L+1 : BlockSize : M-(SearchLimit+L);

MVx = zeros(length(yc_range), length(xc_range));
MVy = zeros(length(yc_range), length(xc_range));


% Main Loop
for i = 1:length(yc_range)
    for j = 1:length(xc_range)
        xc = xc_range(j);
        yc = yc_range(i);
        
        Block           = img_test(yc + BlockRange, xc + BlockRange, :);
        
        [MVy1 MVx1]     = FullSearch(Block, img_ref, xc, yc, SearchLimit);
        
        MVx(i,j) = MVx1;
        MVy(i,j) = MVy1;
    end
end
 
% Maximize MV
MVx(MVx> SearchLimit) =  SearchLimit;
MVx(MVx<-SearchLimit) = -SearchLimit;
MVy(MVy> SearchLimit) =  SearchLimit;
MVy(MVy<-SearchLimit) = -SearchLimit;


% Median filter to clean up MV
MVx = medfilt2(MVx, [3 3]);
MVy = medfilt2(MVy, [3 3]);
