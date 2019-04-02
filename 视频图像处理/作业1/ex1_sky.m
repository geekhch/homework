im = imread('ch01_data/scene1.jpg'); % ��ȡͼ��
[rows, cols, nc] = size(im); 
% ͨ������
R = im(:,:,1); 
G = im(:,:,2); 
B = im(:,:,3); 
flg = R >= 120 & G >= 150 & B >= 200; 
[x, y] = meshgrid(1:cols, 1:rows);
R(flg) = 255; 
G(flg) = 127; 
B(flg) = 0; 
im_ = cat(3, R,G,B); 
imshow(im_)
imwrite(im_,'output/ex1_sky1.jpg')