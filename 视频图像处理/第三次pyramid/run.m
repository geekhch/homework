lena = imread('lena_color.bmp'); %: input image
nLayers = 3; %: number of Gaussian layers 
hsize = 21; %: filter size (gaussian filter)
sigma = logspace(-1, 2, 50); %: vector of inner layer variance (gaussian filter)
factor = 1/2; %: resize factor between adjacent layer

cur_factor = 1;
aviobj = VideoWriter('pyramid.avi');
aviobj.FrameRate=30; %控制视频速度
open(aviobj);

pyramid = cell(nLayers,50); %50个不同sigma滤波器
for level_loop = 1:nLayers
    resized = imresize(lena,cur_factor,'bilinear');
    for filter = 1:50
        h = fspecial('gaussian',[9,9],sigma(filter));
        blured = imfilter(resized, h); %滤波
        pyramid{level_loop,filter} = blured;
    end
    cur_factor = cur_factor*factor; %上一层金字塔缩小比例
end

% 视频方式显式金字塔
for level=1:3
    for filter=1:50
        img = lena;
        for last = 1:level
            [w,h,d] = size(pyramid{last,filter});
            img(1:w,1:h,:) = pyramid{last,filter};
        end
        writeVideo(aviobj, img);
    end
end
close(aviobj)

        