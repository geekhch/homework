% 单应性矩阵 H =     
% 0.7369   -0.1211   -0.0003
% 0.0298    0.9468   -0.0000
% 501.7590    5.2591    1.0000

% 重叠部分，使用左边和右边设置0.5为权重进行加权

%%
function imageStitching 
    Img1Str = 'data\test2.jpg'; 
    Img2Str = 'data\test3.jpg'; 
    im1 = im2double(rgb2gray(imread(Img1Str))); 
    im2 = im2double(rgb2gray(imread(Img2Str))); 
    %% 提取sift特征
    [frames1, des1] = sift(im1);
    [frames2, des2] = sift(im2);
    matches = siftmatch(des1, des2, 3); 
    figure;
    h=plotmatches(im1,im2,frames1(1:2,:),frames2(1:2,:),matches);
    %% 计算单应性矩阵H
    match1 = frames1(1:2,matches(1,:))+1; 
    match2 = frames2(1:2,matches(2,:))+1; 
    [rows1, cols1] = size(im1); 
    H = estimateGeometricTransform(match2', match1', 'projective');
    
    %% 使用H计算img2对应的新坐标
    [rows2, cols2] = size(im2); 
    [x2, y2] = meshgrid(1:cols2, 1:rows2); 
    m = (H.T)' * [x2(:) y2(:) ones(numel(im2), 1)]'; 
    m = m'; 
    m(:, 1) = m(:, 1) ./ m(:, 3); 
    m(:, 2) = m(:, 2) ./ m(:, 3); 
    m = round(m(:, 1:2)); 
    
    %% 拼接图像的非重叠部分的像素值
    I1 = im2double(imread(Img1Str)); 
    I2 = im2double(imread(Img2Str)); 
        
    [rows1, cols1] = size(im1); 
    minx = min(min(m(:, 1)), 1); 
    miny = min(min(m(:, 2)), 1); 
    maxx = max(max(m(:, 1)), cols1); 
    maxy = max(max(m(:, 2)), rows1); 
    rows = round(maxy - miny + 1); 
    cols = round(maxx - minx + 1); 
    I3_left = zeros(rows, cols, 3); 
    I3_left(1 - miny + 1 : 1 - miny + 1 + rows1 -1, 1 - minx + 1 : 1 - minx + 1 + cols1 -1, :) = I1; 

    panoramaView = imref2d([rows cols], [minx maxx], [miny maxy]);
    I3_right = imwarp(I2, H, 'OutputView', panoramaView); 
    
    R_left = I3_left(:, :, 1); 
    G_left = I3_left(:, :, 2); 
    B_left = I3_left(:, :, 3); 
    R_right = I3_right(:, :, 1); 
    G_right = I3_right(:, :, 2); 
    B_right = I3_right(:, :, 3); 
    
    %% 重叠部分处理    
    msk_left = R_left == 0 & G_left == 0 & B_left == 0;  
    msk_right = R_right == 0 & G_right == 0 & B_right == 0;  
    
    msk = msk_left==0 & msk_right==0; 
    
    result = I3_left + I3_right; 
    R = result(:,:,1);
    G = result(:,:,2);
    B = result(:,:,3);
    R(msk) = 0.9*R_left(msk) + 0.1*R_right(msk);
    G(msk) = 0.9*G_left(msk) + 0.1*G_right(msk);
    B(msk) = 0.9*B_left(msk) + 0.1*B_right(msk);
    result = cat(3, R, G, B); 
%     imwrite(result, 'data\output.jpg');
    figure;
    imshow(result)
end 