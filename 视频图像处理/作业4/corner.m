clc;clear;
imgr = imread('facade.bmp');
img = rgb2gray(imgr);

%�����ݶ�ͼ��,��ӳ�䵽0-1��double����
h = [-1 -1 -1; 0 0 0; 1 1 1];
Iy = im2double(imfilter(img, h));
Ix = im2double(imfilter(img, h'));
Iy2_ = Iy.^2;
Ix2_ = Ix.^2;
Ixy_ = Iy.*Ix;

% ���ݶ�ͼ����У�7,2����˹�˲�
Ix2 = imfilter(Ix2_, fspecial('gaussian',[7 7], 2));
Iy2 = imfilter(Iy2_, fspecial('gaussian',[7 7], 2));
Ixy = imfilter(Ixy_, fspecial('gaussian',[7 7], 2));

%����׼���������Ӧͼ��
R = zeros(size(Ixy));
[row,col] = size(Ixy);
for i=1:row
    for j = 1:col
        D = [Ix2(i,j) Ixy(i,j); Ixy(i,j) Iy2(i,j)];
        R(i,j) = det(D) - 0.06*trace(D)^2;
    end
end

% ׼��1�����ص����0.01*maxR
maxR = max(max(R));
R1 = R>(0.01*maxR);

% ׼��2��3x3�������������ֵ��
% ʹ�ü��ٷ�ʽ����ԭͼ�����3x3����ֵ�˲���������˲�ǰ������ֵ��ȵĵ㣬����Եõ�ÿ��3x3��������ֵ��
R2=ordfilt2(R,9,ones(3,3));
R2 = R==R2;

% ����׼��õ��Ľ�����룬�õ��ǵ��Ǿ���
P = R1.*R2;

% ���ת��Ϊ����
[cnry,cnrx] = ind2sub(size(P),find(P==1));


% scatter��ͼ
imshow(imgr)
hold on;
scatter(cnrx,cnry,7,'r','filled');
