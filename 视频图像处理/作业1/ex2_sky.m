im = imread('ch01_data/scene2.jpg'); % ��ȡͼ��
[rows, cols, nc] = size(im); 
% ͨ������
R = im(:,:,1); 
G = im(:,:,2); 
B = im(:,:,3); 
flg = R >= 100 & G >= 100 & B >= 210; 
[x, y] = meshgrid(1:cols, 1:rows);
flg2 = y <= rows/2;
flg = flg & flg2;
R(flg) = 255; 
G(flg) = 127; 
B(flg) = 0; 
im_ = cat(3, R,G,B); 
imshow(im_)
imwrite(im_,'output/ex2_sky2.jpg')