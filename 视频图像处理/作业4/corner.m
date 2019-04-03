clc;clear;
imgr = imread('facade.bmp');
img = rgb2gray(imgr);

%计算梯度图像,并映射到0-1的double类型
h = [-1 -1 -1; 0 0 0; 1 1 1];
Iy = im2double(imfilter(img, h));
Ix = im2double(imfilter(img, h'));
Iy2_ = Iy.^2;
Ix2_ = Ix.^2;
Ixy_ = Iy.*Ix;

% 对梯度图像进行（7,2）高斯滤波
Ix2 = imfilter(Ix2_, fspecial('gaussian',[7 7], 2));
Iy2 = imfilter(Iy2_, fspecial('gaussian',[7 7], 2));
Ixy = imfilter(Ixy_, fspecial('gaussian',[7 7], 2));

%计算准则函数及其对应图像
R = zeros(size(Ixy));
[row,col] = size(Ixy);
for i=1:row
    for j = 1:col
        D = [Ix2(i,j) Ixy(i,j); Ixy(i,j) Iy2(i,j)];
        R(i,j) = det(D) - 0.06*trace(D)^2;
    end
end

% 准则1：像素点大于0.01*maxR
maxR = max(max(R));
R1 = R>(0.01*maxR);

% 准则2：3x3邻域内最大像素值点
% 使用加速方式：对原图像进行3x3极大值滤波，再求出滤波前后像素值相等的点，则可以得到每个3x3邻域的最大值点
R2=ordfilt2(R,9,ones(3,3));
R2 = R==R2;

% 两条准则得到的结果相与，得到角点标记矩阵
P = R1.*R2;

% 标记转换为坐标
[cnry,cnrx] = ind2sub(size(P),find(P==1));


% scatter绘图
imshow(imgr)
hold on;
scatter(cnrx,cnry,7,'r','filled');
