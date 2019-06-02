function [ J ] = byDarkFun( I, blockSize, w0)
%BYDARKFUN �˴���ʾ�йش˺�����ժҪ
%   blockSize [1,151];
%   w0 [0.1 1] Խ��ȥ��Խ���ԣ������ܵ�����ɫʧ��

t0 = 0.1; % ��С������
grayI=rgb2gray(I);
[h,w,s]=size(I);
 
dark_I = min(I,[],3);
dark_I = ordfilt2(dark_I,1,ones(blockSize,blockSize));
r = dark_I>(0.99*max(max(dark_I)));
%%������͸����
R = I(:,:,1);
G = I(:,:,2);
B = I(:,:,3);
bak(:,1) = R(r);
bak(:,2) = G(r);
bak(:,3) = B(r);
max_val = 0;
[num,c] = size(bak);

%% ȫ�������A
for i=1:num
    if(sum(bak(i,:))>max_val)
        A(1,1,:) = double(bak(i,:));
    end
end
ceof = double(I);
for i=1:h
    for j=1:w
        ceof(i,j,:) = double(I(i,j,:))./A;
    end
end

%% ͸����t
ceof = min(ceof,[],3);
ceof = ordfilt2(ceof,1,ones(blockSize,blockSize));
t=1-w0*(ceof);
t(t<t0)=t0;
 
%% ȥ��
I1=double(I);
J = I;
J(:,:,1) = uint8((I1(:,:,1) - A(1))./t+A(1));
J(:,:,2) = uint8((I1(:,:,2) - A(2))./t+A(2));
J(:,:,3) = uint8((I1(:,:,3) - A(3))./t+A(3));
end

