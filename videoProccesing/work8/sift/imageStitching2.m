function imageStitching2

    Img1Str = 'data\panorama_image1.jpg'; 
    Img2Str = 'data\panorama_image2.jpg'; 
    im1 = im2double(rgb2gray(imread(Img1Str))); 
    im2 = im2double(rgb2gray(imread(Img2Str))); 
    [frames1, des1] = sift(im1);
    [frames2, des2] = sift(im2);
    matches = siftmatch(des1, des2, 100); 
%     figure;
%     h=plotmatches(im1,im2,frames1(1:2,:),frames2(1:2,:),matches);
    % pnt1 = A * pnt2; 
    match1 = frames1(1:2,matches(1,:))+1; 
    match2 = frames2(1:2,matches(2,:))+1; 
    [rows1, cols1] = size(im1); 
    A = estimateGeometricTransform(match2', match1', 'projective');
  
    [rows2, cols2] = size(im2); 
    [x2, y2] = meshgrid(1:cols2, 1:rows2); 
    m = (A.T)' * [x2(:) y2(:) ones(numel(im2), 1)]'; 
    m = m'; 
    m(:, 1) = m(:, 1) ./ m(:, 3); 
    m(:, 2) = m(:, 2) ./ m(:, 3); 
    m = round(m(:, 1:2)); 
        
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
    I3_right = imwarp(I2, A, 'OutputView', panoramaView); 
    
    R_left = I3_left(:, :, 1); 
    G_left = I3_left(:, :, 2); 
    B_left = I3_left(:, :, 3); 
    R_right = I3_right(:, :, 1); 
    G_right = I3_right(:, :, 2); 
    B_right = I3_right(:, :, 3); 
    msk_left = R_left == 0 & G_left == 0 & B_left == 0;  
    msk_right = R_right == 0 & G_right == 0 & B_right == 0;  
    
    R_right(msk_right) = R_left(msk_right); 
    G_right(msk_right) = G_left(msk_right); 
    B_right(msk_right) = B_left(msk_right); 
    
    
    R_left(msk_left) = R_right(msk_left); 
    G_left(msk_left) = G_right(msk_left); 
    B_left(msk_left) = B_right(msk_left); 
    
    R = 0.5*R_left + 0.5*R_right;
    G = 0.5*G_left + 0.5*G_right;
    B = 0.5*B_left + 0.5*B_right;
    result = cat(3, R, G, B); 
    imwrite(result, 'data\panorama_stitching2.bmp'); 
        
end 