lena = imread('lena_color.bmp'); %: input image
nLayers = 3; %: number of Gaussian layers 
hsize = 21; %: filter size (gaussian filter)
sigma = logspace(-1, 2, 50); %: vector of inner layer variance (gaussian filter)
factor = 1/2; %: resize factor between adjacent layer

cur_factor = 1;
aviobj = VideoWriter('pyramid.avi');
open(aviobj);

pyramid = cell(nLayers,50);
for level_loop = 1:nLayers
    resized = imresize(lena,cur_factor,'bilinear');
    for filter = 1:50
        h = fspecial('gaussian',[9,9],sigma(filter));
        blured = imfilter(resized, h);
        pyramid{level_loop,filter} = blured;
    end
    cur_factor = cur_factor*factor;
end

for level=1:3
    for last = 1:level
        