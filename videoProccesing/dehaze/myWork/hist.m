%%%%
% 通过直方图均衡化去雾
% 缺点：rgb失真严重
%%%%

[filename,pathname]=uigetfile('../images/*.*','select an image');
RGB = imread([pathname filename]); % 读取彩色图
figure
imshow(RGB);
title('原图');
gray = rgb2gray(RGB);
[R, C, K] = size(RGB); % 新增的K表示颜色通道数

% 统计每个像素值出现次数
cnt = zeros(256,1);

for i = 1 : R
    for j = 1 : C
            cnt(gray(i, j) + 1) = cnt(gray(i, j) + 1) + 1;
    end
end
f = zeros(256,1);
cnt = double(cnt);
% 统计每个像素值出现的概率， 得到概率直方图

    for i = 1 : 256
        f( i) = cnt(i) / (R * C);
    end
% 求累计概率，得到累计直方图

    for i = 2 : 256
        f(i) = f( i - 1) + f( i);
    end

% 用f数组实现像素值[0, 255]的映射。 

    for i = 1 : 256
        f(i) = f(i) * 255;
    end

% 完成每个像素点的映射

for i = 1 : R
    for j = 1 : C

            gray(i, j) = f( gray(i, j) + 1);

    end
end

figure
imshow(gray);
title('均衡化的灰度图');

%%%%%%%%%%%%%%%%rgb
cnt = zeros(3,256);
for i = 1 : R
    for j = 1 : C
        for k = 1 : K
            cnt(k, RGB(i, j, k) + 1) = cnt(k, RGB(i, j, k) + 1) + 1;
        end
    end
end
f = zeros(3, 256);
f = double(f); cnt = double(cnt);
% 统计每个像素值出现的概率， 得到概率直方图
for k = 1 : K
    for i = 1 : 256
        f(k, i) = cnt(k, i) / (R * C);
    end
end
% 求累计概率，得到累计直方图
for k = 1 : K
    for i = 2 : 256
        f(k, i) = f(k, i - 1) + f(k, i);
    end
end
% 用f数组实现像素值[0, 255]的映射。 
for k = 1 : K
    for i = 1 : 256
        f(k, i) = f(k, i) * 255;
    end
end
% 完成每个像素点的映射
RGB = double(RGB);
for i = 1 : R
    for j = 1 : C
        for k = 1 : K
            RGB(i, j, k) = f(k, RGB(i, j, k) + 1);
        end
    end
end


% 输出
RGB = uint8(RGB);
figure
imshow(RGB);
title('处理后rgb图');