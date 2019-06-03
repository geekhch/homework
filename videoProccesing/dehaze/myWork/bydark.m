% 暗通道https://blog.csdn.net/childbor/article/details/81627619
%=========================================================%
%调用规则：（有雾时调用，否则不调用）
%实际操作时,according to experiments：
%percent=under_50/total
%percent<0.1%,取w=0.6
%percent>0.1%&&percent<1%,取w=0.45
%percenet>1%&&percent<2%,取w=0.3
%else not use haze-free-adjust
%有雾：绘制出的直方图<50的部分<1%
%最后控制台还会输出原图中under_50像素点所占比例
%=========================================================%
clc
blockSize=3;               %每个block为15个像素
w0=0.75;                    
t0=0.1;
% A=200;
[filename,pathname]=uigetfile('../images/*.*','select an image');
I = imread([pathname filename]); % 读取彩色图

%set(gcf,'outerposition',get(0,'screensize'));%获得SystemScreenSize 传递给当前图像句柄gcf的outerposition属性
figure
imshow(I);
title('Original Image');
grayI = rgb2gray(I);
%统计<50的像素所占的比例
%%%%%%%%%%%%%%%%%%%%%%
under_50 = sum(sum(grayI<=50));
total=size(I,1)*size(I,2)*size(I,3);
percent=under_50/total;

[h,w,s]=size(I);
min_I=zeros(h,w);
 
dark_I = min(I,[],3);
dark_I = ordfilt2(dark_I,1,ones(blockSize,blockSize));
r = dark_I>(0.98*max(max(dark_I)));
%%　计算透光率
R = I(:,:,1);
G = I(:,:,2);
B = I(:,:,3);
bak(:,1) = R(r);
bak(:,2) = G(r);
bak(:,3) = B(r);
max_val = 0;
[num,c] = size(bak);
for i=1:num
    if(sum(bak(i,:))>max_val)
        A(1,1,:) = double(bak(i,:));
    end
end
dark_channel=double(dark_I);

ceof = double(I);
for i=1:h
    for j=1:w
        ceof(i,j,:) = double(I(i,j,:))./A;
    end
end
ceof = min(ceof,[],3);
ceof = ordfilt2(ceof,1,ones(blockSize,blockSize));
t=1-w0*(ceof);
t(t<t0)=t0;
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
I1=double(I);
J = I;
J(:,:,1) = uint8((I1(:,:,1) - A(1))./t+A(1));
J(:,:,2) = uint8((I1(:,:,2) - A(2))./t+A(2));
J(:,:,3) = uint8((I1(:,:,3) - A(3))./t+A(3));
figure
imshow(J);
title('Haze-Free Image:');
