%%%%
% ͨ��ֱ��ͼ���⻯ȥ��
% ȱ�㣺rgbʧ������
%%%%

[filename,pathname]=uigetfile('../images/*.*','select an image');
RGB = imread([pathname filename]); % ��ȡ��ɫͼ
figure
imshow(RGB);
title('ԭͼ');
gray = rgb2gray(RGB);
[R, C, K] = size(RGB); % ������K��ʾ��ɫͨ����

% ͳ��ÿ������ֵ���ִ���
cnt = zeros(256,1);

for i = 1 : R
    for j = 1 : C
            cnt(gray(i, j) + 1) = cnt(gray(i, j) + 1) + 1;
    end
end
f = zeros(256,1);
cnt = double(cnt);
% ͳ��ÿ������ֵ���ֵĸ��ʣ� �õ�����ֱ��ͼ

    for i = 1 : 256
        f( i) = cnt(i) / (R * C);
    end
% ���ۼƸ��ʣ��õ��ۼ�ֱ��ͼ

    for i = 2 : 256
        f(i) = f( i - 1) + f( i);
    end

% ��f����ʵ������ֵ[0, 255]��ӳ�䡣 

    for i = 1 : 256
        f(i) = f(i) * 255;
    end

% ���ÿ�����ص��ӳ��

for i = 1 : R
    for j = 1 : C

            gray(i, j) = f( gray(i, j) + 1);

    end
end

figure
imshow(gray);
title('���⻯�ĻҶ�ͼ');

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
% ͳ��ÿ������ֵ���ֵĸ��ʣ� �õ�����ֱ��ͼ
for k = 1 : K
    for i = 1 : 256
        f(k, i) = cnt(k, i) / (R * C);
    end
end
% ���ۼƸ��ʣ��õ��ۼ�ֱ��ͼ
for k = 1 : K
    for i = 2 : 256
        f(k, i) = f(k, i - 1) + f(k, i);
    end
end
% ��f����ʵ������ֵ[0, 255]��ӳ�䡣 
for k = 1 : K
    for i = 1 : 256
        f(k, i) = f(k, i) * 255;
    end
end
% ���ÿ�����ص��ӳ��
RGB = double(RGB);
for i = 1 : R
    for j = 1 : C
        for k = 1 : K
            RGB(i, j, k) = f(k, RGB(i, j, k) + 1);
        end
    end
end


% ���
RGB = uint8(RGB);
figure
imshow(RGB);
title('�����rgbͼ');