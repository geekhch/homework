% ��ͨ��https://blog.csdn.net/childbor/article/details/81627619
%=========================================================%
%���ù��򣺣�����ʱ���ã����򲻵��ã�
%ʵ�ʲ���ʱ,according to experiments��
%percent=under_50/total
%percent<0.1%,ȡw=0.6
%percent>0.1%&&percent<1%,ȡw=0.45
%percenet>1%&&percent<2%,ȡw=0.3
%else not use haze-free-adjust
%�������Ƴ���ֱ��ͼ<50�Ĳ���<1%
%������̨�������ԭͼ��under_50���ص���ռ����
%=========================================================%
clc
blockSize=3;               %ÿ��blockΪ15������
w0=0.75;                    
t0=0.1;
% A=200;
[filename,pathname]=uigetfile('../images/*.*','select an image');
I = imread([pathname filename]); % ��ȡ��ɫͼ

%set(gcf,'outerposition',get(0,'screensize'));%���SystemScreenSize ���ݸ���ǰͼ����gcf��outerposition����
figure
imshow(I);
title('Original Image');
grayI = rgb2gray(I);
%ͳ��<50��������ռ�ı���
%%%%%%%%%%%%%%%%%%%%%%
under_50 = sum(sum(grayI<=50));
total=size(I,1)*size(I,2)*size(I,3);
percent=under_50/total;

[h,w,s]=size(I);
min_I=zeros(h,w);
 
dark_I = min(I,[],3);
dark_I = ordfilt2(dark_I,1,ones(blockSize,blockSize));
r = dark_I>(0.98*max(max(dark_I)));
%%������͸����
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
